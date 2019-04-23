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
