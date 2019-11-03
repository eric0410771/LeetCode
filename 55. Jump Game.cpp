class Solution {
public:
    bool canJump(vector<int>& nums) {
        int counter = nums.size() - 1;
        int tmp = 0;
        bool first = true;
        while(true){
            if(counter == 0)
                return true;
            else{
                if(first)
                {
                    tmp = counter - 1;
                    first = false;
                }
                if(tmp + nums[tmp]>=counter)
                {
                    counter = tmp;
                    first = true;
                }
                else{
                    if(tmp == 0){
                        return false;
                    }{
                        tmp -= 1;
                    }
                }
            }
        }
    }
};