void ShellSort(int arr[], int len){
    int i, j, gap;
    for(gap = len / 2; gap > 0; gap/=2){
        for(i = gap; i < len; i++){
            int key = arr[i];
            for(j = i; j>= gap && arr[j-gap] > key; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = key;
        }
    }
}