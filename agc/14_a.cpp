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

int a[3];

int main(){
  REP(i, 3) cin >> a[i];
  sort(a, a + 3);

  REP(i, 3) {
    if(a[i] % 2 == 1) {
      cout << 0 << endl;
      return 0;
    }
  }

  if(a[0] == a[2]) {
    cout << -1 << endl;
    return 0;
  }

  int l = a[1] - a[0], r = a[2] - a[1];
  int ans = 0;
  while((l % 2 == 0) && (r % 2 == 0)) {
    l /= 2;
    r /= 2;
    ans ++;
  }

  cout << ans << endl;

  return 0;
}

