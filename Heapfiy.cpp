void heapify(int arr[] , int n , int i){
    //inititalize largest as root;
    int largest = i;
    //left
    int left = 2 * i + 1;
    //right;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != i){
        swap(&arr[i] , &arr[largest]);
        heapify(arr , n , largest);
    }
}
