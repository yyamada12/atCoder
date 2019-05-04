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

string A;

int main(){
  cin >> A;
  ll l = A.size();

  map<char, ll> mp;
  REP(i, l) {
    mp[A[i]]++;
  }

  ll ans = l * (l - 1) / 2 + 1;

  char c = 'a';
  REP(i, 26) {
    ans -= mp[c] * (mp[c] - 1) / 2;
    c = char(c + 1);
  }

  cout << ans << endl;
  
  return 0;
}

