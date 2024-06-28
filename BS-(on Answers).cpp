/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Find square Root

int sqroot(int n){
    return n*n;
}

int root(int n){
    int low = 0, high = n;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        int sq = sqroot(mid);
        if(sq>n){
            high = mid-1;
        }else{
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

//Find Nth root of given number

int power(int base, int e){
    int ans = 1;
    while(e){
        if(e%2){
            ans = ans*base;
            e-=1;
        }else{
            base = base*base;
            e/=2;
        }
    }
    return ans;
}

int Kthroot(int n, int k){
    int low = 0, high = n;
    int ans= -1;
    while(low<=high){
        int mid = (low+high)/2;
        int krt = power(mid, k);
        if(krt>n){
            high = mid-1;
        }else{
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

//Koko eating banana's

int Nofhrs(vector<int>bananas, int k){
    int hrs = 0;
    for(auto x:bananas){
        hrs = hrs + ceil((double)x/(double)k);
    }
    return hrs;
}

int findK(vector<int>bananas, int hrs){
    int low = 1;
    int high = accumulate(bananas.begin(), bananas.end(), 0);
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        int hr = Nofhrs(bananas, mid);
        if(hr>hrs){
            low = mid+1;
        }else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}

//Find minimum no of days require to make M Bouquets with k flowers

int NofBouquets(vector<int>bloomDay, int k, int day){
    int c=0;
    int res =0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            c++;
        }else{
            res+=(c/k);
            c=0;
        }
    }
    res+=(c/k);
    return res;
}

int Nofdays(vector<int> bloomDay, int m, int k){
    int low = 1;
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    if(m*k>high){
        return -1;
    }
    while(low<=high){
        int mid = (low+high)/2;
        int nbq = NofBouquets(bloomDay, k, mid);
        if(nbq>=m){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

//Kth missing positive number

int Kthmis(vector<int>arr, int k){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        int nofmis = arr[mid] -mid-1;
        if(nofmis>=k){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return high+k+1;
}

//Aggressive cows

int NofAgCo(vector<int>arr, int distance){
    int c = 1;
    int last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=distance){
          c++;
          last = arr[i];
        }
    }
    return c;
}

int findDist(vector<int>arr, int NofCows){
    sort(arr.begin(), arr.end());
    int low = 1, high = arr.back() - arr.front();
    int ans= -1;
    while(low<=high){
        int mid = (low+high)/2;
        int nc = NofAgCo(arr, mid);
        if(nc>=NofCows){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

//Median of two sorted arrays

double MedianofArr(vector<int>arr1, vector<int>arr2, int n1, int n2){
    if(n1>n2){
        return MedianofArr(arr2, arr1, n2, n1);
    }
    int low = 0, high = n1;
    int left = (n1+n2+1)/2;
    int n = n1+n2;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = mid1==0?INT_MIN:arr1[mid1-1];
        int l2 = mid2==0?INT_MIN:arr2[mid2-1];
        int r1 = mid1==n1?INT_MAX:arr1[mid1];
        int r2 = mid2==n2?INT_MAX:arr2[mid2];
        if(l1<=r2&&l2<=r1){
            if(n%2){
                return (double)(max(l1,l2)+min(r1,r2))/2.00;
            }else{
                return (double)max(l1, l2);
            }
        }
        if(l1>r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }
    return 0.0;
}

//Kth element from two sorted arrays

int Kthele(vector<int>arr1, vector<int>arr2, int n1, int n2, int k){
    if(n1>n2){
        return Kthele(arr2, arr1, n2, n1, k);
    }
    int low = max(0, k-n2), high = min(n1, k);
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = k - mid1;
        int l1 = mid1==0?INT_MIN:arr1[mid1-1];
        int l2 = mid2==0?INT_MIN:arr2[mid2-1];
        int r1 = mid1==n1?INT_MAX:arr1[mid1];
        int r2 = mid2==n2?INT_MAX:arr2[mid2];
        if(l1<=r2&&l2<=r1){
            return max(l1, l2);
        }
        if(l1>r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }
    return 0.0;
}

int main()
{
    // int n;
    // cout<<"Enter number of which root is to be found: ";
    // cin>>n;
    
    // int res = root(n);
    // cout<<"Result: "<<res;
    
    // int k;
    // cout<<"Enter value of K: ";
    // cin>>k;
    // int res = Kthroot(n, k);
    // cout<<"Result: "<<res;
    
    // int n;
    // cout<<"Enter number of elements in array: ";
    // cin>>n;
    // vector<int>arr(n);
    // cout<<"Enter number of bananas in each pile: ";
    // cout<<"Enter bloomDay of ith flower: ";
    // cout<<"Enter elements of array: ";
    // cout<<"Distance at which stalls are located: ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    
    // int hrs;
    // cout<<"Available amount of hours: ";
    // cin>>hrs;
    // int res = findK(arr, hrs);
    // cout<<"Eating Rate bananans per hour: "<<res;
    
    // int m, k;
    // cout<<"Enter no of Bouquets required: ";
    // cin>>m;
    // cout<<"Enter no of flowers required in each bouquets: ";
    // cin>>k;
    // int res = Nofdays(arr, m, k);
    // cout<<"minimum no of days to make m bouquets: "<<res;
    
    // int k;
    // cout<<"Enter kth missing to be found: ";
    // cin>>k;
    // int res = Kthmis(arr, k);
    // cout<<"Result: "<<res;
    
    // int NofCows;
    // cout<<"No of Cows: ";
    // cin>>NofCows;
    // int res = findDist(arr, NofCows);
    // cout<<"Minimum distance between stalls: "<<res;
    
    int n1, n2;
    cout<<"Enter number of elements in array1: ";
    cin>>n1;
    cout<<"Enter number of elements in arrat2: ";
    cin>>n2;
    cout<<"Enter elements in array1: ";
    vector<int>arr1(n1);
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter elements in array2: ";
    vector<int>arr2(n2);
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    // double res = MedianofArr(arr1, arr2, n1, n2);
    // cout<<"Result: "<<res;
    
    int k;
    cout<<"Enter k value: ";
    cin>>k;
    int res = Kthele(arr1, arr2, n1, n2, k);
    cout<<"Result: "<<res;
}
