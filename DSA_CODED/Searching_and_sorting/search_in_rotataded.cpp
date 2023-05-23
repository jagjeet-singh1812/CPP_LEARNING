#include<iostream>
#include<vector>
using namespace std;
int pivot_search(vector<int>a, int l, int h)
{
    int n=a.size();
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        // corner cases
        if (a[mid] >= a[mid + 1] && mid+1<n)
            return mid;
        if (a[mid] < a[mid - 1] and mid-1>=0)
            return mid - 1;
        if (a[mid] <= a[l] && mid>0)
        {//left search
            h = mid-1 ;
        }
        else
        {
            // right search
            l = mid + 1;
        }
        mid = l + (h - l) / 2;
    }
    return l;
}

int binary_search(vector<int> &v, int low, int high, int key)
{
 while (low <= high)
    {
        int mid = low + (high - low) / 2; 
        if (v[mid] == key)
            return mid;
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return -1;
}
int search(vector<int>& nums, int target) {
  int ans=-1;
  if(nums.size()==2){
            if(nums[0]==target) return 0;
            if(nums[1]==target) return 1;
            else return -1;
        }
  int pivot=pivot_search(nums,0,nums.size()-1);
    if(target>=nums[0] && target<=nums[pivot] && pivot<=nums.size()){
        ans=binary_search(nums,0,pivot,target);
    }
    else {
    ans=binary_search(nums,pivot+1,nums.size()-1,target);
  }
  return ans;
    }