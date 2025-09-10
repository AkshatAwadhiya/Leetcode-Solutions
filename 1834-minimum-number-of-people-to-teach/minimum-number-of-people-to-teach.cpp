class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        vector<set<int>> userLanguages(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLanguages[i + 1].insert(lang);
            }
        }      
        vector<pair<int, int>> problematicPairs;
        for (auto& friendship : friendships) {
            int u = friendship[0];
            int v = friendship[1];
            
            if (!canCommunicate(userLanguages[u], userLanguages[v])) {
                problematicPairs.push_back({u, v});
            }
        }        
        if (problematicPairs.empty()) {
            return 0;
        }
        
        int minTeachings = m + 1;
        for (int lang = 1; lang <= n; lang++) {
            set<int> usersToTeach;
            
            for (auto& pair : problematicPairs) {
                int u = pair.first;
                int v = pair.second;
                
                bool uKnows = userLanguages[u].count(lang) > 0;
                bool vKnows = userLanguages[v].count(lang) > 0;
                
                if (!uKnows && !vKnows) {
                    usersToTeach.insert(u);
                    usersToTeach.insert(v);
                } else if (!uKnows) {
                    usersToTeach.insert(u);
                } else if (!vKnows) {
                    usersToTeach.insert(v);
                }
            }
            
            minTeachings = min(minTeachings, (int)usersToTeach.size());
        }
        
        return minTeachings;
    }
    
private:
    bool canCommunicate(const set<int>& lang1, const set<int>& lang2) {
        for (int lang : lang1) {
            if (lang2.count(lang) > 0) {
                return true;
            }
        }
        return false;
    }
};