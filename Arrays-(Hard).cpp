/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// Pascal triangle row-1 C col-1

vector<int> Nrow(int n){
    int ans = 1;
    vector<int>res;
    res.push_back(ans);
    for(int i=1;i<n;i++){
        ans=ans*(n-i)/i;
        res.push_back(ans);
    }
    return res;
}

//Majority element (N>3)

vector<int> modifiedmoores(vector<int>arr){
    int c1 =0;
    int c2 =0;
    int ele1, ele2;
    vector<int>res;
    for(auto x:arr){
        if(c1==0&&x!=ele2){
            ele1 = x;
            c1=1;
        }else if(c2==0&&x!=ele1){
            ele2 = x;
            c2=1;
        }else if(x==ele1){
            c1++;
        }else if(x==ele2){
            c2++;
        }else{
            c1--;
            c2--;
        }
    }
    c1 =0;
    c2 =0;
    for(auto x:arr){
        if(x==ele1){
            c1++;
        }else if(x==ele2){
            c2++;
        }
    }
    if(c1>arr.size()/3){
        res.push_back(ele1);
    }
    if(c2>arr.size()/3){
        res.push_back(ele2);
    }
    return res;
}

// 3 Sum problem

vector<vector<int>> three_sum(vector<int>arr, int k){
    sort(arr.begin(), arr.end());
    vector<vector<int>>res;
    for(int i=0;i<arr.size();i++){
        if(i>0&&arr[i]==arr[i-1]){
            continue;
        }
        int l = i+1;
        int h = arr.size()-1;
        while(l<h){
            int s = arr[i] + arr[l] + arr[h];
            if(s<k){
                l++;
            }else if(s>k){
                h--;
            }else{
                res.push_back({arr[i], arr[l], arr[h]});
                l++;
                h--;
                while(arr[l]==arr[l-1]){
                    l++;
                }
                while(arr[h]==arr[h+1]){
                    h--;
                }
            }
        }
    }
    return res;
}

// 4 Sum problem

vector<vector<int>> four_sum(vector<int>arr, int k){
    vector<vector<int>>res;
    for(int i=0;i<arr.size();i++){
        if(i>0&&arr[i-1]==arr[i]){
            continue;
        }
        for(int j=i+1;j<arr.size();j++){
            if(j>i+1&&arr[j-1]==arr[j]){
                continue;
            }
            int l = j+1;
            int h = arr.size()-1;
            while(l<h){
                int s = arr[i] + arr[l] + arr[h] + arr[j];
                if(s<k){
                    l++;
                }else if(s>k){
                    h--;
                }else{
                    res.push_back({arr[i], arr[j], arr[l], arr[h]});
                    l++;
                    h--;
                    while(arr[l]==arr[l-1]){
                        l++;
                    }
                    while(arr[h]==arr[h+1]){
                        h--;
                    }
                }
            }
        }
    }
    return res;
}

//get index of sub array with xor k

vector<int> mlsubarrayK(vector<int>arr, int k){
    unordered_map<int,int>mp;
    int xr =0;
    int res = INT_MIN;
    int l =-1;
    int h =-1;
    for(int i=0;i<arr.size();i++){
        xr = xr^arr[i];
        if(xr == k){
            res= max(res, i+1);
            l = 1;
            h = i+1;
        }
        if(mp.count(xr^k)){
            res = max(res, i-mp[xr^k]);
            l = mp[xr^k]+1;
            h = i+1;
        }
        if(!mp.count(xr)){
            mp[xr]=i;
        }
    }
    return {l, h};
}

//find repeating and missing number in any order

vector<int> method1R_M(vector<int>arr){
    int n = arr.size();
    int t = n*(n+1)/2;
    int st = n*(2*n+1)*(n+1)/6;
    int mt = accumulate(arr.begin(), arr.end(), 0);
    int mst = 0;
    for(auto x:arr){
        mst+=x*x;
    }
    int val1 = t - mt;
    int val2 = st - mst;
    val2 = val2/val1;
    int y = (val2 - val1)/2;
    int x = val2 - y;
    return {x, y};
} 

