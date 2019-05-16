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

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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

ll N, K;
const int MAX_N = 2000;
int A[MAX_N], B[MAX_N];
vi G[MAX_N];

int check_v(int v, int d) {
  bool used[N];
  REP(i, N) used[i] = false;
  queue<pi> q;
  q.push(pi(0, v));
  used[v] = true;

  int res = 0;
  while(!q.empty()) {
    pi u = q.front();
    q.pop();
    used[u.S] = true;
    if(u.F > d / 2) res++;
    REP(i, G[u.S].size()) {
      if(!used[G[u.S][i]]) q.push(pi(u.F + 1, G[u.S][i]));
    }
  }
  return res;
}

int check_e(int e, int d) {
  bool used[N];
  REP(i, N) used[i] = false;
  queue<pi> q;
  q.push(pi(0, A[e] - 1));
  used[A[e] - 1] = true;
  q.push(pi(0, B[e] - 1));
  used[B[e] - 1] = true;

  int res = 0;
  while(!q.empty()) {
    pi u = q.front();
    q.pop();
    used[u.S] = true;
    if(u.F > d / 2) res++;
    REP(i, G[u.S].size()) {
      if(!used[G[u.S][i]]) q.push(pi(u.F + 1, G[u.S][i]));
    }
  }
  return res;
}

int main(){
  cin >> N >> K;
  REP(i, N - 1) cin >> A[i] >> B[i];
  REP(i, N - 1) {
    G[A[i] - 1].pb(B[i] - 1);
    G[B[i] - 1].pb(A[i] - 1);
  }

  int ans = INFi;
  if(K % 2 == 0) {
    REP(i, N) {
      ans = min(ans, check_v(i, K));
    }
  } else {
    REP(i, N - 1) {
      ans = min(ans, check_e(i, K));
    }
  }

  cout << ans << endl;

  return 0;
}

