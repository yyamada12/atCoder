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
