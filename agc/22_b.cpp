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

int N;

int main(){
  cin >> N;
  if(N == 3) {
    cout << 2 << " " << 5 << " " << 63 << endl;
    return 0;
  }
  if(N <= 15002) {
    if((N - 2) % 3 == 1) {
      for(int i = 1; i <= N - 4; i++) {
        cout << i * 2 << " ";
      }
      cout << (N - 2) * 2 << " " << (N - 1) * 2 << " " << 3 << " " << 9 << endl;
    } else {
      for(int i = 1; i <= N - 2; i++) {
        cout << i * 2 << " ";
      }
      cout << 3 << " " << 9 << endl;
    }
  } else if(N % 2 == 0) {
    REP(i, 15000){
      cout << (i + 1) * 2 << " ";
    }
    REP(i, N - 15000) {
      cout << i * 6 + 3;
      if(i == N - 15000 - 1) cout << endl;
      else cout << " ";
    }
  } else {
    REP(i, 15000 - 1){
      cout << (i + 1) * 2 << " ";
    }
    REP(i, N - 15000 + 1) {
      cout << i * 6 + 3;
      if(i == N - 15000) cout << endl;
      else cout << " ";
    }
  }

  return 0;

}

