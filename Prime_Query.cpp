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
    int n; cin >> n;
    vector<int> v(n); for(auto &i : v) cin >> i;
    v.insert(v.begin(), 0);
    vector <int> ones(n+1), twos(n+1);
    ones[0] = 0;
    for(int i = 1; i <= n; i++) {
        ones[i] = ones[i-1];
        if(v[i] == 1) ones[i]++;

        twos[i] = twos[i-1];
        if(v[i] == 2) twos[i]++;
    }

    // vec_print(ones);
    // vec_print(twos);
    
    int q; cin >> q;
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        int one = ones[r] - ones[l - 1]; 
        int two = twos[r] - twos[l - 1];
        int rem = r - l + 1 - one - two;
        
        cout << "one, two, rem = ";
        cout << one << " " << two << " " << rem << endl;
        int ans = 0;
        int Min = min(one, two), Max = max(one, two);
        ans = Min * Max;
        if(k) {
            if(rem >= k) rem = k, k = 0;
            else k -= rem;
            cout << "rem , k = ";
            cout << rem << " " << k << endl;
            if(rem) {
                Min = min(one, two), Max = max(one, two);
                
                int x = Max - Min;
                if(x >= rem) {
                    Min += rem;
                    k -= rem;
                    rem = 0;
                } else {
                    Min += x;
                    rem -= x;
                    k -= x;
                }
                if(rem) {
                    rem /= 2;
                    Min += rem;
                    Max += rem;
                    rem = 0;
                }

                cout << "Update rem = " << rem << endl;
                cout << "Updated Max Min = " << Max << " " << Min << endl;
                if(!k) ans = Min * Max;
                else {
                     int x = Max - Min;
                    cout << "x = " << x << endl;
                    x = min(x, k);
                    x /= 2;
                    Min += x;
                    Max -= x;
                    ans = Min * Max;
                }
            }
            else {
                int x = Max - Min;
                cout << "x = " << x << endl;
                x /= 2;
                x = min(x, k);
                Min += x;
                Max -= x;
                ans = Min * Max;
            }
        }
        cout << "Min , Max = ";
        cout << Min << " " << Max << endl;
        cout << "ans = ";
        cout << ans << endl;
    }
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
