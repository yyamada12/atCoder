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

ll N, M;
const int MAX_M = 200000;
int p[MAX_M], q[MAX_M], c[MAX_M];

// set V in main
// d[MAX_V] shows the answer

const int MAX_V = 1000000;

struct edge{int to; ll cost;};
typedef pair<ll, int> P;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

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

ll ct;

struct edge2{int to, company;};
vector<edge2> G2[MAX_V];

int main(){
  cin >> N >> M;
  REP(i, M) cin >> p[i] >> q[i] >> c[i];

  map<int, int> mp[N];
  REP(i, M) {
    G2[p[i] - 1].pb(edge2{q[i] - 1, c[i]});
    G2[q[i] - 1].pb(edge2{p[i] - 1, c[i]});
  }
  ct = N;
  REP(i, N) {
    for (auto itr : G2[i]) {
      int t = itr.to;
      int c = itr.company;
      if(!mp[i][c]) mp[i][c] = ct++;
      if(!mp[t][c]) mp[t][c] = ct++;
      G[i].pb(edge{mp[i][c], 1});
      G[mp[i][c]].pb(edge{i, 1});
      G[mp[i][c]].pb(edge{mp[t][c], 0});
      G[mp[t][c]].pb(edge{mp[i][c], 0});
      G[mp[t][c]].pb(edge{t, 1});
      G[t].pb(edge{mp[t][c], 1});
    }
  }
  V = ct;
  dijkstra(0);
  if(d[N - 1] == INFll) {
    cout << -1 << endl;
  } else {
    cout << d[N - 1] / 2 << endl;
  }
  


  return 0;
}
