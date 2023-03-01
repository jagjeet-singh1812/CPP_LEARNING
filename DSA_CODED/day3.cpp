#include<bits/stdc++.h>
using namespace std;
int main()
{
// bitwise operator
// and --> 1 only when both are 1 (a&b)
// or --> 0 only when both are 0 (a|b)
// not -->negation of number ~(a)
// xor--> (a^b) only 1 when both are different else zero
// xor of same number is 0.
bool a = false;
cout<< (~a) <<endl; //-1 as by 1 s compliment method
bool b = true;
cout<< (~b) <<endl; // -2 by 1's compliment method 
int c =3;
cout<<(c<<1)<<endl; // left shift is multiplying by 2.
cout<<(c>>1)<<endl; // right shift is floor division by 2.
int d=5;
cout<< (++d)*(++d)<<endl; // 49 due to operator precedance.
for(int i=0;i<3;i++){
    cout<<i<<endl;
    break;// terminates the loop/ foofa ji
}
cout<<"done"<<endl;
for(int i=0;i<3;i++){
    if(i==1)continue;// doesn't executes codes after it.used to skip any an iteration/ tau ji
    cout<<i<<endl; 
}
cout<<"done"<<endl;

int val;
cin>>val;
switch(val){
    case 1: cout<<"ha bhai"<<endl;
    cout<<"dhyaan kaha hai"<<endl;
    break; // continue cant be used inside switch statements as its only used to skip an iteration 
    case 2: 
    cout<<"ha bhai 2"<<endl;
    cout<<"dhyaan kaha hai"<<endl;
    break;
    default: cout<<"yo"<<endl;
}

return 0;
}