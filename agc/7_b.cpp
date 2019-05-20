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
