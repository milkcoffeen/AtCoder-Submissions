#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using namespace std;

/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep_up(i, a, n) for (ll i = a; i < n; ++i)
#define rep_down(i, a, n) for (ll i = a; i >= n; --i)
#define P pair<ll, ll>
#define pb push_back
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define endl "\n"

#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define vvvvll vector< vector <vector <vector<ll> > > >
#define vvvll vector< vector< vector<ll> > >
#define vvll vector< vector<ll> >
#define vll vector<ll>
#define pqll priority_queue<ll>
#define pqllg priority_queue<ll, vector<ll>, greater<ll>>

template<class T> inline void vin(vector<T>& v) { rep(i, v.size()) cin >> v.at(i); }
template <class T>
using V = vector<T>;

constexpr ll INF = (1ll << 60);
constexpr ll mod = 1000000007;
//constexpr ll mod = 998244353;

constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
void pt(T val)
{
    cout << val << "\n";
}
template <typename T>
void pt_vll(vector<T> &v)
{
    ll vs = v.size();
    rep(i, vs)
    {
        cout << v[i];

        if (i == vs - 1)
            cout << "\n";
        else
            cout << " ";
    }
}
ll mypow(ll a, ll n)
{
    ll ret = 1;
    if (n == 0)
        return 1;
    if (a == 0)
        return 0;
    rep(i, n)
    {
        if (ret > (ll)(9e18 + 10) / a)
            return -1;
        ret *= a;
    }
    return ret;
}
long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

//ここまでテンプレ

ll rev(ll x){
    vll a;
    while(x>0){
        a.pb(x%10);
        x/=10;
    }
    ll res=0;
    for(auto e:a){
        res*=10;
        res+=e;
    }
    return res;
}

void solve(){
    ll n, m, k, cnt = 0, sum = 0, ans = 0;
    cin>>n>>k;
    if(k>rev(k)){
        pt(0);
        return;
    }
    ll x=k;
    ll y=rev(k);
    rep(i,15){
        if(x>mypow(10,15)||y>mypow(10,15)) break;
        if(x<=n) ans++;
        if(y<=n&&k!=rev(k)) ans++;
        x*=10;
        y*=10;
    }
    pt(ans);
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << fixed << setprecision(16);
    //ll T;
    //cin>>T;
    //rep(ca,T)
    solve();
}   