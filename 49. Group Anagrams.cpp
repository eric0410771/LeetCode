class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> lengths;
        int *alphe_count = new int[26];
        
        vector<vector<string>> output;
        int counter = 0;
        
        vector<vector<char>> s_char;
        vector<vector<int>> s_int;
        for(int i = 0;i<strs.size();i++){
            vector<char> tmp_s_char;
            vector<int> tmp_s_int;
            char *c_s = new char[strs[i].length()+1];
            strcpy(c_s, strs[i].c_str());
            
            int value = 0;
            for(int j = 0;j<26;j++){
                alphe_count[j] = 0;
            }
            bool same = false;
            for(int j = 0;j<strs[i].length();j++){
                alphe_count[(int)(c_s[j] - 'a')] += 1;
            
            }
            for(int j = 0;j < 26;j++){
                if(alphe_count[j] != 0){
                    tmp_s_char.push_back((char)('a'+j));
                    tmp_s_int.push_back(alphe_count[j]);
                }
            }
            for(int j = 0;j < counter;j++){
                if(strs[i].length() == lengths[j] && tmp_s_char.size() == s_char[j].size()){
                    bool tmp_same = true;
                    for(int k = 0;k<tmp_s_char.size();k++){
                        if(!(tmp_s_char[k] == s_char[j][k] && tmp_s_int[k] == s_int[j][k]))
                        {
                            tmp_same = false;
                            break;
                        }
                    }
                    if(tmp_same){
                        same = true;
                        output[j].push_back(strs[i]);
                        break;
                    }
                }
                
            }
            if (!same){
                counter += 1;
                vector<string> tmp;
                tmp.push_back(strs[i]);
                s_char.push_back(tmp_s_char);
                s_int.push_back(tmp_s_int);
                lengths.push_back(strs[i].length());
                output.push_back(tmp);
            }
            
        }
        return output;
    }
};