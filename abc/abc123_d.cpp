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

ll X, Y, Z, K;
const int MAX_N = 1000;
const int MAX_K = 3000;
ll A[MAX_N], B[MAX_N], C[MAX_N];
ll D[MAX_N * MAX_N], E[MAX_N * MAX_K];

int main(){
  cin >> X >> Y >> Z >> K;
  REP(i, X) cin >> A[i];
  REP(i, Y) cin >> B[i];
  REP(i, Z) cin >> C[i];
  
  REP(i, X) REP(j, Y) D[i * Y+ j] = A[i] + B[j];
  
  sort(D, D + X * Y, greater<ll>());

  if(X * Y > 3000) {
    REP(i, 3000) REP(j, Z) E[i * Z + j] = D[i] + C[j];
    sort(E, E + 3000 * Z, greater<ll>());
  } else {
    REP(i, X * Y) REP(j, Z) E[i * Z + j] = D[i] + C[j];
    sort(E, E + X * Y * Z, greater<ll>());
  }

  REP(i, K) cout << E[i] << endl;

  return 0;
}
