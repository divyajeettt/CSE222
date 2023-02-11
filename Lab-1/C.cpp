#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define m n/2
#define a (*A)
#define b (*B)

using namespace std;


// bit flip B to make it equal to A
int flips(string *A, string *B, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            b[i] = a[i];
            count++;
        }
    }
    return count;
}


// count the number of flips required to make A and B sloppy shuffles of each other
int sloppy_shuffle(string *A, string *B, int n) {
    if (a == b)
        return 0;
    else if (n%2 == 1)
        return flips(A, B, n);
    else {
        string A1 = a.substr(0, m);
        string A2 = a.substr(m, m);

        string B11 = b.substr(0, m);
        string B12 = b.substr(0, m);
        string B21 = b.substr(m, m);
        string B22 = b.substr(m, m);

        int path1 = sloppy_shuffle(&A1, &B11, m) + sloppy_shuffle(&A2, &B21, m);
        int path2 = sloppy_shuffle(&A1, &B22, m) + sloppy_shuffle(&A2, &B12, m);

        if (path1 < path2) *B = B11 + B21;
        else *B = B12 + B22;

        return min(path1, path2);
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
        cout << sloppy_shuffle(&A, &B, n) << endl;
        cout << B << endl;
    }

    return 0;
}