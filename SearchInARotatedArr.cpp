int search(int* arr, int n, int key) {
    // Write your code here.
    // step -1 
    int low = 0;
    int high = n-1;

    // step 2 
    while (low<=high){
        //int mid = low + ((high – low) / 2); 
        int mid = (low + high) >> 1;
        if (arr[mid]==key){
            return mid;
        }
        // either on the left or right partion 
        // sorted 
        if (arr[low]<=arr[mid]){
            if (arr[low]<=key && arr[mid]>=key){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // not in ascend sort 
        else{
            if (arr[mid]<=key && key<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
