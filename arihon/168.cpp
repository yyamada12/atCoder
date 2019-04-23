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


int n, m;
const int MAX_N = 100000, MAX_M = 5000;
ll a[MAX_N];
int l[MAX_M], r[MAX_M], k[MAX_M]; 
ll b[100][1000];

bool check(int l, int r, int k, int x) {
  int num = 0;
  while(l != r && l % 1000 != 0) {
    if(a[l] <= x) num ++;
    l++;
  }
  while(r != l && r % 1000 != 999) {
    if(a[r] <= x) num ++;
    r--;
  } 
  while(l < r) {
    num += upper_bound(b[l / 1000], b[l / 1000] + 1000, x) - b[l / 1000];
    l += 1000;
  }
  return num >= k;
}

ll search(int l, int r, int k) {
  ll lb = 0, ub = INFi;
  while(ub - lb > 1) {
    ll mid = (lb + ub) / 2;
    if(check(l, r, k, mid)) ub = mid;
    else lb = mid;
  }
  return lb;
}

int main(){
  cin >> n >> m;
  REP(i, n) cin >> a[i];
  REP(i, 100) REP(j, 1000) b[i][j] = INFi;
  REP(i, n) {
    b[i / 1000][i % 1000] = a[i];
  }
  REP(i, 100) sort(b[i], b[i] + 1000);

  REP(j, m) {
    cin >> l[j] >> r[j] >> k[j];
  }

  REP(j, m) {
    cout << search(l[j] - 1 , r[j] - 1, k[j]) << endl;
  }
  
  return 0;
}
