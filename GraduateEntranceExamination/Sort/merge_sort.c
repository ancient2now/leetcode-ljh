#include "test.h"
//数组分为两半后，每一个都是排好序的，组合成新的有序数组
void merge(int * arr, int L, int M, int R){
    /*
    L-M 为数组1
    M-R 为数组2
    L M R 全为数组下标
    */
    int i;
    int len1 = M-L+1;
    int arr1[len1];
    int len2 = R-M;
    int arr2[len2];
    int index = 0;
    //拆分两数组
    for(i = L; i <= M; i++){
        arr1[index++] = arr[i];
    }
    index = 0;
    for(; i <= R; i++){
        arr2[index++] = arr[i];
    }

    //合并两数组
    int i1 = 0;
    int i2 = 0;
    index = L;
    while(i1 < len1 && i2 < len2){
        if(arr1[i1] < arr2[i2]){
            arr[index++] = arr1[i1++];
        }else{
            arr[index++] = arr2[i2++];
        }
    }
    while(i1 < len1){
        arr[index++] = arr1[i1++];
    }
    while(i2 < len2){
        arr[index++] = arr2[i2++];
    }
}
void MergeSort(int arr[], int L, int R){
    if(L == R)
        return;
    int mid = (L+R) / 2;
    MergeSort(arr, L, mid); 
    MergeSort(arr, mid+1, R);
    merge(arr, L, mid, R);
}