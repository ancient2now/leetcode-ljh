#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int  a, int b);
void heapify(int arr[], int start, int end);
void heap_sort(int arr[], int len);
void array_print(int * array, int len);


int main(int argc, char const *argv[])
{
    int arr[] = {10,2,1,40,3,12,7,8,12};
    int len = sizeof(arr)/sizeof(int);
    array_print(arr, len);
    heap_sort(arr, len);
    array_print(arr, len);
    return 0;
}


void heap_sort(int arr[], int len){
    int root = len/2 - 1;
    /*构建大顶堆*/
    for(int i = root; i >= 0; i--){
        heapify(arr, i, len);
    }
    /*堆调整*/
    for(int i = len; i > 0; i--){
        swap(arr, 0, i-1);
        heapify(arr, 0, i-1);
    }
}


void heapify(int arr[], int root, int len){
    if(root >= len)
        return;
    int left = root*2 + 1;
    int right = root*2 + 2;
    int max = root;
    if(left < len && arr[left] > arr[max]){
        max = left;
    }
    if(right < len && arr[right] > arr[max]){
        max = right;
    }
    if(max != root){
        swap(arr, root, max);
        heapify(arr, max, len);
    }
}


void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void array_print(int * array, int len){
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    puts("");
}

