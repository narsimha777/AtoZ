/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Assign Cookies

int findContentChildren(vector<int>& g, vector<int>& s){
    int gind = 0;
    int sind = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while(gind<g.size()&&sind<s.size()){
        while(sind<s.size()&&s[sind]<g[gind]){
            sind++;
        }
        if(sind==s.size()){
            break;
        }
        gind++;
        sind++;
    }
    return gind;
}

// Fractional Knap Sack

struct Items{
    int weight;
    int value;
};

bool mycmp(Items a, Items b){
    return (double)(a.value)/(a.weight)>(double)(b.value)/(b.weight);
}

double FractionalKnapSack(Items arr[], int W, int n){
    double res = 0;
    sort(arr, arr+n, mycmp);
    int i=0;
    while(W&&i<n){
        if(W>=arr[i].weight){
            W-=arr[i].weight;
            res+=arr[i].value;
        }else{
            double fract = (double)W/arr[i].weight;
            W=0;
            res += fract*(arr[i].value);
        }
        i++;
    }
    return res;
}

// Lemonade change

bool lemonadeChange(vector<int>&bills){
    if(bills[0]!=5){
        return false;
    }
    int fives = 1;
    int tens = 0;
    int twenty = 0;
    for(int i=1;i<bills.size();i++){
        if(bills[i]==5){
            fives++;
        }else if(bills[i]==10){
            if(fives==0){
                return false;
            }
            tens++;
            fives--;
        }else if(bills[i]==20){
            if(tens == 0){
                if(fives<3){
                    return false;
                }
                fives -=3;
            }else{
                if(fives == 0){
                    return false;
                }
                fives--;
                tens--;
            }
            twenty++;
        }
    }
    return true;
}

// Valid parenthesis checker

bool checkValidString(string s){
    int mini =0;
    int maxi =0;
    for(auto x:s){
        if(x=='('){
            mini++;
            maxi++;
        }else if(x==')'){
            mini--;
            maxi--;
        }else{
            maxi++;
            mini--;
        }
        if(mini<0){
            mini =0;
        }
        if(maxi<0){
            return false;
        }
    }
    return mini==0;
}

int main()
{
    // int g, s;
    // cout<<"Enter number of students: ";
    // cin>>g;
    // cout<<"Enter number of cookies: ";
    // cin>>s;
    // vector<int>grd(g);
    // vector<int>sizck;
    // cout<<"Enter greed factor of each student: ";
    // for(int i=0;i<g;i++){
    //     cin>>grd[i];
    // }
    // cout<<"Enter cookies size: ";
    // for(int i=0;i<s;i++){
    //     cin>>sizck[i];
    // }
    // cout<<"Result: "<<findContentChildren(grd, sizck);
    
    // int n;
    // cout<<"Enter number of items required: ";
    // cin>>n;
    // Items arr[n];
    // cout<<"Enter items weight and value: "<<endl;
    // for(int i=0;i<n;i++){
    //     int v, w;
    //     cout<<"Enter value: ";
    //     cin>>v;
    //     arr[i].value = v;
    //     cout<<"Enter weight: ";
    //     cin>>w;
    //     arr[i].weight = w;
    // }
    // int W;
    // cout<<"Enter required weight: ";
    // cin>>W;
    // cout<<"Result: "<<FractionalKnapSack(arr, W, n);
    
    // int n;
    // cout<<"Enter number of customers: ";
    // cin>>n;
    // vector<int>bills(n);
    // cout<<"Enter bills given by customers: "<<endl;
    // for(int i=0;i<n;i++){
    //     cin>>bills[i];
    // }
    // cout<<"Result: "<<lemonadeChange(bills);
    
    // string s;
    // cout<<"Enter string: ";
    // cin>>s;
    // cout<<"Result: "<<checkValidString(s);
}