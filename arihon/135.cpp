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

int n, S;
const int MAX_N = 100000;
int a[MAX_N];

int main(){
  cin >> n >> S;
  REP(i, n) cin >> a[i];

  int l = 0, r = 0;
  int ans = INFi;
  int s = 0;
  while(r < n) {
    while(s < S && r < n) {
      s+= a[r++];
    }
    while(s >= S) {
      ans = min(ans, r - l);
      s-= a[l++];
    }
  }

  cout << ans << endl;

  return 0;
}
