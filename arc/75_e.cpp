#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i = n - 1; i >= 0; i--)

#define ALL(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define UNIQUE(v) do{sort(v.begin(), v.end()); v.erase( unique(v.begin(), v.end()), v.end() );} while(0)

#define y0 y3487465
#define y1 y8687969

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

ll N, K;
const ll MAX_N = 200000;
ll a[MAX_N];

// bit O(log n) for a query
// 1. set n
// 2. init bit[0] ... bit[n + 1]
// 3. use add(i, x) and sum(i)


ll bit[MAX_N + 1], n;

int sum(int i) {
  ll s = 0;
  while(i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, ll x) {
  while(i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int main(){
  cin >> N >> K;
  REP(i, N) cin >> a[i];

  REP(i, N) a[i] -= K;
  ll s[N];
  ll su = 0;
  REP(i, N) {
    su += a[i];
    s[i] = su;
  }

  vll sorts;
  REP(i, N) sorts.pb(s[i]);
  sort(ALL(sorts));

  ll compress_s[N];
  REP(i, N) {
    compress_s[i] = lower_bound(ALL(sorts), s[i]) - sorts.begin();
  }

  n = N;
  REP(i, N + 1) bit[i] = 0;

  ll ans = 0;
  add(lower_bound(ALL(sorts), 0) - sorts.begin() + 1, 1);
  REP(i, N) {
    
    ans += sum(compress_s[i] + 1);
    add(compress_s[i] + 1, 1);
  }
  
  cout << ans << endl;

  return 0;
}
