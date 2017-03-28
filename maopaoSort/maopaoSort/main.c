//
//  main.c
//  maopaoSort
//
//  Created by 任超 on 17/3/28.
//  Copyright © 2017年 任超. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 8

//一般实现
void bubble_sort(int a[],int n)//n为数组a的元素个数
{
    //一定进行N-1轮比较
    for(int i=0; i<n-1; i++)
    {
        //每一轮比较前n-1-i个，即已排序好的最后i个不用比较
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
//优化实现
void bubble_sort_better(int a[],int n)//n为数组a的元素个数
{
    //最多进行N-1轮比较
    for(int i=0; i<n-1; i++)
    {
        int isSorted = 1;
        //每一轮比较前n-1-i个，即已排序好的最后i个不用比较
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                isSorted = 0;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
        if(isSorted)
            break; //如果没有发生交换，说明数组已经排序好了
    }
}



int main(int argc, const char * argv[]) {
    int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};
    //bubble_sort(num, N);
    bubble_sort_better(num, N);
    for(int i=0; i<N; i++)
        printf("%d  ", num[i]);
    printf("\n");
    return 0;
}
