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

ll N, W;
const int MAX_N = 100;
ll w[MAX_N], v[MAX_N];

int main(){
  cin >> N >> W;
  REP(i, N) cin >> w[i] >> v[i];
  
  vll w0, w1, w2, w3;
  REP(i, N) {
    if(w[i] == w[0]) {
      w0.pb(v[i]);
    } else if (w[i] == w[0] + 1) {
      w1.pb(v[i]);
    } else if (w[i] == w[0] + 2) {
      w2.pb(v[i]);
    } else {
      w3.pb(v[i]);
    }
  }

  sort(ALL(w0), greater<ll>());
  sort(ALL(w1), greater<ll>());
  sort(ALL(w2), greater<ll>());
  sort(ALL(w3), greater<ll>());

  ll ans = 0;
  REP(i, w0.size() + 1) {
    REP(j, w1.size() + 1) {
      REP(k, w2.size() + 1) {
        REP(l, w3.size() + 1) {
          if(i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) + l * (w[0] + 3) > W) continue;
          ll s = 0;
          REP(t, i) {
            s += w0[t];
          }
          REP(t, j) {
            s += w1[t];
          }
          REP(t, k) {
            s += w2[t];
          }
          REP(t, l) {
            s += w3[t];
          }
          ans = max(ans, s);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
