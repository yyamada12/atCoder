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

int N, L, P;
const int MAX_N = 10000;
int A[MAX_N + 2];
int B[MAX_N];

int main(){
  cin >> N >> L >> P;
  REP(i, N) cin >> A[i + 1];
  REP(i, N) cin >> B[i];
  A[0] = 0;
  A[N + 1] = L;

  priority_queue<int> pq;
  
  int gas = P;
  int ans = 0;

  REP(i, N + 1) {
    cout << i << ", " << gas << endl;
    gas -= A[i + 1] - A[i];
    while(gas < 0 && !pq.empty()) {
      gas += pq.top(); pq.pop();
      ans ++;
    }
    if(gas < 0 && pq.empty()) {
      cout << -1 << endl;
      return 0;
    }
    pq.push(B[i]);
  }

  cout << ans << endl;

  return 0;
}
