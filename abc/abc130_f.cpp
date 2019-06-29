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

ll N;
const ll MAX_N = 100000;
ll x[MAX_N], y[MAX_N];
char d[MAX_N];

int main(){
  cin >> N;
  REP(i, N) cin >> x[i] >> y[i] >> d[i];
  map<char, ll> xmax, xmin, ymax, ymin;
  char cs[4] = {'R', 'L', 'U', 'D'};
  for (auto c: cs) {
    xmax[c] = -INFll;
    xmin[c] = INFll;
    ymax[c] = -INFll;
    ymin[c] = INFll;
  }
  REP(i, N) {
    xmax[d[i]] = max(xmax[d[i]], x[i] * 2);
    xmin[d[i]] = min(xmin[d[i]], x[i] * 2);
    ymax[d[i]] = max(ymax[d[i]], y[i] * 2);
    ymin[d[i]] = min(ymin[d[i]], y[i] * 2);
  }

  vll ts;
  ts.pb(0);
  ts.pb(xmax['L'] - max(xmax['U'], xmax['D']));
  ts.pb((xmax['L'] - xmax['R']) / 2);
  ts.pb(max(xmax['U'], xmax['D']) - xmax['R']);
  
  ts.pb(min(xmin['U'], xmin['D']) - xmin['R']);
  ts.pb((xmin['L'] - xmin['R']) / 2);
  ts.pb(xmin['L'] - min(xmin['U'], xmin['D']));


  ts.pb(ymax['D'] - max(ymax['L'], ymax['R']));
  ts.pb((ymax['D'] - ymax['U']) / 2);
  ts.pb(max(ymax['L'], ymax['R']) - ymax['U']);

  ts.pb(min(ymin['L'], ymin['R']) - ymin['U']);
  ts.pb((ymin['D'] - ymin['U']) / 2);
  ts.pb(ymin['D'] - min(ymin['L'], ymin['R']));


  ll ans = INFll;

  for (auto t: ts) {
    if(t >= 0 && t < 500000000) {
      ll r = max(max(xmax['L'] - t, xmax['R'] + t), max(xmax['U'], xmax['D']));
      ll l = min(min(xmin['L'] - t, xmin['R'] + t), min(xmin['U'], xmin['D']));
      ll u = max(max(ymax['U'] + t, ymax['D'] - t), max(ymax['L'], ymax['R']));
      ll d = min(min(ymin['U'] + t, ymin['D'] - t), min(ymin['R'], ymin['L']));

      ans = min(ans, (r - l) * (u - d));
    }
  }

  cout << setprecision(15) << fixed << ans / 4.0 << endl;


  return 0;
}
