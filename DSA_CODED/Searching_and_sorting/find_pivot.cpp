#include <bits/stdc++.h>
#define ll long long
using namespace std;
// basically find the changing  point
int search(vector<int>a, int l, int h)
{
    // l: The starting index
    // h: The ending index, you have to search the key in this range
    // complete the function here
    int n=a.size();
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        // corner cases
        if (a[mid] >= a[mid + 1] && mid+1<n)
            return mid;
        if (a[mid] < a[mid - 1] and mid-1>=0)
            return mid - 1;
        if (a[mid] <a[l] && mid>0)
        {//left search
            h = mid-1 ;
        }
        else
        {
            // right search
            l = mid + 1;
        }
        mid = l + (h - l) / 2;
    }
    return l;
}

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        cout.tie(NULL);
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);

#endif
        int t;
        // cin>>t;
        t = 1;
        vector<int>v {1,3};
        while (t-- > 0)
        {
            int ans = search(v, 0, v.size()-1);
            cout<<"pivot index found at: "<<ans<<endl;// ans is 0 index
        }
        return 0;
    }
    