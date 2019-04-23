#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
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
