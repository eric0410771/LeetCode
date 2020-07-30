class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row = matrix.size();
        if(row == 0){
            return 0;
        }
        
        int col = matrix[0].size();
        int **int_matrix = new int* [row];
        int **acc_matrix = new int* [row];
        
        
        for(int i = 0;i<row;i++){
            int_matrix[i] = new int[col];
            acc_matrix[i] = new int[col];
        }
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                int_matrix[i][j] = (int)(matrix[i][j] - '0');
            }
        }
        for(int j = 0;j<col;j++){
            for(int i = row - 1; i >=0 ;i--){
                if(i == row-1){
                    acc_matrix[i][j] = int_matrix[i][j];
                }else{
                    acc_matrix[i][j] = int_matrix[i][j] * (int_matrix[i][j] + acc_matrix[i + 1][j]);
                    
                }
                
                
            }
        }
        
        
        int max = 0;
        for(int i = 0 ;i<row;i++){
            for(int j = 0;j<col;j++){
                if(acc_matrix[i][j] != 0){
                    int counter = 1;
                    int min_value = acc_matrix[i][j];
                    if(max < min_value){
                        max = min_value;
                    }
                    for(int k = j + 1; k<col ;k++){
                        if(acc_matrix[i][k]!=0){
                            counter += 1;
                            if(min_value > acc_matrix[i][k]){
                                min_value = acc_matrix[i][k];
                            }
                            if(max < counter * min_value){
                                max = counter * min_value;
                            }
                            
                        }else{
                            break;
                        }
                    }
                    
                    
                }
            }
        }
        
        return max;
    }
};