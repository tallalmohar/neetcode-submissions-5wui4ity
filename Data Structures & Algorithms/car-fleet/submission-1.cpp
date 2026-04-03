class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,int>> pairs;
       for(int i = 0; i < position.size();i++){
        pairs.push_back({position[i],speed[i]});
       } 
       sort(pairs.rbegin(),pairs.rend());
       vector<double> time;
       for(auto p : pairs){
        time.push_back((double)(target - p.first)/p.second);
        while(time.size() >= 2 && time.back() <= time[time.size()-2]){
           time.pop_back();
        }
       }
       return time.size();
    }
};
