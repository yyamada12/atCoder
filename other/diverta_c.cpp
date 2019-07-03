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

ll N;
const ll MAX_N = 10000;
string s[MAX_N];

int main(){
  cin >> N;
  REP(i, N) cin >> s[i];
  ll numa = 0, numb = 0, numab = 0;
  REP(i, N) {
    if(s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') {
      numab++;
    } else if(s[i][0] == 'B') {
      numb++;
    } else if(s[i][s[i].size() - 1] == 'A') {
      numa++;
    }
  }

  ll num = 0;
  REP(i, N) {
    REP(j, s[i].size() - 1) {
      if(s[i][j] == 'A' && s[i][j + 1] == 'B') {
        num++;
      } 
    }
  }

  ll m = min(numa, numb);
  if(m > 0) {
    cout << numab + m + num << endl;
  } else if(numa == numb && numab > 0) {
    cout << numab - 1 + num << endl;
  } else {
    cout << numab + num << endl;
  }


  return 0;
}
