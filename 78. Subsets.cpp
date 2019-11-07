class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> none;
        output.push_back(none);
        for(int i = 1;i<=nums.size();i++){
            vector<int> tmp;
            recursive(0, i, nums, output, tmp);
        }
        return output;
    }
    void recursive(int start, int number, vector<int> & nums, vector<vector<int>>& output, vector<int> tmp){
        if(number == 1){
            for(int i = start; i < nums.size(); i++){
                tmp.push_back(nums[i]);
                output.push_back(tmp);
                tmp.erase(tmp.end()-1);
            }
        }else{
            for(int i = start; i< nums.size();i++){
                tmp.push_back(nums[i]);
                recursive(i+1, number - 1, nums, output, tmp);
                tmp.erase(tmp.end()-1);
            }
        }
        
    }
};