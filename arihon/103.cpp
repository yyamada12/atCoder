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

// prim: O(V^2)
// 1. set V and cost in main
// 2. prim() return sum of mincost

const int MAX_V = 10000;

ll cost[MAX_V][MAX_V];
ll mincost[MAX_V];
bool used[MAX_V];
int V;

ll prim(){
  for (int i = 0; i < V; i++) {
    mincost[i] = INFll;
    used[i] = false;
  }
  mincost[0] = 0;
  ll res = 0;

  while(1) {
    int v = -1;
    for(int u = 0; u < V; u++) {
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if(v == -1) break;
    used[v] = true;
    res += mincost[v];

    for (int u = 0; u < V; u++) {
      mincost[u] = min(mincost[u], cost[v][u]);
    }
  }
  return res;
}

int N, M, R;
const int MAX_R = 50000;
int x[MAX_R], y[MAX_R], d[MAX_R];

int main(){
  cin >> N >> M >> R;
  V = N + M;
  REP(i, V) {
    REP(j, V) {
      cost[i][j] = 0;
    }
  }
  REP(i, V) cost[i][i] = INFi;
  REP(i, R) {
    cin >> x[i] >> y[i] >> d[i];
    y[i] += N;
    cost[x[i]][y[i]] = -d[i];
    cost[y[i]][x[i]] = -d[i];
  }

  cout << V * 10000 + prim() << endl;
  
  return 0;
}
