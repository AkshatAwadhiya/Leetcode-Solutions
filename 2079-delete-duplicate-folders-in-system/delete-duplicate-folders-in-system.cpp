class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        bool toDelete = false;
        string signature = "";
    };
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();        
        for (auto& path : paths) {
            TrieNode* curr = root;
            for (string& folder : path) {
                if (curr->children.find(folder) == curr->children.end()) {
                    curr->children[folder] = new TrieNode();
                }
                curr = curr->children[folder];
            }
        }        
        generateSignatures(root);        
        unordered_map<string, vector<TrieNode*>> signatureGroups;
        collectSignatures(root, signatureGroups);
        
        for (auto& group : signatureGroups) {
            if (group.second.size() > 1 && !group.first.empty()) {
                for (TrieNode* node : group.second) {
                    markForDeletion(node);
                }
            }
        }        
        vector<vector<string>> result;
        vector<string> currentPath;
        collectRemainingPaths(root, currentPath, result);
        
        return result;
    }
    
private:
    string generateSignatures(TrieNode* node) {
        if (!node) return "";
        
        vector<string> childSignatures;
        for (auto& child : node->children) {
            string childSig = generateSignatures(child.second);
            childSignatures.push_back(child.first + ":" + childSig);
        }
        
        sort(childSignatures.begin(), childSignatures.end());
        
        string signature = "";
        for (string& sig : childSignatures) {
            signature += sig + ",";
        }
        
        node->signature = signature;
        return signature;
    }
    
    void collectSignatures(TrieNode* node, unordered_map<string, vector<TrieNode*>>& signatureGroups) {
        if (!node) return;
        
        signatureGroups[node->signature].push_back(node);
        
        for (auto& child : node->children) {
            collectSignatures(child.second, signatureGroups);
        }
    }
    
    void markForDeletion(TrieNode* node) {
        if (!node) return;
        
        node->toDelete = true;
        for (auto& child : node->children) {
            markForDeletion(child.second);
        }
    }
    
    void collectRemainingPaths(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
        if (!node) return;        
        if (!currentPath.empty() && !node->toDelete) {
            result.push_back(currentPath);
        }        
        for (auto& child : node->children) {
            if (!child.second->toDelete) {
                currentPath.push_back(child.first);
                collectRemainingPaths(child.second, currentPath, result);
                currentPath.pop_back();
            }
        }
    }
};