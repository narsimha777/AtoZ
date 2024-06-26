/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    int capacity;
    int heap_size;
    vector<int> harr;

    MinHeap(int c) : capacity(c), heap_size(0), harr(vector<int>(c)) {}

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    void deleteKey(int i) {
        if (i >= heap_size) {
            return;
        }
        swap(harr[i], harr[heap_size - 1]);
        heap_size--; 
        Heapify(i);
    }

    void InsertKey(int key) {
        if (heap_size == capacity) {
            return;
        }
        harr[heap_size] = key;
        int i = heap_size;
        heap_size++;
        while (i > 0 && harr[parent(i)] > harr[i]) {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    int ExtractMin() {
        if (heap_size == 0) {
            return -1;
        }
        int ans = harr[0];
        swap(harr[0], harr[heap_size - 1]);
        heap_size--;
        Heapify(0);
        return ans;
    }

    int getMin() {
        if (heap_size == 0) {
            return -1;
        }
        return harr[0];
    }

    void Heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        if (l < heap_size && harr[l] < harr[smallest]) {
            smallest = l;
        }
        if (r < heap_size && harr[r] < harr[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            Heapify(smallest);
        }
    }
};

class MaxHeap{
    public:
        
        int capacity;
        int heap_size;
        vector<int>harr;
        
        MaxHeap(int c): capacity(c), heap_size(0), harr(vector<int>(c)) {}
        
        int left(int i){
            return 2*i+1;
        }
        
        int right(int i){
            return 2*i+2;
        }
        
        int parent(int i){
            return (i-1)/2;
        }
        
        int getMax(){
            if(heap_size==0){
                return -1;
            }
            return harr[0];
        }
        
        void InsertKey(int key){
            if(heap_size==capacity){
                return;
            }
            harr[heap_size] = key;
            int i= heap_size;
            heap_size++;
            while(i>0&&harr[i]>harr[parent(i)]){
                swap(harr[i], harr[parent(i)]);
                i = parent(i);
            }
        }
        
        int ExtractMax(){
            if(heap_size==0){
                return -1;
            }
            int ans = harr[0];
            swap(harr[heap_size-1], harr[0]);
            heap_size--;
            Heapify(0);
            return ans;
        }
        
        void Heapify(int i){
            int l = left(i);
            int r = right(i);
            int largest = i;
            if(l<heap_size&&harr[l]>harr[largest]){
                largest = l;
            }
            if(r<heap_size&&harr[r]>harr[largest]){
                largest = r;
            }
            if(i!=largest){
                swap(harr[i], harr[largest]);
                Heapify(largest);
            }
        }
};

int main()
{
//   MinHeap* mh = new MinHeap(10);
//   int n;
//   cout<<"Enter number of elements to enter: ";
//   cin>>n;
//   cout<<"Enter Elements: ";
//   for(int i=0;i<n;i++){
//       int x;
//       cin>>x;
//       mh->InsertKey(x);
//   }
  
//   int y;
//   cout<<"Do u want to perform functions: ";
//   cin>>y;
//   while(y){
//       int f;
//       cout<<"TO GET MIN(1), TO EXTRACT MIN(2), TO INSERT KEY(3): "<<endl;
//       cin>>f;
//       if(f==1){
//           cout<<"Result: "<<mh->getMin()<<endl;
//       }else if(f==2){
//           cout<<"Result: "<<mh->ExtractMin()<<endl;
//       }else if(f==3){
//           int x;
//           cout<<"Enter Key value to Enter: ";
//           cin>>x;
//           mh->InsertKey(x);
//       }
//       cout<<"Do u want to continue: "<<endl;
//       cin>>y;
//   }
  
    MaxHeap* mxh = new MaxHeap(10);
    int n;
    cout<<"Enter number of elements to enter: ";
    cin>>n;
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mxh->InsertKey(x);
    }
    
    int y;
    cout<<"Do u want to perform functions: ";
    cin>>y;
    while(y){
        int f;
        cout<<"TO GET MAX(1), TO EXTRACT MAX(2), TO INSERT KEY(3): "<<endl;
        cin>>f;
        if(f==1){
            cout<<"Result: "<<mxh->getMax()<<endl;
        }else if(f==2){
            cout<<"Result: "<<mxh->ExtractMax()<<endl;
        }else if(f==3){
            int x;
            cout<<"Enter Key value to Enter: ";
            cin>>x;
            mxh->InsertKey(x);
        }
        cout<<"Do u want to continue: "<<endl;
        cin>>y;
    }
}