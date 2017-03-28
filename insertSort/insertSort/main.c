//
//  main.c
//  insertSort
//
//  Created by 任超 on 17/3/28.
//  Copyright © 2017年 任超. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

#define N 8

void insert_sort(int a[],int n);
//插入排序实现,这里按从小到大排序
void insert_sort(int a[],int n)//n为数组a的元素个数
{
    //进行N-1轮插入过程
    for(int i=1; i<n; i++)
    {
        //首先找到元素a[i]需要插入的位置
        int j=0;
        while( (a[j]<a[i]) && (j<i))
        {
            j++;
        }
        //将元素插入到正确的位置
        if(i != j)  //如果i==j，说明a[i]刚好在正确的位置
        {
            int temp = a[i];
            for(int k = i; k > j; k--)
            {
                a[k] = a[k-1];
            }
            a[j] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};
    insert_sort(num, N);
    for(int i=0; i<N; i++)
        printf("%d  ", num[i]);
    printf("\n");
    return 0;
}
