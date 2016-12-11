//
//  mazequeue.cpp
//  homeworktwocs32
//
//  Created by Shivraj Gill on 7/14/15.
//  Copyright (c) 2015 Shivraj Gill. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    
    queue<Coord> coordQueue;
    
    Coord a(sr,sc);
    coordQueue.push(a);
    maze[sr][sc] = 'D';
    
    while(!coordQueue.empty()){
        
        const int row = coordQueue.front().r();
        const int col = coordQueue.front().c();
        
        cout << "(" << coordQueue.front().r() << "," << coordQueue.front().c() << ")"<< endl;
        coordQueue.pop();
        
        if(row == er && col == ec) {
            return true;
            
        }
        else
        {
            if(row - 1 > 0 && col < nCols && col > 0 && row - 1 < nRows){
                if(maze[row - 1][col] == '.') { //North
                     maze[row - 1][col] = 'D';
                     coordQueue.push(Coord(row - 1, col));
                 }
                
            }
            
            if(row < nRows && col + 1 < nCols && col + 1 > 0 && row > 0){
                
                if(maze[row][col+1] == '.') {//East
                    maze[row][col+1] = 'D';
                    coordQueue.push(Coord(row, col+1));
                }
                
            }
            
            if(row + 1 < nRows && col < nCols && col > 0 && row + 1 > 0){
                if(maze[row+1][col] == '.') {//South
                    maze[row + 1][col] = 'D';
                    coordQueue.push(Coord(row + 1, col));
                }
                
            }
            
            if(row < nRows && col - 1 < nCols && col - 1 > 0 && row > 0){

                if(maze[row][col-1] == '.') {//West
                    maze[row][col-1] = 'D';
                    coordQueue.push(Coord(row, col-1));
                }
                
            }
            
            
        }
        
    }
    
    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X.......@X",
        "XX@X@@.XXX",
        "X..X.X...X",
        "X..X...@.X",
        "X....XXX.X",
        "X@X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}




