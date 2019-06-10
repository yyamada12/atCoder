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
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

int H, W;
const int MAX_H = 2000;
string S[MAX_H];

int main(){
  cin >> H >> W;
  REP(i, H) cin >> S[i];

  vpll vh[H], vw[W];
  REP(i, H) {
    ll ct = 0, x = 0;
    REP(j, W) {
      if(S[i][j] == '#') {
        vh[i].pb(pll(x, ct));
        ct = 0;
        x = j + 1;
      } else {
        ct++;
      }
      if(j == W - 1) vh[i].pb(pll(x, ct));
    }
  }

  REP(j, W) {
    ll ct = 0, x = 0;
    REP(i, H) {
      if(S[i][j] == '#') {
        vw[j].pb(pll(x, ct));
        ct = 0;
        x = i + 1;
      } else {
        ct++;
      }
      if(i == H - 1) vw[j].pb(pll(x, ct));
    }
  }

  ll ans = 0;
  
  REP(i, H) {
    REP(j, W) {
      if(S[i][j] == '#') continue;
      ans = max(ans, (upper_bound(ALL(vh[i]), pll(j + 1, -1)) - 1)->S + (upper_bound(ALL(vw[j]), pll(i + 1, -1)) - 1)->S - 1);
    }
  }

  cout << ans << endl;

  return 0;
}
