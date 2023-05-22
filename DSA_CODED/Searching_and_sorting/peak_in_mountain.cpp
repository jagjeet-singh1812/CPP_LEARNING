// An array arr a mountain if the following properties hold:
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
// You must solve it in O(log(arr.length)) time complexity.
// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// brute force soln
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& a) {
//         int up=0;
//         int down=0;
//         int ans=-1;
//         int n=a.size()-1;
//         for(int i=0;i<n;i++){
//             if(a[i]<a[i+1]){
//              up++;
//             }
//             if(a[i]>a[i+1] && up){
//                 ans=i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };

// binary serach method
#include<iostream>
#include<vector>
using namespace std;
 int peakIndexInMountainArray(vector<int>& arr) {
         ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
int s=0;
int e=arr.size()-1;
   int mid=s+(e-s)/2;
while(s<e){
    //if inc line so search iin righ side i.e move towards the peak
    if(arr[mid]<arr[mid+1]) s=mid+1;
    // so at p or line i.e decreasing
    else e=mid;
    mid=s+(e-s)/2;
}
return s;
// return e;
    }