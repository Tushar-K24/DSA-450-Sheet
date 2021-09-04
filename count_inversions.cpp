//author : Tushar Khanduri [https://github.com/Tushar-K24]
//problem link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], int l, int m, int r, long long &cnt){
        long long left[m-l+1], right[r-m];
        for(int i=l;i<=m;i++) left[i-l]=arr[i];
        for(int i=m+1;i<=r;i++) right[i-m-1]=arr[i];
        int ptr1=0,ptr2=0;
        int ptr=l;
        while(ptr1<m-l+1 && ptr2<r-m){
            if(left[ptr1]>right[ptr2]){
                cnt+=m-l+1-ptr1;
                arr[ptr]=right[ptr2];
                ptr2++;
            }
            else{
                arr[ptr]=left[ptr1];
                ptr1++;
            }
            ptr++;
        }
        while(ptr1<m-l+1){
            arr[ptr]=left[ptr1];
            ptr1++;
            ptr++;
        }
        while(ptr2<r-m){
            arr[ptr]=right[ptr2];
            ptr2++;
            ptr++;
        }
    }
    //0 1 2 3 4
    //2 4 1 3 5
    //l=0,r=4,m=2
    //0,2,1
    //0,1,0
    void merge_sort(long long arr[], long long l, long long r, long long &cnt){
        if(l>=r) return;
        long long m=(l+r)/2;
        merge_sort(arr,l,m,cnt);
        merge_sort(arr,m+1,r,cnt);
        merge(arr,l,m,r,cnt);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long cnt=0;
        merge_sort(arr,0,N-1,cnt);
        return cnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends