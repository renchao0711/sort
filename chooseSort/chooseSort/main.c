//
//  main.c
//  chooseSort
//
//  Created by 任超 on 17/3/28.
//  Copyright © 2017年 任超. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#define N 8

void select_sort(int a[],int n);
//选择排序实现
void select_sort(int a[],int n)//n为数组a的元素个数
{
    //进行N-1轮选择
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        //找出第i小的数所在的位置
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        //将第i小的数，放在第i个位置；如果刚好，就不用交换
        if( i != min_index)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};
    select_sort(num, N);
    for(int i=0; i<N; i++)
        printf("%d  ", num[i]);
    printf("\n");
    return 0;
}
