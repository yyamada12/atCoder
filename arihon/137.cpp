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
