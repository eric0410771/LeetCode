class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> copy_board;
        for(int i = 0;i<9;i++){
            vector<int> tmp;
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    tmp.push_back(0);
                }else{
                    tmp.push_back(board[i][j] - '0');
                }
            }
            copy_board.push_back(tmp);
        }
        int *array = new int[10];
        for(int i=0 ; i<9; i++){
            for(int j = 0;j<10;j++){
                array[j] = 0;
            }
            for(int j = 0;j<9;j++)
            {   
                if(copy_board[i][j] > 0&&array[copy_board[i][j]] == 1){
                    cout<<"here";
                    return false;
                }    
                array[copy_board[i][j]] += 1;
            }
            for(int j = 0;j<10;j++){
                array[j] = 0;
            }
            for(int j = 0; j<9; j++){
                if(copy_board[j][i] > 0 && array[copy_board[j][i]] == 1){
                    return false;
                }
                array[copy_board[j][i]] += 1;
            }
        }    
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++){
                
                for(int k = 0;k<10;k++){
                    array[k] = 0;
                }
                
                int centeri = i * 3 + 1;
                int centerj = j * 3 + 1;
                for(int shifti = -1; shifti < 2 ;shifti++){
                    for(int shiftj = -1; shiftj <2 ; shiftj++){
                        if(copy_board[centeri+shifti][centerj+shiftj] > 0 && array[copy_board[centeri+shifti][centerj+shiftj]]==1){
                            return false;
                        }
                        array[copy_board[centeri+shifti][centerj + shiftj]] += 1;
                    }
                }
                
            }
        }
        return true;
    }
    
};