/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Stack using Linked List

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int a){
        data = a;
        next = nullptr;
    }
};

StackNode* top;

void push(int a){
    if(!top){
        top = new StackNode(a); 
    }
    else{
        StackNode* temp = new StackNode(a);
        temp->next = top;
        top = temp;
    }
}

int pop(){
    if(!top){
        return -1;
    }else{
        int ans = top->data;
        StackNode* temp = top;
        top = top->next;
        delete(temp);
        return ans;
    }
}

// Check for balanced paranthesis

bool checkBalancedParan(string s){
    if(s==""||s.length()==0){
        return true;
    }
    stack<int>st;
    for(auto x:s){
        if(x=='('){
            st.push(x);
        }else{
            st.pop();
        }
    }
    return st.empty();
}

// Implement Min stack

stack<int>s;
int mini = INT_MAX;

int MinStack(int n){
    if(s.empty()){
        s.push(n);
        mini = n;
    }else if(n<=mini){
        s.push(2*n-mini);
        mini = n;
    }else{
        s.push(n);
    }
    return mini;
}

// Infix to postfix

int precedence(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*'||c=='/'){
        return 2;
    }else if(c=='-'||c=='+'){
        return 1;
    }
    return -1;
}

string InfixtoPostfix(string str){
    stack<char>s;
    string res="";
    for(auto x:str){
        if(isalnum(x)){
            res+=x;
        }else if(x=='('){
            s.push(x);
        }else if(x==')'){
            while(!s.empty()&&s.top()!='('){
                res+=s.top();
                s.pop();
            }
            if(!s.empty()&&s.top()=='('){
                s.pop();
            }
        }else{
            while(!s.empty()&&precedence(s.top())>=precedence(x)){
                res+=s.top();
                s.pop();
            }
            s.push(x);
        }
    }
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    return res;
}

//Prefix to Infix

string prefixToinfix(string str){
    stack<string>s;
    for(int i = str.length()-1;i>=0;i--){
        if(isalnum(str[i])){
            string temp = "";
            temp += str[i];
            s.push(temp);
        }else{
            string l = s.top();
            s.pop();
            string r = s.top();
            s.pop();
            s.push('('+l+str[i]+r+')');
        }
    }
    return s.top();
}

//Prefix to Postfix

string preToPost(string str){
    stack<string> s;
    for(int i=str.length()-1;i>=0;i--){
        if(isalnum(str[i])){
            string temp = "";
            temp+=str[i];
            s.push(temp);
        }else{
            string l = s.top();
            s.pop();
            string r = s.top();
            s.pop();
            s.push(l+r+str[i]);
        }
    }
    return s.top();
}

// Postfix to Infix

string PosttoInfix(string str){
    stack<string> s;
    for(auto x:str){
        if(isalnum(x)){
            string temp = "";
            temp +=x;
            s.push(temp);
        }else{
            string r = s.top();
            s.pop();
            string l = s.top();
            s.pop();
            s.push('('+l+x+r+')');
        }
    }
    return s.top();
}

//Postfix to Prefix

string PostoPre(string str){
    stack<string>s;
    for(auto x:str){
        if(isalnum(x)){
            string temp = "";
            temp+=x;
            s.push(temp);
        }else{
            string r = s.top();
            s.pop();
            string l = s.top();
            s.pop();
            s.push(x+l+r);
        }
    }
    return s.top();
}

int main(){
    // int n;
    // cout<<"Enter number of functions: ";
    // cin>>n;
    // vector<int> arr(n);
    // cout<<"Data must not be 2 or 1 as they are reserved for functions=> "<<endl;
    // cout<<"Enter functions: ";
    // int x;
    // for(int i=0;i<n;i++){
    //     cin>>x;
    //     arr[i]=x;
    //     if(x==1){
    //         i+=1;
    //         cin>>x;
    //         arr[i]=x;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     if(arr[i]==1){
    //         push(arr[i+1]);
    //     }else if(arr[i]==2){
    //         pop();
    //     }
    // }
    // cout<<"Result: ";
    // while(top){
    //     cout<<top->data<<" ";
    //     top=top->next;
    // }
    
    // string s;
    // cout<<"Enter String: ";
    // cin>>s;
    
    // cout<<"Result: "<<checkBalancedParan(s); 
    
    // int n;
    // cout<<"Enter number of Elements in Min Stack: ";
    // cin>>n;
    // cout<<"Enter Elements in Min Stack: ";
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     cout<<MinStack(x)<<" "<<endl;
    // }
    
    // example string: a+b*(c^d-e)^(f+g*h)-i
    // string s;
    // cout<<"Enter Infix String: ";
    // cin>>s;
    // cout<<"Postfix: "<<InfixtoPostfix(s);
    
    // example string: *-A/BC-/AKL
    // string s;
    // cout<<"Enter Prefix String: ";
    // cin>>s;
    // cout<<"Infix: "<<prefixToinfix(s);
    
    // example string: *-A/BC-/AKL
    // string s;
    // cout<<"Enter Prefix string: ";
    // cin>>s;
    // cout<<"Result: "<<preToPost(s);
    
    // example string: ab*c+ 
    // string s;
    // cout<<"Enter Postfix string: ";
    // cin>>s;
    // cout<<"Infix: "<<PosttoInfix(s);
    
    // example string: ABC/-AK/L-*
    string s;
    cout<<"Enter Postfix string: ";
    cin>>s;
    cout<<"Prefix: "<<PostoPre(s);
}