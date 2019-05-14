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

int N, K;
const int MAX_N = 100000;
double l[MAX_N];

bool check(double x) {
  int c = 0;
  REP(i, N) {
    c += int(l[i] / x);
  }
  return c < K;
}

int main(){
  cin >> N >> K;
  REP(i, N) cin >> l[i];

  double lb = 0, ub = INFi;

  while(ub - lb > 0.001) {
    double mid = (lb + ub) / 2;
    if(check(mid)) ub = mid;
    else lb = mid;
  }


  cout << int(lb * 100) / 100.0 << endl;

  return 0;
}
