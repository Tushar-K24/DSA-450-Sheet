//author : Tushar Khanduri [https://github.com/Tushar-K24]
//problem link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int *get_index(int arr1[], int arr2[], int n, int m, int index)
    {
        if (index < n)
            return &arr1[index];
        return &arr2[index - n];
    }

    void heapify(int arr1[], int arr2[], int n, int m, int size, int idx)
    {
        if (2 * idx + 1 >= size)
        {
            return;
        }
        else
        {
            if (2 * idx + 2 >= size)
            {
                int *child = get_index(arr1, arr2, n, m, 2 * idx + 1);
                int *root = get_index(arr1, arr2, n, m, idx);
                if (*child > *root)
                {
                    swap(*root, *child);
                }
                return;
            }
            else
            {
                int *child1 = get_index(arr1, arr2, n, m, 2 * idx + 1);
                int *child2 = get_index(arr1, arr2, n, m, 2 * idx + 2);
                int *root = get_index(arr1, arr2, n, m, idx);
                if (*root > max(*child1, *child2))
                    return;
                else
                {
                    if (*child1 > *child2)
                    {
                        swap(*root, *child1);
                        heapify(arr1, arr2, n, m, size, 2 * idx + 1);
                    }
                    else
                    {
                        swap(*root, *child2);
                        heapify(arr1, arr2, n, m, size, 2 * idx + 2);
                    }
                }
            }
        }
    }

    void merge(int arr1[], int arr2[], int n, int m)
    {
        //build max heap
        for (int i = (n + m) / 2 - 1; i >= 0; i--)
        {
            heapify(arr1, arr2, n, m, n + m, i);
        }

        //heap sort
        for (int i = n + m - 1; i > 0; i--)
        {
            int *idx = get_index(arr1, arr2, n, m, i);
            swap(arr1[0], *idx);
            heapify(arr1, arr2, n, m, i, 0);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends