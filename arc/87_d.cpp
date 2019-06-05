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

string s;
int x, y;

int main(){
  cin >> s >> x >> y;
  vi vx, vy;
  bool hori = true;
  s += 'T';
  int ct = 0;
  REP(i, s.size()) {
    if(s[i] == 'T') {
      if(hori) vx.pb(ct);
      else vy.pb(ct);
      hori = !hori;
      ct = 0;
    } else {
      ct++;
    }
  }
  
  int lx = vx.size(), ly = vy.size(), l = 16000, s = 8000;
  bool dpx[lx][l + 1], dpy[ly + 1][l + 1];
  REP(i, lx) REP(j, l + 1) dpx[i][j] = false;
  REP(i, ly + 1) REP(j, l + 1) dpy[i][j] = false;
  dpx[0][s + vx[0]] = true;
  REP(i, lx - 1) {
    REP(j, l + 1) {
      if(j >= vx[i + 1]) dpx[i + 1][j] = dpx[i + 1][j] || dpx[i][j - vx[i + 1]];
      if(j + vx[i + 1] < l + 1) dpx[i + 1][j] = dpx[i + 1][j] || dpx[i][j + vx[i + 1]];
    }
  }

  dpy[0][s] = true;
  REP(i, ly) {
    REP(j, l + 1) {
      if(j >= vy[i]) dpy[i + 1][j] = dpy[i + 1][j] || dpy[i][j - vy[i]];
      if(j + vy[i] < l + 1) dpy[i + 1][j] = dpy[i + 1][j] || dpy[i][j + vy[i]];
    }
  }

  if(dpx[lx - 1][s + x] && dpy[ly][s + y]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
