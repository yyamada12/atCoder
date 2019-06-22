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
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

int N;
const int MAX_N = 100001;
int x[MAX_N], y[MAX_N];

// union-find O(α(n))
// 1. init(n) *** Notice that if 3 groupes, init(3 * n)
// 2. use unite(x, y) and same(x, y)

int par[MAX_N * 2];
int rk[MAX_N * 2];

void init(int n){
  REP(i,n){
    par[i] = i;
    rk[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(rk[x] < rk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rk[x] == rk[y]) rk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

int main(){
  cin >> N;
  REP(i, N) cin >> x[i] >> y[i];

  init(2 * MAX_N);
  vpi vx, vy;
  REP(i, N) {
    vx.pb(pi(x[i], y[i]));
    vy.pb(pi(y[i], x[i]));
  }

  sort(ALL(vx));
  sort(ALL(vy));

  REP(i, N - 1) {
    if(vx[i].F == vx[i + 1].F) {
      unite(vx[i].S + MAX_N, vx[i + 1].S + MAX_N);
    }
    if(vy[i].F == vy[i + 1].F) {
      unite(vy[i].S, vy[i + 1].S);
    }
  }

  set<pi> st;
  map<int, int> mpx, mpy;
  REP(i, MAX_N) {
    mpx[find(i)]++;
    mpy[find(MAX_N + i)]++;
  }
  REP(i, N) {
    st.insert(pi(find(x[i]), find(y[i] + MAX_N)));
  }

  ll ans = 0;
  for (auto itr : st) {
    ans += ll(mpx[itr.first]) * mpy[itr.second];
  }

  cout << ans - N << endl;

  return 0;
}
