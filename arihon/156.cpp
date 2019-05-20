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

int N, C;
const int MAX_N = 10000, MAX_C = 10000;
int L[MAX_N];
int S[MAX_C], A[MAX_C];

int n;
double vx[4 * MAX_N], vy[4 * MAX_N];
double ang[4 * MAX_N];

int prv[MAX_N];

void init(int n_) {
  n = 1;
  while(n_ > n) n *= 2;
  REP(i, 2 * n - 1) {
    vx[i] = 0;
    vy[i] = 0;
    ang[i] = PI / 2.0;
  }
}

void prepare (int v, int l, int r) {
  if( r - l == 1) {
    if(l < N) vy[v] = L[l];
  }
  else {
    int m = (l + r) / 2;
    int chl = v * 2 + 1, chr = v * 2 + 2;
    prepare(chl, l, m);
    prepare(chr, m, r);
    vy[v] = vy[chl] + vy[chr];
  }
}

void change(int s, double a, int v, int l, int r) {
  if( r - l == 1) return;
  int m = (l + r) / 2;
  int chl = v * 2 + 1, chr = v * 2 + 2;
  change(s, a, chl, l, m);
  change(s, a, chr, m, r);
  if(s <= m) ang[v] += a;
  vx[v] = vx[chl] - vx[chr] * cos(ang[v]) + vy[chr] * sin(ang[v]);
  vy[v] = vy[chl] + vx[chr] * sin(ang[v]) - vy[chr] * cos(ang[v]);
}



int main(){
  cin >> N >> C;
  REP(i, N) cin >> L[i];
  REP(j, C) cin >> S[j];
  REP(j, C) cin >> A[j];

  init(N);
  prepare(0, 0, n);

  REP(i, C) {
    change(S[i], (prv[S[i]] - A[i]) / 180.0 * PI, 0, 0, n); 
    prv[S[i]] = A[i];

    cout << vx[0] << ", " << vy[0] << endl;
  }

  
  
  return 0;
}
