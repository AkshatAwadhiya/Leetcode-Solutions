class Solution {
    static bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    static string toLowerStr(const string& s) {
        string t = s;
        for (char& c : t) c = tolower(c);
        return t;
    }
    static string devowel(const string& s) {
        string t = s;
        for (char& c : t) {
            char lc = tolower(c);
            c = (lc=='a'||lc=='e'||lc=='i'||lc=='o'||lc=='u') ? '*' : lc;
        }
        return t;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        unordered_map<string,string> lowerFirst;
        unordered_map<string,string> devowelFirst;
        lowerFirst.reserve(wordlist.size()*2);
        devowelFirst.reserve(wordlist.size()*2);

        for (const string& w : wordlist) {
            string lw = toLowerStr(w);
            if (!lowerFirst.count(lw)) lowerFirst[lw] = w;

            string mw = devowel(w); // devowel uses lowercase for consonants and '*' for vowels
            if (!devowelFirst.count(mw)) devowelFirst[mw] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (const string& q : queries) {
            if (exact.count(q)) { // exact-case match
                ans.push_back(q);
                continue;
            }
            string lq = toLowerStr(q);
            auto itL = lowerFirst.find(lq);
            if (itL != lowerFirst.end()) {
                ans.push_back(itL->second);
                continue;
            }
            string mq = devowel(q);
            auto itM = devowelFirst.find(mq);
            if (itM != devowelFirst.end()) {
                ans.push_back(itM->second);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};