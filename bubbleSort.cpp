#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int size){
    for(int round=1;round<size;round++){
        for(int element=0;element<size-round;element++){
            if(arr[element] > arr[element+1]){
                swap(arr[element],arr[element+1]);
            }
        }
    }
    return;
}


int main(){
    vector<int> v = {10,7,1,6,9,14};
    for(const auto& element : v){
        cout << element << " ";
    }
    cout << endl;
    bubbleSort(v,v.size());
    for(auto& element : v){
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
