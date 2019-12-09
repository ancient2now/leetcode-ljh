
int comp(const void * a, const void * b){
    return *(int*)a-*(int*)b;
}

int largestPerimeter(int* A, int ASize){
    if(ASize < 3)
        return 0;
    qsort(A, ASize, sizeof(int), comp);
    for(int i = ASize-1; i >= 2; i--){
        if(A[i] < (A[i-1]+A[i-2]))
            return A[i]+A[i-1]+A[i-2];
    }
    return 0;
}

