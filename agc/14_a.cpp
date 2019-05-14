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

