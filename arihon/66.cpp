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

int n, m;
int M = 10000;

int main(){
  cin >> n >> m;
  cin >> M;
  int dp[n + 1][m + 1];
  REP(j, m + 1) dp[0][j] = 1;
  REP(i, n + 1) dp[i][0] = 0;
  REP(i, n) {
    REP(j, m) {
      if(i >= j) dp[i + 1][j + 1] = (dp[i - j][j + 1] + dp[i + 1][j]) % M;
      else dp[i + 1][j + 1] = dp[i + 1][j];
    }
  }

  REP(i, n + 1) {
    REP(j, m + 1) {
      cout << dp[i][j] << ",";
    }
    cout << endl;
  }

  cout << dp[n][m] << endl;


  

  return 0;
}
