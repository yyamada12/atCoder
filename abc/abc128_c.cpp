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

int N, M;
const int MAX_M = 10;
int p[MAX_M];

int main(){
  cin >> N >> M;
  set<int> st[M];
  REP(i, M) {
    int k, s;
    cin >> k;
    REP(j, k){
      cin >> s;
      st[i].insert(s - 1);
    }
  }
  REP(i, M) cin >> p[i];

  int ans = 0;

  REP(i, 1 << N) {
    int ct[M];
    REP(k, M) ct[k] = 0;
    REP(j, N) {
      if(i >> j & 1) {
        REP(k, M) {
          if(st[k].find(j) != st[k].end()) {
            ct[k] ++;
          }
        }
      }
    }
    bool flag = true;
    REP(k, M) {
      flag = flag && (ct[k] % 2 == p[k]);
    }
    if(flag) ans++;
  }
  
  cout << ans << endl;

  return 0;
}
