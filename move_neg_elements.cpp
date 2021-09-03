#include <bits/stdc++.h>
using namespace std;

vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    int ptr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            swap(nums[ptr], nums[i]);
            ptr++;
        }
    }
    return nums;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        nums = separateNegativeAndPositive(nums);
        for (int i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}