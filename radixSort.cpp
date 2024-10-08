#include <iostream>
#include <vector>
using namespace std;


void radixSort(vector<int>& arr, int position){
    vector<int> temp1(10,0);
    int size = arr.size();
    vector<int> temp2(size);
    
    for (int i = 0; i < size; ++i){
        temp1[(arr[i] / position) % 10] += 1;
    }
    for (int j = 1; j < 10; j++){
        temp1[j] += temp1[j - 1];
    }
    for (int k = size - 1; k >= 0; --k){
        temp2[--temp1[(arr[k] / position) % 10]] = arr[k];
    }
    for (int l = 0; l < size; l++){
        arr[l] = temp2[l];
    }
}

void radix_sort(vector<int>& arr){
    int maxElement = arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i] > maxElement){
            maxElement = arr[i];
        }
    }

    for(int i=1;maxElement/i>0;i*=10){
        radixSort(arr,i);
    }
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
    radix_sort(v);

    // Display sorted vector
    cout << "Sorted vector: ";
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}