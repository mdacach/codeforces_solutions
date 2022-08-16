#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
#define int long long
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}

ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

int32_t main(){
  fastio;
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll tot=0;
  for(int z=c;z<=d;z++){
    int mn = max(a,z-c + 1);
    if(mn > b)continue;

    int mn2 = max(b,z - mn + 1);

    int ter = (b - mn + 1);   

    int put1 = min(ter,mn2 - b + 1);

    int a1 = c - mn2 + 1;

    tot+=(put1*(a1 + a1 + put1 - 1) / 2);

    ter-=put1;
    tot+=ter*(c-b+1);

  }
  cout << tot << endl;
  
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}