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
//constexpr ll mod = 1000000007;
constexpr ll mod = 998244353;

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


struct Edge {
    long long to;
    long long cost;
};

#define Graph vector<vector<Edge>>

void dijkstra(const Graph &G, ll s, vector<ll> &dis) {
    ll N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        ll v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

void solve(){
    ll n, m, k, cnt = 0, sum = 0, ans = 0;
    cin>>n>>m;
    Graph G(n+1);
    rep(i,m){
        ll u,v;
        cin>>u>>v;
        G[u].pb({v,1});
        G[v].pb({u,1});
    }
    vll dist(n+1,INF);
    vll dist2(n+1,INF);
    dijkstra(G,1ll,dist);
    dijkstra(G,n,dist2);
    vll an;
    rep(i,n){
        ans=min(dist[n],dist[i+1]+dist2[0]);
        chmin(ans,dist[0]+dist2[i+1]);
        if(ans>=INF/2) ans=-1;
        an.pb(ans);
    }
    pt_vll(an);
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