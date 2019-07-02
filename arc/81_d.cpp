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
string S1, S2;

int main(){
  cin >> N;
  cin >> S1 >> S2;

  vi vec;
  int i = 0;
  while(i < N) {
    if(i == N - 1) {
      vec.pb(1);
      break;
    }
    if(S1[i] == S1[i + 1]) {
      vec.pb(2);
      i += 2;
    } else {
      vec.pb(1);
      i++;
    }
  }

  ll ans = 0;
  if(vec[0] == 1) {
    ans = 3;
  } else {
    ans = 6;
  }

  REP(i, vec.size() - 1) {
    if(vec[i] == 1) {
      ans = ans * 2 % MOD;      
    } else {
      if(vec[i + 1] == 2) {
        ans = ans * 3 % MOD;
      }
    }
  }

  cout << ans << endl;


  return 0;
}
