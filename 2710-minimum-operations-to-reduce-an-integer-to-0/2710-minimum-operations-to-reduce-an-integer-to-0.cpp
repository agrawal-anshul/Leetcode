class Solution {
public:
    int minOperations(int n) {
        int count=0;
        while(n!=0){
            int x=floor(log2(n));
            int y=ceil(log2(n));
            int ans1=pow(2, x), ans2=pow(2, y);
            n=(min(abs(n-ans1), abs(n-ans2)));
            count++;
        }
        return count;
    }
};