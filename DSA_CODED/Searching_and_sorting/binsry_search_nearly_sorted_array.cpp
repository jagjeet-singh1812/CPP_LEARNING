#include<bits/stdc++.h>
#define ll long long
using namespace std;

// almost sorted array is whose i th element can be at i,i+1,i-1;
int binary_search_nearly_sorted(vector<int> &v, int low, int high, int key)
{ // time complexity-->log(n) where n is size of array
    while (low <= high)
    {
    int mid = low + (high - low) / 2; // to avoid overflow
     if(v[mid]==key){
     return mid;
     }
     if(mid > low &&v[mid-1]==key){
     return mid-1;
     }
     if(v[mid+1]==key && mid <high){
     return mid+1;
     }
        else if (key < v[mid])
        {
            high = mid - 2;// as mid-1 is already checked above
        }
        else if (key > v[mid])
        {
            low = mid + 2;// as mid +1 is already checked above
        }
    }
    return -1;
} 
// input:
// 5 
// 3 2 1 4 5
// 1
// ouput : 2
int main()
{
 int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int key;
    cin >> key;
    int ans = binary_search_nearly_sorted(v, 0, n - 1, key);
    cout<<ans<<endl;
    return 0;
}