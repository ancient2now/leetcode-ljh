#include <stdio.h>
void print_array(int * arr, int len);
int binary_search(int * arr, int len, int val);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr) / sizeof(int);
    print_array(arr, len);
    int index = binary_search(arr, len, 7);
    if(index != -1)
        printf("arr[%d]=%d\n", index, arr[index]);
    return 0;
}
int binary_search(int * arr, int len, int val){
    if(len == 0)
        return -1;
    int low = 0;
    int high = len-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == val)
            return mid;
        else if(arr[mid] < val)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

void print_array(int * arr, int len){
    for(int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

