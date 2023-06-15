// #include <bits/stdc++.h> 
// long long merge(vector<int> &arr, int low, int mid, int high){
//     vector<int> temp;
//     int left = low;
//     int right = mid+1;

//     // make pairs 
//     int count=0;
//     while (left<=mid && right<=high){
//         if (arr[left]<=arr[right]){
//             temp.push_back(arr[left]);
//         }
//         else{
//             temp.push_back(arr[right]);
//             count+=(mid-left+1); // the first array has - mid - left + 1
//             right++;
//         }
//     }
//     // if elements on the left half are still left //
//     while (left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     // transfering all elements from temporary to arr //
//     for (int i=low;i<=high;i++){
//         arr[i] = temp[i-low];
//     }
//     return count;


// }

// long long mergesort(vector<int> &arr, int low, int high){
//     int count=0;
//     if (low>=high){
//         return count;
//     }
//     int mid = (low+high)/2;
//     count+=mergesort(arr, low, mid);
//     count+=mergesort(arr,mid+1,high);
//     count+=merge(arr, low, mid,high);
//     return count;
// }

// long long getInversions(long long *arr, int n){
//     // Write your code here.
//     return mergesort(arr, 0, n-1);
// }

#include <bits/stdc++.h> 

long long merge(long long* arr, int n, int left, int mid, int right) {
    long long leftArrSize = (mid - left + 1);
    long long rightArrSize = (right - (mid + 1)) + 1; // (right - mid)

    long long ret = 0;
    long long *leftArr = new long long[leftArrSize];
    long long *rightArr = new long long[rightArrSize];

    for (int i = 0; i < leftArrSize; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < rightArrSize; j++) rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = j = 0;
    k = left;

    while (i < leftArrSize && j < rightArrSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            ret += (mid - (left + i) + 1);
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftArrSize) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArrSize) {
        arr[k++] = rightArr[j++];
    }
    
    delete[] leftArr;
    delete[] rightArr;

    return ret;
}

long long mergeSort(long long* arr, int n, int left, int right) {
    long long ret = 0;
    if (left < right) {
        long long mid = (left + ((right - left) >> 1));
        ret += mergeSort(arr, n, left, mid);
        ret += mergeSort(arr, n, mid + 1, right);
        ret += merge(arr, n, left, mid, right);
    }
    return ret;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, n, 0, n - 1);
}
