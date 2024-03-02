// "In the name of Allah, most gracious and most merciful"
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << (#x) << " = " << x << endl;
#define int long long
#define ll long long
#define el "\n"
#define nl cout << "\n";
#define all(v) v.begin(), v.end()
#define vec_print(v) \
    for (auto itr : v) cout << itr << " "; cout << endl;
#define vec_print_err(v) \
    for (auto itr : v) cerr << itr << " "; cerr << endl;

void solve() {
    int a, b, l; cin >> a >> b >> l;
    vector <int> ans;
    while(1) {
        int r = l;
        while(1) {
            ans.push_back(r);
            if(r % b != 0) break;
            r /= b;
        }

        if(l % a != 0) break;
        l /= a;
    }

    sort(all(ans));
    cout << unique(all(ans)) - ans.begin() << endl;
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