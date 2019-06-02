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

ll N;
const int MAX_N = 10000;
ll a[MAX_N - 1], b[MAX_N - 1], c[MAX_N];

bool used[MAX_N];
vll G[MAX_N];

priority_queue<ll, vll, greater<ll> > pq;

ll ans[MAX_N];

void dfs(int v) {
  used[v] = true;
  REP(i, G[v].size()) {
    if(!used[G[v][i]]) dfs(G[v][i]);
  }
  ans[v] = pq.top();
  pq.pop();
}



int main(){
  cin >> N;
  REP(i, N - 1) cin >> a[i] >> b[i];
  REP(i, N) cin >> c[i];
  REP(i, N - 1) {
    G[a[i] - 1].pb(b[i] - 1);
    G[b[i] - 1].pb(a[i] - 1);
  }
  REP(i, N) {
    used[i] = false;
    pq.push(c[i]);
  }
  dfs(0);

  sort(c, c + N);
  ll s = 0;
  REP(i, N - 1) {
    s += c[i];
  }
  cout << s << endl;

  REP(i, N) {
    cout << ans[i];
    if(i != N -1) cout << " ";
    else cout << endl;
  }

  return 0;
}
