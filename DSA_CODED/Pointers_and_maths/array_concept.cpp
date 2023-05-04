#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int a[]){
    //as array as passed by default as  call by refrence i.e pointer is passed 
cout<<"size inside function :"<<sizeof(a)<<endl;//8
cout<<"arr i.e base addrres : "<< a<<endl;
a[3]=8;
}

void update(int* ptr){
  cout<<"address of ptr is :"<<&ptr<<endl;
  cout<<"ptr is pointing to :"<<ptr<<endl;
  *ptr=*ptr+10;
}
    


int main()
{
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // freopen("error.txt", "w", stderr);
// #endif
    int a[10]={1,4,5,6};// if a single value is entered then whole array is initialized to zero as *(arr+i) and *(i+arr) are same 
        cout<<2[a]<<" "<<a[2]<<" as both are same "<<endl;
              for(int i=0;i<10;i++){
          cout<<a[i]<<" ";
        }
        cout<<endl;
        solve(a);
        cout<<"size outside function :"<<sizeof(a)<<endl;//40
        for(int i=0;i<10;i++){
          cout<<a[i]<<" ";
        }
        cout<<endl;


    return 0;
}