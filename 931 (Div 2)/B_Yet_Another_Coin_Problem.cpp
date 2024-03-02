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
    int n; cin >> n;
    vector <int> ans ={0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3};
    if(n < 15) cout << ans[n] << endl;
    else if(n % 15 == 5) cout << n / 15 + 1 << endl;
    else if(n % 15 == 8) cout << n / 15 + 2 << endl;
    else cout << n / 15 + ans[n % 15] << endl;
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
