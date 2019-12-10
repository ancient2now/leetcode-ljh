#include <stdio.h>
#include <stdlib.h>

void array_print(int * array, int len);
void merge(int * array, int L, int M, int R);
void merge_sort(int * array, int L, int R);

int main(int argc, char const *argv[])
{
    int arr[] = {10,2,1,40,3,12,7,8,12,100};
    // int arr[] = {1,2,10,40,3,12,7,8,12};

    int len = sizeof(arr)/sizeof(int);
    array_print(arr, len);
    merge_sort(arr, 0, len-1);
    // merge(arr, 3, 3, 4);
    array_print(arr, len);
    return 0;
    return 0;
}

void merge_sort(int * array, int L, int R){
    if(L == R)
        return;
    int mid = (L+R) / 2;
    merge_sort(array, L, mid);
    merge_sort(array, mid+1, R);
    merge(array, L, mid, R);
}

//数组分为两半后，每一个都是排好序的，组合成新的有序数组
void merge(int * array, int L, int M, int R){
    int left_size = M-L+1;
    int right_size = R-M;
    // printf("left_size=%d right_size=%d\n", left_size, right_size);
    int left_array[left_size];
    int right_array[right_size];
    int left_index = 0;
    int right_index = 0;
    int i;
    int index = L;
    //给左边数组赋值
    for(i = 0; i < left_size; i++){
        left_array[i] = array[index++];
    }
    // array_print(left_array, left_size);
    //给右边数组赋值
    for(i = 0 ; i < right_size; i++){
        right_array[i] = array[i+M+1];
    }
    // array_print(right_array, right_size);

    index = L;
    //合并两个有序数组
    while(left_index < left_size && right_index < right_size){
        if(left_array[left_index] < right_array[right_index]){
            array[index++] = left_array[left_index++];
        }else{
            array[index++] = right_array[right_index++];
        }
    }

    while(left_index < left_size){
        array[index++] = left_array[left_index++];
    }
    while(right_index < right_size){
        array[index++] = right_array[right_index++];
    }

}


void array_print(int * array, int len){
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    puts("");
}