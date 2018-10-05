#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

namespace sf {
  string S;
  int n, gap, sa[MAXN], temp[MAXN], pos[MAXN], lcp[MAXN];
  
  bool sufCmp(int i, int j) {
    if(pos[i] != pos[j])
      return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < n && j < n) ? pos[i] < pos[j] : i > j;
  }
 
  void buildSA() {
  	n = S.size();
    for(int i=0; i<n; i++) sa[i] = i, pos[i] = S[i];
    for(gap = 1 ;; gap *= 2) {
      sort(sa, sa+n, sufCmp);
      for(int i=0; i<n-1; i++) temp[i+1] = temp[i] + sufCmp(sa[i], sa[i+1]);
      for(int i=0; i<n; i++) pos[sa[i]] = temp[i];
      if(temp[n-1] == n-1) break;
    }
  }
 
  void buildLCP() {
    for(int i=0, k=0; i<n; i++) if (pos[i] != n-1) {
      for(int j = sa[pos[i] + 1]; S[i+k] == S[j+k];) ++k;
      lcp[pos[i]] = k;
      if(k) --k;
    }
  }
};

int main() {
    sf::S = "suffixarray";
    sf::buildSA();
    sf::buildLCP();
    return 0;
};