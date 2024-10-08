#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr){
    int maxElement = arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i] > maxElement){
            maxElement = arr[i];
        }
    }

    vector<int> freqArr(maxElement+1,0);

    for(int populateCount=0;populateCount<arr.size();populateCount++){
        freqArr[arr[populateCount]]++;
    }

    int count = 0;
    for(int getCount=0;getCount<maxElement;getCount++){
        if(freqArr[getCount] > 0){
            arr[count] = getCount;
            freqArr[getCount]--;
            count++;
        }
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
    countSort(v);

    // Display sorted vector
    cout << "Sorted vector: ";
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}