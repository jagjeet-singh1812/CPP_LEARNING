#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++)cin>>v[i];
int key;
cin>>key;
for(int i=0;i<n;i++){//O(n) complexity
    if(v[i]==key) {
        cout<<"found"<<endl;
        return;
    }
}
cout<<"not found"<<endl;
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
    t=1;

    while(t-- >0)
    {
        solve();
    }
    return 0;
}