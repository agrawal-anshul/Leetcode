class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy=prices[0];
        for(int i=0;i<prices.size();i++){
            if( prices[i]< buy){
                buy=prices[i];
            }
            int curr_profit = prices[i]-buy;
            if(curr_profit>max_profit){
                max_profit = curr_profit;
            }
        }
        return max_profit;
    }
};