/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 
// checksorted 
bool checkrotSorted(int arr[], int N){
    int c = 0;
    for(int i=0;i<N;i++){
        if(arr[i]>arr[(i+1)%N]){
            c++;
        }
    }
    return c == 1;
}

// remove Duplicates
void removeDup(vector<int>&arr,int N){
    int i = 0;
    int j = 0;
    while(i<N){
        while(arr[i]==arr[j]){
            i++;
        }
        j+=1;
        arr[j] = arr[i];
    }
    arr.erase(arr.begin()+j,arr.end());
}

//left and right rotate

void leftandright(vector<int>&arr, int n, int k, int a){
    k= k%n;
    if(a){
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        reverse(arr.begin(), arr.end());
    }else if(!a){
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }
}

//move zeros to end

void moveZeroes(vector<int>&arr, int n){
    int j=0;
    while(arr[j]){
        j++;
    }
    int i=j+1;
    while(i<n){
        while(arr[i]==0){
            i++;
        }
        if(i<n){
            swap(arr[i], arr[j]);
        }
        j+=1;
    }
}

// longest subarray with given sum K (+ve)

int longestSubarray(vector<int>&arr, int n, int k){
    int l =0;
    int r = 0;
    int s = 0;
    int res = 0;
    while(r<n){
        s+=arr[r];
        while(s>k){
            s-=arr[l];
            l++;
        }
        res = max(res, r-l+1);
        r++;
    }
    return res;
}

//longest Subarray with sum K (-ve & +ve)

int longestBSubarray(vector<int>&arr, int n, int k){
    unordered_map<int,int>mp;
    int s =0;
    int res = 0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s==k){
            res = max(res, i+1);
        }
        if(mp.count(s-k)){
            int len = i - mp[s-k];
            res = max(res, len);
        }
        if(mp.count(s)){
            continue;
        }
        mp[s] = i;
    }
    return res;
}

int main(){
    int n;
    cout<<"Number of Elements"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter numbers: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // bool res = checkrotSorted(arr, n);
    // cout << (res ? "True" : "False") << endl;
    
    // removeDup(arr, n);
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    
    // int dir;
    // cout<<"Enter left(1) or right(0): "<<endl;
    // cin>>dir;
    // int k;
    // cout<<"Enter amount of rotation K"<<endl;
    // cin>>k;
    // leftandright(arr, n, k, dir);
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    
    // moveZeroes(arr, n);
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    
    // int k;
    // cout<<"Enter required sum"<<endl;
    // cin>>k;
    // int res = longestSubarray(arr, n, k);
    // cout<<"Answer: "<<res;
    
    int k;
    cout<<"Enter required sum"<<endl;
    cin>>k;
    int res = longestBSubarray(arr, n, k);
    cout<<"Answer: "<<res;
}