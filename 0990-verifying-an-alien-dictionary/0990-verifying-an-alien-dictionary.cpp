class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i = 0; i<order.size();i++){
            mp[order[i]] = i;
        }

        if(words.size()<2)return true;

        for(int i=0; i< words.size()-1;i++){
            string w1 = words[i];
            int n1 = words[i].size();

            string w2 = words[i+1];
            int n2 = words[i+1].size();

            int id1 = 0, id2 = 0;
            while(id1 < n1 && id2 < n2){
                if(mp[w1[id1]] > mp[w2[id2]])
                    return false;
                else if(mp[w1[id1]] < mp[w2[id2]]){
                    break;
                }
                id1++;
                id2++;
            }
            if(id1==n1){
                // w1 is smaller in length hence should come first, which is the case.
            }else if(id2 == n2){
                // w2 is smaller but comes second, which should happen.
                return false;
            }else{
                // break case;
                // goto next words
            }

        }
        return true;
    }
};