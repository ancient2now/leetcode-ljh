/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//如果数字非常大应该怎么处理？
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int temp[1000] ={0};
    for(int i = 0; i < nums1Size; i++){
        temp[nums1[i]] = 1;
    }
    for(int i = 0; i < nums2Size; i++){
        if(temp[nums2[i]] == 1){
            temp[nums2[i]]++;
        }        
    }
    int * ret = malloc(sizeof(int)*1000);
    int index = 0;
    for(int i = 0; i < 1000; i++){
        if(temp[i] > 1){
            ret[index++] = i; 
        }
    }
    *returnSize = index;
    return ret;
}
