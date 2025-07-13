#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int matchings = 0;
        int trainerIdx = 0;
        
        for (int playerAbility : players) {
            while (trainerIdx < trainers.size() && trainers[trainerIdx] < playerAbility) {
                trainerIdx++;
            }
            
            if (trainerIdx < trainers.size()) {
                matchings++;
                trainerIdx++;
            }
        }
        
        return matchings;
    }
};
