class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        
        for (const string& f : folder) {
            if (result.empty() || !isSubfolder(f, result.back())) {
                result.push_back(f);
            }
        }
        
        return result;
    }
    
private:
    bool isSubfolder(const string& folder, const string& parent) {
        if (folder.length() <= parent.length()) {
            return false;
        }        
        if (folder.substr(0, parent.length()) != parent) {
            return false;
        }        
        return folder[parent.length()] == '/';
    }
};