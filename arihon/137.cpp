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

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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

int P;
const int MAX_P = 1000000;
int a[MAX_P];

int main(){
  cin >> P;
  REP(i, P) cin >> a[i];

  set<int> st;
  int last = 0;
  REP(i, P) {
    st.insert(a[i]);
  }
  int n = st.size();


  map<int, int> mp;
  int l = 0, r = 0;
  int ans = INFi;
  int num = 0;
  while(r < P) {
    while(num < n && r < P) {
      if(mp[a[r++]]++ == 0) num++;
    }
    while(num == n) {
      ans = min(ans, r - l);
      if(--mp[a[l++]] == 0) num--;
    }
  }

  cout << ans << endl;

  return 0;
}
