class Solution {
    
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        // sort(v.begin(),v.end(),compare);
        sort(v.begin(),v.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first > b.first;
        }); //using lamda function

        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};