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

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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

int N, M;
int S[15][15];

int main(){
  cin >> N >> M;
  REP(i, N) REP(j, M) cin >> S[i][j];

  int ans[N][M], col[N][M]; 
  REP(k, 1 << M) {
    REP(i, N) REP(j, M) {
      ans[i][j] = 0;
      col[i][j] = S[i][j];
    }
    REP(s, M) {
      if(k >> s & 1) {
        ans[0][s] = 1;
        if(s > 0) col[0][s - 1] = 1 - col[0][s - 1];
        col[1][s] = 1 - col[1][s];
        if(s < M - 1) col[0][s + 1] = 1 - col[0][s + 1];
      }
    }
    REP(i, N) {
      if (i == 0) continue;
      REP(j, M) {
        if(col[i- 1][j] == 1) {
          ans[i][j] = 1;
          col[i][j] = 1 - col[i][j];
          REP(d, 4){
            int di = i + dirx[d];
            int dj = j + diry[d];
            if(di >= 0 && di < N && dj >= 0 && dj < M) {
              col[di][dj] = 1 - col[di][dj];
            }
          }
        }
      }
    }
    bool flag = true;
    REP(j, M) {
      if(col[N - 1][j] == 1) {
        flag = false;
        break;
      }
    }
    if(flag) {
      REP(i, N) {
        REP(j, M) {
          if(j != M -1)cout << ans[i][j] << " ";
          else cout << ans[i][j];
        }
        cout << endl;
      }
      return 0;
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
