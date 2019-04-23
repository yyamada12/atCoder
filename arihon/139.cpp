#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <set>
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
string S;

int main(){
  cin >> N;
  cin >> S;
  int a[N], b[N];
  REP(i, N) {
    if(S[i] == 'F') a[i] = 1;
    else a[i] = -1;
  }

  int min = INFi, mink = 0;
  REP(k, N + 1) {
    int r = 1, ct = 0;
    if(k == 0) continue;

    REP(i, N) {
      if(i >= k) r *= b[i - k];
      b[i] = r * a[i];
      if(i <= N - k)r = r * b[i];
      if(i > N - k && b[i] == -1) {
        ct = INFi;
        break;
      }
      if(b[i] == -1) ct++;
    }

    if(min > ct) {
      min = ct;
      mink = k;
    }
  }

  cout << min << endl;
  cout << mink << endl;

  return 0;
}
