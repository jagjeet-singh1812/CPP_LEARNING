#include<bits/stdc++.h>
#define ll long long
using namespace std;

// binary indexed tree
// x & -x gives the rightmost set bit
// to remove rightmost set bit we can use x-(x&-x)
struct fenwick_tree
{
    // always consider 1 based index 
    vector<ll> bit;
    void init(vector<ll> x)
    {
        bit.assign(x.size()+1, 0);
        for (int i = 0; i < x.size(); i++)
        {
            update(i+1,x[i]);
        }
    }
    // to get sum from  l to r use this ft.sum(r)-ft.sum(l-1)
    ll sum(ll index)
    {
        ll ans = 0;
        for (; index > 0; index -= (index & -index))//log(n)
        {
            ans += bit[index];
        }
        return ans;
    }
    void update(ll i,ll value){
     for(;i<bit.size();i+=(i&(-i))){
        bit[i]+=value;
     }
    }
};

void solve(){
ll n,q;
cin>>n>>q;
vector<ll>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
fenwick_tree ft;
ft.init(v);
 while(q--){
    int l,r;
    cin>>l>>r;
    if(l==1){
        cout<<ft.sum(r)<<endl;
        continue;
    }
    cout<<ft.sum(r)-ft.sum(l-1)<<endl;
 }
    
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
