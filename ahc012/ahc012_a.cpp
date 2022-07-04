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
ll n;
vll a(10);
vll x;
vll y;
ll resa=0;
ll X,Y,XX,YY;


ll score_cal(vll &C, vll &D, ll opt){
    XX=0;
    YY=0;
    rep(i,X){
        if(C[i]<INF/2) XX++;
    }
    rep(i,Y){
        if(D[i]<INF/2) YY++;
    }
    vvll su(XX+1,vll(YY+1));
    rep(i,n){
        ll t=lower_bound(all(C),x[i])-C.begin();
        ll s=lower_bound(all(D),y[i])-D.begin();
        if(x[i]==C[t]) continue;
        if(y[i]==D[s]) continue;
        su[t][s]++;
    }
    vll b(10);
    rep(i,XX+1){
        rep(j,YY+1){
            if(su[i][j]>10||su[i][j]==0) continue;
            b[su[i][j]-1]++;
        }
    }
    ll res=0;
    vll w(10,1);
    if(opt==1){
        rep(i,10){
            w[i]=a[i]+5*i;
        }
    }
    rep(i,10){
        res+=min(a[i],b[i])*(w[i]*w[i]*w[i]);
    }
    return res*1000000/resa;
}

void solve(){
    ll m, k, cnt = 0, sum = 0, ans = 0;
    random_device seed_gen;
    mt19937 engine(seed_gen());
    ll time=clock();
    cin>>n>>k;
    vin(a);
    rep(i,10){
        resa+=a[i];
    }
    x.assign(n,0ll);
    y.assign(n,0ll);
    rep(i,n){
        cin>>x[i]>>y[i];
    }
    ll kk=90;
    X=11;
    Y=kk-X;
    ll wid=40;//幅
    ll K=3; //繰り返し数
    vll C(X); //x
    vll D(Y); //y
    vll CC(X);
    vll DD(Y);
    ll maxi=100000;
    while(clock() < 0.80 * CLOCKS_PER_SEC){ //初期解
        rep(i,X){
            if(i==0){
                C[i]=-9990;
            }else{
                C[i]=C[i-1]+300+engine()%(24000/X);
                chmin(C[i],10000ll);
            }
        }
        rep(i,Y){
            if(i==0){
                D[i]=-9990;
            }else{
                D[i]=D[i-1]+50+engine()%(500);
                chmin(D[i],10000ll);
            }
        }
        sum=score_cal(C,D,1ll);
        if(maxi+30000<sum){
            maxi=sum;
            CC=C;
            DD=D;
        }
    }
    maxi=score_cal(C,D,0ll);
    
    while(clock() < 2.97 * CLOCKS_PER_SEC){ //山登り
        C=CC;
        D=DD;
        ll ti=clock()*10/CLOCKS_PER_SEC; //0~30
        wid=50-ti;
        K=15-ti/2;
        rep(i,K){
            ll t=engine()%X;
            if(C[t]<wid-10000||C[t]>10000-wid) continue;
            C[t]-=wid;
            C[t]+=engine()%(2*wid);
        }
        rep(i,K){
            ll t=engine()%Y;
            if(D[t]<wid-10000||D[t]>10000-wid) continue;
            D[t]-=wid;
            D[t]+=engine()%(2*wid);
        }
        ll tt=engine()%10;
        if(tt<=5){
            rep(i,tt+1){
                ll t=engine()%Y;
                D[t]=INF;
            }
        }else if(tt>7){
            D[Y-1]=engine()%20000;
            D[Y-1]-=10000;
        }
        sort(all(C));
        sort(all(D));
        sum=score_cal(C,D,0ll);
        //pt(sum);
        if(maxi+1000<sum){
            maxi=sum;
            CC=C;
            DD=D;
            cnt++;
            /*
            XX=0;
            YY=0;
            rep(i,X){
                if(CC[i]<INF/2) XX++;
            }
            rep(i,Y){
                if(DD[i]<INF/2) YY++;
            }
            kk=XX+YY;
            
            pt(kk);
            rep(i,YY){
                ll px=-10;
                ll qx=10;
                cout<<px<<" "<<DD[i]<<" "<<qx<<" "<<DD[i]<<endl;
            }
            rep(i,XX){
                ll px=-10;
                ll qx=10;
                cout<<CC[i]<<" "<<px<<" "<<CC[i]<<" "<<qx<<endl;
            }
            */
        }
        
    }
    XX=0;
    YY=0;
    rep(i,X){
        if(CC[i]<INF/2) XX++;
    }
    rep(i,Y){
        if(DD[i]<INF/2) YY++;
    }
    kk=XX+YY;
    pt(kk);
    rep(i,YY){
        ll px=-10;
        ll qx=10;
        cout<<px<<" "<<DD[i]<<" "<<qx<<" "<<DD[i]<<endl;
    }
    rep(i,XX){
        ll px=-10;
        ll qx=10;
        cout<<CC[i]<<" "<<px<<" "<<CC[i]<<" "<<qx<<endl;
    }
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