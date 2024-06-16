/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h> 
using namespace std;

// Print binary format

string convertIntoBinary(int n){
    string res = "";
    if(n==0){
        return "0"; 
    }
    while(n!=1){
        if(n%2){
            res+="1";
        }else{
            res+="0";
        }
        n/=2;
    }
    res+="1";
    reverse(res.begin(), res.end());
    return res;
}

//check ith bit is set or not

bool checkith(int n, int i){
    return n&(1<<i);
}

//check if number is odd or even

string checkOddEve(int n){
    return n&1?"Odd":"Even";
}

//Check if number is power of 2 or not

string checkPow2(int n){
    return n&(n-1)?"No":"Yes";
}

// Unset the rightmost setbit

int UnsetRBit(int n){
    n= n&(n-1);
    return n;
}

// Swap two numbers

void swap(int &a, int &b){
    a = a^b;
    b = b^a;
    a = a^b;
    return;
}

// Divide two integers

int divide(int dividend, int divisor){
    bool sign = false;
    if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)){
        sign = true;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    int ans = 0;
    while(dividend>=divisor){
        int cnt = 0;
        while(dividend>=divisor<<(cnt+1)){
            cnt++;
        }
        dividend-=divisor<<(cnt);
        ans +=1<<(cnt);
    }
    return ans;
}

int main()
{
//   int n;
//   cout<<"Enter number to be checked: ";
//   cin>>n;
  
// cout<<"Result: "<<convertIntoBinary(n);

//   int i;
//   cout<<"Enter ith position to be checked: ";
//   cin>>i;
//   cout<<"Result: ";
//   cout<<checkith(n ,i);

//  cout<<"Result: "<<checkOddEve(n);

//  cout<<"Power of Two: "<<checkPow2(n);

//   int r = UnsetRBit(n);
//   cout<<"Before Unset: "<<convertIntoBinary(n)<<endl;
//   cout<<"After Unset: "<<convertIntoBinary(r)<<endl;

    // int a;
    // int b;
    // cout<<"Enter number A: ";
    // cin>>a;
    // cout<<"Enter number B: ";
    // cin>>b;
    // swap(a, b);
    // cout<<"A and B: "<<a<<" and "<<b;
    
    int dividend;
    int divisor;
    cout<<"Enter dividend: ";
    cin>>dividend;
    cout<<"Enter divisor: ";
    cin>>divisor;
    int res = divide(dividend, divisor);
    cout<<"Result: "<<res;
}