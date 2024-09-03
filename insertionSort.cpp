#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int size){
    for(int round=1;round<size;round++){
        int temp = arr[round];
        int element=round-1;
        for(;element>=0;element--){
            if(arr[element] > temp){
                // shift
                arr[element+1] = arr[element];
            } else {
                // break the comparison
                break;
            }
        }
        arr[element+1] = temp;
    }
}

int main(){
    vector<int> v = {10,7,1,6,9,14};
    for(const auto& element : v){
        cout << element << " ";
    }
    cout << endl;
    insertionSort(v,v.size());
    for(auto& element : v){
        cout << element << " ";
    }
    cout << endl;
    return 0;
}