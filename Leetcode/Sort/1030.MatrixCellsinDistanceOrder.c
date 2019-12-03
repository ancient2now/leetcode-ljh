#include <stdio.h>
#include <stdlib.h>
/* O(n^2) 超时*/
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int ** ret = (int**)malloc(100*100*sizeof(int*));
    int index = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int * new = (int*)malloc(2*sizeof(int));
            new[0] = i;
            new[1] = j;
            ret[index++] = new;
        }
    }
    *returnSize = index;
    *returnColumnSizes = malloc(index*sizeof(int));
    for(int i = 0; i < index; i++){
        (*returnColumnSizes)[i] = 2;
        for(int j = 0; j < index-1-i; j++){
            int dis1 = abs(ret[j][0]-r0)+abs(ret[j][1]-c0);
            int dis2 = abs(ret[j+1][0]-r0)+abs(ret[j+1][1]-c0);
            if(dis1 > dis2){
                int * temp = ret[j];
                ret[j] = ret[j+1];
                ret[j+1] = temp;
            }
        }
    }
    
    return ret;
}
int main(int argc, char const *argv[])
{
    int R = 2;
    int C = 2;
    int r0 = 0;
    int c0 = 1;
    int * returnColumnSizes;
    int returnSize = 0;
    int ** ret = allCellsDistOrder(R, C, r0, c0, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; i++){
        printf("%d %d \n", ret[i][0], ret[i][1]);
    }
    return 0;
}
