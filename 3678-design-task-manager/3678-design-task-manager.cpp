class TaskManager {
    struct Comp {
        bool operator()(const pair<int, int> & a, const pair <int, int> b) const {
            // Sort by priority descending first, then by taskId descending
            if (a.second != b.second) return a.second > b.second;
            return a.first > b.first;
        }
    };

    // UserId -> set of {taskId, priority} for that user
    unordered_map<int, set<pair<int,int>, Comp>> userTasks;

    // Map taskId to {userId, priority} for quick lookup and global task management
    unordered_map<int, pair<int,int>> taskMap;

    // Global set to quickly get the top task across all users
    set<pair<int,int>, Comp> globalTasks;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            int userId = task.at(0);
            int taskId = task.at(1);
            int priority = task.at(2);

            userTasks[userId].insert({taskId, priority});
            taskMap[taskId] = {userId, priority};
            globalTasks.insert({taskId, priority});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        userTasks[userId].insert({taskId, priority});
        taskMap[taskId] = {userId, priority};
        globalTasks.insert({taskId, priority});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskMap[taskId];

        // Remove old entry
        userTasks[userId].erase({taskId, oldPriority});
        globalTasks.erase({taskId, oldPriority});

        // Insert new entry
        userTasks[userId].insert({taskId, newPriority});
        globalTasks.insert({taskId, newPriority});

        // Update taskMap
        taskMap[taskId].second = newPriority;        
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = taskMap[taskId];

        userTasks[userId].erase({taskId, priority});
        globalTasks.erase({taskId, priority});
        taskMap.erase(taskId);        
    }
    
    int execTop() {
        if (globalTasks.empty()) return -1;

        auto [taskId, priority] = *globalTasks.begin();
        int userId = taskMap[taskId].first;

        // Remove task from everywhere
        globalTasks.erase({taskId, priority});
        userTasks[userId].erase({taskId, priority});
        taskMap.erase(taskId);

        return userId;        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */