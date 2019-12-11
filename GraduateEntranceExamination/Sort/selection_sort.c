void SelectSort(int arr[], int len){
    int i, j;
    int min;
    for(i = 0; i < len; i++){
        min = i;
        for(j = i+1; j < len; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}