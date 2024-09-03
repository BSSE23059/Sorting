#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int size){
    for(int round=0;round<size-1;round++){
        int minIndex = round;
        for(int j=round+1;j<size;j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex],arr[round]);
    }
}

int main(){
    vector<int> v = {10,7,1,6,9,14};
    for(const auto& element : v){
        cout << element << " ";
    }
    cout << endl;
    selectionSort(v,v.size());
    for(auto& element : v){
        cout << element << " ";
    }
    cout << endl;
    return 0;
}