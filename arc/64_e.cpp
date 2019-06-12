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

ll xs, ys, xt, yt;
int N;
const int MAX_N = 1000;
ll x[MAX_N + 2], y[MAX_N + 2], r[MAX_N + 2];

// set V in main
// d[MAX_V] shows the answer

const int MAX_V = 100000;

struct edge{int to; double cost;};
typedef pair<double, int> P;

int V;
vector<edge> G[MAX_V];
double d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>  > que;
  fill(d, d + V, INFll);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  cin >> xs >> ys >> xt >> yt;
  cin >> N;
  REP(i, N) cin >> x[i] >> y[i] >> r[i];
  x[N] = xs, x[N + 1] = xt, y[N] = ys, y[N + 1] = yt, r[N] = 0, r[N + 1] = 0;

  REP(i, N + 2) {
    for (int j = i + 1; j < N + 2; j++) {
      double dis = sqrt(double((x[i] - x[j]) * (x[i] - x[j])) + double((y[i] - y[j]) * (y[i] - y[j])));
      double cost = max(0.0, dis - r[i] - r[j]);
      G[i].pb(edge{j, cost});
      G[j].pb(edge{i, cost});
    }
  }

  V = N + 2;
  dijkstra(N);
  cout << fixed << setprecision(12) << d[N + 1] << endl;


  return 0;
}
