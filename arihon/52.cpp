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

int N;
const int MAX_N = 100;
int w[MAX_N], v[MAX_N];
int W;

int main(){
  cin >> N;
  REP(i, N) cin >> w[i] >> v[i];
  cin >> W;

  int d[N + 1][W + 1];
  REP(j, W + 1) d[0][j] = 0;
  REP(i, N + 1) d[i][0] = 0;
  REP(i, N) {
    REP(j, W) {
      d[i + 1][j + 1] = d[i][j + 1];
      if(j + 1 >= w[i]) {
        d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j + 1 - w[i]] + v[i]);
      }
    }
  }

  REP(i, N + 1) {
    REP(j, W + 1) {
      cout << d[i][j] << ",";
    }
    cout << endl;
  }
 cout << d[N][W] << endl;
  
  return 0;
}
