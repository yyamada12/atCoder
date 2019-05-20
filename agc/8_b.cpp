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

int N, K;
const int MAX_N = 100000;
ll a[MAX_N];

int main(){
  cin >> N >> K;
  REP(i, N) cin >> a[i];
  
  ll sum = 0;
  REP(i, N) {
    if(a[i] > 0) sum += a[i];
  }

  ll b[N - K + 1], x[N - K + 1];

  ll cb = 0, cx = sum;
  REP(i, N - K + 1) {
    if(i == 0) {
      REP(j, K) {
        cb += a[j];
        if(a[j] > 0) cx -= a[j];
      }
      b[i] = cb;
      x[i] = cx;
    } else {
      cb += a[i + K - 1] - a[i - 1];
      b[i] = cb;
      if(a[i + K - 1] > 0) cx -= a[i + K - 1];
      if(a[i - 1] > 0) cx += a[i - 1];
      x[i] = cx;
    }
  }

  ll ans = 0;
  REP(i, N - K + 1) {
    // cout << b[i] << ", " << x[i] << endl;
    ans = max(ans, x[i]);
    ans = max(ans, x[i] + b[i]);
  }

  cout << ans << endl;

  return 0;
}

