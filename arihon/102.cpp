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

// set V in main
// d[MAX_V] shows the answer

const int MAX_V = 5000;
const int MAX_E = 100000;

struct edge{int to; ll cost;};
typedef pair<ll, int> P;

int V;
vector<edge> G[MAX_V];
ll d1[MAX_V], d2[MAX_V];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>  > que;
    fill(d1 , d1 + V, INFll);
    fill(d2, d2 + V, INFll);
    d1[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    int d = p.first;
    if(d2[v] < d) continue;
    for(int i = 0; i < G[v].size(); i++){
        edge e = G[v][i];
        if(d1[e.to] >  + e.cost){
          d2[e.to] = d1[e.to];
          d1[e.to] = d + e.cost;
          que.push(P(d, e.to));
        } else if (d1[e.to] == d + e.cost){
          continue;
        } else if(d2[e.to] > d + e.cost) {
          d2[e.to] = d + e.cost;
          que.push(P(d2[e.to], e.to));
        }
      }
    }
}

int N, R;
int A[MAX_E], B[MAX_E], D[MAX_E];

int main(){
  cin >> N >> R;
  REP(i, R) {
    cin >> A[i] >> B[i] >> D[i];
    G[A[i] - 1].push_back(edge{B[i] - 1, D[i]});
    G[B[i] - 1].push_back(edge{A[i] - 1, D[i]});
  }

  V = N;

  dijkstra(0);
  cout << d2[N - 1] << endl;

  return 0;
}
