#include<bits/stdc++.h>
#define ll long long
using namespace std;

void getsubsequences(string s,string present,vector<string>& output,int i){
    if(i>=s.length()){
output.push_back(present);
return;
    }
    // // exclude
    // getsubsequences(s,present,output,i+1);
    // //include
    // present.push_back(s[i]);
    // getsubsequences(s,present,output,i+1);
    // can also be written as 
    //include first
     present.push_back(s[i]);
    getsubsequences(s,present,output,i+1);
    present.pop_back();
    //then exclude
    getsubsequences(s,present,output,i+1);
}

void solve(){
ll n;
cin>>n;
string s;
cin>>s;
vector<string> output;
string p="";
getsubsequences(s,p,output,0);
for(auto x:output){
    cout<<x<<endl;
}
cout<<output.size()<<endl;
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