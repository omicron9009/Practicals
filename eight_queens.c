// https://www.mycompiler.io/view/AngrJjFzBrm

#include <stdio.h>
#define N  8 
int board[N][N] ;
int isSafe(int row ,int col){
    int i , j ; 
    for(i = 0 ; i < row ; i++){
        if(board[i][col]==1 ){
            return 0 ;
        }
    }

    for( i = row , j = col  ; i >=0 && j >= 0 ; i--,j-- ){
        if(board[i][j]==1)
            return 0 ; 
    }

    for( i = row, j= col; i >=0 && j < N; i-- , j++ ){
        if(board[i][j]==1)
            return 0 ; 
    }

    return 1  ;
}

int solve(int row){
    if(row == N){
        return 1 ;
     }
    for(int col = 0 ; col < N ; col ++){
        if(isSafe(row,col)){
            board[row][col]=1 ;
            if(solve(row+1)){
                return 1 ;
            }
            board[row][col]=0;
        }
    }
    return  0;
    
}
void PrintBoard(){
    for(int i = 0 ;i < N ;i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
    return ;
}

int main() {
    solve(0);
    PrintBoard();
    return 0 ;
}
