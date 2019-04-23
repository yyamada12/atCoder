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

// calc the solution of ax + by = 1
// 1. def empty x, y in main
// 2. extgcd(a, b, x, y) return gcd and set the solution of x, y

ll extgcd(ll a, ll b, ll& x, ll& y){
  ll d = a;
  if(b!=0){
    d = extgcd(b, a%b, y, x);
    y -= (a / b) * x;
  }else{
    x = 1; y = 0;
  }
  return d;
}

int a, b;

int main(){
  cin >> a >> b;
  ll x, y;
  extgcd(a, b, x, y);
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  if(x > 0) a1 = x;
  else a2 = -x;
  if(y > 0) b1 = y;
  else b2 = -y;
  cout << a1 << b1 << a2 << b2 << endl;
  
  return 0;
}
