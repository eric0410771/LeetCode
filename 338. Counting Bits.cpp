class Solution {
public:
    vector<int> countBits(int num) {
        int* binary = new int[32];
        for(int i = 0;i<32;i++){
            binary[i] = 0;
            
        }
        int counter;
        vector<int> result;
        result.push_back(0);
        int tmp = 0;
        for(int i = 1;i<=num;i++){
            counter = 0;
            while(true){
                if(binary[counter]==0){
                    binary[counter] += 1;
                    tmp += 1;
                    break;
                }else{
                    binary[counter] = 0;
                    tmp -= 1;
                    counter += 1;
                }
            }
            result.push_back(tmp);
        }
        return result;
        
    }
};