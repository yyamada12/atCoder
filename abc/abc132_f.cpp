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

ll N, K;
const ll MAX_K = 100, MAX_RN = 70000;
static int dp[MAX_K][MAX_RN];

int main(){
  cin >> N >> K;

  vll vec;
  for(ll i = 1; i * i <= N; i++) {
    vec.pb(i);
    if(i * i != N) {
      vec.pb(N / i);
    }
  }

  sort(ALL(vec));

  ll M = vec.size();

  dp[0][0] = 1;
  REP(i, M - 1) {
    dp[0][i + 1] = vec[i + 1] - vec[i];
  }

  REP(i, K - 1) {
    ll s = 0;
    for(int j = M - 1; j >= 0; j--) {
      s += dp[i][M - j - 1];
      s %= MOD;
      dp[i + 1][j] = dp[0][j] * s % MOD;
    }
  }

  ll ans = 0;
  REP(j, M) {
    ans += dp[K - 1][j];
    ans %= MOD;
  }

  cout << ans << endl;
  
  return 0;
}
