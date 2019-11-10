class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> output;
        
        char * c_s = new char[s.length()+1];
        int * i_s = new int[s.length()];
        int length = s.length();
        int *count = new int[1048576];
        int end_pointer = 9;
        if(length <=10){
            return output;
        }
        for(int i = 0;i<1048576;i++)
        {
            count[i] = 0;
        }
        strcpy(c_s, s.c_str());
        char *map = new char[4];
        map[0] = 'A';
        map[1] = 'T';
        map[2] = 'C';
        map[3] = 'G';
        
        for(int i = 0;i<length;i++){
            if(c_s[i] == 'A'){
                i_s[i] = 0;
            }else if(c_s[i] == 'T'){
                i_s[i] = 1;
            }else if(c_s[i] == 'C'){
                i_s[i] = 2;
            }else{
                i_s[i] = 3;
            }
        }
        int tmp = 0;
        int constant = 1;
        for(int i = 0;i<10;i++){
            tmp *= 4;
            constant *= 4;
            tmp += i_s[i];
        }
        constant/=4;
        count[tmp] += 1;
        end_pointer += 1;
        while(end_pointer<length){
            tmp -= i_s[end_pointer-10] * constant;
            tmp *= 4;
            tmp += i_s[end_pointer];
            
            if(count[tmp] == 1){
                char *s_c = new char[11];
                s_c[10] = '\0';
                int copy_tmp = tmp;
                for(int i = 0;i<10;i++){
                    s_c[9-i] = map[copy_tmp%4];
                    copy_tmp/=4;
                }
                string save = string(s_c);
                output.push_back(s_c);
            }
            count[tmp] += 1;
            end_pointer += 1;
        }
        return output;
    }
};