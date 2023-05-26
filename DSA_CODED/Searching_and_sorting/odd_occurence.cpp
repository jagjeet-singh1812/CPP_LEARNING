#include <bits/stdc++.h>
#define ll long long
using namespace std;
int search(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    int mid=s+(e-s)/2;
    while (s <= e)
    {
        if (s == e) return s; // for single element
        if(mid&1){// odd
          if(v[mid]==v[mid-1]) s=mid+1;
          else e=mid-1;
        }    
        else{// even
           if(v[mid]==v[mid+1]) s=mid+2;
           else e=mid;
        }
        mid=s+(e-s)/2;
    }
    return -1;
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout<<"index is "<<search(v)<<endl;
    cout<<"value is "<<v[search(v)]<<endl;
    return 0;
}