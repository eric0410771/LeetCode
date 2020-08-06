class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        left_priority(result, n, n, "");
        return result;
        
    }
private:
    void left_priority(vector<string> &result, int left, int right, string value){
        if(left == right && left == 0)
        {
            result.push_back(value);
        }else{
            
            if(left != 0){
                left_priority(result, left - 1, right, value +"(");
            }
            if(left < right){
                left_priority(result, left, right - 1, value + ")");
            }
        }
    }
};