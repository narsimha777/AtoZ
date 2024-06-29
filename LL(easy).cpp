/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; 

struct NodeD {
    int data;
    struct NodeD* next;
    struct NodeD* prev;
    NodeD(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

//Reverse LL

Node* reverse(Node* head){
    if(!head||!head->next){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

//Reverse DLL

NodeD* reverseDLL(NodeD* head){
    NodeD* curr = head;
    NodeD* p =nullptr;
    while(curr){
        NodeD* temp =curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        p=curr;
        curr = curr->prev;
    }
    return p;
}

// TortoiseHare Method

Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//Detect a loop

bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

Node* findLoopoint(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//Check linked list is palindrome

Node* cur;

bool checkLLpalin(Node* head){
    if(!head){
        return true;
    }
    bool ans = checkLLpalin(head->next)&&head->data==cur->data;
    cur = cur->next;
    return ans;
}

// Segrregate Odd and even nodes

Node* segOddEve(Node* head){
    if(!head||!head->next){
        return head;
    }
    Node* e = head->next;
    Node* o = head;
    Node* eh = e;
    while(e&&e->next){
        o->next = e->next;
        o = o->next;
        e->next = o->next;
        e=e->next;
    }
    o->next=eh;
    return head;
}

//Remove Nth node from back

Node* removeNth(Node* head, int n){
    Node* fast = head;
    while(n){
        fast=fast->next;
        n--;
    }
    if(!fast){
        return head->next;
    }
    Node* slow = head;
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete(temp);
    return head;
}

//Merge Sort linked list

Node* mergeLL(Node* A, Node* B){
    Node* res = new Node(-1);
    Node* rh = res;
    while(A&&B){
        if(A->data<B->data){
            res->next = A;
            A =A->next;
        }else{
            res->next = B;
            B=B->next;
        }
        res=res->next;
    }
    if(A){
        res->next = A;
    }
    if(B){
        res-> next = B;
    }
    Node* temp=rh;
    rh = rh->next;
    delete(temp);
    return rh;
}

Node* middleNodeSRT(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* p = nullptr;
    while(fast&&fast->next){
        p =slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(p){
        p->next = nullptr;
    }
    return slow;
}

Node* mergeSortLL(Node* head){
    if(!head||!head->next){
        return head;
    }
    Node* m = middleNodeSRT(head);
    Node* l = mergeSortLL(head);
    Node* r = mergeSortLL(m);
    return mergeLL(l, r);
}

//Sort Linked List of zeroes, ones and twos

Node* segZOT(Node* head){
    Node* zeroes = new Node(-1);
    Node* res = zeroes;
    Node* ones = new Node(-1);
    Node* oh = ones;
    Node* twos = new Node(-1);
    Node* th = twos;
    Node* curr = head;
    while(curr){
        if(curr->data == 0){
            zeroes->next = curr;
            zeroes = zeroes->next;
        }else if(curr->data==1){
            ones->next = curr;
            ones = ones->next;
        }else{
            twos->next = curr;
            twos = twos->next;
        }
        curr=curr->next;
    }
    twos->next = nullptr;
    ones->next = th->next;
    zeroes->next = oh->next;
    Node* temp = res;
    res = res->next;
    delete(oh);
    delete(th);
    delete(temp);
    return res;
}

// Find Intersection point

Node* findIntersection(Node* headA, Node* headB){
    Node* currA = headA;
    Node* currB = headB;
    while(currA!=currB){
        currA = currA->next;
        currB = currB->next;
        if(!currA){
            currA = headB;
        }
        if(!currB){
            currB = headA;
        }
    }
    return currA;
}

// Add 1 to number

Node* addOne(Node* head){
    if(!head){
        return new Node(1);
    }
    Node* curr = reverse(head);
    Node* res = new Node(-1);
    Node* rh = res; 
    int carry = 1;
    while(curr){
        int sum = curr->data + carry;
        int d = sum%10;
        int carry = sum/10;
        res->next = new Node(d);
        res=res->next;
        curr=curr->next;
    }
    if(carry){
        res->next = new Node(carry);
    }
    Node* temp = rh;
    rh = rh->next;
    delete(temp);
    return reverse(rh);
}

// Add two numbers

Node* AddNUMB(Node* A, Node* B){
    int carry = 0;
    Node* res = new Node(-1);
    Node* rh = res;
    A = reverse(A);
    B = reverse(B);
    while(A&&B){
        int sum = A->data+B->data+carry;
        carry = sum/10;
        int d = sum%10;
        res->next = new Node(d);
        res=res->next;
        A=A->next;
        B=B->next;
    }
    while(A){
        int sum = A->data+carry;
        carry = sum/10;
        int d = sum%10;
        res->next = new Node(d);
        res=res->next;
        A=A->next;
    }
    while(B){
        int sum = B->data+carry;
        carry = sum/10;
        int d = sum%10;
        res->next = new Node(d);
        res=res->next;
        B=B->next;
    }
    if(carry){
        res->next = new Node(carry);
    }
    Node* temp = rh;
    rh = rh->next;
    delete(temp);
    return reverse(rh);
}

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
    
    // cout<<"Result: ";
    // Node* rhead = reverse(head);
    // while(rhead){
    //     cout<<rhead->data<<" ";
    //     rhead=rhead->next;
    // }
    
    // NodeD* head = new NodeD(x);
    // NodeD* curr = head;
    // for(int i =1;i<n;i++){
    //     cin>>x;
    //     NodeD* temp = curr;
    //     curr->next = new NodeD(x); 
    //     curr=curr->next;
    //     curr->prev  = temp;
    // }
    // cout<<"Result: ";
    // NodeD* rhead = reverseDLL(head);
    // while(rhead){
    //     cout<<rhead->data<<" ";
    //     rhead=rhead->next;
    // }
    
    // Node* mid = middleNode(head);
    // cout<<"Result: "<<mid->data;
    
    // curr->next = head->next->next;
    
    // bool isLoop = detectLoop(head);
    // cout<<"Result: "<<isLoop;
    
    // Node* lp = findLoopoint(head);
    // cout<<"Result: "<<lp->data;
    
    // cur=head;
    // bool isPalin = checkLLpalin(head);
    // cout<<"Result: "<<isPalin;
    
    // cout<<"Result: ";
    // Node* res = segOddEve(head);
    // while(res){
    //     cout<<res->data<<" ";
    //     res=res->next;
    // }
    
    // int k;
    // cout<<"Enter Nth pos from back: ";
    // cin>>k;
    // Node* res = removeNth(head, k);
    // cout<<"Result: ";
    // while(res){
    //     cout<<res->data<<" ";
    //     res=res->next;
    // }
    
    // Node* res = mergeSortLL(head);
    // cout<<"Result: ";
    // while(res){
    //     cout<<res->data<<" ";
    //     res=res->next;
    // }
    
    // Node* res = segZOT(head);
    // cout<<"Result: ";
    // while(res){
    //     cout<<res->data<<" ";
    //     res=res->next;
    // }
    
    // cout<<"Enter elements of B: ";
    // cin>>x;
    
    // Node* headB = new Node(x);
    // Node* cur = headB;
    // for(int i =1;i<n;i++){
    //     cin>>x;
    //     cur->next = new Node(x); 
    //     cur=cur->next;
    // }
    // curr->next = headB->next->next;
    // Node* res = findIntersection(head, headB);
    // cout<<"Result: "<<res->data;
    
    // cout<<"Result: ";
    // Node* res =addOne(head);
    // while(res){
    //     cout<<res->data<<" ";
    //     res=res->next;
    // }
    
    cout<<"Enter elements in B: ";
    cin>>x;
    
    Node* headB = new Node(x);
    Node* cur = headB;
    for(int i =1;i<n;i++){
        cin>>x;
        cur->next = new Node(x); 
        cur=cur->next;
    }
    Node* res = AddNUMB(head, headB);
    cout<<"Result: ";
    while(res){
        cout<<res->data<<" ";
        res=res->next;
    }
}
