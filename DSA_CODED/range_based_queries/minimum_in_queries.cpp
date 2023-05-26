#include<bits/stdc++.h>
#define ll long long
using namespace std;

// segment tree
class segtree{
    vector<ll>seg;
public:
    segtree(ll n){
     seg.resize(4*n+1);
    }
void build(ll ind,ll low,ll high, vector<ll>&arr){
    if(low==high){// base codition
        seg[ind]=arr[low];
        return;
    }
    ll mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=min(seg[2*ind+2],seg[2*ind+1]);
}

ll query(ll ind,ll low,ll high,ll l,ll r){
if(r<low || l>high){// no overlap codition i.e l r low high or low high l r
    return INT_MAX;
}
// complete overlap l low high r
if(low>=l && high<=r){
 return seg[ind];
}
//partial overlap case is this 
ll mid=(low+high)>>1;
ll left=query(2*ind+1,low,mid,l,r);
ll right=query(2*ind+2,mid+1,high,l,r);
return min(left,right);
}


void update(ll ind,ll low,ll high,ll i,ll val){
    if(low==high){
        seg[ind]=val;
        return ;
    }
    ll mid=(high+low)>>1;
    if(i<=mid) update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
   seg[ind]=min(seg[2*ind+2],seg[2*ind+1]);
}


};


void solve(){
ll n,q;
cin>>n>>q;
vector<ll>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
segtree st(n);
st.build(0,0,n-1,v);
// cout<<seg[5]<<endl;
while(q--)
{
    char type;
    cin>>type;
    if(type=='q'){//as query wala thing
    ll l,r;
    cin>>l>>r;
    l=l-1;// as 0 based seg tree
    r=r-1;// as 0 based seg tree
    cout<<st.query(0,0,n-1,l,r)<<endl;
    }
    else {
        ll i,val;
        cin>>i>>val;
        i=i-1;// as 0 based seg tree
        st.update(0,0,n-1,i,val);
        v[i]=val;
    }
}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    {
        solve();
    }
    return 0;
}
