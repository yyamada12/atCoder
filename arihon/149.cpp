#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <set>
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

int N, W;
const int MAX_N = 40;
ll w[MAX_N], v[MAX_N];

int main(){
  cin >> N >> W;
  REP(i, N) cin >> w[i] >> v[i];

  pll suml[1 << (N / 2)];
  REP(i, 1 << (N / 2)) {
    ll sumw = 0, sumv = 0;
    REP(j, N / 2) {
      if(i >> j & 1) {
        sumw += w[j];
        sumv += v[j];
      }
    }
    suml[i] = pll(sumw, sumv);
  }

  sort(suml, suml + (1 << (N / 2)));

  ll ans = 0;

  REP(i, 1 << (N - N / 2)) {
    ll sumw = 0, sumv = 0;
    REP(j, N - N / 2) {
      if(i >> j & 1) {
        sumw += w[N / 2 + j];
        sumv += v[N / 2 + j];
      }
    }
    if(sumw <= W) {
      ans = max(ans, sumv + (upper_bound(suml, suml + (1 << (N / 2)), pll(W - sumw, INFll)) - 1)->second);
    }
  }

  cout << ans << endl;

  return 0;
}
