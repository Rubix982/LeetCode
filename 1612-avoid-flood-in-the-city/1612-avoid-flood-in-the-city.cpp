class Solution {
public:
vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();

    // This will be our answer array
    // By default: every day = 1 (arbitrary for dry days)
    vector<int> ans(n, 1);

    // This map tells us which lakes are currently full,
    // and on which day they were last filled
    unordered_map<int, int> fullLakes;

    // This set stores the indices of days where it did NOT rain (rains[i] == 0)
    // Set keeps them sorted automatically (so we can find the next dry day easily)
    set<int> dryDays;

    for (int day = 0; day < n; ++day) {
        int lake = rains[day];

        if (lake == 0) {
            // This is a dry day — store the index
            dryDays.insert(day);
        } else {
            // It rained on lake X
            ans[day] = -1;  // by rule, all rain days are -1

            // Check if this lake was already full
            if (fullLakes.count(lake)) {
                // Find the earliest dry day that happens AFTER we last filled this lake
                int lastRainDay = fullLakes[lake];
                auto dryIt = dryDays.upper_bound(lastRainDay);

                if (dryIt == dryDays.end()) {
                    // No dry day available to dry this lake before it rains again → flood!
                    return {};
                }

                // We found a valid dry day
                int dryDayIndex = *dryIt;
                ans[dryDayIndex] = lake;  // we’ll dry this lake on that day
                dryDays.erase(dryIt);     // remove the used dry day
            }

            // Update when this lake was last filled
            fullLakes[lake] = day;
        }
    }

    return ans;
}
};