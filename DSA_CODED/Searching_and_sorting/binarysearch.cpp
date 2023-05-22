#include <iostream>
#include <algorithm> //binary_search is present here
#include <vector>
#define ll long long
using namespace std;
// can be only be applied if sorted or monotonic inc or dec order
int binary_search_my(vector<int> &v, int low, int high, int key)
{ // time complexity-->log(n) where n is size of array
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (v[mid] == key)
            return mid;
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return -1;
}
int findfirstoccurence(vector<int> &v, int low, int high, int key)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (v[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return ans;
}

int findlastoccurence(vector<int> &v, int low, int high, int key)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (v[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int key;
    cin >> key;
    int ans = binary_search_my(v, 0, n - 1, key);
    // inbuilt use
    // if(binary_search(v.begin(),v.end(),key)) cout<<"yes found inbuilt one"<<endl;
    // else cout<<"not found"<<endl;

    // if(binary_search_my)
    // if(ans==-1) cout<<"not found"<<endl;
    // else cout<<"found at "<< ans << " index of the array"<<endl;
    cout << findfirstoccurence(v, 0, n - 1, key) << endl;
    cout << findlastoccurence(v, 0, n - 1, key) << endl;
int totaloccurences=findfirstoccurence(v, 0, n - 1, key)+findlastoccurence(v, 0, n - 1, key) +1;// valid only for sorted array as bs is applied
    // inbuiltfunction
    auto start=lower_bound(v.begin(),v.end(),key);
    auto end=upper_bound(v.begin(),v.end(),key);
    cout<<start-v.begin()<<endl;
    cout<<end-v.begin()<<endl;
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
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}