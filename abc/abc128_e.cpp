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

ll N, Q;
const ll MAX_N = 200000, MAX_Q = 200000;
ll S[MAX_N], T[MAX_N], X[MAX_N];
ll D[MAX_Q];

struct Event {
  ll time;
  int type;
  ll x;
};

bool comp(const Event& lhs, const Event& rhs) {
  if(lhs.time == rhs.time) {
    return lhs.type < rhs.type;
  } else {
    return lhs.time < rhs.time;
  }
}

int main(){
  cin >> N >> Q;
  REP(i, N) cin >> S[i] >> T[i] >> X[i];
  REP(i, Q) cin >> D[i];

  vector<Event> events;
  REP(i, N) {
    events.pb(Event{S[i] - X[i], 1, X[i]});
    events.pb(Event{T[i] - X[i], -1, X[i]});
  }

  sort(ALL(events), comp);

  set<ll> st;

  int itr = 0;
  REP(i, Q) {
    while(itr < 2 * N && events[itr].time <= D[i]) {
      Event e = events[itr];
      if(e.type == 1) {
        st.insert(e.x);
      } else {
        st.erase(e.x);
      }
      itr++;
    }
    if(st.empty()) {
      cout << -1 << endl;
    } else {
      cout << *st.begin() << endl;
    }
  }

  return 0;
}
