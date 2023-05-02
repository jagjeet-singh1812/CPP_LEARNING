#include<bits/stdc++.h>
using namespace std;
// hashing is assigning a number to any data structure
// prob of no of collision inc bad hash
// worst hashing fuction is which return a constant number 
// polynomial hash ab= 1*pow(26,1)+2*(pow(26,0) so similar to binary but base is 26 or greater than use 31 
// there is an issue with 26(blackbox it) and use prime no. 31
// to reduce collision use double hashing or use prefix hashes
// https://cp-algorithms.com/string/string-hashing.html#calculation-of-the-hash-of-a-string
int count_unique_substrings(string const& s) {
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
long long compute_hash(string &s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long h=0;
    long long p_pow = 1;
    for (char c : s) {
        // hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        // p_pow = (p_pow * p) % m;
        h=(h*31+(c-'a'+1))%m;
    }
    return h;
    // return hash_value;
}
int main(){
string s1,s2;
cin>>s1>>s2;
if(compute_hash(s1)==compute_hash(s2)) cout<<0<<endl;
cout<<compute_hash(s1)<<compute_hash(s2)<<endl;
return 0;
}