struct Cmp {
    bool operator()(const pair<long long,long long>& a,
                    const pair<long long,long long>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

class TaskManager {
    unordered_map<int, pair<int,int>> info;
    set<pair<long long,long long>, Cmp> ordered;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            info[taskId] = {userId, priority};
            ordered.insert({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        info[taskId] = {userId, priority};
        ordered.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto it = info.find(taskId);
        int userId = it->second.first;
        int oldPriority = it->second.second;
        ordered.erase({oldPriority, taskId});
        it->second.second = newPriority;
        ordered.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        auto it = info.find(taskId);
        int oldPriority = it->second.second;
        ordered.erase({oldPriority, taskId});
        info.erase(it);
    }
    
    int execTop() {
        if (ordered.empty()) return -1;
        auto [priority, taskId] = *ordered.begin();
        ordered.erase(ordered.begin());
        auto it = info.find(taskId);
        int userId = it->second.first;
        info.erase(it);
        return userId;
    }
};
