class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)return 0;

        int maxProfit = 0;
        int buyIndex = 0, sellIndex = 1;

        while(buyIndex < sellIndex and sellIndex < n){
            int bp = prices[buyIndex];
            int sp = prices[sellIndex];
            int currProfit = sp - bp;
            if(currProfit>0){
                if(currProfit>maxProfit){
                    maxProfit = currProfit;
                }
            }else{
                // If profit is negative, move buyIndex to current sellIndex
                buyIndex = sellIndex;
            }
            // Always move sellIndex forward
            sellIndex++;
        }
        return maxProfit;
    }
};