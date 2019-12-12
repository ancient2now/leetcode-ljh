#include "test.h"
void recursion(int arr[], int L, int R){
    if(L > R)
        return;
    int pivot = arr[L];
    int l = L;
    int r = R;
    while(l < r){
        while(l < r && arr[r] > pivot){
            r--;
        }
        if(l < r){
            arr[l++] = arr[r];
        }
        while(l < r && arr[l] < pivot)
        {
            l++;
        }
        if(l < r){
            arr[r--] = arr[l];
        }    
    }
    arr[l] = pivot;

    recursion(arr, L, l-1);
    recursion(arr, l+1, R);
}
void QuickSort(int arr[], int len){
    recursion(arr, 0, len-1);
}
