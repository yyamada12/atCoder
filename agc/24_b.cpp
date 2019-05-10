#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
#include <set>
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

