// "In the name of Allah, most gracious and most merciful"
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << (#x) << " = " << x << endl;
#define ll long long
#define el "\n"
#define nl cout << "\n";
#define all(v) v.begin(), v.end()
#define vec_print(v) \
    for (auto itr : v) cout << itr << " "; cout << endl;
#define vec_print_err(v) \
    for (auto itr : v) cerr << itr << " "; cerr << endl;

const ll MAXN = 1000001;
vector <int> spf(MAXN);

void PrimeFactorization(int N) {
    for(int i = 2; i * i <= N; i++) {
        if(N % i == 0) {
            int cnt = 0;
            while(N % i == 0) {
                N /= i;
                cnt++;
            }

            cout << i << "^" << cnt << endl;
        }
        
    }
    if(N > 1) cout << N << "^" << 1 << endl;
}

void PrimeFactorizationSieve() {
    for(int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }        

    for(int i = 2; i * i <= MAXN; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= MAXN; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    } 
}

vector <int> getPrimeFactors(int N) {
    vector <int> factors;    

    while(N != 1) {
        factors.push_back((spf[N]));
        N /= spf[N];
    }
    return factors;
}
// vector <int> primes(1000001), pp(1000001);
void solve() {
    vector <int> v = {1};
    cout << v.back() << " " << v.front() << "\n";
    v.pop_back();
    cout << v.back();
}

int main() {
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