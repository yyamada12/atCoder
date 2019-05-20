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

ll H, W;
const int MAX_HW = 1000;
string A[MAX_HW];

struct ct{
  int x, y, c;
};

int main(){
  cin >> H >> W;
  REP(i, H) cin >> A[i];

  queue<ct> q;

  bool used[H][W];

  REP(i, H) {
    REP(j, W) {
      used[i][j] = false;
      if(A[i][j] == '#') {
        used[i][j] = true;
        q.push(ct{i, j, 0});
      }
    }
  }

  int ans = 0;

  while(!q.empty()) {
    ct crt = q.front();
    q.pop();
    ans = max(ans, crt.c);
    REP(d, 4) {
      int nx = crt.x + dirx[d];
      int ny = crt.y + diry[d];
     
      if(nx >= 0 && nx < H && ny >= 0 && ny < W && !used[nx][ny]) {
        q.push(ct{nx, ny, crt.c + 1});
        used[nx][ny] = true;
      }
    }
  }

  cout << ans << endl;


  return 0;
}

