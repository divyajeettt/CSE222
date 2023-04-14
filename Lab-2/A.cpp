#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;


int main() {
    int N;
    cin >> N;

    ll cards[N][2];
    for (int i = 0; i < N; i++) {
        cin >> cards[i][0] >> cards[i][1];
    }

    ll elegant[N][2];
    memset(elegant, 0, sizeof(elegant));
    elegant[0][0] = elegant[0][1] = 1;
    if (cards[0][0] == cards[0][1])
        elegant[0][1] = 0;

    for (int i = 1; i < N; i++) {
        if (cards[i][0] != cards[i-1][0]) {
            elegant[i][0] = (elegant[i][0] + elegant[i-1][0]) % MOD;
        }
        if (cards[i][0] != cards[i-1][1]) {
            elegant[i][0] = (elegant[i][0] + elegant[i-1][1]) % MOD;
        }
        if (cards[i][1] != cards[i-1][0]) {
            elegant[i][1] = (elegant[i][1] + elegant[i-1][0]) % MOD;
        }
        if (cards[i][1] != cards[i-1][1]) {
            elegant[i][1] = (elegant[i][1] + elegant[i-1][1]) % MOD;
        }
        if (cards[i][0] == cards[i][1]) {
            elegant[i][1] = 0;
        }
    }

    cout << (elegant[N-1][0] + elegant[N-1][1]) % MOD << endl;

    return 0;
}