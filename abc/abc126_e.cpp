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
const int MAX_M = 100000;
ll X[MAX_M], Y[MAX_M], Z[MAX_M];

// Union-Find Tree
// 1. init(n);
// 2. unite(x, y)
// 3. use find(x) or same(x, y)

const int MAX_N = ${1: 100000};
int par[MAX_N];
int depth[MAX_N];

void init(int n) {
  for(int i = 0; i < n; i++) {
    par[i] = i;
    depth[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return;

  if(depth[x] < depth[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(depth[x] == depth[y]) depth[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int main(){
  cin >> N >> M;
  REP(i, M) cin >> X[i] >> Y[i] >> Z[i];
  init(N);
  REP(i, M) {
    unite(X[i] - 1, Y[i] - 1);
  }
  set<int> s;
  REP(i, N) {
    s.insert(find(i));
  }

  cout << s.size() << endl;

  return 0;
}
