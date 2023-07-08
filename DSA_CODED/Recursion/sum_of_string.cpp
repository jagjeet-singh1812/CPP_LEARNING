#include<bits/stdc++.h>
#define ll long long
using namespace std;

string add(string& s1,string& s2,int p1,int p2,int c){
if(p1<0 and p2<0){
    if(c!=0){
        return string(1,c+'0');
    }
    return "";
}
//ek case
int n1=(p1>=0?s1[p1]:'0') - '0';
int n2=(p2>=0?s2[p2]:'0') - '0';
int sum=n1+n2+c;
int digit=sum%10;
c=sum/10;
string ans="";
ans.push_back(digit+'0');
ans+=add(s1,s2,p1-1,p2-1,c);
return ans;
}

void solve(){
string s1, s2;
cin>>s1>>s2;
    int c=0;
    string ans=add(s1,s2,s1.length()-1,s2.length()-1,c);
    reverse(ans.begin(),ans.end());
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