
class FoodRatings {
public:
    // See The last submission for custom designing of SET {{ Althoug the solu is giving wrong ans }}
    // NOTE : if first value is same then it sort on basis of second value
    map<string,set<pair<int,string>>> s;   // putting all foodes with same cusines together
    unordered_map<string,string> cus; // cusisines
    unordered_map<string,int> rat;   // rating
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();++i)
        {
            s[cuisines[i]].insert({-ratings[i],foods[i]});
            cus[foods[i]]=cuisines[i];
            rat[foods[i]]=-ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int r=rat[food];
        string c=cus[food];
        s[c].erase({r,food});
        s[c].insert({-newRating,food});
        rat[food]=-newRating;
    }
    
    string highestRated(string cuisine) {
        pair<int,string> p= *(s[cuisine].begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */