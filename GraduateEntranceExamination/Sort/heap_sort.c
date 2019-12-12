#include "test.h"
void heapify(int arr[], int root, int len){
    if(root > len)
        return;
    int left = root*2 + 1;
    int right = root*2 + 2;
    int max = root;
    if(left < len && arr[left] > arr[max])
        max = left;
    if(right < len && arr[right] > arr[max])
        max = right;

    if(max != root){
        int temp = arr[root];
        arr[root] = arr[max];
        arr[max] = temp;
    }
    heapify(arr, left, len);
    heapify(arr, right, len);
}
void HeapSort(int arr[], int len){
    //构建大顶堆
    int i;
    for(i = (len-1) / 2; i >=0; i--){
        heapify(arr, i, len);
    }
    //调整堆，每次取出堆顶最大的那个元素
    for(i = len; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = temp;
        heapify(arr, 0, i-1);
    }
}





