#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution 

{
    public:
    bool isPossible(int A[],int n,int m,int mid){
        int student_count=1;
        int current_sum=0;
        for(int i=0;i<n;i++){
            if(A[i]>mid){
                return false;
            }
            if(current_sum+A[i]>mid){
                student_count++;
                current_sum=0;
                current_sum+=A[i];
                if(student_count>m){
                    return false;
                }
            }
            else{
                current_sum+=A[i];
            }
        }
    return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int no_of_book, int no_of_student) 
    {
        if(no_of_book<no_of_student){
            return -1;
        }
        int start=0;
        int end=accumulate(A,A+no_of_book,0);//O(n)
        int ans=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(A,no_of_book,no_of_student,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
// tc->O(log(sum of book pages-max_allocated)).
void solve(){
ll n,m;
cin>>n>>m;
int v[n];
for(int i=0;i<n;i++){
cin>>v[i];
}
Solution s;
cout<<s.findPages(v,n,m)<<endl;
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