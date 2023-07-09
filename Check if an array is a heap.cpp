bool isHeap(int arr[],  int n)
{
    // Start from root and go till the last internal
    // node
    for (int i=0; i<=(n-2)/2; i++)
    {
        // If left child is greater, return false
        if (arr[2*i +1] > arr[i])
                return false;
  
        // If right child is greater, return false
        if (2*i+2 < n && arr[2*i+2] > arr[i])
                return false;
    }
    return true;
}
  
