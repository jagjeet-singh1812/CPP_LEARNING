#include<bits/stdc++.h>
#define ll long long
using namespace std;//

int f(int n){
    if(n==0||n==1){
        return 1;
    }
    else return f(n-1)+f(n-2);
}

//recurcive soln for printiing array 
// T(n)=k+T(n-1);
// so t(n)=nk+k1==>O(n)
// and space complexity is also O(n).
void printarray(int a[],int n){
    if(n==0) return;
    cout<<*a<<endl;
    printarray(a+1,n-1);
}

void solve(){
ll n;
cin>>n;
vector<ll>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
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