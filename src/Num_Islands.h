//
// Created by Ye Xu on 1/4/22.
//

#ifndef LEETCODEGRIND_NUM_ISLANDS_H
#define LEETCODEGRIND_NUM_ISLANDS_H

#include<vector>
#include<queue>
using namespace std;



/*
 * FOR DFS and BFS practice
 * Note that DFS and BFS can be all complete with a corresponding LIFO and FIFO data structure
 * But here the DFS is done as the book suggested using recursion instead.
 */

//TODO: ********************* IMPORTANT *********************
class Num_Islands_Solutions {
public:
    int numIslandsBFS(vector<vector<char> >& grid);
    void DFSVisiting(vector<vector<char> >& grid, int row, int col);
    int numIslandsDFS(vector<vector<char> >& grid);
    int numIslandsDFS_iter(vector<vector<char> >& grid);
};

class Max_Island_Area{
public:
    int maxAreaOfIslandBFS(vector<vector<int> >& grid);

};


#endif //LEETCODEGRIND_NUM_ISLANDS_H
