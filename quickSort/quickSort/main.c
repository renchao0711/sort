//
//  main.c
//  quickSort
//
//  Created by 任超 on 17/3/28.
//  Copyright © 2017年 任超. All rights reserved.
//

#include <stdio.h>

int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}

void quick_sort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }
    return;
}

int main(int argc, const char * argv[]) {
    
    int i;
    int arr[6]={32,12,7, 78, 23,45};
    printf("排序前 \n");
    for(i=0;i<6;i++)
        printf("%d\t",arr[i]);
    quick_sort(arr,0,6-1);
    printf("\n排序后 \n");
    for(i=0; i<6; i++)
        printf("%d\t", arr[i]);
    printf ("\n");
    return 0;
}
