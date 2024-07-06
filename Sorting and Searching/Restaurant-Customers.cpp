#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    vector<pair<ll, int>> events; // Pair of time and event type (-1 for start, 1 for end)
    for (int i = 0; i < n; i++)
    {
        events.push_back({a[i].first, -1}); // Start of interval
        events.push_back({a[i].second, 1}); // End of interval
    }

    sort(events.begin(), events.end()); // Sort events by time

    int cur = 0, mx = 0;
    for (auto &event : events)
    {
        if (event.second == -1) cur++;
        else cur--;
        mx = max(mx, cur);
    }
    cout << mx << endl;
    return 0;
}
