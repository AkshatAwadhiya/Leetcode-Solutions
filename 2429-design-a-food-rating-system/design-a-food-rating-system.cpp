struct Cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

class FoodRatings {
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int>    foodRating;
    unordered_map<string, set<pair<int,string>, Cmp>> byCuisine;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]]  = ratings[i];
            byCuisine[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string c = foodCuisine[food];
        int old  = foodRating[food];
        auto& s  = byCuisine[c];
        s.erase({old, food});
        s.insert({newRating, food});
        foodRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        const auto& s = byCuisine[cuisine];
        return s.begin()->second;
    }
};
