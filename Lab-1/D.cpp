#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define m n/2

using namespace std;


// check if A and B are sloppy shuffles of each other
bool is_sloppy_shuffle(string A, string B, int n) {
    if (A == B)
        return true;
    else if (n%2 == 1)
        return false;
    else {
        string A1 = A.substr(0, m);
        string A2 = A.substr(m, m);
        string B1 = B.substr(0, m);
        string B2 = B.substr(m, m);
        return (
            is_sloppy_shuffle(A1, B1, m) && is_sloppy_shuffle(A2, B2, m) ||
            is_sloppy_shuffle(A1, B2, m) && is_sloppy_shuffle(A2, B1, m)
        );
    }
}


int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        string A, B;
        cin >> A >> B;
        cout << (is_sloppy_shuffle(A, B, n) ? "YES" : "NO") << endl;
    }

    return 0;
}