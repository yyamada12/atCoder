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

string S, T;
int q;
const int MAX_Q = 100000;
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];

int main(){
  cin >> S >> T >> q;
  REP(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  int s = S.size(), t = T.size();
  int sa[s + 1], sb[s + 1], ta[t + 1], tb[t + 1];
  int cta = 0, ctb = 0;
  sa[0] = 0; sb[0] = 0; ta[0] = 0; tb[0] = 0;
  REP(i, s) {
    if(S[i] == 'A') cta++;
    else ctb++;
    sa[i + 1] = cta;
    sb[i + 1] = ctb;
  }
  cta = 0, ctb = 0;
  REP(i, t) {
    if(T[i] == 'A') cta++;
    else ctb++;
    ta[i + 1] = cta;
    tb[i + 1] = ctb;
  }

  REP(i, q) {
    int nsa = sa[b[i]] - sa[a[i] - 1], nsb = sb[b[i]] - sb[a[i] - 1];
    int nta = ta[d[i]] - ta[c[i] - 1], ntb = tb[d[i]] - tb[c[i] - 1];
    if ((nsa - nta - (nsb - ntb)) % 3 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
