/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Palindrome partitioning

bool isPalin(string s){
    string temp = s;
    reverse(s.begin(), s.end());
    return s==temp;
}

void solvePalin(vector<vector<string>>&res, vector<string> curr, string s){
    if(!s.length()||s==""){
        res.push_back(curr);
        return;
    }
    for(int i=1;i<=s.length();i++){
        if(isPalin(s.substr(0, i))){
            curr.push_back(s.substr(0, i));
            solvePalin(res, curr, s.substr(i, s.length()));
            curr.pop_back();
        }
    }
}

vector<vector<string>> palinPartition(string s){
    vector<string>curr;
    vector<vector<string>>res;
    solvePalin(res, curr, s);
    return res;
}

//N- Queen's problem

bool isSafe(vector<string>&res, int rowInd, int colInd, int n){
    for(int i=0;i<rowInd;i++){
        if(res[i][colInd]=='Q'){
            return false;
        }
    }
    int i=rowInd;
    int j=colInd;
    while(i>=0&&j>=0){
        if(res[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=rowInd;
    j=colInd;
    while(i>=0&&j<n){
        if(res[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void solve(vector<vector<string>>&res, vector<string>board, int n, int rowInd){
    if(rowInd==n){
        res.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board, rowInd, i, n)){
            board[rowInd][i] = 'Q';
            solve(res, board, n, rowInd+1);
            board[rowInd][i] = '.';
        }
    }
    return;
}   

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    string s = "";
    for(int i=0;i<n;i++){
        s+='.';
    }
    vector<string> board(n, s);
    int rowInd = 0;
    solve(res, board, n, rowInd);
    return res;
}

// Word break

bool isContain(string s, vector<string>dict){
    for(auto x:dict){
        if(x==s){
            return true;
        }
    }
    return false;
}

void solveWB(string s, vector<string>& dict, bool &ans){
    if(s.length()==0||s==""){
        ans = true;
        return;
    }
    for(int i=1;i<=s.length();i++){
        if(isContain(s.substr(0, i), dict)){
            solveWB(s.substr(i, s.length()), dict, ans);
            if(ans){
                return;
            }
        }
    }
}

bool wordBreak(string s, vector<string>& dict){
    bool ans = false;
    solveWB(s, dict, ans);
    return ans;
}



int main()
{
    
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    // string s;
    // cout<<"Enter string to be partitioned: ";
    // cin>>s;
    // vector<vector<string>> res = palinPartition(s);
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // vector<vector<string>> res = solveNQueens(n);
    // for(auto x:res){
    //     for(auto y:x){
    //       cout<<y<<endl;
    //     }
    //     cout<<endl;
    // }
    
    // vector<string>dict(n);
    // string s;
    // cout<<"Enter dictionary elements: ";
    // for(int i=0;i<n;i++){
    //     cin>>s;
    //     dict[i] = s;
    // }
    // string s1;
    // cout<<"Enter word: ";
    // cin>>s1;
    // bool res = wordBreak(s1, dict);
    // cout<<"Result: "<<res;
}