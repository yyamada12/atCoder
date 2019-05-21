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
const int MAX_N = 1000;
int P[MAX_N];
ll X[MAX_N];

vi G[MAX_N];

int main(){
  cin >> N;
  REP(i, N - 1) cin >> P[i];
  REP(i, N) cin >> X[i];
  REP(i, N - 1) {
    G[P[i] - 1].pb(i + 1);
  }

  ll Y[N];
  REP(i, N) Y[i] = 0;

  bool dp[N][5001];

  RREP(i, N) {
    ll s = 0;
    REP(j, G[i].size()) {
      s += X[G[i][j]] + Y[G[i][j]];
    }
    REP(j, G[i].size() + 1) {
       REP(k, X[i] + 1) {
         dp[j][k] = false;
       }
    }
    dp[0][0] = true;
    REP(j, G[i].size()) {
      int ch = G[i][j];
      REP(k, X[i] + 1) {
        if(k >= X[ch]) {
          dp[j + 1][k] = dp[j][k - X[ch]];
        }
        if(k >= Y[ch]) {
          dp[j + 1][k] = dp[j + 1][k] || dp[j][k - Y[ch]];
        }
      }
    }
    bool flag = false;
    RREP(k, X[i] + 1) {
      if(dp[G[i].size()][k]) {
        Y[i] = s - k;
        flag = true;
        break;
      }
    }
    if(!flag) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  cout << "POSSIBLE" << endl;



  return 0;
}
