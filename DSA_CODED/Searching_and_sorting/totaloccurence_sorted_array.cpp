#include <iostream>
#include <algorithm> //binary_search is present here
#include <vector>
#define ll long long
using namespace std;

int findfirstoccurence(int v[], int low, int high, int key)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (v[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return ans;
}

int findlastoccurence(int v[], int low, int high, int key)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (v[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return ans;
}
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	   if( findlastoccurence(arr,0,n-1,x)==-1) return 0;
	    int ans=findlastoccurence(arr,0,n-1,x)-findfirstoccurence(arr,0,n-1,x)+1;
	    return ans;
	}

    