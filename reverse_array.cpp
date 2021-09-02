//Initial Template for C++
//author : Tushar Khanduri [https://github.com/Tushar-K24]
//problem link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << reverseWord(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

//User function Template for C++

string reverseWord(string str)
{
    reverse(str.begin(), str.end());
    return str;
}