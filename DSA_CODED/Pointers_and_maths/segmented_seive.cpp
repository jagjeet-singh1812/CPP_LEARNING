#include<bits/stdc++.h>
using namespace std;
vector<bool>Sieve(long long n){
    // Create a sieve
    vector<bool>sieve(n+1,true); // Mark every number as prime initially
    sieve[0] = sieve[1] = false; // As 0 and 1 are not prime
    // Optimization - 2 => Changing the outer for loop
    for(long long i = 2;i<=sqrt(n);i++){ // 2 will be the first prime number
        if(sieve[i] == true){ 
            // long long j = i*2; 
            // Optimization - 1
            long long j = i * i;
            while(j<=n){
                sieve[j] = false; // Mark multiples of prime number as non prime
                j  += i;
            }
        }
    }
    return sieve;
}
vector<bool>segSieve(long long L,long long R){
    // Using prime array to mark segmented sieve
    vector<bool>sieve = Sieve(sqrt(R));
    vector<long long>basePrimes;
    // Step - 2
    for(long long i = 0;i<sieve.size();i++){
        if(sieve[i]  == true){
            // It is prime so push back in base primes
            basePrimes.push_back(i);
        }
    }
    // Step - 1
    // for(auto k:basePrimes) cout<<k<<" ";
    cout<<endl;
    vector<bool>segSieve(R-L+1,true);
    // Base Condition
    if(L == 1 || L == 0){
        segSieve[L] = false;
    }
    // Step - 3
    for(auto prime:basePrimes){
        long long first_mul = (L/prime) * prime;
        if(first_mul < L){
            first_mul = first_mul + prime;
        }
        long long j = max(first_mul,prime*prime); // Might be case that first_mul may be marked already
        // Exactly same loop as normal sieve
        while(j<=R){
            segSieve[j - L] = false; // Resemblance thing as 0th index is mapped to 110
            j = j + prime;
        }
    }
    return segSieve;
}
int main(){
    long long L,R;
  cin>>L>>R;
    vector<bool>segmentedSieve = segSieve(L,R);
    for(long long i = 0;i<segmentedSieve.size();i++){
        if(segmentedSieve[i]){
            cout<<i+L<<" ";
        }
    }
return 0;
}