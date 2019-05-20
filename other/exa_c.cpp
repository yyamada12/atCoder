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

int N, Q;
const int MAX_Q = 200000;
string s;
char t[MAX_Q], d[MAX_Q];

int main(){
  cin >> N >> Q;
  cin >> s;
  REP(i, Q) cin >> t[i] >> d[i];

  int rl, rr, lr, ll;
  int i = Q - 1;
  while(i >= 0) {
    if(s[N - 1] == t[i] && d[i] == 'R') {
      rl = N - 1;
      rr = N - 1;
      break;
    }
    i--;
  }

  while(i >= 0) {
    if(d[i] == 'L') {
      if(rr + 1 < N && s[rr + 1] == t[i]) rr++;
      if(s[rl] == t[i]) rl++;
    }
    else if(d[i] == 'R') {
      if(s[rr] == t[i]) rr--;
      if(rl - 1 >= 0 && s[rl - 1] == t[i]) rl--;
    }

    if(rr < rl) break;
  }

  int j = Q - 1;
  while(j >= 0) {
    if(s[0] == t[j] && d[j] == 'L') {
      ll = 0;
      lr = 0;
      break;
    }
    j--;
  }

  while(j >= 0) {
    if(d[j] == 'L') {
      if(lr + 1 < N && s[lr + 1] == t[j]) lr++;
      if(s[ll] == t[j]) ll++;
    }
    else if(d[j] == 'R') {
      if(s[lr] == t[j]) lr--;
      if(ll - 1 >= 0 && s[ll - 1] == t[j]) ll--;
    }

    if(lr < ll) break;
  }

  cout << "ll: " << ll << ", lr: " << lr << ", rr: " << rr << ", rl: " << rl << endl;

  cout <<  N - (ll - lr + 1 + rr - rl + 1) << endl;


  return 0;
}
