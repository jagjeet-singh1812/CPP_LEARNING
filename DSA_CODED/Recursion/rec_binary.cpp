#include<bits/stdc++.h>
#define ll long long
using namespace std;

int binary_search(vector<int> &x,int low,int high,int key){
int mid=(high+low)>>1;//high+(low-high)/2;
if(low>high){
    return -1;
}
if(x[mid]==key){
    return mid;
}
// else if(x[mid]>key){
// return binary_search(x,low,mid-1,key);
// }
// else {
// return binary_search(x,mid+1,high,key);
// }
return (x[mid]>key)?( binary_search(x,low,mid-1,key)):(binary_search(x,mid+1,high,key));
}
void solve(){
ll n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
  int key;
  cin>>key;
 cout<<binary_search(v,0,n-1,key)<<endl;  
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