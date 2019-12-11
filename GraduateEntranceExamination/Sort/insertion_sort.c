void InsertSort(int arr[], int len){
    int i, j;
    int key;
    for(i = 1; i < len; i++){
        key = arr[i];
        for(j = i; j > 0 && arr[j-1] > key; j--){
            arr[j] = arr[j-1]; 
        }
        arr[j] = key;
    }
}