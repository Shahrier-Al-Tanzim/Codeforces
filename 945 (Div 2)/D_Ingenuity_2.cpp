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
    if(s.size() == 2) {
        if(s.front() == s.back()) cout << "HR" << endl;
        else cout << "NO" << endl;
        return;
    }
    map <char, char> com;
    com['N'] = 'S';
    com['S'] = 'N';
    com['E'] = 'W';
    com['W'] = 'E';

    map <char, int> mp;
    for(auto i : s) mp[i]++;

    // ========
    int cnt = 0;
    for(auto [a, b] : mp){
        if(b == 1) cnt++;
    }
    if(cnt == 4) {
        string t = s;
        int l = 0, r = 0;
        for(int i = 0; i < 4; i++) {
            if(t[i] == com[t[0]]) {
                r = i; 
                break;
            }
        }

        for(int i = 0; i < 4; i++) {
            if(i == l or i == r) t[i] = 'R';
            else t[i] = 'H';
        }
        cout << t << endl;
        return;
    }
    // ========
    // map_print(mp);
    // =======
    if(mp['N'] % 2 == 0) {
        if(mp['S'] % 2 == 1) {cout << "NO" << endl; return;}
    } else {
        if(mp['S'] % 2 == 0) {cout << "NO" << endl; return;}
        else {
            mp['N']--;
            mp['S']--;
        }
    }
    
    if(mp['E'] % 2 == 0) {
        if(mp['W'] % 2 == 1) {cout << "NO" << endl; return;} 
    } else {
        if(mp['W'] % 2 == 0) {cout << "NO" << endl; return;}
        else {
            mp['E']--;
            mp['W']--;
        }
    }
    // =========
    // cout << "===" << endl;
    // map_print(mp);

    map <char, int> tmp;
    tmp['N'] = mp['N'] / 2;
    tmp['S'] = mp['S'] / 2;
    tmp['E'] = mp['E'] / 2;
    tmp['W'] = mp['W'] / 2;
    // cout << "=====" << endl;
    // map_print(tmp);
    string t = s;
    // for R
    for(auto &i : t) {
        if(i == 'R') continue;
        if(mp[i] > tmp[i]) {
            mp[i]--;
            i = 'R';
        }
    }
    // cout << "========" << endl;
    // map_print(mp);
    // for H 
    for(auto &i : t) {
        if(i == 'R' or i == 'H') continue;
        if(tmp[i]) {
            tmp[i]--;
            i = 'H';
        }
    }

    // for others
    for(auto &i : t) {
        if(i != 'R' and i != 'H') i = 'H';
    }
    cout << t << endl;
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
