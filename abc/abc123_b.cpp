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

int a[5], b[5];

int main(){
  int ans = 0;
  REP(i, 5) {
    cin >> a[i];
    if(a[i] % 10 == 0) b[i] = 10;
    else b[i] = a[i] % 10;
  }

  sort(b, b + 5);

  REP(i, 5) {
    if(a[i] % 10 != 0) a[i] = (a[i] / 10 + 1) * 10;
    ans += a[i];
  }

  ans -= 10 - b[0];
  
  cout << ans << endl;

  return 0;
}
