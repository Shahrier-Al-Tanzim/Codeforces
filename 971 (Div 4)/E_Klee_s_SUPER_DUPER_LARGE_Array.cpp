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

int diff(int l, int r) {
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}

void solve() {
    int n, k; cin >> n >> k;
    int l = k, r = n + k - 1;
    int ans = LLONG_MAX;

    while(l <= r) {
        int mid = (l + r) / 2;
        int sum1 = diff(k, mid);
        int sum2 = diff(mid + 1, n + k - 1);
        ans = min(ans, abs(sum1 - sum2));

        if(sum1 > sum2) r = mid - 1;
        else l = mid + 1;
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