vector<int> method2R_M(vector<int>arr){
    int xr = 0;
    for(int i=0;i<arr.size();i++){
        xr^=arr[i];
        xr^=(i+1);
    }   
    int bit = xr&~(xr-1);
    int x = 0, y =0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]&bit){
            x ^= arr[i];
        }else{
            y^=arr[i];
        }
        if((i+1)&bit){
            x ^= (i+1);
        }else{
            y^= (i+1);
        }
    }
    return {x, y};
}

// Count inversions

int merge(vector<int> &arr, int low, int mid, int high){
    int cnt =0;
    int a[mid-low+1];
    int b[high-mid];
    for(int i=low;i<=mid;i++){
        a[i-low] = arr[i];
    }
    for(int i=mid+1;i<=high;i++){
        b[i-mid-1] = arr[i];
    }
    int u = 0, v = 0, k = low;
    while(u<(mid-low+1)&&v<(high-mid)){
        if(a[u]<b[v]){
            arr[k] = a[u];
            u++;
       }else{
           arr[k] = b[v];
           cnt += (mid-low+1-u);
           v++;
       }
       k++;
    }
    while(u<(mid-low+1)){
        arr[k]= a[u];
        u++;
        k++;
    }
    while(v<(high-mid)){
        arr[k] = b[v];
        v++;
        k++;
    }
    return cnt;
}

int mergeSort(vector<int>&arr, int low, int high){
    int cnt  = 0;
    if(low>=high){
        return cnt;
    }
    int mid = (low+high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

int inversionCount(vector<int>arr){
    return mergeSort(arr, 0, arr.size()-1);
}

//Reverse pairs

void mergeRP(vector<int> &arr, int low, int mid, int high){
    int a[mid-low+1];
    int b[high-mid];
    for(int i=low;i<=mid;i++){
        a[i-low] = arr[i];
    }
    for(int i=mid+1;i<=high;i++){
        b[i-mid-1] = arr[i];
    }
    int u = 0, v = 0, k = low;
    while(u<(mid-low+1)&&v<(high-mid)){
        if(a[u]<b[v]){
            arr[k] = a[u];
            u++;
       }else{
           arr[k] = b[v];
           v++;
       }
       k++;
    }
    while(u<(mid-low+1)){
        arr[k]= a[u];
        u++;
        k++;
    }
    while(v<(high-mid)){
        arr[k] = b[v];
        v++;
        k++;
    }
    return ;
}

int countPairs(vector<int>&arr, int low, int mid, int high){
    int cnt = 0;
    int j = mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high&&arr[i]>2*arr[j]){
            j++;
        }
        cnt+= j - mid - 1;
    }
    return cnt;
}

int mergeSortRP(vector<int>&arr, int low, int high){
    int cnt  = 0;
    if(low>=high){
        return cnt;
    }
    int mid = (low+high)/2;
    cnt+=mergeSortRP(arr, low, mid);
    cnt+=mergeSortRP(arr, mid+1, high);
    cnt+=countPairs(arr, low, mid, high);
    mergeRP(arr,low,mid,high);
    return cnt;
}

int reversePairs(vector<int>arr){
    return mergeSortRP(arr, 0, arr.size()-1);
}


int main(){
    
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // int n;
    // cout<<"Enter number of rows: ";
    // cin>>n;
    // vector<vector<int>>res;
    // for(int i=0;i<n;i++){
    //     res.push_back(Nrow(i+1));
    // }
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // vector<int>res = modifiedmoores(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // int k;
    // cout<<"Enter required sum: ";
    // cin>>k;
    // vector<vector<int>>res = three_sum(arr, k);
    // cout<<"Result: ";
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    // int k;
    // cout<<"Enter required sum: ";
    // cin>>k;
    // vector<vector<int>>res = four_sum(arr, k);
    // cout<<"Result: ";
    // for(auto x:res){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    // int k;
    // cout<<"Enter required K: ";
    // cin>>k;
    // vector<int> res = mlsubarrayK(arr, k);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;   
    
    // vector<int>res = method1R_M(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    // vector<int>res = method2R_M(arr);
    // cout<<"Result: ";
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;    
    
    // int res = inversionCount(arr);
    // cout<<"Result: "<<res;
    
    int res = reversePairs(arr);
    cout<<"Result: "<<res;
    
}