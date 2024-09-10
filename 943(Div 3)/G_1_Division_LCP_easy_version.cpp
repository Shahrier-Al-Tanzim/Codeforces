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

typedef long long LL;
typedef pair<LL, LL> PLL;

namespace Hashing {
    #define ff first
    #define ss second

    const PLL M = {1e9+7, 1e9+9};        ///Should be large primes
    const LL base = 1259;                ///Should be larger than alphabet size
    const int N = 1e6+7;                 ///Highest length of string

    PLL operator+ (const PLL& a, LL x)     {return {a.ff + x, a.ss + x};}
    PLL operator- (const PLL& a, LL x)     {return {a.ff - x, a.ss - x};}
    PLL operator* (const PLL& a, LL x)     {return {a.ff * x, a.ss * x};}
    PLL operator+ (const PLL& a, PLL x)    {return {a.ff + x.ff, a.ss + x.ss};}
    PLL operator- (const PLL& a, PLL x)    {return {a.ff - x.ff, a.ss - x.ss};}
    PLL operator* (const PLL& a, PLL x)    {return {a.ff * x.ff, a.ss * x.ss};}
    PLL operator% (const PLL& a, PLL m)    {return {a.ff % m.ff, a.ss % m.ss};}
    ostream& operator<<(ostream& os, PLL hash) {
        return os<<"("<<hash.ff<<", "<<hash.ss<<")";
    }
    PLL pb[N];      ///powers of base mod M

    ///Call pre before everything
    void hashPre() {
        pb[0] = {1,1};
        for (int i=1; i<N; i++)     pb[i] = (pb[i-1] * base)%M;
    }

    ///Calculates hashes of all prefixes of s including empty prefix
    vector<PLL> hashList(string s) {
        int n = s.size();
        vector<PLL> ans(n+1);
        ans[0] = {0,0};
        for (int i=1; i<=n; i++)    ans[i] = (ans[i-1] * base + s[i-1])%M;
        return ans;
    }

    ///Calculates hash of substring s[l..r] (1 indexed)
    PLL substringHash(const vector<PLL> &hashlist, int l, int r) {
        return (hashlist[r]+(M-hashlist[l-1])*pb[r-l+1])%M;
    }
}

using namespace Hashing;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;

    auto hash_list = hashList(s);
    
    int lo = 0, hi = n+1;
    while(hi - lo > 1) {
        int cnt = 1;
        int len = (lo + hi) >> 1;
        auto pre = substringHash(hash_list, 1, len);
        for(int i = len+1; i + len - 1 <= n; i++) {
            if(substringHash(hash_list, i, i + len - 1) == pre) {
                i = i + len - 1;
                cnt++;
            }
        }

        if(cnt < l) hi = len;
        else lo = len;
    }

    cout << lo << endl;
}   

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    
    hashPre();
    int t = 1;
    cin >> t; 
    for(int i = 1; i <= t; i++) {
    // while(t--) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
}
