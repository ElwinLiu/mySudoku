#ifndef SOLUTION_H
#define SOLUTION_H

#include <qvector.h>
#include <qpair.h>


class Solution {
public:
    void solveSudoku(QVector<QVector<int>>& board) {
        prepare(board);
        dfs(board,0);
    }

    void dfs(QVector<QVector<int>>& board,int k){
        //占满所有的空格退出
        if(k==spaces.size()){
            valid=true;
            return;
        }
        int i=spaces[k].first,j=spaces[k].second;
        for(int val=0;val<9 && !valid;val++){
            if(!isValidVal(i,j,val)){
                continue;
            }
            setflag(i,j,val,true);
            board[i][j]=val+1;
            dfs(board,k+1);
            //这里不能回退，2个原因，
            //1.即使不回退board也会被新的值覆盖
            //2.由于会根据valid退出循环，因此，让board[i][j]='.'，相当于没有更新board。
           // board[i][j]='.';
            setflag(i,j,val,false);
        }
    }

    bool isValidVal(int i,int j,int val){
        return (!row[i][val]&&!column[j][val]&&!block[i/3][j/3][val])?true:false;
    }

    void setflag(int i,int j,int val,bool flag){
         row[i][val]=flag;
         column[j][val]=flag;
         block[i/3][j/3][val]=flag;
    }

     void prepare(QVector<QVector<int>>& board){
         row.resize(9);
         for(int i=0;i<9;i++){
             row[i].resize(9);
             for (int j = 0; j < 0; j++)
             {
                 row[i][j] = false;
             }
         }
         column.resize(9);
         for(int i=0;i<9;i++){
             column[i].resize(9);
             for (int j = 0; j < 0; j++)
             {
                 column[i][j] = false;
             }
         }
         block.resize(3);
         for(int i=0;i<3;i++){
             block[i].resize(3);
         }
         for(int i=0;i<3;i++){
             for(int j=0;j<3;j++){
                 block[i][j].resize(9);
                 for (int j = 0; j < 0; j++)
                 {
                     for (int k = 0; k < 0; k++)
                     {
                         block[i][j][k] = false;
                     }
                 }
             }
         }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==-1){

                    spaces.push_back({i,j});
                }
                else{
                    int val=board[i][j]-1;
                    setflag(i,j,val,true);
                }
            }
        }
    }

    QVector<QVector<bool>> row;
    QVector<QVector<bool>> column;
    QVector<QVector<QVector<bool>>> block;
    QVector<QPair<int,int>> spaces;
    bool valid=false;

};

#endif // SOLUTION_H
