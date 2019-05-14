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

int N;
const int MAX_N = 300;
ll A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

ll gcd (ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cin >> N;
  REP(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];
  REP(i, N) {
    if(A[i] < B[i] || D[i] < B[i] || A[i] % B[i] > C[i]) {
      cout << "No" << endl;
      continue;
    }
    if(B[i] <= C[i]) {
      cout << "Yes" << endl;
      continue;
    }
    ll g = gcd(B[i], D[i]);
    ll x = A[i] % B[i];
    if(B[i] - g + x % g <= C[i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  return 0;

}

