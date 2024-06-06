/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Selection Sort

int select(int arr[], int n, int a){
    int res;
    int mini = INT_MAX;
    for(int i=a;i<n;i++){
        if(arr[i]<mini){
            mini = arr[i];
            res = i;
        }
    }
    return res;
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int ind = select(arr,n,i);
        swap(arr[ind], arr[i]);
    }
}

// Bubble Sort

void bubble(int arr[], int i, int n){
    if(i==n-1){
        return;
    }
    if(arr[i]>arr[i+1]){
        swap(arr[i], arr[i+1]);
    }
    bubble(arr, i+1, n);
}

void bubbleSort(int arr[], int n){
    if(n==0){
        return;
    }
    bubble(arr, 0, n-1);
    bubbleSort(arr, n-1);
}

//Insertion Sort

void insert(int arr[], int n){
    if(n==0){
        return;
    }
    if(arr[n]<arr[n-1]){
        swap(arr[n], arr[n-1]);
    }else{
        return;
    }
    insert(arr, n-1);
}

void insertionSort(int arr[], int n){
    if(n==0){
        return;
    }
    insertionSort(arr, n-1);
    insert(arr, n-1);
}

//Merge Sort

void merge(int arr[], int l, int m, int r){
    int a[m-l+1];
    int b[r-m];
    for(int i=l;i<=m;i++){
        a[i-l] = arr[i];
    }
    for(int i=m+1;i<=r;i++){
        b[i-m-1] = arr[i];
    }
    int u = 0, v = 0, k = l;
    while((u<m-l+1)&&(v<r-m)){
        if(a[u]<b[v]){
            arr[k] = a[u];
            u++;
        }else{
            arr[k] = b[v];
            v++;
        }
        k++;
    }
    while(u<m-l+1){
        arr[k] = a[u];
        u++;
        k++;
    }
    while(v<r-m){
        arr[k] = b[v];
        v++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h){
    if(l>=h){
        return;
    }
    int m =(l+h)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, h);
    merge(arr, l, m, h);
}

//Quick Sort

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i =l+1;
    int j= h;
    while(i<=j){
        while(i<=h&&arr[i]<pivot){
            i++;
        }
        while(j>=0&&arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

// Counting Sort

void countingSort(int arr[], int n){
    int res[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<10;i++){
        count[i] = count[i-1]+count[i];
    }
    for(int i=0;i<n;i++){
        int ind = count[arr[i]];
        res[ind-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = res[i];
    }
}

// Radix Sort

void countingSort(int arr[], int n, int e){
    int res[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        int d = (arr[i]/e)%10;
        count[d]++;
    }
    for(int i=1;i<10;i++){
        count[i] = count[i-1]+count[i];
    }
    for(int i=0;i<n;i++){
        int d = (arr[i]/e)%10;
        int ind = count[d];
        res[ind-1] = arr[i];
        count[d]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = res[i];
    }
}

void radixSort(int arr[], int n){
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        m = max(m, arr[i]);
    }
    for(int e=1;m/e>0;e*=10){
        countingSort(arr, n, e);
    }
}

// Bucket Sort

pair<int,int> getMinMax(int arr[], int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    return {mini, maxi};
}

void bucketSort(int arr[], int n){
    vector<vector<int>>buckets(n);
    vector<int>res;
    pair<int,int> p = getMinMax(arr, n);
    int mini = p.first;
    int maxi = p.second;
    int bs = (maxi-mini+1)/n+1;
    for(int i =0;i<n;i++){
        int ind = (arr[i] - mini)/bs;
        buckets[ind].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(!buckets[i].empty()){
            sort(buckets[i].begin(), buckets[i].end());
            res.insert(res.end(), buckets[i].begin(), buckets[i].end());
        }
    }
    for(int i=0;i<n;i++){
        arr[i] = res[i];
    }
}

// Shell Sort

void shellSort(int arr[], int n){
    for(int gap = n/2; gap>0;gap/=2){
        //insertion sort with gap size
        for(int it = gap;it<n;it++){
            int ele = arr[it];
            int j;
            for(j=it;j>=gap&&arr[j-gap]>ele;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j] = ele;
        }
    }
}

int main()
{
    int n = 6;
    int a[n]={9,1,8,3,7,2};
    selectionSort(a, n);
    cout<<"Selection Sort: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b[n]={9,1,8,3,7,2};
    bubbleSort(b, n);
    cout<<"Bubble Sort: ";
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int c[n]={9,1,8,3,7,2};
    insertionSort(c, n);
    cout<<"Insertion Sort: ";
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    int d[n]={9,1,8,3,7,2};
    mergeSort(d, 0, n-1);
    cout<<"Merge Sort: ";
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    int e[n]={9,1,8,3,7,2};
    quickSort(e, 0, n-1);
    cout<<"Quick Sort: ";
    for(int i=0;i<n;i++){
        cout<<e[i]<<" ";
    }
    cout<<endl;
    int f[n]={9,1,8,3,7,2};
    countingSort(f, n);
    cout<<"Counting Sort: ";
    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;
    int g[n]={9,1,8,3,7,2};
    radixSort(g, n);
    cout<<"Radix Sort: ";
    for(int i=0;i<n;i++){
        cout<<g[i]<<" ";
    }
    cout<<endl;
    int k[n]={9,1,8,3,7,2};
    bucketSort(k, n);
    cout<<"Bucket Sort: ";
    for(int i=0;i<n;i++){
        cout<<k[i]<<" ";
    }
    cout<<endl;
    int l[n]={9,1,8,3,7,2};
    shellSort(l, n);
    cout<<"Shell Sort: ";
    for(int i=0;i<n;i++){
        cout<<l[i]<<" ";
    }
    cout<<endl;
}
