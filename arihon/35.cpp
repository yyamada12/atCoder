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

int N, M;
const ll MAX_N = 100, MAX_M = 100;
char c[MAX_N][MAX_M];

bool checked[MAX_N][MAX_M];

void dfs(int i, int j) {
  checked[i][j] = true;
  if(c[i][j] == 'W') {
    REP(k, 8) {
      int ni = i + dirx[k];
      int nj = j + diry[k];
      if(ni >= 0 && ni < N && nj >= 0 && nj < M && !checked[ni][nj]) dfs(i + dirx[k], j + diry[k]);
    }
  }
}

int main(){
  cin >> N >> M;
  REP(i, N) REP(j, M) cin >> c[i][j];
  REP(i, N) REP(j, M) checked[i][j] = false;

  ll ans = 0;

  REP(i, N) REP(j, M) if(!checked[i][j] && c[i][j] == 'W') {
    dfs(i, j);
    ans++;
  }

  cout << ans << endl;

  return 0;
}
