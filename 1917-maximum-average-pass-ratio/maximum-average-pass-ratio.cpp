class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;        
        for (auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double gain = calculateGain(pass, total);
            pq.push({gain, {pass, total}});
        }        
        for (int i = 0; i < extraStudents; i++) {
            auto top = pq.top();
            pq.pop();            
            double currentGain = top.first;
            int pass = top.second.first;
            int total = top.second.second;            
            pass++;
            total++;            
            double newGain = calculateGain(pass, total);
            pq.push({newGain, {pass, total}});
        }
        
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto cls = pq.top();
            pq.pop();
            
            int pass = cls.second.first;
            int total = cls.second.second;
            totalRatio += (double)pass / total;
        }
        
        return totalRatio / classes.size();
    }
    
private:
    double calculateGain(int pass, int total) {
        double currentRatio = (double)pass / total;
        double newRatio = (double)(pass + 1) / (total + 1);
        return newRatio - currentRatio;
    }
};