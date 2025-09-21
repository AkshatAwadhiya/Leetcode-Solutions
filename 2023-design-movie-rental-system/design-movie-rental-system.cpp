#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class MovieRentingSystem {
private:
    // Store price for each (shop, movie) pair
    unordered_map<int, unordered_map<int, int>> prices; // shop -> movie -> price
    
    // For search: movie -> set of (price, shop) for unrented copies
    unordered_map<int, set<pair<int, int>>> unrented; // movie -> {(price, shop)}
    
    // For report: set of (price, shop, movie) for rented copies
    set<tuple<int, int, int>> rented; // {(price, shop, movie)}
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // Initialize data structures with all movies as unrented
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            
            // Store price information
            prices[shop][movie] = price;
            
            // Add to unrented set (sorted by price, then by shop)
            unrented[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        
        // Check if movie exists in unrented collection
        if (unrented.find(movie) == unrented.end()) {
            return result;
        }
        
        // Get up to 5 cheapest unrented copies
        // Set is already sorted by (price, shop)
        int count = 0;
        for (auto& p : unrented[movie]) {
            if (count >= 5) break;
            result.push_back(p.second); // shop
            count++;
        }
        
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = prices[shop][movie];
        
        // Remove from unrented
        unrented[movie].erase({price, shop});
        
        // Add to rented (sorted by price, shop, movie)
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices[shop][movie];
        
        // Remove from rented
        rented.erase({price, shop, movie});
        
        // Add back to unrented
        unrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        
        // Get up to 5 cheapest rented movies
        // Set is already sorted by (price, shop, movie)
        int count = 0;
        for (auto& t : rented) {
            if (count >= 5) break;
            int shop = get<1>(t);
            int movie = get<2>(t);
            result.push_back({shop, movie});
            count++;
        }
        
        return result;
    }
};