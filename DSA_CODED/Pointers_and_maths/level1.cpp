#include<bits/stdc++.h>
#define ll long long
using namespace std;

// need of pointer
// dynamic memory allocation.
void solve(){
// pointers --> its a variable which used for storing the address of other variable(block).
// size of pointer of any data type is 4 bytes(32 bit compiler) or 8 bytes (64 bit compiler) depends upon aritechture of system.(why?)
// symbol table stores the mapping of variable and its addresses.
// addresses are in hexadecimal form.
int a=5;
int b=7;
int *ptr=&a;
// * is defrencing operator.
// & is address operator.
cout<<&a<<endl;
cout<<&b<<endl;
cout<<ptr<<endl;
int aa=5;
// pointer creation
int *x=&aa;
cout<<"address of aa is "<<&aa<<endl;
cout<<"x is pointing on "<<x<<endl;
cout<<"value at address x using derefrencing operator : "<<*x<<endl;
cout<<"address of x is "<<&x<<endl;
cout<<"size of integer pointer is "<<sizeof(x)<<endl;

char temp='b';
char *t=&temp;
cout<<"size of char pointer is "<<sizeof(t)<<endl;

double tempo=123.456;
double *to=&tempo;
cout<<"size of double pointer is "<<sizeof(to)<<endl;

// int* kk; bad pratice 
//segmentation fault may occur so use null pointer
//null pointer
int* kk=nullptr;
cout<<"unintializd pointer refrencing: "<<kk<<endl;


// pointer addition
 int aaa=5;
int * te=&aaa;
cout<<"before te is pointing to "<<*te<<endl;
*te=*te+1;
cout<<"after  te is pointing to "<<*te<<endl;
// cout<<aaa<<endl;

//copying a pointer
int aaaa=7;
int* tt= &aaaa;
//copy of a pointer
int* copy=tt;
cout<<*copy<<endl;
cout<<"adress of copy"<<&copy<<endl;
cout<<*tt<<endl;
cout<<"address of tt"<<&tt<<endl;


}
    
    //making of 2-d array using pointers
    //     int **board = new int*[n];
    // for(int i = 0; i < n; i++){
    //     board[i] = new int[n];
    //     for(int j = 0; j < n; j++){
    //         board[i][j] = 0;
    //     }
    // }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif


    {
        solve();
    }
    return 0;
}