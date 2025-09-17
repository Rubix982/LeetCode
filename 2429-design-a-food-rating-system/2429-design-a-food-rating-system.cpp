class FoodRatings {
    struct FoodInfo {
        string cuisine;
        int rating;
    };
    
    // Custom comparator for cuisine sets
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first; // higher rating first
            return a.second < b.second; // smaller name first
        }
    };

    unordered_map<string, FoodInfo> foodMap; // food -> {cuisine, rating}
    unordered_map<string, set<pair<int,string>, Comp>> cuisineMap; // cuisine -> ordered set of (rating, food)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({ratings[i], foods[i]});
        }        
    }
    
    void changeRating(string food, int newRating) {
        auto& info = foodMap[food];
        string cuisine = info.cuisine;
        int oldRating = info.rating;
        
        // remove old entry
        cuisineMap[cuisine].erase({oldRating, food});
        // update foodMap
        info.rating = newRating;
        // insert new entry
        cuisineMap[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */