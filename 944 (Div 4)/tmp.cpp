#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename DT> 
using ordered_set = tree <DT, null_type, less<DT>, rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;


#define tcout(i) cout << "Case #" << i << ": "
const ll MOD = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e5+5;





void solve(int tc)
{   
    ll n, k, q; cin >> n >> k >> q;
    vector<ll> a(k), b(k);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    while(q--)
    {
        ll d; cin >> d;
        if(d==n)
        {
            cout << b[k-1] << ' ';
            continue;
        }
        ll i = upper_bound(a.begin(), a.end(), d)-a.begin();
        ll ap=0, bp=0;
        if(i) ap=a[i-1], bp=b[i-1];
        
        ll dist = a[i]-ap, time = b[i]-bp;
        // long double speed = (long double)dist/time;
        ll cur = ((d-ap)*time)/dist;
        
        // cout << i << '?'<< a[i] << '?' <<b[i] <<endl;
        // cout << dist<< '-' << time<< '-' << speed << endl;
        // cout << ap << '<' << bp << '<' << d << endl;

        cout <<  bp+cur<<' ';
    }
    
    cout << '\n';
}


signed main()
{
    cin.tie(0)->sync_with_stdio(0);





    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) solve(i);

    return 0;
}