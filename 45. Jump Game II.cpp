class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> backward;
        int last_step = -1;
        int current_step = -1;
        backward.push_back(-1);
        for(int i = nums.size()-1;i >= 0; i--){
            bool previous = false;
            current_step = -1;
            for(int j = 0; j < backward.size() -1; j++){
                if(nums[i] == 1){
                    bool no = false;
                    
                    for(j = backward.size()-2;j>=0;j--){
                        if(backward[j] != i+1){
                            no = true;
                            break;
                        }
                    }
                    if(no){
                        if(j != backward.size()-2){
                            j += 1;
                        }
                    }else{
                        j = 0;
                    }
                }
                if(i + nums[i] >= backward[j] && nums[i]!=0){

                    backward[j+1] = i;
                    previous = true;
                    if(current_step <0){
                        current_step = j+2;
                        
                        if(current_step >= last_step + 1 && nums[i] == 1){
                            current_step = last_step + 1;
                        }
                    }
                    
                }
                if(nums[i] == 1){
                    break;
                }
            }

            if(i + nums[i] >= nums.size()-1){
                backward[0] = i;
                if(i != nums.size()-1){
                    current_step = 1;
                }else{
                    current_step = 0;
                }
                previous = true;
            }
            if(!previous){
                backward.push_back(-1);
                if(i+nums[i] >= backward[backward.size()-2]){
                    backward[backward.size()-1] = i;
                    current_step = backward.size();
                }
            }
            last_step = current_step;
        }
        return current_step;
    }
};