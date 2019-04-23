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
const int MAX_N = 2000;
char c[MAX_N];

int main(){
  cin >> N;
  REP(i, N) cin >> c[i];
  
  int l = 0, r = N - 1;
  int ct = 0;
  while(l <= r) {
    if (ct > 0 && ct % 80 == 0) cout << '\n';
    bool left = true;
    REP(i, r - l) {
      if(c[l + i] < c[r - i]) {
        left = true;
        break;
      } else if(c[l + i] > c[r - i]) {
        left = false;
        break;
      }
    }
    if(left) cout << c[l++];
    else cout << c[r--];
    ct++;
  }

  cout << '\n';

  return 0;
}
