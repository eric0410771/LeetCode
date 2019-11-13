class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> output;
        output.push_back(0);
        for(int i = 1; i<=num;i++){
            output.push_back(parallel_bitcount(i));
        }
        return output;
    }
    
    int parallel_bitcount(int num){
        bitset<32> bit_num = btoi(num);
        bit_num = itob(btoi(bit_num)-btoi(((bit_num >> 1)&itob(0x55555555))));
        bit_num = itob(btoi(bit_num & itob(0x33333333)) + btoi(bit_num >> 2 &itob(0x33333333)));
        bit_num = itob(btoi(bit_num) + btoi(bit_num >> 4));
        bit_num = bit_num & itob(0x0f0f0f0f);
        bit_num = itob(btoi(bit_num) * 0x01010101)>>24;
        
        return btoi(bit_num);
    }
    bitset<32> itob(int num){
        return bitset<32>(num);
    }
    unsigned long long int btoi(bitset<32> bit_num){
        return (int)(bit_num.to_ulong());
    }
};