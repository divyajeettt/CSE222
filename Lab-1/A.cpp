#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;


// count cross intersections
ll count_cross_intersections(ll *array, int start, int mid, int end) {
    ll count = 0;
    int i = start;
    int j = mid+1;
    while (i <= mid && j <= end) {
        if (array[i] <= array[j]) i++;
        else {
            count += (mid - i + 1);
            j++;
        }
    }
    return count;
}


// merge two sorted parts of the array
void merge(ll *array, int start, int mid, int end) {
    ll temp[end - start + 1];
    int i = start;
    int j = mid+1;
    int k;

    for (k = 0; i <= mid && j <= end; k++) {
        if (array[i] <= array[j])
            temp[k] = array[i++];
        else
            temp[k] = array[j++];
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= end) temp[k++] = array[j++];

    for (int i = start; i <= end; i++)
        array[i] = temp[i - start];
}


// count wire intersections
ll count_intersections(ll *array, int start, int end) {
    if (start == end) return 0;
    else {
        ll mid = (start + end) / 2;
        ll I1 = count_intersections(array, start, mid);
        ll I2 = count_intersections(array, mid+1, end);
        ll C = count_cross_intersections(array, start, mid, end);
        merge(array, start, mid, end);
        return (I1 + I2 + C);
    }
}


// utility function to sort the vector of pairs
bool comp(pll a, pll b) {
    return ((a.first == b.first) ? (a.second < b.second) : (a.first < b.first));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pll> joints(n);
    for (int i = 0; i < n; i++) {
        cin >> joints[i].first >> joints[i].second;
    }

    sort(joints.begin(), joints.end(), comp);

    // check if the sorting is correct
    // for (int i = 0; i < n; i++) {
    //     cout << joints[i].first << " " << joints[i].second << endl;
    // }

    ll Q[n];
    for (int i = 0; i < n; i++) {
        Q[i] = joints[i].second;
    }

    cout << count_intersections(Q, 0, n-1) << endl;

    return 0;
}