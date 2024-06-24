/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// longest sub string with no repeating characters

int longestUqSubstr(string s){
    unordered_map<char,int>mp;
    int res = 0;
    int l=0,r=0;
    while(r<s.length()){
        if(mp.count(s[r])){
            l = max(l, mp[s[r]]+1);
        }
        res = max(res, r-l+1);
        mp[s[r]] = r;
        r++;
    }
    return res;
}

// Max consecutive ones after flipping K bits 

int Maxconsqbits(string s, int k){
    int res = 0;
    int l=0, r=0;
    int z = 0;
    while(r<s.length()){
        if(s[r]=='0'){
            z++;
        }
        while(l<=r&&z>k){
            if(s[l]=='0'){
                z--;
            }
            l++;
        }
        res = max(res, r-l+1);
        r++;
    }
    return res;
}

// Fruits into basket

int MaxFruits(string s){
    unordered_map<char, int>mp;
    int r =0, l=0;
    int res = 0;
    while(r<s.length()){
        mp[s[r]]++;
        while(l<=r&&mp.size()>2){
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

// longest repeating characters replacement

int longestRepeatchr(string s, int k){
    unordered_map<char,int>mp;
    int r=0, l=0;
    int res =0;
    int maxfrq = 0;
    while(r<s.length()){
     mp[s[r]]++;
     maxfrq = max(maxfrq, mp[s[r]]);
     while(l<=r&&(r-l+1)-maxfrq>k){
         mp[s[l]]--;
         if(mp[s[l]]==0){
             mp.erase(s[l]);
         }
         maxfrq = 0;
         for(auto x:mp){
             maxfrq = max(maxfrq, x.second);
         }
         l++;
     }
     res = max(res, r-l+1);
     r++;
    }
    return res;
}

// Binary subarray with sum

int subarraySum(string str, int goal){
    if(goal<0){
        return 0;
    }
    int l=0, r=0;
    int s=0;
    int res = 0;
    while(r<str.length()){
        s+=(str[r]-'0');
        while(s>goal&&l<=r){
            s-=(str[l]-'0');
            l++;
        }
        res+=(r-l+1);
        r++;
    }
    return res;
}

int CountBinarySubarray(string str, int s){
    return subarraySum(str, s) - subarraySum(str, s-1);
}

// Count number of nice sub array

int NsubarraySum(string str, int goal){
    if(goal<0){
        return 0;
    }
    int l=0, r=0;
    int s=0;
    int res = 0;
    while(r<str.length()){
        s+=(str[r]-'0')%2;
        while(s>goal&&l<=r){
            s-=(str[l]-'0')%2;
            l++;
        }
        res+=(r-l+1);
        r++;
    }
    return res;
}

int countNiceSubarr(string str, int s){
    return NsubarraySum(str, s) - NsubarraySum(str, s-1);
}

// Number of Substring Containing All the three characters

int NumSubstrUq(string str){
    int r=0, l=0;
    vector<int>mp(3, -1);
    int res =0;
    while(r<str.length()){
        mp[str[r]-'a']=r;
        if(mp[0]!=-1&&mp[1]!=-1&&mp[2]!=-1){
            res += min(mp[0], min(mp[1], mp[2]))+1;
        }
        r++;
    }
    return res;
}

//Maximum point from K cards 

int MaxptCrds(string s, int k){
    int res = 0;
    if(k>=s.length()){
        for(auto x:s){
            res+=(x-'0');
        }
        return res;
    }
    int lsum = 0, rsum = 0;
    int rind = s.length()-1;
    for(int i=0;i<k;i++){
        lsum += (s[i]-'0');
    }
    res = max(lsum, res);
    for(int i=k-1;i>=0;i--){
        lsum -= (s[i]-'0');
        rsum += (s[rind]-'0');
        rind--;
        res = max(res, lsum+rsum);
    }
    return res;
}

int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;
    
    // cout<<"Result: "<<longestUqSubstr(s);
    
    // int k;
    // cout<<"Enter number of bits that can be flipped: ";
    // cin>>k;
    // cout<<"Result: "<<Maxconsqbits(s, k);
    
    // cout<<"Result: "<<MaxFruits(s);
    
    // int k;
    // cout<<"Enter number of characters that can be replaced: ";
    // cin>>k;
    // cout<<"Result: "<<longestRepeatchr(s, k);
    
    // int k;
    // cout<<"Enter target value: ";
    // cin>>k;
    // cout<<"Result: "<<CountBinarySubarray(s, k);
    
    // int k;
    // cout<<"Enter target value: ";
    // cin>>k;
    // cout<<"Result: "<<countNiceSubarr(s, k);
    
    // cout<<"Result: "<<NumSubstrUq(s);
    
    int k;
    cout<<"Enter number of cards required: ";
    cin>>k;
    cout<<"Result: "<<MaxptCrds(s, k);
}