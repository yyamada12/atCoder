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

ll N, M;
string S, T;

ll gcd (ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm (ll a, ll b) {
  return (a * b / gcd(a, b));
}

int main(){
  cin >> N >> M;
  cin >> S >> T;

  ll L = lcm(N, M);
  ll G = gcd(N, M);
  ll n = N / G;
  ll m = M / G;
  REP(i, G) {
    if(S[n * i] != T[m * i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << L << endl;

  return 0;
}

