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

string S;

int main(){
  cin >> S;
  if(S.length() < 26) {
    map<char, int> mp;
    REP(i, S.length()){
      mp[S[i]]++;
    }
    REP(i, 26) {
      if(mp[char('a' + i)] == 0) {
        cout << S + char('a' + i) << endl;
        return 0;
      }
    }
  } else if(S == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
    return 0;
  } else {
    map<char, int> mp;
    priority_queue<char> pq;
    pq.push(S[25]);
    mp[S[25]]++;
    int i = 24;
    while(S[i] > pq.top()) {
      pq.push(S[i]);
      mp[S[i]]++;
      i--;
    }
    REP(j, 26) {
      if(char('a'+ j) > S[i] && mp[char('a' + j)] > 0) {
        cout << S.substr(0, i) + char('a' + j) << endl;
        return 0;
      }
    }

  }
}

