// "In the name of Allah, most gracious and most merciful"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define int long long
#define el "\n"
#define nl cout << "\n";
#define stp setprecision
#define fixed_stp fixed << setprecision
#define vec_print(v) for  (auto itr : v) cout << itr << " "; nl;
#define map_print(v) for  (auto [it1, it2] : v) cout << it1 << " " << it2 << endl;
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pi 2 * acos(0.0)
#define all(v) v.begin(), v.end() 

void solve() {
  string s; cin >> s;
  vector <string> vs;
  int cnt = 0;
  string tmp = "";
  s += '1';
  for(int i = 0; i < s.size() - 1; i++) {
    tmp += s[i];
    if(s[i] == '1' and s[i+1] == '0') {
      vs.push_back(tmp);
      tmp = "";
    }
  }
  if(!tmp.empty()) vs.push_back(tmp);
  // for(auto i : vs) cout << i << endl;
  int o = 0, z = 0, oz = 0;
  for(auto i : vs) {
    if(i[0] == '1') o++;
    else {
      int f = 0;
      for(auto j : i) f = (j == '1');
      if(f) oz++; 
      else z++;
    }
  }
  // cout << o << " " << z << " " << oz << endl;
  oz *= 2;
  if(oz >= 2) oz--;
  cout << o + z + oz<< endl;
}   

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    cin >> t; 
    for(int i = 1; i <= t; i++) {
    // while(t--) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
}
