#include<iostream>
using namespace std;

class Heap{
public:
    int *arr;
    int capacity;
    int index;

    Heap(int n){
        this->capacity = n;
        arr = new int[n];
        index = 0;
        // jab bhi insert krna hoga, tab index+1 krke insert krdena
    }

    void printHeap(){
        for(int i = 1; i<capacity;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // TC : O(logn)
    void insert(int val){
        // STEP 1: insert the element normally into the first empty position inside the array
        // STEP 2: then compare the element with the parent and put the element at the right place
        if(index == capacity - 1){
            cout << "overflow"<<endl;
            return;
        }
        // space is available
        // STEP 1: 
        index++;
        arr[index] = val;
        // now put value at right position-> by comparing with parent node
        int i = index; 
        // STEP 2: HEAPIFY
        while(i > 1){ //index ki jgh i pe kaam krenge ab
            int parentIndex = i/2;
            if(arr[parentIndex] < arr[i]){
                swap(arr[parentIndex],arr[i]);
                i = parentIndex;
            }
            else{ 
                //parent ki value already badi hai, no need to do anything
                break;
            }
        }
    }

    // TC : O(logn)
    void deleteFromHeap(){
        // replace
        swap(arr[1],arr[index]);
        // size decrease
        index--;
        // heapify
        heapify(arr,index,1);
    }

    void heapify(int *arr, int n, int currIndex){
         // n -> number of elements in heaps
        int i = currIndex;
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        int largestKaIndex = i; // assuming i par hi sbse badi value hai
        // but it is possible ki sabse badi value left ya right me ho
        // check for left,
        if(leftIndex < n && arr[leftIndex] > arr[largestKaIndex]){ //compare with largestKaIndex and not i, kyuki ho skta hai i 10 ho, left me 40 ho and right me 30, toh jab right me compare krenge toh 30 ajayega i me jabki 40 hona chahiye tha
            // left me badi value milgyi
            largestKaIndex = leftIndex;
        }
        // check for right,
        if(rightIndex < n && arr[rightIndex] > arr[largestKaIndex]){
            // right me badi value milgyi
            largestKaIndex = rightIndex;
        }
        // now we have sabse bade element ka index
        // largestValue is still i, no need to do anything
        // largestValue left ya right me se koi hai then swap
        if(largestKaIndex != i){
            // left ya right me se koi bada element milgya
            swap(arr[i],arr[largestKaIndex]);
            i = largestKaIndex; 
            // baaki recursion sambhal lega
            heapify(arr,n,i);
        }
    }
};

int main(){
    Heap pq(10);
    // 50 40 20 10 30
    pq.insert(10);
    pq.printHeap();
    pq.insert(20);
    pq.printHeap();
    pq.insert(30);
    pq.printHeap();
    pq.insert(40);
    pq.printHeap();
    pq.insert(50);
    pq.printHeap();

    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();

    return 0;
}