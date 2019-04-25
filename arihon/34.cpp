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

int N;
ll K;

ll a[20];

bool dfs (ll s, int i) {
  if(s == K) return true;
  if(i == N) return false;
  return (dfs(s + a[i], i + 1) || dfs(s, i + 1));
}

int main(){
  cin >> N >> K;
  REP(i, N) cin >> a[i];

  if (dfs(0, 0)) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}