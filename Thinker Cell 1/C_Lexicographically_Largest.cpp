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
    vector <int> v(n); for(auto &i : v) cin >> i; 
    vector <int> pos(n); for(auto &i : pos) cin >> i; 
    map <int, int> mp;
    for(int i = 0; i < n; i++) {
        int x = abs(0 - pos[i]);
        // cout << x << " ";
        // if(mp[x]) mp[x] += v[i];
        // else mp[x] = v[i];
         mp[x] += v[i];
    }
    // nl;
    // map_print(mp);

    int extra = 0, extra_step = 0;
    int i = 0;
    string ans = "YES";
    // cerr << "A " << " h " << "st " << " bu ex" << endl;
    for(auto &[a, b]: mp) {
        int A = a - extra_step;
        int h = b - extra;

        int step = h / k; if(h % k) step++;

        if(step > A) {ans = "NO"; break;}

        int bullet = step * k;

        // bullet +=  extra;
        // cerr << A << "  " << h << "  " << step << "   " << bullet << " ";
        if(bullet < h) {ans = "NO"; break;}
        bullet -= h;
        extra += bullet;
        // cerr << extra << endl;
        extra_step = step;

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

// extra = 0; 
// bul = 1 * 2 = 2;
// bul -= 1; bul = 1
// extra = 1

// bul = 2 1