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
const int MAX_N = 20000;
int p[MAX_N];

int main(){
  cin >> N;
  REP(i, N) cin >> p[i];
  int a[N], b[N];

  REP(i, N) {
    a[i] = (i + 1) * 20000;
    b[N - i - 1] = (i + 1) * 20000;
  }

  REP(i, N) a[p[i] - 1] += i;

  REP(i, N) {
    cout << a[i];
    if(i == N - 1) cout << endl;
    else cout << " ";
  }

  REP(i, N) {
    cout << b[i];
    if(i == N - 1) cout << endl;
    else cout << " ";
  }

  return 0;
}
