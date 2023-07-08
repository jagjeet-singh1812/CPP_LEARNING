#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve1(vector<int>&v,int sum,int& maxi,int i){
    if(i>=v.size()){
        maxi=max(maxi,sum);
        return;
    }
    // include
    solve1(v,sum+v[i],maxi,i+2);
    //exclude
    solve1(v,sum,maxi,i+1); 
}
//non adj max sum
void solve(){
ll n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
int maxi=INT_MIN;
int ans=0;
solve1(v,ans,maxi,0);
cout<<maxi<<endl;
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