/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Binary Search

int binarySearch(vector<int>arr, int low, int high, int target){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid]>target){
       return binarySearch(arr, low, mid-1, target);
    }else if(arr[mid]<target){
       return binarySearch(arr, mid+1, high, target);
    }else{
        return mid;
    }
}

// Lower Bound

int lowerBound(vector<int>arr, int target){
   int low = 0;
   int high = arr.size()-1;
   int ans;
   while(low<=high){
       int mid = (low+high)/2;
       if(arr[mid]<target){
           low = mid+1;
       }else{
           ans = arr[mid];
           high = mid-1;
       }
   }
   return ans;
}

// upper Bound

int higherBound(vector<int>arr, int target){
   int low = 0;
   int high = arr.size()-1;
   int ans;
   while(low<=high){
       int mid = (low+high)/2;
       if(arr[mid]<target){
           low = mid+1;
       }else if(arr[mid]>target){
           ans = arr[mid];
           high = mid-1;
       }else{
           low = mid+1;
       }
   }
   return ans;
}

//Floor and Ceil in array
pair<int,int> FloorandCeil(vector<int>arr, int target){
   int low = 0;
   int high = arr.size()-1;
   pair<int,int> ans= {-1, -1};
   while(low<=high){
       int mid = (low+high)/2;
       if(arr[mid]<target){
           ans.first = arr[mid];
           low = mid+1;
       }else if(arr[mid]>target){
           ans.second = arr[mid];
           high = mid-1;
       }else{
           return {arr[mid], arr[mid]};
       }
   }
   return ans;
}

//Find first and last occurence of a digit in array

pair<int,int> firstAndLast(vector<int>arr, int target){
    int low = 0;
    int high = arr.size()-1;
    pair<int,int> res;
    while(low<=high){
        int mid = (low+high)/2; 
        if(arr[mid]<target){
            low = mid+1;
        }else if(arr[mid]>target){
            high = mid -1;
        }else{
            res.first = mid;
            high = mid-1;
        }
    }
    low = 0;
    high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2; 
        if(arr[mid]<target){
            low = mid+1;
        }else if(arr[mid]>target){
            high = mid -1;
        }else{
            res.second = mid;
            low = mid+1;
        }
    }
    return res;
}

//Search in rotated and Sorted

int SearchinRot(vector<int>arr, int target){
    int l = 0;
    int h = arr.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[l]<=arr[mid]){
            if(arr[l]<=target&&target<=arr[mid]){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }else{
            if(arr[mid]<=target&&target<=arr[h]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
    }
    return -1;
}

//Search in rotated and Sorted with duplicates

int SearchinRotD(vector<int>arr, int target){
    int l = 0;
    int h = arr.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[l]==arr[mid]&&arr[h]==arr[mid]){
            l++;
            h--;
            continue;
        }
        if(arr[l]<=arr[mid]){
            if(arr[l]<=target&&target<=arr[mid]){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }else{
            if(arr[mid]<=target&&target<=arr[h]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
    }
    return -1;
}

//Find minimum in rotated and sorted array

int minInSorted(vector<int>arr){
    int ans = INT_MAX;
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            low = mid+1; 
        }else{
            ans = min(ans , arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

// Single element in a Sorted array

int SingleElement(vector<int>arr){
    if(arr.size()==1){
        return arr[0];
    }
    if(arr[0]!=arr[1]){
        return arr[0];
    }
    if(arr[arr.size()-1]!=arr[arr.size()-2]){
        return arr[arr.size()-1];
    }
    int low = 1;
    int high = arr.size()-2;
    while(low<=high){
        int mid = (low+high)/2;
        if((arr[mid]!=arr[mid+1])&&(arr[mid]!=arr[mid-1])){
            return arr[mid];
        }
        if((mid%2==0&&arr[mid]==arr[mid+1])||(mid%2==1&&arr[mid]==arr[mid-1])){
            low= mid+1;
        }else{
            high= mid-1;
        }
    }
    return -1;
}

// Find peak element

int peakElement(vector<int>arr){
    if(arr.size()==1){
        return arr[0];
    }
    if(arr[0]>arr[1]){
        return arr[0];
    }
    if(arr[arr.size()-1]>arr[arr.size()-2]){
        return arr[arr.size()-1];
    }
    int l = 1, h = arr.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1]){
            return arr[mid];
        }
        if(arr[mid-1]<arr[mid]){
            l =mid+1;
        }else {
            h = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // int res = binarySearch(arr, 0, n-1, target);
    // cout<<"Result: "<<res;
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // int res = lowerBound(arr, target);
    // cout<<"Lower Bound: "<<res;
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // int res = higherBound(arr, target);
    // cout<<"Higher Bound: "<<res;
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // pair<int,int> res = FloorandCeil(arr, target);
    // cout<<"Floor and Ceil: "<<res.first<<" "<<res.second;
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // pair<int,int> res = firstAndLast(arr, target);
    // cout<<"First and last occurence: "<<res.first<<" "<<res.second;
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // int res = SearchinRot(arr, target);
    // cout<<"Search in Rotated in and Sorted: "<< res;
    
    // int target;
    // cout<<"Enter Target required: ";
    // cin>>target;
    // int res = SearchinRotD(arr, target);
    // cout<<"Search in Rotated in and Sorted with duplicates: "<< res;
    
    // int res = minInSorted(arr);
    // cout<<"minimum in array: "<<res;
    
    // int res = SingleElement(arr);
    // cout<<"Single Element in an array is: "<<res;
    
    int res = peakElement(arr);
    cout<<"Peak Element in an array is: "<<res;
}