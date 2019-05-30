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

int N, K;
const int MAX_N = 5000;
ll a[MAX_N];

int main(){
  cin >> N >> K;
  REP(i, N) cin >> a[i];

  bool dp[N + 1][K], rdp[N + 1][K];
  vi v[N + 1], rv[N + 1];
  v[0].pb(0);
  rv[0].pb(0);
  REP(i, N + 1) {
    REP(j, K) {
      dp[i][j] = false;
      rdp[i][j] = false;
    }
  }
  dp[0][0] = true;
  rdp[0][0] = true;
  REP(i, N) {
    REP(j, K) {
      dp[i + 1][j] = dp[i][j];
      if(j >= a[i]) dp[i + 1][j] = dp[i + 1][j] || dp[i][j - a[i]];
      if(dp[i + 1][j]) v[i + 1].pb(j);

      rdp[i + 1][j] = rdp[i][j];
      if(j >= a[N - 1 - i]) rdp[i + 1][j] = rdp[i][j - a[N - 1 - i]];
      if(rdp[i + 1][j]) rv[i + 1].pb(j);
    }
  }

  int ans = 0;

  // cout << endl;

  // REP(i, N + 1) {
  //   REP(j, v[i].size()) {
  //     cout << v[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // REP(i, N + 1) {
  //   REP(j, rv[i].size()) {
  //     cout << rv[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  REP(i, N) {
    int m = 0;
    REP(j, v[i].size()) {
      m = max(m, *(upper_bound(ALL(rv[N - 1 - i]), K - v[i][j] - 1) - 1) + v[i][j]);
    }
    // cout << "i: " << i << ", m: " << m << ", a[i]: " << a[i] << endl;
    if(m < K - a[i]) ans++;
  }

  cout << ans << endl;

  return 0;
}
