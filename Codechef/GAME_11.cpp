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
    int n, m; cin >> n >> m;
    
    vector <int> bat(n), bowl(m);
    for(auto &i : bat) cin >> i;
    for(auto &i : bowl) cin >> i;
    if(n < 4 or m < 4 or n + m < 11) {cout << -1 << "\n"; return;}

    sort(all(bat));
    sort(all(bowl));
    // vec_print(bat);
    // vec_print(bowl);
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        cnt += bat.back() + bowl.back();
        bat.pop_back(); bowl.pop_back();
    }
    vector <int> rem;
    // if(!bat.empty())
    for(auto &i : bat) rem.push_back(i);
    // if(!bowl.empty())
    for(auto &i : bowl) rem.push_back(i);

    sort(all(rem));

    if(rem.size() < 3) {cout << -1 << "\n"; return;}
    for(int i = 0; i < 3; i++) {
        cnt += rem.back();
        rem.pop_back();
    }

    cout << cnt << "\n";
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
