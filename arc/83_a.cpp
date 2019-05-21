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

int a, b, c, d, e, f;

int main(){
  cin >> a >> b >> c >> d >> e >> f;

  vi water, sugar;
  REP(i, 31) REP(j, 31) {
    if(i * a + j * b <= 30) water.pb(i * a + j * b);
  }
  REP(i, 1501) REP(j, 1501) {
    if(i * c + j * d <= 1500) sugar.pb(i * c + j * d);
  }

  UNIQUE(water);
  UNIQUE(sugar);

  double m = 0.0;
  int ms = 0, mw = a;
  REP(i, water.size()) {
    REP(j, sugar.size()) {
      int w = water[i], s = sugar[j];
      if(w * 100 + s <= f && w * e >= s) {
        if(m < double(s)/double(s + w * 100)) {
          m = double(s)/double(s + w * 100);
          ms = s;
          mw = w;
        }
      }
    }
  }

  cout << ms + mw * 100 << " " << ms << endl;

  return 0;
}
