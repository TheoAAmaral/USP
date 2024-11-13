#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> v, int start, int end){
    
}


void mergesort(vector<int> v, int start, int end){
    if (end < start){
        int mid = end/2;
        mergesort(v, start, mid);
        mergesort(v, mid+1, end);
        merge(v, start, end)
    }
}



int main(){
    vector<int> v = {1, 10, 5, 6, 7, 4, 2};

    
}