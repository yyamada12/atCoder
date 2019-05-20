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

int N, M;
const int MAX_M = 100000;
int x[MAX_M], y[MAX_M]; 

int main(){
  cin >> N >> M;
  REP(i, M) cin >> x[i] >> y[i];

  bool red[N];
  int num[N];
  REP(i, N) {
    red[i] = false;
    num[i] = 1;
  }
  red[0] = true;

  REP(i, M) {
    int from = x[i] - 1, to = y[i] - 1;
    if(red[from]) {
      red[to] = true;
    }
    num[from]--;
    num[to]++;
    if(num[from] == 0) red[from] = false;
  }

  int ans = 0;
  REP(i, N) if(red[i]) ans++;

  cout << ans << endl;

  return 0;
}
