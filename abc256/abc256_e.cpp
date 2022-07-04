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

struct UnionFind {
    vector<ll> par,size;

    UnionFind(ll N) : par(N) { //最初はすべてが根であるとして初期化
        size.resize(N,1);
        for(ll i=0;i<N;i++) par[i] = i;
    }

    ll root(ll x){ //データxの木の根を再帰で得る
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y){ //xとyの木を併合
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return; //同じ木にあるときはそのまま
        if(size[rx]>size[ry]){
            par[ry]=rx;
            size[rx] += size[ry];
        }else{
            par[rx] = ry;
            size[ry] += size[rx];
        }
        return;
    }

    bool same(ll x, ll y){ //2つのデータx,yが属する木が同じならtrue
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll treesize(ll x){return size[root(x)];}
};

void solve(){
    ll n, m, k, cnt = 0, sum = 0, ans = 0;
    cin>>n;
    vll a(n);
    vll c(n);
    vin(a);
    vin(c);
    UnionFind uf(n);
    V<pair<ll,P>> p; 
    rep(i,n){
        p.pb({c[i],{i,a[i]-1}});
    }
    sort(all(p),greater<pair<ll,P>>());
    rep(i,n){
        ll x=p[i].se.fi;
        ll y=p[i].se.se;
        if(uf.same(x,y)){
            ans+=p[i].fi;
        }
        uf.unite(x,y);
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