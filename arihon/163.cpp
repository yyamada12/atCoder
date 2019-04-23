#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
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

int N, Q;
const int MAX_N = 100000, MAX_Q = 100000;
ll A[MAX_N];
char T[MAX_Q];
int l[MAX_Q], r[MAX_Q];
ll x[MAX_Q];

int n;
ll sum[MAX_N * 2], add[MAX_N * 2];

void init(int n_) {
  n = 1;
  while(n_ >= n) n *= 2;
  REP(i, 2 * n - 1) {
    sum[i] = 0;
    add[i] = 0;
  }
}

void update(int l, int r, ll x, int v, int L, int R) {
  if(l >= R || r <= L) return;
  if(l <= L && R <= r) {
    add[v] += x;
    return;
  }
  int M = (L + R) / 2;
  int chl = 2 * v + 1, chr = 2 * v + 2;

  sum[v] += add[v] * (R - L) + x * (min(r, R) - max(l, L));
  add[chl] += add[v];
  add[chr] += add[v];
  add[v] = 0;
  
  update(l, r, x, chl, L, M);
  update(l, r, x, chr, M, R);
}

ll get(int l, int r, int v, int L, int R) {
  if(l >= R || r <= L) return 0;
  if(l <= L && R <= r) {
    return sum[v] + add[v] * (R - L);
  }

  int M = (L + R) / 2;
  int chl = 2 * v + 1, chr = 2 * v + 2;
  
  sum[v] += add[v] * (R - L);
  add[chl] += add[v];
  add[chr] += add[v];
  add[v] = 0;

  return get(l, r, chl, L, M) + get(l, r, chr, M, R);
}

int main(){
  cin >> N >> Q;
  REP(i, N) cin >> A[i];
  REP(j, Q) {
    cin >> T[j];
    if(T[j] == '1') cin >> l[j] >> r[j] >> x[j];
    else if (T[j] == '2') cin >> l[i] >> r[i];
  }

  
  cout << ans << endl;
  
  return 0;
}
