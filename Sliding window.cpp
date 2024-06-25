/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// longest substring with atmost k unique characters in it

int lsubstringwithKunq(string s, int k){
    unordered_map<char,int>mp;
    int res =0;
    int r=0, l=0;
    while(r<s.length()){
        mp[s[r]]++;
        while(l<=r&&mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        res = max(res, r-l+1);
        r++;
    }
    return res;
}

// minimum window substring that contains all chracters of t

string minWinstring(string s, string t){
    if(t.length()>s.length()){
        return "";
    }
    int l =0, r=0;
    int res = 0;
    int cnt =0;
    int sind =-1;
    int minlen = INT_MAX;
    unordered_map<int,int>mp;
    for(auto x:t){
        mp[x]++;
    }
    while(r<s.length()){
        if(mp[s[r]]>0){
            cnt++;
        }
        mp[s[r]]--;
        while(cnt==t.length()){
            if(minlen>(r-l+1)){
                minlen = (r-l+1);
                sind =l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0){
                cnt--;
            }
            l++;
        }
        r++;
    }
    return sind==-1?"":s.substr(sind, minlen);
}

int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;
    
    // int k;
    // cout<<"Enter number of unique characters required in the sub string: ";
    // cin>>k;
    // cout<<"Result: "<<lsubstringwithKunq(s, k);
    
    string t;
    cout<<"Enter string t: ";
    cin>>t;
    cout<<"Result: "<<minWinstring(s, t);
}