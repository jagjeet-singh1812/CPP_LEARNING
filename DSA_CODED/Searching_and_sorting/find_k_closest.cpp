// https://leetcode.com/problems/find-k-closest-elements
#include<bits/stdc++.h>
#define ll long long
using namespace std;

//naive approach
class Solution1
 {
public:

static bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        vector<pair<int,int>>diff(arr.size());
        for(int i=0;i<arr.size();i++){
            diff[i].first=arr[i];
            diff[i].second=abs(arr[i]-x);
        }
         stable_sort(begin(diff),end(diff),[x](const auto a, const auto b){
            return a.second<b.second;   // sort by distance from x
        });
         int temp=0;
         for(auto j:diff){
             if(temp<k)ans.push_back(j.first);
             temp++;
         }
         sort(ans.begin(),ans.end());
         return ans;
    }
};//

//two pointer approach soln
class Solution2 {
public:
// O(n-k) approach

vector<int>twopointer(vector<int>& a, int k, int x){
    int h=a.size()-1;
    int l=0;
    while(h-l>=k){
        if(x-a[l]>a[h]-x) l++; //go to right
        else h--;
    }
    return vector<int>(a.begin()+l,a.begin()+h+1);
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      return twopointer(arr,k,x);
    }
};

// bs search approach

class Solution {
public:
    int lowerbound(vector<int>& arr, int x) {
        int l = 0;
        int h = arr.size() - 1;
        int ans = h;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k >= arr.size()) {
            return arr;
        }

        vector<int> result;
        int h = lowerbound(arr, x);
        int l = h - 1;

        while (k > 0) {
            if (l < 0) {
                h++;
            }
            else if (h >= arr.size()) {
                l--;
            }
            else if (x - arr[l] > arr[h] - x) {
                h++;
            }
            else {
                l--;
            }
            k--;
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }
};


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
    return 0;
}