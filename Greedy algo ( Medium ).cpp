/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//N meetings in one room

struct Job{
  int start;
  int end;
};

bool mycmp(Job a, Job b){
    return a.end<b.end;
}

int maxMeetings(Job arr[], int n){
    sort(arr, arr+n, mycmp);
    int endtime = 0;
    int res = 0;
    for(int i=0;i<n;i++){
        if(arr[i].start>endtime){
            res++;
            endtime = arr[i].end;
        }
    }
    return res;
}

// Minimum number of platforms in railways

struct Rt {
    int ar;
    int dep;
};

bool mySort(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first; 
}

int reqPlatforms(Rt arr[], int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i].ar, 1});
        v.push_back({arr[i].dep, -1});
    }
    int res = 0;
    int curr = 0;
    sort(v.begin(), v.end(), mySort);
    for (auto x : v) {
        curr += x.second;
        res = max(res, curr);
    }
    return res;
}

// Scheduling to obtain maximum profit

struct Jobs{
    int profit;
    int JobId;
    int deadline;
};

bool reSort(Jobs a, Jobs b){
    return a.profit > b.profit;
}

vector<int> maxProfit(Jobs arr[], int n){
    sort(arr, arr+n, reSort);
    int maxDd = -1;
    int res = 0;
    for(int i=0;i<n;i++){
        maxDd = max(maxDd, arr[i].deadline);
    }
    int cnt =0;
    vector<int>hash(maxDd+1, -1);
    for(int i=0;i<n;i++){
        int j = arr[i].deadline;
        while(j>0&&hash[j]!=-1){
            j--;
        }
        if(j>0){
            hash[j] = arr[i].JobId;
            res+=arr[i].profit;
            cnt++;
        }
    }
    return {cnt, res};
} 

// Candies to chidren according to rank

vector<int> candy(vector<int>& ratings){
    int n = ratings.size();
    vector<int>l(n, 1);
    vector<int>r(n, 1);
    vector<int>res(n);
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            l[i] = l[i-1]+1;
        }
        if(ratings[n-i-1]>ratings[n-i]){
            r[n-i-1] = r[n-i]+1;
        }
    }
    for(int i=0;i<n;i++){
        res[i] = max(l[i], r[i]);
    }
    return res;
}

// Page Replacement ( LRU )

int PageReplacement(vector<int>Pages, int c, int n){
    deque<int>dq;
    int res=0;
    for(auto x:Pages){
        auto it = find(dq.begin(), dq.end(), x);
        if(it==dq.end()){
            if(dq.size()==c){
                dq.pop_front();
                dq.push_back(x);
            }else{
                dq.push_back(x);
            }
            res++;
        }else{
            dq.erase(it);
            dq.push_back(x);
        }
    }
    return res;
}

//Insert Interval

vector<vector<int>> InsertInterval(vector<vector<int>>intervals, vector<int> newInterval, int n){
    vector<vector<int>>res;
    int i=0;
    while(i<n&&intervals[i][1]<newInterval[0]){
        res.push_back(intervals[i]);
        i++;
    }
    while(i<n&&intervals[i][0]<=newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res.push_back(newInterval);
    while(i<n){
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

int main()
{
    // int n;
    // cout<<"Enter number of meetings: ";
    // cin>>n;
    // Job arr[n];
    // cout<<"Enter meeting timings: "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter start time: ";
    //     cin>>arr[i].start;
    //     cout<<"Enter end time: ";
    //     cin>>arr[i].end;
    // }
    // cout<<"Result: "<<maxMeetings(arr, n);
    
    // int n;
    // cout<<"Enter number of rail timings: ";
    // cin>>n;
    // Rt arr[n];
    // cout<<"Enter rail timings: "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter arrival time: ";
    //     cin>>arr[i].ar;
    //     cout<<"Enter departure time: ";
    //     cin>>arr[i].dep;
    // }
    // cout<<"Maximum platforms: "<<reqPlatforms(arr, n);
    
    // int n;
    // cout<<"Enter number of jobs: ";
    // cin>>n;
    // Jobs arr[n];
    // cout<<"Enter job values: "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter jobid: ";
    //     cin>>arr[i].JobId;
    //     cout<<"Enter profit of job: ";
    //     cin>>arr[i].profit;
    //     cout<<"Enter deadline of job: ";
    //     cin>>arr[i].deadline;
    // }
    // vector<int> res = maxProfit(arr, n);
    // cout<<"Max obtainable profit: "<<res[1]<<endl;
    // cout<<"Maximum number of jobs that can be done: "<<res[0];
    
    // int n;
    // cout<<"Enter number of students: ";
    // cin>>n;
    // vector<int>arr(n);
    // cout<<"Enter students rank: ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // vector<int> res = candy(arr);
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    
    // int n;
    // cout<<"Enter number of pages: ";
    // cin>>n;
    // int c;
    // cout<<"Enter capacity of LRU:";
    // cin>>c;
    // vector<int>pages(n);
    // cout<<"Enter pages value: ";
    // for(int i=0;i<n;i++){
    //     cin>>pages[i];
    // }
    // cout<<"Replaced pages: "<<PageReplacement(pages, c, n);
    
    int n;
    cout<<"Enter number of intervals: ";
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cout<<"Enter starting time of interval: ";
        cin>>intervals[i][0];
        cout<<"Enter ending time of interval: ";
        cin>>intervals[i][1];
    }
    vector<int>newInterval(2);
    cout<<"Enter starting time of new interval: ";
    cin>>newInterval[0];
    cout<<"Enter ending time of new interval: ";
    cin>>newInterval[1];
    vector<vector<int>>res = InsertInterval(intervals, newInterval, n);
    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}