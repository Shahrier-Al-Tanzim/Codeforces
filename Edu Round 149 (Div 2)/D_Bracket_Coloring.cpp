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

    int open = 0, close = 0;
    for(auto i : s) {
        if(i == '(') open ++;
        else close ++;
    }

    if(open != close) {cout << -1 << endl; return;} 

    vector <int> ind(n);
    stack <char> shoja, ulta;
    stack <char> st;
    string tmp;
    for(int i = 0; i < n; i++) {
        if(st.empty()) {
            if(s[i] == '(') {
                ind[i] = 1;
            } else {
                ind[i] = 2;
            }
            st.push(s[i]);
        } else {
            if(st.top() == '(') {
                ind[i] = 1;
                if(s[i] == ')') {
                    st.pop();
                } else {
                    ind[i] = 1;
                    st.push(s[i]);
                }
            } else if(st.top() ==')') {
                ind[i] = 2;
                if(s[i] == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
    }
    set <int> stt;
    for(auto i : ind) stt.insert(i);
    cout << stt.size() << endl;
    if(stt.size() == 1) {
        for(int i = 0; i < n; i++) cout << 1 << " ";
    } else {
        for(auto i : ind) cout << i << " ";
    }
    nl;
    // "((())) )(";
    // ")))((("
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
