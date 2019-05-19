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

int H, W;
const int MAX_HW = 500;
string a[MAX_HW];

int main(){
  cin >> H >> W;
  REP(i, H) cin >> a[i];

  char red[H][W], blue[H][W];

  REP(i, H) {
    REP(j, W) {
      red[i][j] = '.';
      blue[i][j] = '.';
    }
  }

  REP(i, H) {
    red[i][0] = '#';
    blue[i][W - 1] = '#';
  }
  for(int j = 1; j < W - 1; j++) {
    REP(i, H) {
      if(i % 2 == 0) {
        red[i][j] = '#';
      } else {
        blue[i][j] = '#';
      }
    }
  }

  REP(i, H) REP(j, W) if(a[i][j] == '#') {
    red[i][j] = '#';
    blue[i][j] = '#';
  }

  REP(i, H) {
    REP(j, W) {
      cout << red[i][j];
    }
    cout << endl;
  }
  cout << endl;
  REP(i, H) {
    REP(j, W) {
      cout << blue[i][j];
    }
    cout << endl;
  }

  return 0;
}

