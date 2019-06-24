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

ll N;


int main(){
  cin >> N;
  int D = 61;
  ll dp0[D], dp1[D], dp2[D];
  dp0[D - 1] = 1;
  dp1[D - 1] = 0;
  dp2[D - 1] = 0;
  RREP(i, D - 1) {
    int crt = (N >> i) & 1 ;
    if(crt == 1) {
      dp0[i] = dp0[i + 1];
      dp1[i] = (dp0[i + 1] + dp1[i + 1]) % MOD;
      dp2[i] = (dp1[i + 1] * 2 % MOD + dp2[i + 1] * 3 % MOD) % MOD;
    } else {
      dp0[i] = (dp0[i + 1] + dp1[i + 1]) % MOD;
      dp1[i] = dp1[i + 1];
      dp2[i] = (dp1[i + 1] + dp2[i + 1] * 3 % MOD) % MOD;
    }
  }
  
  cout << ((dp0[0] + dp1[0]) % MOD + dp2[0]) % MOD << endl;


  return 0;
}
