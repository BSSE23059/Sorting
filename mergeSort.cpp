#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int end){
    int mid = (start+end)/2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    vector<int> arr1(len1);
    vector<int> arr2(len2);

    int mainArrayIndex = start;
    for(int i=0;i<len1;i++){
        arr1[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for(int i=0;i<len2;i++){
        arr2[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;


    while(index1 < len1 && index2 < len2) {
        if (arr1[index1] < arr2[index2]) {
            arr[mainArrayIndex++] = arr1[index1++];
        } else {
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = arr1[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = arr2[index2++];
    }


}

void mergeSort(vector<int>& arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}

int main(){
    vector<int> v = {10, 7, 1, 6, 9, 14};
    
    // Display original vector
    cout << "Original vector: ";
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;

    // Perform merge sort
    mergeSort(v, 0, v.size() - 1);

    // Display sorted vector
    cout << "Sorted vector: ";
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
