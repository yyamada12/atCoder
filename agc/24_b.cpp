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

int N;
const int MAX_N = 200000;
int P[MAX_N];


int main(){
  cin >> N;
  REP(i, N) cin >> P[i];

  int l = 1;

  set<int> st;
  bool ne[N + 1];
  int inc[N + 1];

  REP(i, N) {
    ne[P[i]] = st.find(P[i] + 1) == st.end();
    st.insert(P[i]);
  }

  inc[N] = 1;
  for(int i = N - 1; i >= 1; i--) {
    if(ne[i]) inc[i] = inc[i + 1] + 1;
    else inc[i] = 1;
    l = max(l, inc[i]);
  }

  cout << N - l << endl;
  
  return 0;

}

