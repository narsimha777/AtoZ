/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Next Greater element in circular arrays

vector<int> nextGreater(vector<int>arr, int n){
    stack<int>s;
    vector<int>res(n, -1);
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty()&&s.top()<=arr[(i%n)]){
            s.pop();
        }
        if(i<n){
            if(!s.empty()){
                res[i] = s.top();
            }
        }
        s.push(arr[(i%n)]);
    }
    return res;
}

// Trapping Rain water

int maxWater(vector<int>heights){
    int n = heights.size();
    int res = 0;
    int l[n], r[n];
    l[0] = heights[0];
    r[n-1] = heights[n-1];
    for(int i=1;i<n;i++){
        if(l[i-1]<heights[i]){
            l[i] = heights[i];
        }else{
            l[i] = l[i-1];
        }
        if(r[n-i]<heights[n-i-1]){
            r[n-i-1] = heights[n-i-1];
        }else{
            r[n-i-1] = r[n-i]; 
        }
    }
    for(int i=0;i<n;i++){
        res += min(l[i], r[i]) - heights[i];
    }
    return res;
}

// Asteroid collision

bool oppsign(int a, int b) {
    return (a > 0 && b < 0) || (a < 0 && b > 0);
}

vector<int> asteroidCollisions(vector<int>arr){
    stack<int>s;
    vector<int>res;
    for(auto x:arr){
        if(s.empty()){
            s.push(x);
        }else if(s.top()<0){
            s.push(x);
        }else if(x<0){
            while(!s.empty()&&oppsign(x,s.top())&&abs(s.top())<=abs(x)){
                if(abs(x)==abs(s.top())){
                    x==0;
                }
                s.pop();
            }
            if((s.empty()||s.top()<0)&&x){
                s.push(x);
            }
        }else{
            s.push(x);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// Remove K digits

string removeKdigits(string num, int k){
    stack<int>s;
    string res= "";
    for(auto x:num){
        int d = x-'0';
        while(!s.empty()&&k&&s.top()>d){
            s.pop();
            k--;
        }
        if(s.empty()&&d==0){
            continue;
        }
        s.push(d);
    }
    while(!s.empty()&&k){
        s.pop();
        k--;
    }
    if(s.empty()){
        return "0";
    }
    while(!s.empty()){
        res+=to_string(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// Largest Rectangle in histogram

vector<int> prevSmaller(vector<int>heights){
    int n = heights.size();
    vector<int>res(n, -1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty()&&heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(!s.empty()){
            res[i] = s.top();
        }
        s.push(i);
    }
    return res;
}

vector<int> nextSmaller(vector<int>heights){
    int n = heights.size();
    vector<int>res(n, n);
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(!s.empty()){
            res[i] = s.top();
        }
        s.push(i);
    }
    return res;
}

int largestRectangleArea(vector<int>heights){
    vector<int> l = prevSmaller(heights);
    vector<int> r = nextSmaller(heights);
    int res = INT_MIN;
    for(int i = 0;i<heights.size();i++){
        res = max(res, (r[i]-l[i]-1)*heights[i]);
    }
    return res;
}

// Sliding Window Maximum

vector<int> maxSlidingWindow(vector<int>nums, int k){
    vector<int> res;
    deque<int>dq;
    for(int i=0;i<nums.size();i++){
        while(!dq.empty()&&dq.front()<i-k+1){
            dq.pop_front();
        }
        while(!dq.empty()&&nums[dq.back()]<nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i-k+1>=0){
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

// LRU Cache

class LRUCache{
    public: 
    
        class node{
          public:
            int key;
            int data;
            node* next = nullptr;
            node* prev = nullptr;
            node(int k, int d){
                key = k;
                data = d;
            }
        };
        
        unordered_map<int, node*>mp;
        int capacity;
        node* head= new node(-1, -1);
        node* tail= new node(-1, -1);
        
        LRUCache(int c){
            capacity = c;
            head->next = tail;
            tail->prev = head;
        }
        
        void addnode(node* newnode){
            node* temp = head->next;
            head->next = newnode;
            newnode->next = temp;
            newnode->prev = head;
            temp->prev= newnode;
        }
        
        void deletenode(node* delnode){
            node* p = delnode->prev;
            node* n = delnode->next;
            p->next = n;
            n->prev = p;
        }
        
        int get(int key){
            if(mp.count(key)){
                node* temp = mp[key];
                int res = temp->data;
                deletenode(temp);
                addnode(temp);
                return res;
            }else{
                return -1;
            }
        }
        
        void put(int key, int value){
            if(mp.count(key)){
                node* temp = mp[key];
                deletenode(temp);
                mp.erase(key);
            }else if(mp.size()==capacity){
                node* lrnode = tail->prev;
                deletenode(lrnode);
                mp.erase(lrnode->key);
            }
            node* newnode = new node(key, value);
            addnode(newnode);
            mp[key] = newnode;
        }
};

int main()
{
    // int n;
    // cout<<"Enter number of Elements: ";
    // cin>>n;
    // vector<int>arr(n);
    // cout<<"Enter elements: ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    
    // vector<int>res = nextGreater(arr, n);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // int maxW = maxWater(arr);
    // cout<<"Water stored: "<<maxW;
    
    // vector<int>res = asteroidCollisions(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // string s;
    // cout<<"Enter number string: ";
    // cin>>s;
    // int k;
    // cout<<"Enter number of digits to remove: ";
    // cin>>k;
    // cout<<"Result: "<<removeKdigits(s, k);
    
    // int res = largestRectangleArea(arr);
    // cout<<"Result: "<<res;
    
    // int k;
    // cout<<"Enter sliding window size: ";
    // cin>>k;
    // vector<int>res = maxSlidingWindow(arr, k);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    int c;
    cout<<"Enter  capacity of LRUCache: ";
    cin>>c;
    LRUCache* lr = new LRUCache(c);
    int n;
    cout<<"Enter number of elements to put in lru: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cout<<"Enter key : ";
        cin>>k;
        int v;
        cout<<"Enter key value: ";
        cin>>v;
        lr->put(k,v);
    }
    bool y;
    cout<<"Do u want to get elements: ";
    cin>>y;
    while(y){
        int num;
        cout<<"Enter key value to get: ";
        cin>>num;
        int res = lr->get(num);
        cout<<"Result: "<<res<<endl;
        cout<<"Do u want to get elements: ";
        cin>>y;
    }
}