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

int n, k;
const int MAX_N = 100000;
ll w[MAX_N], v[MAX_N];

bool check(double x) {

  double tmp[n];
  REP(i, n) tmp[i] = v[i] - w[i] * x;
  sort(tmp, tmp + n, greater<double>());
  double sum = 0;
  REP(i, k) sum += tmp[i];

  return sum < 0;
}

int main(){
  cin >> n >> k;
  REP(i, n) cin >> w[i] >> v[i];

  double lb = 0, ub = INFi;

  while(ub - lb > 0.0001) {
    double mid = (lb + ub) / 2;
    if(check(mid)) ub = mid;
    else lb = mid;
  }


  cout << lb << endl;

  return 0;
}
