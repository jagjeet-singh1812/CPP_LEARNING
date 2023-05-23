#include <iostream>
#include <vector>
using namespace std;
    int find_sqrt(int key)
    {
        int low = 0;
        int high = key;
        int ans;
        while (low <= high)

        {
            long long int mid = low + (high - low) / 2; // to avoid overflow
            if (mid * mid == key)
                return mid;
            else if (key < mid * mid)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
    int main()
    {
        int x;
        cin>>x;
        int ans = find_sqrt(x);
        int precision;
        cout << "enter digit upto precision you want" << endl;
        cin >> precision;
        double final_ans=ans;
        double step=0.1;
        for(int i=0;i<precision;i++){
          for(double j=final_ans;j*j<x;j+=step){
            final_ans=j;
          }
          step/=10;
        }
        cout<<"final ans is "<<final_ans<<endl;
    }
