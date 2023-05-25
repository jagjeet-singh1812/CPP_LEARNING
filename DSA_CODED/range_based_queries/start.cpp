#include<bits/stdc++.h>
using namespace std;
#define int long long
using namespace std;
bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.first>b.first;
}
void solve(){
    int n;
      cin>>n;
      int q;
      cin>>q;
      int a[n];
      for (int i = 0; i < n; i++) {
          cin>>a[i];
      }
      vector<int>count(n,0);
      while(q--)
      {
         int x,y;
        cin>>x>>y;
           count[x-1] += 1;
           if(y-1+1< n)
            count[y-1+1] -= 1;
      }
      for (int i = 1; i < n; ++i)
            count[i] += count[i - 1];
            
      vector<int>ans(n);
      vector<pair<int,int>>v(n);
      for (int i = 0; i <n ; i++) {
         v[i].first=count[i];
         v[i].second=i;
      }
      sort(a,a+n,greater<int>());
      sort(v.begin(),v.end(),comp);
      for(int i=0;i<n;i++)
      {
        ans[v[i].second]=a[i];  
      }
      int res=0;
      for (int i = 0; i < n; ++i)
            res += a[i] *v[i].first;
          
      cout<<res<<"\n";        
      for (int i = 0; i < n; i++) {
          cout<<ans[i]<<" ";
      }
      cout<<"\n";
}

int32_t  main()
{
   int t;
//    cin>>t;
t=1;
   while(t--)
   {
      solve();
   }
   return 0;
}