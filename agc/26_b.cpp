#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
#include <set>
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
const int MAX_N = 300;
ll A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

ll gcd (ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cin >> N;
  REP(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];
  REP(i, N) {
    if(A[i] < B[i] || D[i] < B[i] || A[i] % B[i] > C[i]) {
      cout << "No" << endl;
      continue;
    }
    if(B[i] <= C[i]) {
      cout << "Yes" << endl;
      continue;
    }
    ll g = gcd(B[i], D[i]);
    ll x = A[i] % B[i];
    if(B[i] - g + x % g <= C[i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  return 0;

}

