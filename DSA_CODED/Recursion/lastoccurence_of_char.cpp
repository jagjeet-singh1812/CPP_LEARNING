#include<bits/stdc++.h>
#define ll long long
using namespace std;
void lastocc(string s,int i,int& ans1,int& ans2,char& x,bool& a){
if(i>=s.length()){
    return ;
}
if(s[i]==x){
    if(!a){
        ans1=i;
        a=true;
    }
    else{
            ans2=i;
        }
}
lastocc(s,i+1,ans1,ans2,x,a);
}
void solve(){
string s;
cin>>s;
int f=-1;
int l=-1;
int i=0;
char finder;
cin>>finder;
bool x=false;
lastocc(s,i,f,l,finder,x);
if(l==-1 and f!=-1){
    l=f;
}
else if(l==-1 and f==-1){
cout<<-1<<endl;
return ; 
}
cout<<f<<" "<<l<<endl;
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