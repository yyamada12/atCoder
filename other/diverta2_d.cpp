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

ll N, ga, sa, ba, gb, sb, bb;

ll solve3(ll N, ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
  ll res = N;
  REP(g, N / a1 + 1) {
    REP(s, N / a2 + 1) {
      ll rem = N - g * a1 - s * a2;
      if(rem >= 0) {
        ll b = rem / a3;
        rem = rem - b * a3;
        res = max(res, g * b1 + s * b2 + b * b3 + rem);
      }
    }
  }
  return res;
}

ll solve2(ll N, ll a1, ll a2, ll b1, ll b2) {
  ll res = N;
  REP(s, N / a1 + 1) {
    ll rem = N - s * a1;
    ll b = rem / a2;
    rem = rem - b * a2;
    res = max(res, s * b1 + b * b2 + rem);
  }
  return res; 
}

ll solve1(ll N, ll a1, ll b1) {
  ll res = N;
  ll g = N / a1;
  ll rem = N - g * a1;
  return g * b1 + rem;
}

int main(){
  cin >> N >> ga >> sa >> ba >> gb >> sb >> bb;

  vll goa, gob, backa, backb;
  if(ga < gb) {
    goa.pb(ga); gob.pb(gb);
  } else if (ga > gb) {
    backa.pb(gb); backb.pb(ga);
  }

  if(sa < sb) {
    goa.pb(sa); gob.pb(sb);
  } else if (sa > sb) {
    backa.pb(sb); backb.pb(sa);
  }

  if(ba < bb) {
    goa.pb(ba); gob.pb(bb);
  } else if(ba > bb) {
    backa.pb(bb); backb.pb(ba);
  }

  ll N2;

  if(goa.size() == 3) {
    N2 = solve3(N, goa[0], goa[1], goa[2], gob[0], gob[1], gob[2]);
  } else if (goa.size() == 2) {
    N2 = solve2(N, goa[0], goa[1], gob[0], gob[1]);
  } else if (goa.size() == 1) {
    N2 = solve1(N, goa[0], gob[0]);
  } else {
    N2 = N;
  }

  ll ans;

  if(backa.size() == 3) {
    ans = solve3(N2, backa[0], backa[1], backa[2], backb[0], backb[1], backb[2]);
  } else if (backa.size() == 2) {
    ans = solve2(N2, backa[0], backa[1], backb[0], backb[1]);
  } else if (backa.size() == 1) {
    ans = solve1(N2, backa[0], backb[0]);
  } else {
    ans = N2;
  }
  
  cout << ans << endl;

  return 0;
}
