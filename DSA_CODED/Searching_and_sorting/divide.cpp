#include <bits/stdc++.h>
#define ll long long
using namespace std;
int divide(int divident, int divisor)
{
    if (divident == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    if (divisor == 1)
        return divident;
    ll s = 1;
    ll e = abs(divident);
    ll ans = 0;
    ll mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (abs(mid * divisor) == abs(divident))
        {
            ans = mid;
            break;
        }
        else if (abs(mid * divisor) > abs(divident))
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    if (divident < 0 and divisor < 0 || divident > 0 and divisor > 0)
        return ans;
    else
        return -ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout.tie(NULL);
    int x, y;
    cin >> x >> y;
    cout << divide(x, y) << endl;
    return 0;
}