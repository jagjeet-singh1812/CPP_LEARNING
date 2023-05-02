// #include<bits/stdc++.h>
#include<iostream>
#include<string>
#define ll long long
using namespace std;
// string is a data type and char arr is a data structure
void solve(){
string s;
// cin>>s;
getline(cin,s);//for taking input with spaces
// in strings we cant acsses it null character appende at end for temination of string
if(s.empty()){
    cout<<"empty string"<<endl;
}
else{
cout<<s<<endl;
}
s.push_back('x');
cout<<s<<endl;
s.pop_back();
cout<<s<<endl;
cout<<s.substr(0,3)<<endl;// imp
string a="hello toh kaise hai aap logh";
string b="tohj3f";
if(a.find(b)==string::npos){
    cout<<"not found"<<endl;
}
else{
cout<<a.find(b)<<endl;
}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
    return 0;
}