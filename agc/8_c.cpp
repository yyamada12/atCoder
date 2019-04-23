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

ll a[7];

int main(){
  REP(i, 7) cin >> a[i];

  ll ans = a[0] / 2 * 2 + a[1] + a[3] / 2 * 2 + a[4] / 2 * 2;
  if(a[0] % 2 == 1 &&  a[3] % 2 == 1 &&  a[4] % 2 == 1) ans += 3;
  else if (a[0] % 2 + a[3] % 2 + a[4] % 2 == 2 && a[0] > 0 && a[3] > 0 && a[4] > 0) ans += 1;

  cout << ans << endl;

  return 0;
}

