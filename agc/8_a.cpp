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

int x, y;

int main(){
  cin >> x >> y;
  int ans;
  if( 0 <= x && x < y) ans = y - x;
  else if(x < 0 && 0 < y) ans = abs(abs(y) - abs(x)) + 1;
  else if(x < y && y <= 0) ans = y - x;
  else if(0 < y && y < x) ans = x - y + 2;
  else if(y <= 0 && 0 <= x) ans = abs(abs(y) - abs(x)) + 1;
  else if(y < x && x < 0) ans = x - y + 2;

  cout << ans << endl;

  return 0;
}

