class Solution {
    void generateSubsets(vector<int>& arr, vector<int>& subset, int index, vector<vector<int>>& result) {
	if(index == arr.size()){
		result.push_back(subset);
		return;
	}

    // include current element
    subset.push_back(arr[index]);
	generateSubsets(arr, subset, index+1, result);
    
    // Skip duplicate element after the first the occurrence
    while(index<arr.size()-1 && arr[index]==arr[index+1]){
        index++;   
    }

	// exclude current element
	subset.pop_back();
	generateSubsets(arr, subset, index+1, result);

}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());// Sort to handle duplicates
        generateSubsets(nums,subset, 0, result);
        return result; 
    }
};