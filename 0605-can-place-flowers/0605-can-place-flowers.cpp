// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int count) {
//         int n = flowerbed.size();
//         for(int i=0;i<n;i++){
//             if(flowerbed[i]==0){
//                 if(i == 0){
//                     if(i+1 < n and flowerbed[i+1]!=1){
//                         flowerbed[i] = 1;
//                         count--;
//                     }
//                 }
//                 else if(i == n-1){
//                     if(i-1>=0 && flowerbed[i-1]!=1){
//                         flowerbed[i] = 1;
//                         count--;
//                     }
//                 }
//                 else{
//                     int prev = flowerbed[i-1];
//                     int next = flowerbed[i+1];
//                     if(!prev && !next){
//                         flowerbed[i] = 1;
//                         count--;
//                     }
                    
//                 }
            
//             }
//         }
//         return count==0?true:false;
//     }
// };

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int count) {
        int n = flowerbed.size();

        for(int i = 0; i < n; i++) {
            if(flowerbed[i] == 0) {
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                int next = (i == n - 1) ? 0 : flowerbed[i + 1];

                if(prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    count--;
                    if(count == 0) return true; // Early exit
                }
            }
        }

        return count <= 0;
    }
};