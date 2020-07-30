struct node{
    char c;
    node *u;
    node *d;
    node *l;
    node *r;
    bool touch;
};
typedef node node;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<node*>> node_board;
        int row = board.size();
        int col = board[0].size();
        
        
        for(int i = 0;i < row; i++){
            vector<node*> tmp_row;
            
            for(int j = 0;j<col;j++){
                node* tmp_node = (node*)malloc(sizeof(node));
                tmp_node->u = NULL;
                tmp_node->d = NULL;
                tmp_node->l = NULL;
                tmp_node->r = NULL;
                tmp_node->touch = false;
                tmp_node->c = board[i][j];
                tmp_row.push_back(tmp_node);
            }
            node_board.push_back(tmp_row);
        }
        
        for(int i = 0 ;i< row;i ++){
            for(int j = 0; j < col ;j ++){
                if(i!=0){
                    node_board[i][j]->u = node_board[i-1][j];
                }
                if(j!=0){
                    node_board[i][j]->l = node_board[i][j-1];
                }
                if(i != row -1){
                    node_board[i][j]->d = node_board[i+1][j];
                }
                if(j != col-1){
                    node_board[i][j]->r = node_board[i][j+1];
                }
            }
        }
        bool match;
        
        for(int i = 0;i<row;i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    match = recur(word, 1, i, j, row, col, node_board);
                    if(match){
                        return match;
                    }else{
                        node_board[i][j]->touch = false;
                    }
                }
            }
        }
        return false;
    }
    bool recur(string word, int counter, int i, int j, int row, int col, vector<vector<node*>> node_board){
        bool result = false;
        node_board[i][j]->touch = true;
        if(word[counter]){
            if(i < row - 1 && word[counter] == node_board[i+1][j]->c && !node_board[i+1][j]->touch)
            {
                result = recur(word, counter + 1, i+1, j, row, col, node_board);
                if(result){
                    return true;
                }else{
                    node_board[i+1][j]->touch = false;
                }
            }
            if(i > 0 && word[counter] == node_board[i-1][j]->c && !node_board[i-1][j]->touch)
            {
                result = recur(word, counter+1, i-1, j, row, col, node_board);
                if(result){
                    return true;
                }else{
                    node_board[i-1][j]->touch = false;
                }
            }
            if(j < col - 1 && word[counter] == node_board[i][j+1]->c && !node_board[i][j+1]->touch)
            {
                result = recur(word, counter + 1, i, j+1 , row, col, node_board);
                if(result){
                    return true;
                }else{
                    node_board[i][j+1]->touch = false;
                }
            }
            if(j > 0 && word[counter] == node_board[i][j-1]->c && !node_board[i][j-1]->touch)
            {
                result = recur(word, counter+1, i, j-1, row, col, node_board);
                if(result){
                    return true;
                }else{
                    node_board[i][j-1]->touch = false;
                }
            }
            return false;
        }else{
            return true;
        }
        
    }
};