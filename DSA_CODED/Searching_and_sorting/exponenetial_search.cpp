//also know as doubling / galloping/stazile search
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//you are given a sorted array and find some elment but its time complexity is optimized of binary search
// applied when array size is too large
// its time complexity is O(log i) where i is stopping point 
// application
// search in infinite array
// better in unbounded array

// -------------------------------------------------------------------------------------------------
// https://leetcode.com/discuss/interview-experience/1979273/infinite-sorted-array refer thhis
//----------------------------------------------------------------------------------------------------

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

int exponential_search(vector<int>&arr,int key){
    if(arr[0]==key){
        return 0;
    }
    int i=1;
    int n=arr.size()-1;
    while(arr[i]<=key){
        i=i<<1;
    }
    return binary_search_my(arr,i/2,min(i,n-1),key);
}

int exponential_search_infinite_array(vector<int>&arr,int key){
    if(arr[0]==key){
        return 0;
    }
    int low=0;
    int high=1;
    int n=arr.size()-1;
    while(arr[high]<=key){
        low=high;
        high=high*2;
    }
    return binary_search_my(arr,low,high,key);
}
void solve(){
ll n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
int target;
cin>>target;
cout<<"index is "<<exponential_search(v,target);
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
    cin>>t;

    while(t-- >0)
    {
        solve();
    }
    return 0;
}