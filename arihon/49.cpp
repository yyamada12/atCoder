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

int N;
const int MAX_N = 20000;
int L[MAX_N];

int main(){
  cin >> N;
  REP(i, N) cin >> L[i];

  priority_queue<int, vector<int>, greater<int> > pq;
  REP(i, N) pq.push(L[i]);

  ll ans = 0;

  REP(i, N - 1) {
    int l1 = pq.top();
    pq.pop();
    int l2 = pq.top();
    pq.pop();
    ans += l1 + l2;
    pq.push(l1 + l2);
  }

  cout << ans << endl;

  return 0;
}
