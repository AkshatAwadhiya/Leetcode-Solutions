class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1);
        for (int i = 1; i <= c; i++) {
            parent[i] = i;
        }
        
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        auto unite = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px != py) {
                parent[px] = py;
            }
        };
        
        for (auto& conn : connections) {
            unite(conn[0], conn[1]);
        }
        
        unordered_map<int, set<int>> grids;
        for (int i = 1; i <= c; i++) {
            int root = find(i);
            grids[root].insert(i);
        }
        
        vector<bool> online(c + 1, true);
        
        vector<int> result;
        
        for (auto& query : queries) {
            int type = query[0];
            int station = query[1];
            
            if (type == 1) {
                int gridId = find(station);
                
                if (online[station]) {
                    result.push_back(station);
                } else {
                    if (grids[gridId].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*grids[gridId].begin());
                    }
                }
            } else {
                online[station] = false;
                int gridId = find(station);
                grids[gridId].erase(station);
            }
        }
        
        return result;
    }
};