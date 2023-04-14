#include <bits/stdc++.h>

#define ll long long
#define pill pair<int, ll>
#define till tuple<int, ll, ll>
#define TIME(t) (t + Y/(t+1) + X)

using namespace std;


ll times[1000000];

int main() {
    int N, M;
    cin >> N >> M;

    vector<till> graph[N];
    for (int i = 0; i < M; i++) {
        int U, V;
        ll X, Y;
        cin >> U >> V >> X >> Y;
        graph[U-1].push_back({V-1, X, Y});
        if (U != V) graph[V-1].push_back({U-1, X, Y});
    }

    bool visited[N] = { false };
    priority_queue<pill, vector<pill>, function<bool(pill, pill)>> heap(
        [](pill a, pill b) { return a.second > b.second; }
    );

    for (int i = 0; i < N; i++) times[i] = LONG_LONG_MAX;
    heap.push({0, 0});
    times[0] = 0;

    while (!heap.empty()) {
        int node = heap.top().first;
        heap.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (till edge : graph[node]) {
            int child = get<0>(edge);
            if (visited[child]) continue;
            ll X = get<1>(edge);
            ll Y = get<2>(edge);
            ll opt_t = max(times[node], (ll) ceil(sqrt(Y)-1));
            if (times[child] > TIME(opt_t)) {
                times[child] = TIME(opt_t);
                heap.push({child, TIME(opt_t)});
            }
        }
    }

    if (times[N-1] != LONG_LONG_MAX) cout << times[N-1] << endl;
    else cout << -1 << endl;

    return 0;
}