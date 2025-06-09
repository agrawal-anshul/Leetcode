class Solution {
public:
    int euclideanDistance(pair<int,int> a, pair<int,int> b ){
        return int(pow((a.first - b.first),2) + pow((a.second - b.second),2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, pair<int,int>> >maxHeap;
        for(auto point:points){
            int x = point[0];
            int y = point[1];
            int d = euclideanDistance({x,y}, {0,0});
            maxHeap.push({d, {x,y}});
            while(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while(!maxHeap.empty()){
            auto topEle = maxHeap.top();
            maxHeap.pop();
            res.push_back({topEle.second.first, topEle.second.second});
        }
    return res;
    }
};