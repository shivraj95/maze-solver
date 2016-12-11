//
//  maze.cpp
//  warmupfor3
//
//  Created by Shivraj Gill on 7/21/15.
//  Copyright (c) 2015 Shivraj Gill. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;



bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    
    int row = sr;
    int col = sc;
    
    maze[row][col] = 'D';
    if(row == er && col == ec) {
        return true;
        
    }
    else
    {
        
        if(row - 1 > 0 && col < nCols && col > 0 && row - 1 < nRows){
            if(maze[row - 1][col] == '.') { //North
                if(pathExists(maze, nRows, nCols, row - 1, col, er, ec)){
                    return true;
                }
            }
            
        }
        
        if(row < nRows && col + 1 < nCols && col + 1 > 0 && row > 0){
            if(maze[row][col+1] == '.') {//East
                if(pathExists(maze, nRows, nCols, row, col + 1, er, ec)){
                    return true;
                }
                   
            }
            
        }
        
        if(row + 1 < nRows && col < nCols && col > 0 && row + 1 > 0){
            if(maze[row+1][col] == '.') {//South
                if(pathExists(maze, nRows, nCols, row + 1, col, er, ec)){
                    return true;
                }
            }
            
        }
        
        if(row < nRows && col - 1 < nCols && col - 1 > 0 && row > 0){
            
            if(maze[row][col-1] == '.') {//West
                if(pathExists(maze, nRows, nCols, row, col - 1, er, ec)){
                    return true;
                }
            }
            
        }
    }
    
    return false;
}

