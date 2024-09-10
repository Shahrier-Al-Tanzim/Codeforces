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
    // vector <int> v = {1, 2};
    // vector <int> v = {1, 2, 3, 4};
    vector <int> v = {1, 2, 3, 4, 5};
    // vector <int> v = {1, 2, 3, 4, 5, 6};
    // vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 1 2 3 4  5  6  7  8  9 10
    // 0 2 4 8 12 18 24 32 40 50
    //   2 2 4 4  6  6  8  8  10  
    //0 1 1 2 2  3 3   4 4   5
    int ind = -1;
    int CNT = 0;
    for(int i = 1; i < n; i++) {
        int x = (i + 1) / 2;
        CNT += 2 * x;
        if(CNT <= k) ind = i + 1;
    }
    // cout << "CNT = ";
    // cout << CNT << endl;
    // cout << "IND = ";
    // cout  << ind << endl;
    cerr << ind << " ";
    if(k % 2 != 0 or k > CNT) {cout << "No" << endl; cerr <<"Yes"<< endl; return;}
    cout << "Yes" << endl;
    
    int sum = 0;
    if(ind == -1) {
        for(int i = 1; i <= n; i++) cout << i << " ", sum += (i - i);
        nl;
        if(sum != k) cerr << "No" << endl;
        else cerr << "Yes" << endl;
        return;
    }

    vector <int> ans;
    for(int i = ind; i >= 1; i--) ans.push_back(i);
    for(int i = ind + 1; i <= n; i++) ans.push_back(i);

    for(int i = 0; i < n; i++) sum += abs((i+1) - ans[i]);
    // cout << "SUM = ";
    // cout << sum << endl;
    
    if(sum < k) swap(ans[n - 1], ans[n - 2]);
    
    sum = 0;
    for(int i = 0; i < n; i++) sum += abs((i+1) - ans[i]);
    
    if(sum != k) cerr << "No" << endl;
    else cerr << "Yes" << endl;
    
    // cout << "ANS  = ";
    vec_print(ans);
    
    
    // cout << "SUM = " << sum << endl;
    // nl;
    int Max = 0;
    map <vector <int>, int> mp;
    vector <pair <int, vector <int>>> vp;
    do {
        // for(auto i : v) cout << i << " ";
        // cout << " = ";
        int cnt = 0;
        for(int i = 0; i < v.size(); i++) {
            cnt += abs(i + 1 - v[i]);
        }
        vp.push_back({cnt, v});
        // mp[v] = cnt;
        // Max = max(Max, cnt);
        // cout << cnt << endl;
    } while(next_permutation(all(v)));

    sort(all(vp));
    for(auto [a, b] : vp) {
        for(auto i : b) cout << i << " ";
        cout << " = " << a << endl;
    }
    // cout << Max << endl;
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
