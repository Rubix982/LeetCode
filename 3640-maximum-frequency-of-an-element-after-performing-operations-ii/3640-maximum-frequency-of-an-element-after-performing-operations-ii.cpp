using ll = long long;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    unordered_map<ll,int> freq;
    freq.reserve(n*2);
    for (int x : nums) freq[x]++;

    // Build sweep events for intervals [x-k, x+k]
    vector<pair<ll,int>> events;
    events.reserve(2*n);
    for (int x : nums) {
        ll L = (ll)x - (ll)k;
        ll R = (ll)x + (ll)k;
        events.emplace_back(L, +1);
        events.emplace_back(R + 1, -1); // R inclusive -> decrement at R+1
    }
    sort(events.begin(), events.end());

    // 1) compute global maxCover (cover over all integer points)
    int maxCover = 0;
    ll cur = 0;
    for (auto &e : events) {
        cur += e.second;
        if ((int)cur > maxCover) maxCover = (int)cur;
    }

    // 2) compute cover at each distinct original value
    vector<ll> values;
    values.reserve(freq.size());
    for (auto &p : freq) values.push_back(p.first);
    sort(values.begin(), values.end());

    int ans = 0;
    // sweep again to get cover at each value
    int idx = 0;
    cur = 0;
    for (ll v : values) {
        while (idx < (int)events.size() && events[idx].first <= v) {
            cur += events[idx].second;
            ++idx;
        }
        int cover_v = (int)cur;
        int equal_v = freq[v];
        int freq_v = min(cover_v, equal_v + numOperations);
        ans = max(ans, freq_v);
    }

    // Also consider choosing a T that is not equal to any original number:
    // best we can do there is min(maxCover, numOperations)
    ans = max(ans, min(maxCover, numOperations));

    return ans;
    }
};