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

// union-find O(α(n))
// 1. init(n)
// 2. use unite(x, y) and same(x, y)

const int MAX_N = 150000;

int par[MAX_N];
int rk[MAX_N];

void init(int n){
  REP(i,n){
    par[i] = i;
    rk[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(rk[x] < rk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rk[x] == rk[y]) rk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

int N, K;
int type[MAX_N], x[MAX_N], y[MAX_N];

int main(){
  cin >> N >> K;
  REP(i, K) cin >> type[i] >> x[i] >> y[i];
  REP(i, K) {
    x[i]--;
    y[i]--;
  }

  int ans = 0;
  init(N * 3);
  REP(i, K) {
    if(x[i] < 0 || x[i] >= N || y[i] < 0 || y[i] >= N) {
      ans++;
      continue;
    }

    if(type[i] == 1) {
      if(same(x[i], N + y[i]) || same(x[i], 2 * N + y[i])){
        ans++;
        continue;
      }
      unite(x[i], y[i]); unite(N + x[i], N + y[i]); unite(2 * N + x[i], 2 * N + y[i]);
    }else{
      if(same(x[i], y[i] || same(x[i], 2 * N + y[i]))) {
        ans++;
        continue;
      }
      unite(x[i], N + y[i]); unite(N + x[i], 2 * N + y[i]); unite(2 * N + x[i], y[i]);
    }
  }

  cout << ans << endl;

}
