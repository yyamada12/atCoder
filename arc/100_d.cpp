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
const ll MAX_N  = 200000;
ll A[MAX_N], S[MAX_N];

ll calc(ll l, ll m, ll r) {
  ll P = S[l], Q = S[m] - S[l], R = S[r] - S[m], SS = S[N - 1] - S[r];
  ll MA = max(max(P, Q), max(R, SS));
  ll mi = min(min(P, Q), min(R, SS));
  return MA - mi;
}


int main(){
  cin >> N;
  REP(i, N) cin >> A[i];

  ll s = 0;
  REP(i, N) {
    s += A[i];
    S[i] = s;
  }

  ll l = 0, r = 2;
  ll ans = INFi;
  for(int m = 1; m < N - 1; m++) {
    while(l < m - 1 && abs(S[m] - 2 * S[l]) > abs(S[m] - 2 * S[l + 1])) {
      l++;
    }
    while(r < N - 1 && abs(S[N - 1] + S[m] - 2 * S[r]) > abs(S[N - 1] + S[m] - 2 * S[r + 1])) {
      r++;
    }
    ans = min(ans, calc(l, m, r));
  }

  cout << ans << endl;

  return 0;
}
