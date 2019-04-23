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


ll gcd(ll x, ll y){
  if(x == 0)return y;
  return gcd(y%x, x);
}

int X1, X2, Y1, Y2;

int main(){
  cin >> X1 >> Y1 >> X2 >> Y2;
  int dX = X1 - X2;
  int dY = Y1 - Y2;
  if (dX < 0) dX = -dX;
  if (dY < 0) dY = -dY;
  cout << gcd(dX, dY) - 1 << endl;
  
  return 0;
}
