#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int n,int x,int y,int z){
if(n==0){
    return 0;
}
if(n<0){
    return INT_MIN;
}
int a=solve(n-x,x,y,z);
int b=solve(n-y,x,y,z);
int c=solve(n-z,x,y,z);
return max(a,max(b,c));
}
void solve(){
ll n;
cin>>n;
ll x,y,z;
cin>>x>>y>>z;
int ans=solve(n,x,y,z);
if(ans<0) ans=0;
cout<<ans<<endl;  
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