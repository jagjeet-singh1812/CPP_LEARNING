#include<bits/stdc++.h>
#define ll long long
using namespace std;
// coin exchange value problem



class Solution {
public:
int solve(vector<int>& a,int target,vector<int> &dp){
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }
    if(dp[target]!=-1) return dp[target];
int mini=INT_MAX;
    for(int i=0;i<a.size();i++){
        int ans=solve(a,target-a[i],dp);
        if(ans!=INT_MAX)mini=min(mini,ans+1);
    }
    return dp[target]=mini;
}
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        if( ans==INT_MAX) return -1;
       return ans; 
    }
};



// ---------------------------------------------------------------------------------
int solve(vector<int>& a,int target){
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }
int mini=INT_MAX;
    for(int i=0;i<a.size();i++){
        int ans=solve(a,target-a[i]);
        if(ans!=INT_MAX)mini=min(mini,ans+1);
    }
    return mini;
}

void solve(){
ll n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
cin>>v[i];// distinct element array 
}
int target;
cin>>target;
// ouput minimum n. of elements reqd to make sum equal to target
//You can use the array element any number of times.
cout<<solve(v,target)<<endl;
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
    t=1;

    while(t-- >0)
    {
        solve();
    }
    return 0;
}