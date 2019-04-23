#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
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
const int MAX_N = 100;
int a[MAX_N], m[MAX_N];
int K;

int main(){
  cin >> N;
  REP(i, N) cin >> a[i] >> m[i];
  cin >> K;

  int dp[N + 1][K + 1];
  REP(j, K + 1) dp[0][j] = -1;
  
  REP(i, N) {
    REP(j, K) {
      if(dp[i][j] >= 0) {
        dp[i + 1][j] = m[i];
      } else if(j < a[i]) {
        dp[i + 1][j] = -1;
      } else if(dp[i + 1][j - a[i]] <= 0) {
        dp[i + 1][j] = -1;
      } else {
        dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
      }
    }
  }

  if(dp[N][K] >= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
