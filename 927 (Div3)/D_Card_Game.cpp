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
    char t; cin >> t;
    vector <pair <char, char>> v(2 * n);
    map <char, deque <char>> mp;
    for(int i = 0; i < 2 * n; i++) {
        char a, c; cin >> a >> c;
        v[i] = {c, a};
        mp[c].push_back(a);
    }
    map <char, int> m;

    for(auto [a, b] : mp) {
        // cout << a << " = "; vec_print(b);
        if(a == t) m[a] = mp[a].size();
        else m[a] = mp[a].size() % 2;
    }

    // cout << "----------" << endl;
    int cnt = 0;
    for(auto [a, b] : m) {
        // cout << a << " = " << b << endl; 
        if(a != t) cnt += b;
    }

    if(cnt <= m[t]) {
        m[t] -= cnt;
        if(m[t] % 2 == 0) {
            vector <char> suits = {'H', 'D', 'S', 'C'};
            vector <pair <pair <char, char>, pair <char, char>>> ans;
            vector <pair <char, char>> res, trump;
            for(auto &[a, b] : mp) {
                sort(all(b));
            }
            for(auto st : suits) {
                if(st == t) {
                    for(int i = 0; i < mp[st].size(); i++) {
                        pair <char, char> p1 = {mp[st][i], st};
                        trump.push_back(p1);
                    }
                }
                else {
                    for(int i = 0; i < mp[st].size(); i += 2) {
                        if(mp[st].size() % 2 == 1 and i == mp[st].size() - 1) break;
                        pair <char, char> p1 = {mp[st][i], st};
                        pair <char, char> p2 = {mp[st][i+1], st};
                        ans.push_back({p1, p2});
                    }

                    if(mp[st].size() % 2 == 1) res.push_back({mp[st].back(), st});
                }
            }
            // map_print(res);
            // sort(all(trump));
            // map_print(trump);

            for(int i = 0; i < res.size(); i++) {
                pair <char, char> p1 = res[i];
                pair <char, char> p2 = trump[i];
                ans.push_back({p1, p2});
            }

            int sz = trump.size() - res.size();
            for(int i = res.size(); i < trump.size(); i += 2) {
                pair <char, char> p1 = trump[i];
                pair <char, char> p2 = trump[i+1];
                ans.push_back({p1, p2});
            }

            for(auto [a, b] : ans) {
                cout << a.first << a.second << " " << b.first << b.second << endl;
            }

        } 
        else cout << "IMPOSSIBLE" << endl;
    } 
    else cout << "IMPOSSIBLE" << endl;
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
