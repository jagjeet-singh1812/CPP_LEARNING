#include<bits/stdc++.h>
#define ll long long
using namespace std;

void update(int* ptr){
  cout<<"address of ptr is :"<<&ptr<<endl;// new pointer is made at new address
  cout<<"ptr is pointing to :"<<ptr<<endl;// but points at same loaction
  *ptr=*ptr+10;
}


void update_call_by_refrence(int* &ptr){
  cout<<"address of ptr is :"<<&ptr<<endl;// no new pointer is made at new address
  cout<<"ptr is pointing to :"<<ptr<<endl;//  points at same loaction
  *ptr=*ptr+10;
}
    
    

int main()
{
int kk=5;
int *ptr=&kk;
  cout<<"address of ptr is :"<<&ptr<<endl;
  cout<<"ptr is pointing to :"<<ptr<<endl;
  cout<<"value its pointing to befor function call :"<<kk<<endl;
  update(ptr);
   cout<<"value its pointing to after function call :"<<kk<<endl;
    return 0;
}