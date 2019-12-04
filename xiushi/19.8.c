#include <stdlib.h>
#include <stdio.h>

/* 实现时间复杂度为O(M+N)，查找两个有序数组元素最小差值*/
int GetMinArraySubtraction(int * arr1, int * arr2, int len1, int len2){
    if(arr1[0] >= arr2[len2-1])
        return arr1[0] - arr2[len2-1];
    if(arr1[len1-1] < arr2[0])
        return arr2[0] - arr1[len1-1];

    int index1 = 0;
    int index2 = 0;
    int ret = 1000;
    while (index1 < len1 && index2 < len2)
    {
        if(arr1[index1] <= arr2[index2]){
            int temp = arr2[index2] - arr1[index1];
            if(ret > temp){
                ret = temp;
            }
            index1++;
        }else
        {
            int temp = arr1[index1] - arr2[index2];
            if(ret > temp){
                ret = temp;
            }
            index2++;
        }      
    }
    return ret;
}
int findMinVal(int * arr1, int * arr2, int len1, int len2){
    if(arr1[0] >= arr2[len2-1])
        return arr1[0] - arr2[len2-1];
    if(arr1[len1-1] < arr2[0])
        return arr2[0] - arr1[len1-1];
    puts("===");
    int ret = 1000;
    int index1 = 0;
    int index2 = 0;

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            int temp =  abs(arr2[j]-arr1[i]);
            if(ret > temp){
                ret = temp;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1,3,7};
    int arr2[] = {2,7};
    int minVal = findMinVal(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
    int minVal2 = GetMinArraySubtraction(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
    printf("%d %d\n", minVal, minVal2);
    return 0;
}
