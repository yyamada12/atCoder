#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
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

int N, M;
const int MAX_N = 100000, MAX_M = 100000;
int A[MAX_M], B[MAX_M];

bool used[MAX_N];
vi G[MAX_N];

vi dfs(int v) {
  used[v] = true;
  REP(i, G[v].size()) {
    if(!used[G[v][i]]) {
      vi res = dfs(G[v][i]);
      res.push_back(v);
      return res;
    }
  }
  vi res{v};
  return res;
}

int main(){
  cin >> N >> M;
  REP(i, M){
    cin >> A[i] >> B[i];
    G[A[i] - 1].push_back(B[i] - 1);
    G[B[i] - 1].push_back(A[i] - 1);
  } 

  REP(i, N) used[i] = false;

  vi ans = dfs(0);
  reverse(ALL(ans));
  vi ans2 = dfs(0);
  ans2.pop_back();
  ans.insert(ans.begin(), ALL(ans2));

  int l = ans.size();
  cout << l << endl;
  REP(i, l) {
    cout << ans[l - 1 - i] + 1;
    if(i != l - 1) cout << " ";
    else cout << endl;
  }

  return 0;
}

