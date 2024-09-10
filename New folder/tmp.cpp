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

int longestPalindrome(string s) {
    map <char, int> mp;
    for(auto i : s) mp[i]++;
    int cnt = 0;
    int Max = 0;
    for(auto [a, b] : mp) {
        Max = max(Max, b);
    }

    int f = 0;
    for(auto [a, b] : mp) {
        if(b == Max and f == 0) {
            f = 1;
            continue;
        }

        cnt += b / 2;
    }
    cnt *= 2;
    for(auto [a, b] : mp) {
        if(b == 1 and b != Max) {
            cnt++;
            break;
        }
    }
    return cnt + Max;

}

void solve() {
    cout << longestPalindrome("a") << endl;
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
