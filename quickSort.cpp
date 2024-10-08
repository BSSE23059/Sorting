#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int> &arr, int start, int end){
    int pivot = arr[start];

    int count = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i=start, j = end;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}

void quick_sort(vector<int> &arr,int start, int end){

    // Base case: stop sorting when start index is greater than ending index
    if(start >= end){
        return;
    }

    // finding the pivot index
    int index = partition(arr, start, end);

    // apply quick sort again and again from start to index behind the pivot index
    quick_sort(arr, start, index-1);

    // apply quick sort again and again from index next to pivot index to end
    quick_sort(arr, index + 1, end);
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
   quick_sort(v, 0, v.size() - 1);

    // Display sorted vector
    cout << "Sorted vector: ";
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
