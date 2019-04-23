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



const int MAX_N = 100000;
ll bit[MAX_N + 1], n;

int sum(int i) {
  ll s = 0;
  while(i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, ll x) {
  while(i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int a[MAX_N];

int main(){
  cin >> n;
  REP(i, n) cin >> a[i];

  ll ans = 0;
  REP(i, n) {
    ans += i - sum(a[i]);
    add(a[i], 1);
  }
  
  cout << ans << endl;
  
  return 0;
}
