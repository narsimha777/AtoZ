/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Kth largest element in an array (using priority queue)

int Kthlargest(vector<int>arr, int k){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(auto x:arr){
        pq.push(x);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

// Kth largest element in an array (using quick select)

int partition(vector<int>&arr, int l, int r){
    int i = l+1;
    int j = r;
    int pivot = arr[l];
    while(i<=j){
        while(pivot>arr[i]){
            i++;
        }
        while(pivot<arr[j]){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

// Kth smallest element ( using priority queue )

int Kthsmallest(vector<int>arr, int k){
    priority_queue<int>pq;
    for(auto x:arr){
        pq.push(x);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

// Kth smallest element ( using quick Select )

int KthsmallestP(vector<int>arr, int l, int r, int k){
    if(l>r){
        return -1;
    }
    int p = partition(arr, l ,r);
    if(p==k-1){
        return arr[p];
    }else if(p>k-1){
        return KthsmallestP(arr, l, p-1, k);
    }else{
        return KthsmallestP(arr, p+1, r, k);
    }
}

//Kth largest element ( using quick select )

int KthlargestP(vector<int>arr, int l, int r, int k){
    return KthsmallestP(arr, l, r, arr.size()-k+1);
}

// Sort k sorted array

vector<int> nearlySorted(vector<int>arr, int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>res;
    for(int i=0;i<=k;i++){
        pq.push(arr[i]);
    }
    for(int i=k+1;i<arr.size();i++){
        pq.push(arr[i]);
        res.push_back(pq.top());
        pq.pop();
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

//Merge M sorted vectors

vector<int> MergeMsorted(vector<vector<int>>v, int r, int c){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i=0;i<r;i++){
        pq.push({v[i][0], {i, 0}});
    }
    vector<int>res;
    while(!pq.empty()){
        res.push_back(pq.top().first);
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        if(col+1<c){
            pq.push({v[row][col+1], {row, col+1}});
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

// Replace each element with its rank

void replaceRANK(vector<int>&arr){
    vector<int>r(arr.begin(), arr.end());
    sort(r.begin(), r.end());
    unordered_map<int,int>mp;
    int rind = 0;
    for(int i=0;i<r.size();i++){
        if(!mp.count(r[i])){
            mp[r[i]] = rind;
            rind++;
        }
    }
    for(int i=0;i<arr.size();i++){
        arr[i] = mp[arr[i]];
    }
    return;
}

// Task scheduler

int NumofCycles(vector<int>tasks, int rt){
    unordered_map<int,int>mp;
    int maxfreq = 0;
    int nmxfrq = 0;
    for(auto x:tasks){
        mp[x]++;
        maxfreq= max(mp[x], maxfreq);
    }
    for(auto x:mp){
        if(x.second == maxfreq){
            nmxfrq++;
        }
    }
    int res = (maxfreq-1)*(rt+1)+nmxfrq;
    int s = tasks.size();
    return max(res, s);
}

// Hand of Straights

bool isNStraightHand(vector<int>arr, int grpSz){
    if(arr.size()%grpSz){
        return false;
    }
    map<int,int>mp;
    for(auto x:arr){
        mp[x]++;
    }
    while(!mp.empty()){
        int start = mp.begin()->first;
        for(int i=0;i<grpSz;i++){
            if(!mp.count(start+i)){
                return false;
            }
            mp[start+i]--;
            if(mp[start+i]==0){
                mp.erase(start+i);
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter number of array elements: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // int k;
    // cout<<"Enter Kth element required: ";
    // cin>>k;
    
    // cout<<"Result: "<<Kthlargest(arr, k);
    // cout<<"Result: "<<KthlargestP(arr, 0, n-1, k);
    
    // cout<<"Result: "<<Kthsmallest(arr, k);
    // cout<<"Result: "<<KthsmallestP(arr, 0, n-1, k);
    
    // cout<<"Result: ";
    // vector<int>res = nearlySorted(arr, k);
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // int r, c;
    // cout<<"Enter number of rows: ";
    // cin>>r;
    // cout<<"Enter number of columns: ";
    // cin>>c;
    
    // vector<vector<int>>arr(r,vector<int>(c));
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    
    // vector<int>res = MergeMsorted(arr, r, c);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // cout<<"Result: ";
    // replaceRANK(arr);
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    
    // int rt;
    // cout<<"Enter relaxation time: ";
    // cin>>rt;
    // cout<<"Result: "<<NumofCycles(arr, rt);
    
    int grpSz;
    cout<<"Enter group size: ";
    cin>>grpSz;
    cout<<"Result: "<<isNStraightHand(arr, grpSz);
}