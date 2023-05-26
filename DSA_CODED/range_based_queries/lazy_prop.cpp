#include<bits/stdc++.h>
#define ll long long
using namespace std;

// segment tree
class lazy_seg{
    vector<ll>seg,lazy;
public:
    lazy_seg(ll n){
     seg.resize(4*n+1);
     lazy.resize(4*n+1);
    }
void build(ll ind,ll low,ll high, vector<ll>&arr){
    if(low==high){// base codition
        seg[ind]=arr[low];
        return;
    }
    ll mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=seg[2*ind+2]+seg[2*ind+1];
}

ll query(ll ind,ll low,ll high,ll l,ll r){

if(lazy[ind]!=0){//if update reamining then update it to fresh as ans is calculated down
     seg[ind]+=(high-low+1)*lazy[ind];
     //propogate downwards for remainig nodes
     if(low!=high){
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];
     }
   lazy[ind]=0;
    }

if(r<low || l>high){// no overlap codition i.e l r low high or low high l r
    return 0;
}
// complete overlap l low high r
if(low>=l && high<=r){
 return seg[ind];
}
//partial overlap case is this 
ll mid=(low+high)>>1;
ll left=query(2*ind+1,low,mid,l,r);
ll right=query(2*ind+2,mid+1,high,l,r);
return left+right;
}


void update(ll ind,ll low,ll high,ll l,ll r,ll val){

    if(lazy[ind]!=0){//if update reamining
     seg[ind]+=(high-low+1)*lazy[ind];
     //propogate downwards for remainig nodes
     if(low!=high){
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];
     }
   lazy[ind]=0;
    }

    //no overlap case i.e l r low high || low high l r
    if(r<low || high<l){
        return;
    }
    //complete overlap
if(low>=l && high<=r){
 seg[ind]+=(high-low+1)*val;
 if(low!=high){// i.e its not last/end node or to ensure it has child node 
lazy[2*ind+1]+=val;
lazy[2*ind+2]+=val;
 }
 return;
}
//partial overlap case
    ll mid=(high+low)>>1;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);
   seg[ind]=seg[2*ind+2]+seg[2*ind+1];
}


};

// class lazy_seg {
// 	vector<ll> seg, lazy; 
// public: 
// 	lazy_seg (ll n) {
// 		seg.resize(4 * n); 
// 		lazy.resize(4 * n); 
// 	}
// public: 
// 	void build(ll ind, ll low, ll high, vector<ll>arr) {
// 		if(low == high) {
// 			seg[ind] = arr[low];
// 			return; 
// 		}
// 		ll mid = (low + high) >> 1; 
// 		build(2*ind+1, low, mid, arr); 
// 		build(2*ind+2, mid+1, high, arr); 
// 		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
// 	}
// public:
// 	void update(ll ind, ll low, ll high, ll l, ll r, 
// 		ll val) {
// 		// update the previous remaining updates 
// 		// and propogate downwards 
// 		if(lazy[ind] != 0) {
// 			seg[ind] += (high - low + 1) * lazy[ind]; 
// 			// propogate the lazy update downwards
// 			// for the remaining nodes to get updated 
// 			if(low != high) {
// 				lazy[2*ind+1] += lazy[ind]; 
// 				lazy[2*ind+2] += lazy[ind]; 
// 			}
 
// 			lazy[ind] = 0; 
// 		}
 
// 		// no overlap 
// 		// we don't do anything and return 
// 		// low high l r or l r low high 
// 		if(high < l or r < low) {
// 			return; 
// 		}
 
// 		// complete overlap 
// 		// l low high r 
// 		if(low>=l && high <= r) {
// 			seg[ind] += (high - low + 1) * val; 
// 			// if a leaf node, it will have childrens
// 			if(low != high) {
// 				lazy[2*ind+1] += val; 
// 				lazy[2*ind+2] += val; 
// 			}
// 			return; 
// 		}
// 		// last case has to be no overlap case
// 		ll mid = (low + high) >> 1; 
// 		update(2*ind+1, low, mid, l, r, val);
// 		update(2*ind+2, mid+1, high, l, r, val); 
// 		seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 
// 	}
// public: 
// 	ll query(ll ind, ll low, ll high, ll l, ll r) {
 
// 		// update if any updates are remaining 
// 		// as the node will stay fresh and updated 
// 		if(lazy[ind] != 0) {
// 			seg[ind] += (high - low + 1) * lazy[ind]; 
// 			// propogate the lazy update downwards
// 			// for the remaining nodes to get updated 
// 			if(low != high) {
// 				lazy[2*ind+1] += lazy[ind]; 
// 				lazy[2*ind+2] += lazy[ind]; 
// 			}
 
// 			lazy[ind] = 0; 
// 		}
 
// 		// no overlap return 0; 
// 		if(high < l or r < low) {
// 			return 0; 
// 		}
 
// 		// complete overlap 
// 		if(low>=l && high <= r) return seg[ind]; 
 
// 		ll mid = (low + high) >> 1; 
// 		ll left = query(2*ind+1, low, mid, l, r);
// 		ll right = query(2*ind+2, mid+1, high, l, r);
// 		return left + right; 
// 	}
// };


void solve(){
ll n,q;
cin>>n>>q;
vector<ll>v(n);
for(ll i=0;i<n;i++){
cin>>v[i];
}
lazy_seg st(n);
st.build(0,0,n-1,v);
// cout<<seg[5]<<endl;
while(q--)
{
    int type;
    cin>>type;
    if(type==0){//as query wala thing
    ll l,r;
    cin>>l>>r;
    l=l;// as 0 based seg tree
    r=r;// as 0 based seg tree
    cout<<st.query(0,0,n-1,l,r)<<endl;
    }
    else {// lazy prop from l to r
        ll l,r,val;
        cin>>l>>r>>val;
        l=l-1;// as 0 based seg tree
        r=r-1;// as 0 based seg tree
        st.update(0,0,n-1,l,r,val);
    }
}
}

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    {
        solve();
    }
    return 0;
}
