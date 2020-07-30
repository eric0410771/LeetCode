class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int *total = new long long int[32];
        for(int i = 0; i < 32;i++)
        {
            total[i] = 0;
        }
        
        int sign = 1;
        int tmp_sign;
        int *tmp;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0){
                sign *= -1;
                tmp_sign = -1;
            }else{
                sign *= 1;
                tmp_sign = 1;
            }
            tmp = binarize(tmp_sign * nums[i]);
            
            for(int j = 0; j < 32; j++){
                total[j] += tmp[j];
            }
        }

        int overall = 0;
        long long int base = 1;
        for(int i = 0;i<32;i++){
            overall += base * (total[i]%2);
            base *= 2;
        }
        return overall * sign;
        
        
    }
    int* binarize(int num){
        int *bin_num = new int[32];
        for(int i = 0;i<32;i++)
            bin_num[i] = 0;
        int counter = 0;
        while(num!=0){
            bin_num[counter] = num%2;
            num = num/2;
            counter += 1;
        }
        return bin_num;
        
        
        
    }
};