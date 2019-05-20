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

int w, h, N;
const int MAX_N = 500;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

int compress(int *X1, int *X2, int w) {
  set<int> st;
  REP(i, N) {
    st.insert(X1[i]);
    if(X1[i] > 1) st.insert(X1[i] - 1);
    if(X1[i] < w - 1) st.insert(X1[i] + 1);
    st.insert(X2[i]);
    if(X2[i] > 1) st.insert(X2[i] - 1);
    if(X2[i] < w - 1) st.insert(X2[i] + 1);
  }

  int i = 0;
  map<int, int> mp;
  for(auto itr = st.begin(); itr != st.end(); itr++) {
    mp[*itr] = i++;
    cout << *itr << endl;
  }
  REP(i, N) {
    X1[i] = mp[X1[i]];
    X2[i] = mp[X2[i]];
  }
  return st.size();
}

int main(){
  cin >> w >> h >> N;
  REP(i, N) cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i];

  w = compress(X1, X2, w);
  h = compress(Y1, Y2, h);

  REP(i, N) cout << X1[i] << ",";
  cout << endl;


  return 0;
}
