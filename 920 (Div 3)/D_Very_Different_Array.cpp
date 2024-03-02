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
    deque <int> v1(n), v2(m);
    for(auto &i : v1) cin >> i;
    for(auto &i : v2) cin >> i;

    sort(all(v1));
    // sort(v2.rbegin(), v2.rend());
    sort(all(v2));
    // vec_print(v1); 
    // vec_print(v2);
    int ans = 0;
    while(!v1.empty()) {
        // cout << v1.front() << " " << v1.back() << endl;
        if(v1.size() == 1) {
            ans += max(abs(v1.front() - v2.front()), abs(v1.front() - v2.back()));
            break;
        }

        int left = abs(v1.front() - v2.back());
        int right = abs(v1.back() - v2.front());
        if(left > right) {
            ans += left;
            v1.pop_front();
            v2.pop_back();
        } else {
            ans += right;
            v1.pop_back();
            v2.pop_front();
        }
    }

    cout << ans << endl;
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


