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
    string s; cin >> s;
    map <char, int> mp;
    for(auto i : s) mp[i]++;

    int cnt = 0;
    
    if(n % 2) {
        cnt = 1;
        if(mp.size() == 1) {
            cout << cnt << endl;
            return;
        }

        if(mp.size() == 2) {
            char c = mp.begin()->first;
            for(auto [a, b] : mp) {
                if(b == (n / 2) + 1) c = a;
            }
            // cout << c << endl;
            int f = 0;
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == s[i+1] && s[i] == c) {
                    s.erase(s.begin() + i);
                    f = 1;
                    break;
                }
            }
            // cout << f << endl;
            if(!f) s.erase(s.begin() + (n - 1));            
        }

        if(mp.size() >= 3) {
            char c;
            int Min = mp.begin()->first;
            for(auto [a, b] : mp) {
                if(b <= Min) c = a, Min = b;
            }

            for(int i = 0; i < n; i++) {
                if(s[i] == c) {
                    s.erase(s.begin() + i);
                    break;
                }
            }
        }
    }
    
    

    // cout << s << endl;

    n = s.size();
    map <int, int> odd, even;
    for(int i = 0; i < n; i += 2) {
       odd[s[i]]++;
    }
    for(int i = 1; i < n; i += 2) {
        even[s[i]]++;
    }

    int cnt_odd = 0, cnt_even = 0;
    
    for(auto [a, b] : odd) {
        cnt_odd = max(cnt_odd, b);
    }
    for(auto [a, b] : even) {
        cnt_even = max(cnt_even, b);
    }   
    n = s.size() / 2;

    int ans = n - cnt_odd + n - cnt_even + cnt;
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
