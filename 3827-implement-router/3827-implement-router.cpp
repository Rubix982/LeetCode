class Router {
private:
    int memoryLimit;
    deque<tuple<int,int,int>> queue; // source, destination, timestamp
    unordered_set<string> seen;      // for duplicates
    unordered_map<int, vector<int>> destMap; // destination -> sorted timestamps

    string key(int s, int d, int t) {
        return to_string(s) + "," + to_string(d) + "," + to_string(t);
    }

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string k = key(source,destination,timestamp);
        if (seen.count(k)) return false;

        if ((int)queue.size() >= memoryLimit) {
            auto [s,d,t] = queue.front();
            queue.pop_front();
            seen.erase(key(s,d,t));
            // remove oldest timestamp from destMap[d]
            destMap[d].erase(destMap[d].begin());
            if (destMap[d].empty()) destMap.erase(d);
        }

        queue.emplace_back(source,destination,timestamp);
        seen.insert(k);
        destMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (queue.empty()) return {};
        auto [s,d,t] = queue.front();
        queue.pop_front();
        seen.erase(key(s,d,t));
        destMap[d].erase(destMap[d].begin());
        if (destMap[d].empty()) destMap.erase(d);
        return {s,d,t};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto &ts = destMap[destination];
        auto left = lower_bound(ts.begin(), ts.end(), startTime);
        auto right = upper_bound(ts.begin(), ts.end(), endTime);
        return right - left;
    }
};
