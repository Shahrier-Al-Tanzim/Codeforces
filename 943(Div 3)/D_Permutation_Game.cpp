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

int dp_b[200001], dp_s[200001];

// int func(int i, int cnt, vector <int> &v) {
//     if(cnt == v.size()) return 0;
//     if(dp_b[i] != -1) return dp_b[i];

//     for(auto it : v) {
//         int max = it + dp_bx[i+1];
//     }

//     return dp_b[i];
// }

void solve() {
    int n, k, b, s; cin >> n >>k >> b >> s;
    b--, s--;
    vector<int> p(n); for(auto &i : p) cin >> i;
    vector<int> v(n); for(auto &i : v) cin >> i;

    vector <pair <int, int>> vp(n);
    map<int, pair <int, int>> mp;
    for(int i = 0; i < n; i++) {
        int x = p[i] - 1;
        vp[i] = {v[i], x};
        mp[i] = {v[i], x};
    }

    // map_print(vp);
    // for(auto [a, b] : mp) {
    //     cout << a << " = " << b.first << " - " << b.second << endl;
    // }

    int Max = *max_element(all(v));
    // for B
    int x = b;
    vector <int> B;
    B.push_back(v[x]);
    x = mp[x].second;
    if(B.back() != Max)
    while(x != b)  {
        B.push_back(mp[x].first);
        if(mp[x].first == Max) break;
        x = mp[x].second;
    }

    vector <int> S;
    x = s;
    S.push_back(v[x]);
    x = mp[x].second;
    if(S.back() != Max)
    while(x != s) {
        S.push_back(mp[x].first);
        if(mp[x].first == Max) break;
        x = mp[x].second;
    }

    S.insert(S.begin(), 0);
    B.insert(B.begin(), 0);
    // vec_print(S);
    // vec_print(B);
    int Sasha = 0, Bodya = 0;
    int cnt_s = 0, cnt_b = 0;
    

    for(int i = 1, j = k; i < S.size() and j >= 0; i++, j--) {
        cnt_s += S[i-1];
        int x = cnt_s + S[i] * j;
        Sasha = max(Sasha, x);
        // cout << x << " ";
    }
    // nl;
    // cout << cnt_s << endl;
    for(int i = 1, j = k; i < B.size() and j >= 0; i++, j--) {
        cnt_b += B[i-1];
        int x = cnt_b + B[i] * j;
        Bodya = max(Bodya, x);
        // cout << x << " ";
    }
    // nl;
    // cout << cnt_b << endl;
    // cout << Sasha << " " << Bodya << endl;
    if(Sasha == Bodya) cout << "Draw" << endl;
    else if(Sasha > Bodya) cout << "Sasha" << endl;
    else cout << "Bodya" << endl;
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
