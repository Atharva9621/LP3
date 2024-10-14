#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
 #include <numeric>

using namespace std;
void printMatrix(vector<vector<bool>> mat);
bool isSafe(const vector<vector<bool>>& board, int x, int y){
    int n = board.size();
    for(int i=0; i<n; i++)if(board[x][i])return false;
    for(int i=0; i<n; i++)if(board[i][y])return false;
    //Diagonals (check all coz initial queen can be anywhere)
    for(int i=1; i<=min(x, y); i++)if(board[x-i][y-i])return false;   
    for(int i=1; i<=min(n-1-x, y); i++)if(board[x+i][y-i])return false;   
    for(int i=1; i<=min(x, n-1-y); i++)if(board[x-i][y+i])return false;
    for(int i=1; i<=min(n-1-x, n-1-y); i++)if(board[x+i][y+i])return false;
    return true;
}

bool nQueensBackTracking(vector<vector<bool>>& board, int row, int x, int y){
    cout<<"Row - "<<row<<endl;
    printMatrix(board);
    int n = board.size();
    if(row==n)return true;
    if(row==x)return nQueensBackTracking(board, row+1, x, y);
    for(int i=0; i<n; i++){
        cout<<"       ("<<row<<", "<<i<<")"<<endl;
        if(isSafe(board, row, i)){
            board[row][i] = 1;
            if(nQueensBackTracking(board, row+1, x, y))return true;
            else board[row][i] = 0;
        }
    }
    return false;
}

pair<vector<vector<bool>>, bool>nQueensWithOneQueen(int n, int x, int y){
    //PARAMS:
    //     n: size of the board 
    //     i: row of the 1st queen initially placed
    //     j: col of the 1st queen initially placed
    //RETURNS:
    //     board: optimal arrangement of queens
    //     found: denotes if feasible solution was found
    
    vector<vector<bool>>board(n, vector<bool>(n, 0));
    board[x][y] = 1;
    bool found = nQueensBackTracking(board, 0, x, y);
    return make_pair(board, found);
}

void printMatrix(vector<vector<bool>> mat){
    int n = mat.size();
    for(int i=0; i<n+1; i++)cout<<"=="; cout<<endl;
    for (auto &&row : mat){
        for (auto &&i : row)cout<<i<<' '; cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<n+1; i++)cout<<"=="; cout<<endl;
}

int main(){
    int n=5, x=1, y=1;

    vector<vector<bool>>board; bool found;
    std::tie(board, found) = nQueensWithOneQueen(5, x, y);
    if(found)printMatrix(board);
    else cout<<"NO SOLUTION FOUND"<<endl;
}