#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
#include <set>
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

