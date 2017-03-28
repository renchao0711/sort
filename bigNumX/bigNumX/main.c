//
//  main.c
//  bigNumX
//
//  Created by 任超 on 17/3/28.
//  Copyright © 2017年 任超. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 200

void BigNumberMulti(char *number1, char *number2, int lengthA, int lengthB) {
    
    int tempNumber1[MAX_SIZE], tempNumber2[MAX_SIZE];
    int result[MAX_SIZE] = {0};
    int i, j;
    int count = 0;			//进位
    int temp = 0;
    int resultLen = lengthA + lengthB;
    
    // 字符转整数并反转
    for(i = lengthA - 1; i >= 0; i--) {
        tempNumber1[i] = number1[lengthA - i - 1] - '0';
    }
    
    for(i = lengthB - 1; i >= 0; i--) {
        tempNumber2[i] = number2[lengthB - i - 1] - '0';
    }
    
    // 相乘
    for(i = 0; i <= lengthA; i++) {
        for(j = 0; j <= lengthB; j++) {
            result[i + j] = result[i + j] + tempNumber1[i] * tempNumber2[j];
        }
    }
    
    // 进位
    for(i = 0; i < resultLen; i++) {
        temp = count + result[i];
        result[i] = temp % 10;
        count = temp / 10;
    }
    
    
    for(i = resultLen - 1; i >= 0; i--) {
        if(result[i] != 0) {
            break;
        }
    }
    
    
    resultLen = i + 1;
    
    for(i = resultLen - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    
    printf("\n");
    
}
int main(int argc, const char * argv[]) {
    char number1[MAX_SIZE];
    char number2[MAX_SIZE];
    
    scanf("%s", number1);
    scanf("%s", number2);
    
    BigNumberMulti(number1, number2, (int)strlen(number1), (int)strlen(number2));
    
    return 0;
}
