#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/957710169/
// refer this problem here
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<pair<int,int>>s;
       int i=0;
       int j=1;
       while(j<nums.size()){
           int diff=abs(nums[j]-nums[i]);
           if(diff==k){
               s.insert({nums[i],nums[j]});
               i++;
               j++;
           }
           else if(diff>k){
               i++;
           }
           else{
               j++;
           }
           if(i==j) j++;//to avoid same element collision and calculation 
       }
        return s.size();
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
    int t;
    cin>>t;

    while(t-- >0)
    {
        
    }
    return 0;
}