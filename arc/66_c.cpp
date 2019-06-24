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
const int MAX_N = 100000;
ll A[MAX_N];

// return x^n % p  O(log n)

ll mod_pow(ll x, ll n, ll p) {
  if(n == 0) return 1;
  ll res = mod_pow(x * x % p, n / 2, p);
  if(n & 1) res = res * x % p;
  return res;
}

int main(){
  cin >> N;
  REP(i, N) cin >> A[i];
  map<int, int> mp;
  REP(i, N) mp[A[i]]++;
  if(N % 2 == 0) {
    REP(i, N / 2) {
      if(mp[i * 2 + 1] != 2) {
        cout << 0 << endl;
        return 0;
      }
    }
    cout << mod_pow(2, N / 2, MOD) << endl;
  } else {
    REP(i, N / 2) {
      if(mp[i * 2 + 2] != 2) {
        cout << 0 << endl;
        return 0;
      }
    }
    if(mp[0] != 1) {
      cout << 0 << endl;
      return 0;
    }
    cout << mod_pow(2, N / 2, MOD) << endl; 
  }



  return 0;
}
