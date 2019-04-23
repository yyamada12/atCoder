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

const int MAX_N = 1000000;
int prime[MAX_N];
bool is_prime[MAX_N + 1];

int sieve(int n) {
  int p = 0;
  for(int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[p++] = i;
      for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return p;
}

int a;

int main(){
  cin >> a;
  cout << sieve(a) << endl;
  
  return 0;
}
