#include <iostream>
#include <algorithm> //binary_search is present here
#include <vector>
#define ll long long
using namespace std;
 bool searchMatrix(vector<vector<int>>& arr, int target) {
        //binary search
    int row = 0;
    int col = arr[row].size() - 1;
    while (row < arr.size() && col >= 0) {
        if (arr[row][col] == target) {
            return true;
        }
        // Target lies in further row
        if (arr[row][col] < target) {
            row++;
        }
        // Target lies in previous column
        else {
            col--;
        }
    }
        return false;
    }


    vector<int> findAns(vector<vector<int> > arr, int target)
{
  int row = arr.size();
  int col = arr[0].size();
  int l = 0, h = row * col - 1;
 
  while (l <= h) {
    int mid = l + (h - l) / 2;
 
    int tC = mid % col;
    int tR = mid / col;
    int val = arr[tR][tC];
    if (val == target)
      return { tR, tC };
 
    if (val < target)
      l = mid + 1;
    else
      h = mid - 1;
  }
 
  return { -1, -1 };
}