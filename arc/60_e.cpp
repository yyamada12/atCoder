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

ll N, L, Q;
const ll MAX_N = 100000;
ll x[MAX_N];
const ll MAX_Q = 100000;
ll a[MAX_Q], b[MAX_Q];

ll dp[20][MAX_N];

void query(int l, int r) {
  int crt = l;
  int s = 0;
  while(1) {
    for(int i = 1; i < 20; i++) {
      if(dp[i][crt] >= r) {
        if(i == 1) {
          s += 1;
          cout << s << endl;
          return;
        } else {
          s += int(pow(2, i - 2));
          crt = dp[i - 1][crt];
          break;
        }
      }
    }
  }
}

int main(){
  cin >> N;
  REP(i, N) cin >> x[i];
  cin >> L;
  cin >> Q;
  REP(i, Q) cin >> a[i] >> b[i];

  
  int dest = 0;
  REP(j, N) {
    while(dest != N && x[j] + L >= x[dest]) {
      dest++;
    }
    dp[1][j] = dest - 1;
  }
  for(int i = 2; i < 20; i++) {
    REP(j, N) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }


  REP(i, Q) {
    int l = a[i], r = b[i];
    if(a[i] > b[i]) swap(l, r);
    query(l - 1, r - 1);
  }

  return 0;
}
