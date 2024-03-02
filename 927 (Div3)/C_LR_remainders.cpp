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
    int n, k; cin >> n >> k;
    deque <int> v(n); for(auto &i : v) cin >> i;
    string s; cin >> s;
    int l = 0, r = n - 1;
    for(auto i : s) {
        if(l == r) break;
        if(i == 'L') l++;
        else r--;
    }

    vector <int> ans(n);
    ans.back() = v[l] % k;
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] == 'L') {
            l--;
            ans[i] = (ans[i + 1] * v[l]) % k;
        } else {
            r++;
            ans[i] = (ans[i + 1] * v[r]) % k;
        }
    }
    assert(l == 0);
    assert(r == n - 1);
    vec_print(ans);
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

// 0 1 2 3 4 5
// 1 2 3 4 5 6

// 3