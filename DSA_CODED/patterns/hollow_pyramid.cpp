#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
int n; 
cout<<"enter number of rows"<<endl;
cin>>n;
for(int rows=0;rows<n;rows++){
    for(int space=0;space<n-rows-1;space++){
        cout<<" ";
    }
    for(int col=0;col<2*rows+1;col++){
        if(col==0 || col==2*rows){
         cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<""<<endl;
}

// n=n-1;
for(int rows=n;rows>=0;rows--){
    for(int col=0;col<n-rows;col++){
      cout<<" ";
    }
    for(int col=0;col<2*rows-1;col++){
         if(col==0 || col==2*rows-2){
         cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<""<<endl;
}

} 