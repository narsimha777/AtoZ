/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// x to the Power n 

int Pow(int x, int n){
    if(n==0){
        return 1;
    }
    if(n%2){
        return x*Pow(x, n-1);
    }else{
        return Pow(x*x, n/2);
    }
}

// Reversing a stack

void InsertBottom(stack<int>&st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topEle = st.top();
    st.pop();
    InsertBottom(st, ele);
    st.push(topEle);
}

void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int topEle = st.top();
    st.pop();
    reverseStack(st);
    InsertBottom(st, topEle);
}

// Generate all binary strings

void solve(vector<string>&res, string curr, int n){
    if(n==0){
        res.push_back(curr);
        return;
    }
    solve(res, curr+"0", n-1);
    solve(res, curr+"1", n-1);
}

vector<string> generateAllBs(int n){
    vector<string>res;
    string curr= "";
    solve(res, curr, n);
    return res;
}

//Generate all possible paranthesis

void solve(vector<string>&res, string curr, int o, int c, int n){
    if(curr.length()==2*n){
        res.push_back(curr);
        return;
    }
    if(o<n){
        solve(res, curr+"(", o+1, c, n);
    }
    if(c<n&&o>c){
        solve(res, curr+")", o, c+1, n);
    }
}

vector<string> genParanthesis(int n){
    string curr="";
    vector<string>res;
    int o = 0, c = 0;
    solve(res, curr, o, c, n);
    return res;
}

// Generate all possible power sets

void solveGP(vector<vector<int>>&res, vector<int>curr, vector<int>arr, int i){
    if(i==arr.size()){
        res.push_back(curr);
        return;
    }
    curr.push_back(arr[i]);
    solveGP(res, curr, arr, i+1);
    curr.pop_back();
    solveGP(res, curr, arr, i+1);
}

vector<vector<int>> genPowerSet(vector<int>arr){
    vector<vector<int>>res;
    vector<int>curr;
    int i = 0;
    solveGP(res, curr, arr, i);
    return res;
}

// Count all sub-sequence with sum K

void solveSum(vector<vector<int>>&res, vector<int>curr, vector<int>arr, int s, int i){
    if(i==arr.size()){
        if(s==0){
            res.push_back(curr);
        }
        return;
    }
    curr.push_back(arr[i]);
    solveSum(res, curr, arr, s-arr[i], i+1);
    curr.pop_back();
    solveSum(res, curr, arr, s, i+1);
}

vector<vector<int>> perfectSum(vector<int>arr, int s){
    vector<vector<int>>res;
    vector<int>curr;
    int i = 0;
    solveSum(res, curr, arr, s, i);
    return res;
}

//Check sum

bool solveChkSum(vector<int>arr, int s, int i){
    if(i==arr.size()){
        if(s==0){
            return true;
        }
        return false;
    }
    
    if(solveChkSum(arr, s-arr[i], i+1)){
        return true;
    }
    if(solveChkSum(arr, s, i+1)){
        return true;
    }
    return false;
}

bool checkSum(vector<int>arr, int s){
    int i = 0;
    return solveChkSum(arr, s, i);
}

//Combination sum with atmost K digits

void solveCS3(vector<vector<int>>&res, vector<int>curr, vector<int>arr, int s, int k, int i){
    if(k==0){
        if(s==0){
            res.push_back(curr);
        }
        return;
    }
    if (i >= arr.size() || k < 0) {
        return;
    }
    curr.push_back(arr[i]);
    solveCS3(res, curr, arr, s-arr[i], k-1, i+1);
    curr.pop_back();
    solveCS3(res, curr, arr, s, k, i+1);
}

vector<vector<int>> combS3(vector<int>arr, int s, int k){
    vector<vector<int>>res;
    vector<int>curr;
    int i=0;
    solveCS3(res, curr, arr, s, k, i);
    return res;
}

//Letter Combinations

void solveLC(vector<string>&res, string curr, string digits, unordered_map<int,string>mp, int i){
    if(i==digits.length()){
        if(curr.length()==digits.length()){
            res.push_back(curr);
        }
        return;
    }
    for(auto x:mp[digits[i]-'0']){
        solveLC(res, curr+x, digits, mp, i+1);
    }
}

vector<string> letterCombination(string digits){
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string curr="";
        vector<string> res;
        int i=0;
        solveLC(res, curr, digits, mp, i);
        return res;
}

int main()
{
    // int n;
    // cout<<"Enter number of Elements: ";
    // cin>>n;
    
    // int x;
    // vector<int>arr(n);
    // cout<<"Enter Elements: ";
    // for(int i=0;i<n;i++){
    //     cin>>x;
    //     arr[i] = x;
    // }
    
    // int x;
    // cout<<"Enter Base: ";
    // cin>>x;
    
    // int res = Pow(x, n);
    // cout<<"Result: "<<res;
    
    // int x;
    // stack<int>s;
    // cout<<"Enter Elements: ";
    // for(int i=0;i<n;i++){
    //     cin>>x;
    //     s.push(x);
    // }
    // reverseStack(s);
    // cout<<"Result: ";
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    
    // vector<string>res = generateAllBs(n);
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // vector<string>res = genParanthesis(n);
    // for(auto x:res){
    //     cout<<x<<" || ";
    // }
    
    // vector<vector<int>>res = genPowerSet(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // int s;
    // cout<<"Enter required sum: ";
    // cin>>s;
    // vector<vector<int>>res = perfectSum(arr, s);
    // cout<<"Result: ";
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // int s;
    // cout<<"Enter required sum: ";
    // cin>>s;
    // bool ans = checkSum(arr, s);
    // cout<<"Result: "<<ans;
    
    // int s;
    // cout<<"Enter required sum: ";
    // cin>>s;
    // int k;
    // cout<<"Enter number of digits required: ";
    // cin>>k;
    // vector<vector<int>>res = combS3(arr, s, k);
    // cout<<"Result: ";
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<"Enter required digits: ";
    string dig;
    cin>>dig;
    vector<string> res = letterCombination(dig);
    cout<<"Result: ";
    for(auto x:res){
        cout<<x<<" ";
    }
}