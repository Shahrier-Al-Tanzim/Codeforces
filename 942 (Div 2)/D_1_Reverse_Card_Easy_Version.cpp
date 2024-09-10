#include <bits/stdc++.h>
using namespace std;   

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        char c = s.front();
        if(c >= 'A' and c <= 'Z') c = char(c + 32);
        for(char i = 'a'; i <= 'z'; i++) {
            if(c == i) continue;
            cout << i;
        }

        cout << endl;
    }
}
