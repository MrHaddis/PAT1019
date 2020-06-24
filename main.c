#include<stdio.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1019

int getNumberList(int number);

void printResult(int result, int lowNumber, int highNumber, int status);

int main() {
    //获取输入的数字
    int number;
    scanf("%d", &number);
    //获取第一次的结果
    int result = getNumberList(number);
    //循环获取结果
    while (result != 6174 && result != 0) {
        result = getNumberList(result);
    }
    return 0;
}

/**
 * 对数字进行处理
 * **/
int getNumberList(int number) {
    //定义一个数组存数字
    int numberArray[4];
    //获取每一位的数字存在数组里面
    for (int i = 0; i < 4; ++i) {
        numberArray[i] = number % 10;
        number /= 10;
    }
    //对数字冒泡排序
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3 - i; ++j) {
            if (numberArray[j] > numberArray[j + 1]) {
                int temp = numberArray[j];
                numberArray[j] = numberArray[j + 1];
                numberArray[j + 1] = temp;
            }
        }
    }
    int result = 0;
    //从小到大的数字
    int lowNumber =
            numberArray[0] * 1000 + numberArray[1] * 100 + numberArray[2] * 10 + numberArray[3];
    //从大到小的数字
    int highNumber =
            numberArray[3] * 1000 + numberArray[2] * 100 + numberArray[1] * 10 + numberArray[0];
    //判断是否是特殊情况的数字
    //这里注意 很多时候提交不过 可能是因为 1000 或者 0001 这样的数字没有处理好。
    if (numberArray[0] == numberArray[1] && numberArray[2] == numberArray[3]
        && numberArray[1] == numberArray[2]) {
        printResult(result, lowNumber, highNumber, 1);
    } else if (lowNumber > 0 && lowNumber < 10) {
        result = highNumber - lowNumber;
        printResult(result, lowNumber, highNumber, 2);
    } else if (lowNumber > 10 && lowNumber < 100) {
        result = highNumber - lowNumber;
        printResult(result, lowNumber, highNumber, 3);
    } else if (lowNumber > 100 && lowNumber < 1000) {
        result = highNumber - lowNumber;
        printResult(result, lowNumber, highNumber, 4);
    } else {
        result = highNumber - lowNumber;
        printResult(result, lowNumber, highNumber, 0);
    }
    return result;
}

/**
 * 输出对应的结果
 * **/
void printResult(int result, int lowNumber, int highNumber, int staus) {
    //下面的补0 是因为不够的位数前面要补0
    switch (staus) {
        case 0:
            if (result < 1000 && result > 100) {
                printf("%d - %d = 0%d\n", highNumber, lowNumber, result);
            } else {
                printf("%d - %d = %d\n", highNumber, lowNumber, result);
            }
            break;
        case 1:
            printf("%d - %d = 0000\n", highNumber, lowNumber);
            break;
        case 2:
            if (result < 1000 && result > 100) {
                printf("%d - 000%d = 0%d\n", highNumber, lowNumber, result);
            } else {
                printf("%d - 000%d = %d\n", highNumber, lowNumber, result);
            }
            break;
        case 3:
            if (result < 1000 && result > 100) {
                printf("%d - 00%d = 0%d\n", highNumber, lowNumber, result);
            } else {
                printf("%d - 00%d = %d\n", highNumber, lowNumber, result);
            }
            break;
        case 4:
            if (result < 1000 && result > 100) {
                printf("%d - 0%d = 0%d\n", highNumber, lowNumber, result);
            } else {
                printf("%d - 0%d = %d\n", highNumber, lowNumber, result);
            }
            break;
    }
}
