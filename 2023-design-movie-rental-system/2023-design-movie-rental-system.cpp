class MovieRentingSystem {
private:
    // movie -> set of {price, shop} for unrented movies
    unordered_map<int, set<pair<int,int>>> available;
    
    // set of {price, shop, movie} for rented movies
    set<tuple<int,int,int>> rented;
    
    // map to store price for each (shop, movie)
    unordered_map<int, unordered_map<int,int>> priceMap;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop});
            priceMap[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if(available.count(movie)) {
            auto &s = available[movie];
            for(auto it = s.begin(); it != s.end() && res.size() < 5; ++it) {
                res.push_back(it->second);
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int p = priceMap[shop][movie];
        available[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = priceMap[shop][movie];
        rented.erase({p, shop, movie});
        available[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for(auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it) {
            auto [p, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};
