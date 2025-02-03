class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int max_profit = INT_MIN;
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            profit = prices[i] - buy;
            if(prices[i]<buy){
                buy=prices[i];
            }else if( profit > max_profit){
                max_profit = profit;
            }
        }
        return max_profit;
    }

};