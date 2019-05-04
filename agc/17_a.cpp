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

ll N, P;
const int MAX_N = 50;
ll A[MAX_N];

int main(){
  cin >> N >> P;
  REP(i, N) cin >> A[i];

  int odd_n = 0, even_n = 0;
  REP(i, N) {
    if(A[i] % 2 == 0) {
      even_n++;
    } else {
      odd_n++;
    }
  }

  if(odd_n == 0) {
    if(P == 1) cout << 0;
    else cout << ll(pow(2, N)) << endl;
  } else {
    cout << ll(pow(2, even_n) * pow(2, odd_n - 1)) << endl;
  }



  return 0;
}

