#include<bits/stdc++.h>
#define ll long long
using namespace std;
class segtree{
    vector<ll>seg;
public:
    segtree(ll n){
     seg.resize(4*n+1);
    }
void build(ll ind,ll low,ll high, vector<ll>&arr,int orr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    ll mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,!orr);
    build(2*ind+2,mid+1,high,arr,!orr);
    if(orr) seg[ind]=seg[2*ind+2]|seg[2*ind+1];
    else seg[ind]=seg[2*ind+2]^seg[2*ind+1];
}
ll query(ll ind,ll low,ll high,ll l,ll r){
if(r<low || l>high){
    return INT_MAX;
}
if(low>=l && high<=r){
 return seg[ind];
}
ll mid=(low+high)>>1;
ll left=query(2*ind+1,low,mid,l,r);
ll right=query(2*ind+2,mid+1,high,l,r);
return min(left,right);
}
ll update(ll ind,ll low,ll high,ll i,ll val,int orr){
    if(low==high){
        seg[ind]=val;
        return 1ll;
    }
    ll mid=(high+low)>>1;
    if(i<=mid) update(2*ind+1,low,mid,i,val,!orr);
    else update(2*ind+2,mid+1,high,i,val,!orr);
   if(orr) seg[ind]=seg[2*ind+2]|seg[2*ind+1];
    else seg[ind]=seg[2*ind+2]^seg[2*ind+1];
    return seg[0];
}
};


void solve(){
ll k,q;
cin>>k>>q;
int n=1<<k;
vector<ll>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
segtree st(n);
if(k&1){// start with or
st.build(0,0,n-1,v,1);
}
else{// start with xor
st.build(0,0,n-1,v,0);
}
while(q--){
    ll i,val;
    cin>>i>>val;
    i=i-1;//1 based
    if(k&1){
      cout<<st.update(0,0,n-1,i,val,1)<<endl;
    }
    else{
       cout<<st.update(0,0,n-1,i,val,0)<<endl;
    }
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