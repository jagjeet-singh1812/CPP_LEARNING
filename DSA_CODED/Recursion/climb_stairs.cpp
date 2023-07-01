#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
int dp[10000];
    int climbStairs(int n) {
    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    }
};


void printdigit(ll& n){
    //base case 
    if(n==0) return ;
    printdigit(n/10);
    cout<<n%10<<endl;
}


void printdigit(ll n){
    while(n){
        ll rem=n%10;
        cout<<rem<<" ";
        n=n/10;
    }
}


int climb_stairs(ll n){
  if(n==0||n==1){
    return 1;
  }
  else return climb_stairs(n-1)+climb_stairs(n-2);
}


void solve(){
ll n;
cin>>n;
climb_stairs(n);
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