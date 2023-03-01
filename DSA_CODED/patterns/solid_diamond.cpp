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
    for(int col=0;col<rows+1;col++){
      cout<<"* ";
    }
    cout<<""<<endl;
}

n=n-1;
for(int rows=0;rows<n;rows++){
    // if comment out this loop the inverted right angled triangle
    for(int col=0;col<rows+1;col++){
      cout<<" ";
    }
    for(int space=0;space<n-rows;space++){
        cout<<"* ";
    }
    cout<<""<<endl;
}

} 