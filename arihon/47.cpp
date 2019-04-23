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

int N, R;
const int MAX_N = 1000;
int x[MAX_N];

int main(){
  cin >> R >> N;
  REP(i, N) cin >> x[i];
  sort(x, x + N);
  int prv = x[0];
  int ans = 0;

  int crt = 0;

  while(crt < N) {
    while(crt < N && x[crt] <= prv + R) {
      crt++;
    }
    prv = x[crt - 1];
    ans++;
    while(crt < N && x[crt] <= prv + R) {
      crt++;
    }
    prv = x[crt];
  }
  
  cout << ans << endl;

  return 0;
}
