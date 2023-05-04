#include <bits/stdc++.h>
#define ll long long
using namespace std;
// o(n) approach
bool CheckPrime_naive(ll x)
{
    if (x == 2)
        return true;
    else
    {
        if (x == 1)
            return false;
        else
        {
            ll done = 0;
            for (ll i = 2; i < x; i++)
            {
                if (x % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
// sqrt (n) approach
bool CheckPrime_updated_sqrt(ll x)
{
    if (x == 2)
        return true;
    else
    {
        if (x == 1)
            return false;
        else
        {
            ll done = 0;
            for (ll i = 2; i <= sqrtl(x); i++)
            {
                if (x % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}

void seive_of_eratosthenes(int x)
{
    int count_primes = 0;
    vector<bool> all_primes(x, true);
    all_primes[0] = all_primes[1] = false;
    for (int i = 2; i <= x; i++)
    {
        // we can go from sqrt(n) for better optimization in upper loop
        if (all_primes[i] && i * 1LL * i <= x)
        {
            count_primes++;
            for (int j = i * i; j <= x; j += i)
            {
                all_primes[j] = false;
            }
        }
    }
    cout<<"no of primes in range 1-(n-1) are"<<2*count_primes<<endl;
}
// tc--->n(log(log(n)))
int countPrimes(int x) {
    if(x==0) return 0;
    int count_primes = 0;
    vector<bool> all_primes(x, true);
    all_primes[0] = all_primes[1] = false;
    for (int i = 2; i < x; i++)//n
    {
        if (all_primes[i])
        {
            count_primes++;
            int j=2*i;
            while(j<x){
                all_primes[j] = false;
                j+=i;
            }
        }
    }
    return count_primes;
    }

void naive_prime_count(ll n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (CheckPrime_naive(i))
            c++;
    }
    cout << "the number of prime is: " << c << endl;
}


int gcd(int a,int b){
if(a==0){
    return b;
}
if(b==0){
    return a;
}
else if(a>b){
    return gcd(a-b,b);
}
else if(b>a){
  return gcd(b-a,a);
}
}

int lcm(int a,int b){
    return gcd(a,b)/a*b;
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cout << "enter the range i.e to 1-(n-1)" << endl;
    cin >> n;
    naive_prime_count(n);
    seive_of_eratosthenes(n); 
    cout<<__gcd(24,72)<<endl;// also know as hcf
    cout<<gcd(24,72)<<endl;
    
    return 0;
}