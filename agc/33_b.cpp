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

ll H, W, N;
int sr, sc;
string S, T;

bool count(char a, char b, int d, int s) {
  int res = s;
  REP(i, N) {
    if(S[i] == a) res++;
    if(res >= s + d) return true;
    if(T[i] == b && res > 0) res--;
  }

  return false;
}

int main(){
  cin >> H >> W >> N;
  cin >> sr >> sc;
  cin >> S;
  cin >> T;

  bool ans = count('L', 'R', sc, W - sc) || count('R', 'L', W - sc + 1, sc - 1) 
  || count('U', 'D', sr, H - sr) || count('D', 'U', H - sr + 1, sr - 1);

  if(ans) cout << "NO" << endl;
  else cout << "YES" << endl; 

  return 0;
}

