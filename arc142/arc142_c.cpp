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


void solve(){
    ll n, m, k, cnt = 0, sum = 0, ans = 0;
    cin>>n;
    vll a(n);
    vll b(n);
    ll flag=1;
    rep(i,n-2){
        cout<<"? 1 "<<i+3<<endl;
        cout.flush();
        ll x;
        cin>>x;
        if(x==-1) return;
        a[i+2]+=x;
    }
    rep(i,n-2){
        cout<<"? 2 "<<i+3<<endl;
        cout.flush();
        ll x;
        cin>>x;
        if(x==-1) return;
        if(abs(a[i+2]-x)!=1) flag=0;
        b[i+2]+=x;
    }
    ans=INF;
    rep(i,n-2){
        chmin(ans,a[i+2]+b[i+2]);
    }
    ll cntx=-1,cnty=-1;
    rep(i,n-2){
        if(a[i+2]==1) cntx=i+3;
        if(b[i+2]==1) cnty=i+3;
    }
    ll fla=0;
    if(cntx!=-1&&cnty!=-1){
        fla=1;
        cout<<"? "<<cntx<<" "<<cnty<<endl;
        cout.flush();
        ll z;
        cin>>z;
        if(z==3) fla=0;
    }
    if(flag==1&&fla==0) cout<<"! "<<1<<endl;
    else cout<<"! "<<ans<<endl;
    cout.flush();
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