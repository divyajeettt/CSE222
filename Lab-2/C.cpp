#include <bits/stdc++.h>

#define ll long long
#define till tuple<int, ll, ll>

using namespace std;


ll times[1000000];

bool compare(int below, int above) { return times[below] > times[above]; }

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

    ll t[N] = { LONG_LONG_MAX };
    priority_queue<int, vector<int>, function<bool(int, int)>> heap(compare);
    for (int i = 0; i < N; i++) {
        times[i] = LONG_LONG_MAX;
        heap.push(i);
    }
    times[0] = t[0] = 0;

    while (!heap.empty()) {
        int node = heap.top();
        heap.pop();
        if (t[node] > times[node]) continue;
        for (till edge : graph[node]) {
            int child = get<0>(edge);
            ll X = get<1>(edge);
            ll Y = get<2>(edge);
            ll opt_t = (Y == 0) ? times[node] : max(times[node], (ll) ceil(sqrt(Y) - 1));
            ll new_time = (opt_t*(opt_t+1) + Y + X*(opt_t+1))/(opt_t+1);
            if (times[child] > new_time) {
                times[child] = new_time;
                t[child] = opt_t;
            }
        }
    }

    if (times[N-1] != LONG_LONG_MAX) cout << times[N-1] << endl;
    else cout << -1 << endl;

    return 0;
}