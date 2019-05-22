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
const int MAX_N = 100000;
int u[MAX_N], v[MAX_N], w[MAX_N];

struct edge {
  int t, d;
};
vector<edge> G[MAX_N];
bool used[MAX_N];
int color[MAX_N];

void dfs(int n) {
  used[n] = true;
  REP(i, G[n].size()) {
    edge c = G[n][i];
    if(c.d % 2 == 0) color[c.t] = color[n];
    else color[c.t] = 1 - color[n];
    if(!used[c.t]) dfs(c.t);
  }
  return;
} 

int main(){
  cin >> N;
  REP(i, N - 1) cin >> u[i] >> v[i] >> w[i];
  REP(i, N - 1) {
    G[u[i] - 1].pb(edge{v[i] - 1, w[i]});
    G[v[i] - 1].pb(edge{u[i] - 1, w[i]});
  }

  REP(i, N) used[i] = false;
  color[0] = 1;
  dfs(0);

  REP(i, N) cout << color[i] << endl;
  
  return 0;
}
