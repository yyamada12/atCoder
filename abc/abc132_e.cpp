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

int N, M, S, T;
const int MAX_M = 100000;
int u[MAX_M], v[MAX_M];

// set V in main
// d[MAX_V] shows the answer

const int MAX_V = 300000;

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

int main(){
  cin >> N >> M;
  REP(i, M) cin >> u[i] >> v[i];
  cin >> S >> T;

  REP(i, M) {
    u[i]--;
    v[i]--;
    G[u[i]].pb(edge{v[i] + N, 1});
    G[u[i] + N].pb(edge{v[i] + 2 * N, 1});
    G[u[i] + 2 * N].pb(edge{v[i], 1});
  }
  S--;
  T--;

  V = 3 * N;
  dijkstra(S);

  if(d[T] == INFll) {
    cout << -1 << endl;
  } else {
    cout << d[T] / 3 << endl;
  }

  return 0;
}
