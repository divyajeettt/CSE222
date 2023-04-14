#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define COUNT(child) (count[child][0] + count[child][1])

using namespace std;


void DFS(vector<int> tree[], int node, int parent, ll count[][2]) {
    count[node][0] = count[node][1] = 1;
    for (int child : tree[node]) {
        if (child == parent) continue;
        DFS(tree, child, node, count);
        count[node][0] = (count[node][0] * COUNT(child)) % MOD;
        count[node][1] = (count[node][1] * count[child][0]) % MOD;
    }
}


int main() {
    int N;
    cin >> N;

    vector<int> tree[N];
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    ll count[N][2];
    DFS(tree, 0, -1, count);
    cout << COUNT(0) % MOD << endl;

    return 0;
}