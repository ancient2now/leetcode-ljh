#include <stdio.h>
#include <stdlib.h>
void array_print(int * array, int len);

void quick_sort(int * array, int len);

void quick_sort_recursive(int * array, int start, int end);

int main(int argc, char const *argv[])
{
    int array[] = {10,0,3,0,5,6,7,8,9};
    int len = sizeof(array)/sizeof(int);
    array_print(array, len);
    quick_sort(array, len);
    array_print(array, len);

    return 0;
}
void quick_sort(int * array, int len){
    quick_sort_recursive(array, 0, len-1);
}

void quick_sort_recursive(int * array, int start, int end){
    printf("=====\n");
    if(start > end)
        return;
    int pivot = array[start];
    int left = start;
    int right= end;
    while(left < right){
        while(left < right && array[right] > pivot){
            right--;
        }
        if(left < right){
            array[left] = array[right];
            left++;
        }
        while(left < right && array[left] < pivot){
            left ++;
        }
        if(left < right){
            array[right] = array[left];
            right--;
        }
    }
    array[left] = pivot;
    quick_sort_recursive(array, start, left-1);
    quick_sort_recursive(array, left+1, end);
}



void array_print(int * array, int len){
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    puts("");
}


