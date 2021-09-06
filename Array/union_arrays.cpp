// { Driver Code Starts
//Initial template for C++
//author : Tushar Khanduri [https://github.com/Tushar-K24]
//problem link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        int cnt = 0;
        sort(a, a + n);
        sort(b, b + m);
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < n && ptr2 < m)
        {
            if (ptr1 && a[ptr1] == a[ptr1 - 1])
            {
                ptr1++;
                continue;
            }
            if (ptr2 && b[ptr2] == b[ptr2 - 1])
            {
                ptr2++;
                continue;
            }
            if (a[ptr1] == b[ptr2])
            {
                ptr1++;
                ptr2++;
            }
            else if (a[ptr1] < b[ptr2])
            {
                ptr1++;
            }
            else
            {
                ptr2++;
            }
            cnt++;
        }
        for (int i = ptr1; i < n; i++)
        {
            if (i == 0)
            {
                cnt++;
                continue;
            }
            if (a[i] != a[i - 1])
                cnt++;
        }
        for (int i = ptr2; i < m; i++)
        {
            if (i == 0)
            {
                cnt++;
                continue;
            }
            if (b[i] != b[i - 1])
                cnt++;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends