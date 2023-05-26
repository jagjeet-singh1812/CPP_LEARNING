#include<bits/stdc++.h>
#define ll long long
using namespace std;
class info{
public:
ll close=0,open=0,full=0;

public:
info(ll _close,ll _open,ll _full){
close=_close;
open=_open;
full=_full;
}
info(){
    close=0;
    open=0;
    full=0;
}
};

class segg{
vector<info>seg;
public :
segg(ll n){
    seg.resize(4*n);
}
info merge(info left,info right){
    info ans=info();
    ans.full=left.full+right.full+min(left.open,right.close);
    ans.open=left.open+right.open-min(left.open,right.close);
    ans.close=left.close+right.close-min(left.open,right.close);
    return ans;
}

void build(ll ind,ll low,ll high ,string &s){
    if(low>high) return ;
if(low==high){
    (s[low]=='(')?(seg[ind].open= 1):(seg[ind].open=0);
    (s[low]==')')?(seg[ind].close= 1):(seg[ind].close=0);

    return ;
}
ll mid=(high+low)>>1;
build(2*ind+1,low,mid,s);
build(2*ind+2,mid+1,high,s);
seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}


info query(ll ind,ll low,ll high,ll l,ll r){
if(l>high || r<low){ 
  return info();
  }
if(low>=l && high<=r) return seg[ind];
ll mid=(low+high)>>1;
info left=query(2*ind+1,low,mid,l,r);
info right=query(2*ind+2,mid+1,high,l,r);
info ans=merge(left,right);
return ans;
}
};

void solve(){
string s;
cin>>s;
ll q;
cin>>q;
ll n=s.length();
segg t(n);
t.build(0,0,n-1,s);
while(q--){
    ll l,r;
    cin>>l>>r;
    l--;
    r--;
    info ans=t.query(0,0,n-1,l,r);
    cout<<ans.full*2<<endl;
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
    {
        solve();
    }
    return 0;
}