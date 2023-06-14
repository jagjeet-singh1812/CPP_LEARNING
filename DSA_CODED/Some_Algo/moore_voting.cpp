#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
              element=nums[i];
              count=1;
            }
            else if(nums[i]==element) count++;
            else count--;
        }
        //check part
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if(element==nums[i])count2++;
        }
        if(count2>nums.size()/2) return element;
        else return -1;
            
    }
};

void solve(){
ll n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
cin>>v[i];
}
Solution s;
cout<<s.majorityElement(v)<<endl;
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