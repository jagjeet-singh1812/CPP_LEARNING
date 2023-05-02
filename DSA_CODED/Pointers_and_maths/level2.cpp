#include<bits/stdc++.h>
#define ll long long
using namespace std;

void array_pointer(){
int arr[10]={1,12,13,14,895,659,5137,85,955,1510};//statically allocated array
cout<<"base adress is "<<arr<<endl;
// arr is constant pointer
cout<<"SIZE OF ARR IS "<<sizeof(arr)<<endl;;//return whole array size 
cout<<"base adress is "<<&arr<<endl;//this is imp its equal to arr only 
    for(int i=0;i<10;i++){
cout<<"address of "<<i+1<<" th block is"<<&arr[i]<<endl;
    }
    int * p=arr;
    for(int i=0;i<10;i++,p++){
        cout<<"address of "<<i+1<<" th block is"<<p<<endl;
    }
    cout<<"the first value of arr is "<<*(arr+0)<<endl;
    // note *(arr+i) and *arr+i are different things the second one is addition to the value at *arr i.e arr[0]
    cout<<*(arr+2)+2<<endl;
    for(int i=0;i<10;i++){
cout<<"value at "<<i+1<<" th block in the array is "<<*(arr+i)<<endl;
    }
// this also works the same as arr[i] as internal implemtation its converted to *(arr+i) so this will be convt to *(i+arr) so no error
    for(int i=0;i<10;i++){
        cout<<i[arr]<<endl;
    }
}

void char_array(){
char ch[10]="jagjeet";
char * k=ch;
cout<<ch<<endl;//prints whole char array
cout<<&ch<<endl;
cout<<k<<endl;//print the whole char array
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif
    {
        // array_pointer();
        char_array();
    }
    return 0;
}