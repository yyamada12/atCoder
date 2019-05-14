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

int c1, c5, c10, c50, c100, c500;
int A;

int main(){
  cin >> c1 >> c5 >> c10 >> c50 >> c100 >> c500 >> A;

  int ans = 0;
  while(c500 > 0 && A >= 500) {
    ans++;
    c500--;
    A -= 500;
  }
  while(c100 > 0 && A >= 100) {
    ans++;
    c100--;
    A -= 100;
  }
  while(c50 > 0 && A >= 50) {
    ans++;
    c50--;
    A -= 50;
  }
  while(c10 > 0 && A >= 10) {
    ans++;
    c10--;
    A -= 10;
  }
  while(c5 > 0 && A >= 5) {
    ans++;
    c5--;
    A -= 5;
  }
  while(c1 > 0 && A >= 1) {
    ans++;
    c1--;
    A -= 1;
  }

  cout << ans << endl;


  return 0;
}
