/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// 2 Sum problem

vector<int> twosum(vector<int>arr ,int n, int k){
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
        if(mp.count(k-arr[i])){
            return {mp[arr[i]], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

// Dutch National Flag

void DNF(vector<int>&arr, int n){
    int l =0, m=0, h =n-1;
    while(m<=h){
        if(arr[m]==0){
            swap(arr[l], arr[m]);
            l++;
            m++;
        }else if(arr[m] == 1){
            m++;
        }else{
            swap(arr[m], arr[h]);
            h--;
        }
    }
}

// Moores Algorithm

int majority(vector<int>arr, int n){
    int ele;
    int c =0;
    for(int i=0;i<n;i++){
        if(c==0){
            ele = arr[i];
        }
        if(arr[i]==ele){
            c++;
        }else{
            c--;
        }
    }
    c =0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            c++;
        }
    }
    if(c<=n/2){
        return -1;
    }
    return ele;
}

// Kadanes Algorithm

vector<int> maximumSumSubarray(vector<int>arr, int n){
    int s =0;
    int res = INT_MIN;
    int l=0;
    int h=0;
    for(int i=0;i<n;i++){
        if(s<0){
            l = i;
            s = 0;
        }
        s+=arr[i];
        if(res<s){
            res = s;
            h = i;
        }
    }
    vector<int>ans(arr.begin()+l, arr.begin()+h+1);
    return ans;
}

// Stock buy and Sell

vector<int> BuyAndSell(vector<int>arr, int n){
    int minind = -1;
    int mini = INT_MAX;
    int maxind = -1;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<mini){
            minind = i;
            mini = arr[i];
        }
        if(i>minind&&arr[i]>maxi){
            maxi = arr[i];
            maxind = i;
        }
    }
    if(minind>maxind){
        return {-1, -1};
    }
    return {minind+1, maxind+1};
}

//Alternating positives and negatives with unequal number of positives and negatives

vector<int> rearrange(vector<int>arr, int a){
    vector<int> p;
    vector<int> n;
    vector<int>res;
    for(auto x:arr){
        if(x>0){
            p.push_back(x);
        }else{
            n.push_back(x);
        }
    }
    int num = min(p.size(), n.size());
    for(int i=0;i<num;i++){
        res.push_back(p[i]);
        res.push_back(n[i]);
    }
    if(num==n.size()){
        res.insert(res.end(), p.begin()+num, p.end());
    }else{
        res.insert(res.end(), n.begin()+num, n.end());
    }
    return res;
}

// Next permutation

void next_permutation(vector<int>&arr, int n){
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr.begin(), arr.end());
        return;
    }
    int i = n-1;
    while(i>ind&&arr[i]<arr[ind]){
        i--;
    }
    swap(arr[ind], arr[i]);
    reverse(arr.begin()+ind+1, arr.end());
}

// Longest consecutive sequence in an array

int longestConsecutiveSeq(vector<int>arr, int n){
    unordered_set<int>s;
    for(auto x:arr){
        s.insert(x);
    }
    int res = INT_MIN;
    for(auto x:s){
        if(s.find(x-1)==s.end()){
            int c = 1;
            int i = x+1;
            while(s.find(i)!=s.end()){
                c++;
                i++;
            }
            res=max(res, c);
        }
    }
    return res;
}

//Set matrix to zeroes

void setZeroes(vector<vector<int>>&arr, int n ,int m){
    int co = 1;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0] = 0;
                if(j!=0){
                    arr[0][j] = 0;
                }else{
                    co = 0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][0]==0||arr[0][j]==0){
                arr[i][j] = 0;
            }
        }
    }
    if(arr[0][0]==0){
        for(int i=0;i<m;i++){
            arr[0][i] = 0;
        }
    }
    if(co == 0){
        for(int i =0;i<n;i++){
            arr[i][0] = 0;
        }
    }
}

// Spiral manner

vector<int> spiralPrint(vector<vector<int>>arr, int n, int m){
    int t = 0, l =0, b = n-1, r = m-1;
    vector<int>res;
    while(t<=b&&l<=r){
        for(int i=l;i<=r;i++){
            res.push_back(arr[t][i]);
        }
        t++;
        for(int i=t;i<=b;i++){
            res.push_back(arr[i][r]);
        }
        r--;
        if(t<=b){
            for(int i=r;i>=l;i--){
                res.push_back(arr[b][i]);
            }
            b--;
        }
        if(l<=r){
            for(int i=b;i>=t;i--){
                res.push_back(arr[i][l]);
            }
            l++;
        }
    }
    return res;
}

//Count sub-arrays with given sum

int subarrayK(vector<int>arr, int n, int k){
    unordered_map<int,int>mp;
    int s =0;
    int c = 0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s==k){
            c++;
        }
        if(mp.count(s-k)){
            c+=mp[s-k];
        }
        mp[s]++;
    }
    return c;
}



int main()
{
    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // int k;
    // cout<<"Enter target sum"<<endl;
    // cin>>k;
    // vector<int>res=twosum(arr,n,k);
    // cout<<"Answer: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
        
    // DNF(arr, n);
    // cout<<"Answer: ";
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // int res = majority(arr, n);
    // cout<<"Answer: "<<res;
    // cout<<endl;
    
    // vector<int>res = maximumSumSubarray(arr,n);
    // cout<<"Answer: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // vector<int>res = BuyAndSell(arr, n);
    // cout<<"Answer: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // vector<int>res = rearrange(arr, n);
    // cout<<"Answer: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // next_permutation(arr, n);
    // cout<<"Answer: ";
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // int res = longestConsecutiveSeq(arr, n);
    // cout<<"Answer: "<<res<<endl;
    
    // int n,m;
    // cout<<"Enter number of rows: ";
    // cin>>n;
    // cout<<"Enter number of columns: ";
    // cin>>m;
    // cout<<"Enter elements of array: ";
    // vector<vector<int>>arr(n,vector<int>(m));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // setZeroes(arr, n, m);
    // cout<<"Result:"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // int n,m;
    // cout<<"Enter number of rows: ";
    // cin>>n;
    // cout<<"Enter number of columns: ";
    // cin>>m;
    // cout<<"Enter elements of array: ";
    // vector<vector<int>>arr(n,vector<int>(m));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // vector<int>res = spiralPrint(arr, n, m);
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // int k;
    // cout<<"Enter Requied Sum: ";
    // cin>>k;
    // int res = subarrayK(arr, n, k);
    // cout<<"Result: "<<res<<endl;
}