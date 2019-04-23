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
const int MAX_N = 300;
int a[MAX_N];



int main(){
  cin >> N;
  int sum = 0;
  REP(i, N) {
    cin >> a[i];
    sum += a[i];
  }

  ll dp[N + 1][sum + 1];

  REP(i, N + 1) REP(j, sum + 1) dp[i][j] = 0;
  dp[0][0] = 1;

  REP(i, N) {
    REP(j, sum + 1) {
      dp[i + 1][j] = dp[i][j];
      if(j >= a[i]) dp[i + 1][j] += dp[i][j - a[i]];
    }
  }

  ll ans = 0;
  for(int i = (sum + 1) / 2; i <= sum; i++) {
    ans = (ans + dp[N][i]) % 998244353;
  }

  REP(i, N + 1) {
    REP(j, sum + 1) {
      cout << dp[i][j] << ",";
    }
    cout << endl;
  }

  cout <<ans <<endl;

  return 0;
}
