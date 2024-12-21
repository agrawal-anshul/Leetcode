class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int l=0,r=0,maxLength=-1;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxLength = max(maxLength,r-l+1);
            r++;
        }
        return maxLength;
    }
};