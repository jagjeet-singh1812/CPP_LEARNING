#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long int
/**
 *ASCII VALUES
 *[0, 9] --> [48, 57]
 *[A, Z] --> [65, 90]
 *[a, z] --> [97, 122]
 */
//constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 2e5 + 2;
using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define ull unsigned long long
#define lld long double
#define pb push_back
#define mp make_pair
// #define mod 1e9+7;
#define enld endl
#define PI 3.1415926535897932384626
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define triplet pair<ll, pair<ll, ll>>
#define pp pair<ll, ll>
#define endl "\n"
#define ff first
#define ss second
#define sp(x, y) fixed << setprecision(y) << x
#define hmap unordered_map
#define hset unordered_set
#define haa cout << "YES" << endl
#define nahi cout << "NO" << endl
#define pf(x) cout << x << endl
#define sz(x) (long long int)x.size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<ll> vl;
typedef vector<vl> vvl;

// Loops-
#define fn(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) // Normal for
#define fo(i, n) for (int i = 0; i < n; i++)             // initialized to 0
#define feach(a, b) for (auto &(a) : (b))                // for maps using auto

// custom hash for unordered hmap,hset
struct chash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//debugger
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//overloaded
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
 
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second << ", ");
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

