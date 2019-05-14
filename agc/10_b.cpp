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
const int MAX_N = 100000;
ll A[MAX_N];

int main(){
  cin >> N;
  ll s = 0, maxb = 0;
  ll B[N];
  REP(i, N) {
    cin >> A[i];
    s += A[i];
  }
  REP(i, N) {
    if(i != (N - 1)) B[i] = A[i + 1] - A[i];
    else B[i] = A[0] - A[i];
    maxb = max(maxb, B[i]);
  }

  ll ct = 0;
  REP(i, N) {
    if((maxb - B[i]) % N != 0) {
      cout << "NO" << endl;
      return 0;
    }
    ct += (maxb - B[i]) / N;
  }

  s -= ct * N * (N + 1) / 2;

  if(s >= 0 && s % (N * N * (N + 1) / 2) == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

