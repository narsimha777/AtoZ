/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Find numbers that appear odd number of times

vector<int> findOtimNumber(vector<int> arr){
    int xr = 0;
    for(auto x:arr){
        xr^=x;
    }
    int bit = (xr&(xr-1))^xr;
    int o = 0;
    int z = 0;
    for(auto x:arr){
        if(bit&x){
            o^=x;
        }else{
            z^=x;  
        }
    }
    return { o, z };
}

// Power Set

vector<vector<int>> PowrSt(vector<int> arr){
    int n = arr.size();
    int s = 1<<n;
    vector<vector<int>>res;
    for(int i=0;i<s;i++){
        vector<int>curr;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                curr.push_back(arr[j]);
            }
        }
        res.push_back(curr);
    }
    return res;
}

//Find XOR of elements from L to R

int fun(int n){
    if(n%4==1){
        return 1;
    }else if(n%4==2){
        return n+1;
    }else if(n%4==3){
        return 0;
    }else{
        return n;
    }
}

int xorLtoR(int l, int r){
    return fun(l-1)^fun(r);
}

// Prime factors of a number

vector<int> primeFactrs(int n){
    vector<int> res;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n!=1){
        res.push_back(n);
    }
    return res;
}

// Sieve of Eratosthenes 

int SoErts(int n){
    vector<int> h(n+1, 1);
    int res = 0;
    h[0] = 0;
    h[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(h[i]==1){
            for(int j=i*i;j<=n;j+=i){
                h[j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        res+=h[i];
    }
    return res;
}

// Prime Factorisation Numbers using Sieve

vector<int> PFusSive(int n){
    vector<int> res;
    vector<int> h(n+1, 1);
    for(int i=2;i<n+1;i++){
        h[i]=i;
    }
    h[0] = 0;
    h[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(h[i]==i){
            for(int j=i*i;j<=n;j+=i){
                h[j] = i;
            }
        }
    }
    while(n!=1){
        res.push_back(h[n]);
        n/=h[n];
    }
    return res;
}

int main()
{
    // int n;
    // cout<<"Enter number of Elements: ";
    // cin>>n;
    // vector<int>arr(n);
    // cout<<"Enter elements in array: ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    
    // vector<int>res = findOtimNumber(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // vector<vector<int>> res = PowrSt(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // int l, r;
    // cout<<"Enter L value: ";
    // cin>>l;
    // cout<<"Enter R value: ";
    // cin>>r;
    // int res = xorLtoR(l, r);
    // cout<<"Result: "<<res;
    
    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // vector<int> res = primeFactrs(n);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // int n;
    // cout<<"Enter Number: ";
    // cin>>n;
    // int res = SoErts(n);
    // cout<<"Result: "<<res;
    
    int n;
    cout<<"Enter number: ";
    cin>>n;
    vector<int> res = PFusSive(n);
    cout<<"Result: ";
    for(auto x:res){
        cout<<x<<" ";
    }
}