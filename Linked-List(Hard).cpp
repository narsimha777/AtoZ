/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct NodeD
{
  int data;
  struct NodeD *next;
  struct NodeD *prev;
  NodeD(int x) { data = x; next = prev = NULL; }
};

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

//Delete keys with given value

void deleteAll(NodeD* head, int x){
    NodeD* p = nullptr;
    NodeD* curr = head;
    while(curr){
        if(curr->data==x){
            NodeD* temp = curr;
            if(curr->next){
                curr->next->prev = p;
            }
            if(p){
                p->next = curr->next;
            }else{
                head = curr->next;
            }
            curr=curr->next;
            delete(temp);
        }else{
            p = curr;
            curr=curr->next;
        }
    }
}

//find pairs with given sum in sorted linked list

vector<pair<int,int>> findPairs(NodeD* head, int target){
    NodeD* tail = head;
    NodeD* curr = head;
    vector<pair<int,int>> res;
    while(tail->next){
        tail = tail->next;
    }
    while(curr->data<tail->data){
        int s = curr->data+tail->data;
        if(s>target){
            tail = tail->prev;
        }else if(s<target){
            curr = curr->next; 
        }else{
            res.push_back({curr->data, tail->data});
            curr=curr->next;
            tail=tail->prev;
        }
    }
    return res;
}

//Remove duplicates from sorted linked list

void removeDuplicates(NodeD* head){
    if(!head||!head->next){
        return;
    }
    NodeD* curr = head->next;
    NodeD* l = head;
    while(curr){
        if(curr->data==l->data){
            NodeD* temp = curr;
            curr =curr->next;
            delete(temp);
        }else{
            curr->prev = l;
            l->next = curr;
            l = curr;
            curr= curr->next;
        }
    }
    l->next = nullptr;
    return;
}

//Reverse in groups

Node* ReverseInK(Node* head, int k){
    if(!head||!head->next){
        return head;
    }
    Node* curr = head;
    Node* p = nullptr;
    Node* nex = nullptr;
    int count = 0;
    while(curr&&count!=k){
        nex = curr->next;
        curr->next = p;
        p =curr;
        curr=nex;
        count++;
    }
    if(nex){
        head->next = ReverseInK(nex, k);
    }
    return p;
}

//Rotate Linked list by k

Node* rotateByK(Node* head, int k){
    Node* tail = head;
    int l =1;
    while(tail->next){
        tail = tail->next;
        l++;
    }
    k = k%l;
    if(k==0){
        return head;
    }
    tail->next = head;
    k = l-k;
    while(k){
        tail =tail->next;
        k--;
    }
    head = tail->next;
    tail->next = nullptr;
    return head;
}

//Flatten Linked list
//Deep Clone

int main(){
    int n;
    cout<<"Enter number of nodes required: ";
    cin>>n;
    int x;
    cout<<"Enter elements: ";
    cin>>x;
    Node* head = new Node(x);
    Node* curr = head;
    for(int i =1;i<n;i++){
        cin>>x;
        curr->next = new Node(x); 
        curr=curr->next;
    }
    
    // NodeD* head = new NodeD(x);
    // NodeD* curr = head;
    // for(int i =1;i<n;i++){
    //     cin>>x;
    //     curr->next = new NodeD(x); 
    //     curr=curr->next;
    // }
    
    // int k;
    // cout<<"Enter key value to be delete: ";
    // cin>>k;
    // cout<<"Result: ";
    // deleteAll(head, k);
    // while(head){
    //     cout<<head->data<<" ";
    //     head=head->next;
    // }
    
    // cout<<"Enter Target: ";
    // cin>>k;
    // vector<pair<int,int>>res = findPairs(head, k);
    // cout<<"Result";
    // for(auto &x:res){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    
    // cout<<"Result: ";
    // removeDuplicates(head);
    // while(head){
    //     cout<<head->data<<" ";
    //     head=head->next;
    // }
    
    // Node* head = new Node(x);
    // Node* curr = head;
    // for(int i =1;i<n;i++){
    //     cin>>x;
    //     curr->next = new Node(x); 
    //     curr=curr->next;
    // }
    
    // int k;
    // cout<<"Enter group size: ";
    // cin>>k;
    // cout<<"Result: ";
    // head = ReverseInK(head, k);
    // while(head){
    //     cout<<head->data<<" ";
    //     head=head->next;
    // }
    
    int k;
    cout<<"Enter rotation value: ";
    cin>>k;
    cout<<"Result: ";
    head = rotateByK(head, k);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
