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

ll N, C;
const ll MAX_N  = 100000;
ll x[MAX_N], v[MAX_N];

int main(){
  cin >> N >> C;
  REP(i, N) cin >> x[i] >> v[i];

  ll dpr1[N], dpr2[N], dpl1[N], dpl2[N];
  ll s = v[0] - x[0];
  dpr1[0] = max(0ll, s);
  REP(i, N - 1) {
    s += v[i + 1] - (x[i + 1] - x[i]);
    dpr1[i + 1] = max(dpr1[i], s);
  }
  s = v[0] - x[0] * 2;
  dpr2[0] = max(0ll, s);
  REP(i, N - 1) {
    s += v[i + 1] - (x[i + 1] - x[i]) * 2;
    dpr2[i + 1] = max(dpr2[i], s);
  }
  s = v[N - 1] - (C - x[N - 1]);
  dpl1[0] = max(0ll, s);
  REP(i, N - 1) {
    s += v[N - 1 - i - 1] - (x[N - 1 - i] - x[N - 1 - i - 1]);
    dpl1[i + 1] = max(dpl1[i], s);
  }
  s = v[N - 1] - (C - x[N - 1]) * 2;
  dpl2[0] = max(0ll, s);
  REP(i, N - 1) {
    s += v[N - 1 - i - 1] - (x[N - 1 - i] - x[N - 1 - i - 1]) * 2;
    dpl2[i + 1] = max(dpl2[i], s);
  }

  ll ans = 0;
  REP(i, N - 1) {
    ans = max(ans, max(dpr1[i] + dpl2[N - 1 - i - 1], dpl1[i] + dpr2[N - 1 - i - 1]));
  }
  ans = max(ans, max(dpr1[N - 1], dpl1[N - 1]));

  cout << ans << endl;

  return 0;
}
