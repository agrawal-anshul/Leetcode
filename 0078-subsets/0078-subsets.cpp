class Solution {

void generateSubsets(vector<int>& arr, vector<int>& subset, int index, vector<vector<int>>& result) {
	if(index == arr.size()){
		result.push_back(subset);
		return;
	}
	// include current element
	subset.push_back(arr[index]);
	generateSubsets(arr, subset, index+1, result);

	// exclude current element
	subset.pop_back();
	generateSubsets(arr, subset, index+1, result);

}

// Wrapper function to return all subsets
vector<vector<int>> getAllSubsets(vector<int>& arr) {
    vector<vector<int>> result;
    vector<int> subset;
    generateSubsets(arr, subset, 0, result);
    return result; // Return vector of subsets
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return getAllSubsets(nums);
    }
};