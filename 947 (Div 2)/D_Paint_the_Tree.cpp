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

vector <int> g[100005];

void bfs(int root, vector <int> &dist_) {
    queue <int> q;
    q.push(root);
    dist_[root] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto ch : g[node]) {
            if(dist_[ch] == -1) {
                dist_[ch] = dist_[node] + 1;
                q.push(ch);
            }
        }
    }
}


void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    a--, b--;
    
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> a_dist(n, -1), b_dist(n, -1);

    bfs(a, a_dist);
    bfs(b, b_dist);
    for(int i = 0; i < n; i++) {
        cout << i << " = " << a_dist[i] << endl;
    }
    cout << "======" << endl;
    for(int i = 0; i < n; i++) {
        cout << i << " = " << b_dist[i] << endl;
    }
    int Max = n;
    for(int i = 0; i < n; i++) {
        // Max = min(Max, min(a_dist[i], b_dist[i]));
        int d = a_dist[i] + b_dist[i] >> 1;
        Max = min(Max, d);
    }

    cout << Max << endl;
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
