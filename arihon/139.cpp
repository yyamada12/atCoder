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
