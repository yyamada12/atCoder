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

int N;
int x;

int main(){
  cin >> N;
  cin >> x;
  if(x == 1 || x == 2 * N - 1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  if(x < N) {
    for(int i = 2; i < N; i++) {
      if(i == x) continue;
      cout << i << endl;
    }
    cout << N << endl;
    cout << x << endl;
    cout << 1 << endl;
    for(int i = N + 1; i < 2 * N; i++){
      cout << i << endl;
    }
  } else {
    for(int i = 1; i < N - 1; i++) {
      cout << i << endl;
    }
    cout << 2 * N - 1 << endl;
    cout << x << endl;
    cout << N - 1 << endl;
    for(int i = N; i < 2 * N - 1 ; i++) {
      if(i == x) continue;
      cout << i << endl;
    }
  }

  return 0;
}
