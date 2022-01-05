//
// Created by Ye Xu on 1/4/22.
//

#include "Num_Islands.h"
#include <iostream>
#include <stack>

//TODO: BFS solution, iterative
int Num_Islands_Solutions::numIslandsBFS(vector<vector<char> >& grid){
    int islands_count = 0;
    int width = grid.size();
    int height = grid[0].size();

    for (int i = 0; i < width; i++ ){
        for (int j = 0; j < height; j++){
            if (grid[i][j] == '1'){
                islands_count++;
                queue<pair<int, int> > island_bfs;
                island_bfs.push(make_pair(i, j));
                grid[i][j] = '0';
                while(!island_bfs.empty()){
                    auto temp = island_bfs.front();
                    island_bfs.pop();
                    int x = temp.first;
                    int y = temp.second;
                    //Forward search for neighboring nodes. If a hit, then put into queue
                    //and wait to be poped out of the queue in the FIFO order.
                    if (x + 1 < width && grid[x + 1][y] == '1'){
                        island_bfs.push(make_pair(x + 1, y));
                        grid[x + 1][y] = '0';
                    }
                    if (y + 1 < height && grid[x][y + 1] == '1'){
                        island_bfs.push(make_pair(x, y + 1));
                        grid[x][y + 1] = '0';
                    }
                    //back track seems not necessary, BUT
                    //sometimes after vertical movement, we might
                    //forget the x in front maybe 1, that's why this
                    //back track is important
                    if (x - 1 >= 0 && grid[x - 1][y] == '1'){
                        island_bfs.push(make_pair(x - 1, y));
                        grid[x - 1][y] = '0';
                    }
                    if (y - 1 >= 0 && grid[x][y - 1] == '1'){
                        island_bfs.push(make_pair(x, y - 1));
                        grid[x][y - 1] = '0';
                    }
                }
            }
        }
    }
    return islands_count;
}


//TODO: DFS solution, recursive,
//This structure is almost identical to the BFS structure, here just swap out the FIFO structure with a LIFO
//Recursive DFS visit function(without time stamp)
void Num_Islands_Solutions::DFSVisiting(vector<vector<char> >& grid, int row, int col){
    /*
     * Originally, this right here is used to increment time and pay a visit to all adjacent nodes
     * Here would be a bit different. First time is unecessary, thus there's no need to do a
     * backpropogation to increment time. but rather leave the whole process to the recurssion backtrack.
     * one more thing would be the adjacent nodes are always 4.
     */
    int width = grid.size();
    int height = grid[0].size();
    //first the input row and col is where we find the node to start the DFS traverse.
    //Thus here we needs to set it to 0 first since we just visited.
    grid[row][col] = '0';

    if (row - 1 >= 0 && grid[row - 1][col] == '1')
        DFSVisiting(grid, row - 1, col);
    if (col - 1 >= 0 && grid[row][col - 1] == '1')
        DFSVisiting(grid, row, col - 1);
    if (row + 1 < width && grid[row + 1][col] == '1')
        DFSVisiting(grid, row + 1, col);
    if (col + 1 < height && grid[row][col + 1] == '1')
        DFSVisiting(grid, row, col + 1);
}
//DFS Island count function
int Num_Islands_Solutions::numIslandsDFS(vector<vector<char> >& grid){
    int islands_count = 0;
    int width = grid.size();
    int height = grid[0].size();

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if (grid[i][j] == '1'){
                islands_count += 1;
                DFSVisiting(grid, i, j);

            }
        }
    }
    return islands_count;
}

//TODO: DFS solution, iterative
int Num_Islands_Solutions::numIslandsDFS_iter(vector<vector<char> >& grid){
    int islands_count = 0;
    int width = grid.size();
    int height = grid[0].size();

    for (int i = 0; i < width; i++ ){
        for (int j = 0; j < height; j++){
            if (grid[i][j] == '1'){
                islands_count++;
                //here instead of the FIFO structure, using LIFO to achieve the same idea
                //As there's a boundary set up, thus can prevent the DFS infinity loop
                stack<pair<int, int> > island_bfs;
                island_bfs.push(make_pair(i, j));
                grid[i][j] = '0';
                while(!island_bfs.empty()){
                    auto temp = island_bfs.top();
                    island_bfs.pop();
                    int x = temp.first;
                    int y = temp.second;
                    //Forward search for neighboring nodes. If a hit, then put into queue
                    //and wait to be poped out of the queue in the FIFO order.
                    if (x + 1 < width && grid[x + 1][y] == '1'){
                        island_bfs.push(make_pair(x + 1, y));
                        grid[x + 1][y] = '0';
                    }
                    if (y + 1 < height && grid[x][y + 1] == '1'){
                        island_bfs.push(make_pair(x, y + 1));
                        grid[x][y + 1] = '0';
                    }

                    if (x - 1 >= 0 && grid[x - 1][y] == '1'){
                        island_bfs.push(make_pair(x - 1, y));
                        grid[x - 1][y] = '0';
                    }
                    if (y - 1 >= 0 && grid[x][y - 1] == '1'){
                        island_bfs.push(make_pair(x, y - 1));
                        grid[x][y - 1] = '0';
                    }
                }
            }
        }
    }
    return islands_count;
}



//Island area BFS version
//Note the grid data type has been changed from char to int.
int Max_Island_Area::maxAreaOfIslandBFS(vector<vector<int> >& grid){
    int islands_count = 0;
    int width = grid.size();
    int height = grid[0].size();
    int max_area = 0;

    for (int i = 0; i < width; i++ ){
        for (int j = 0; j < height; j++){

            if (grid[i][j] == 1){

                int curr_area = 1;
                islands_count++;
                queue<pair<int, int> > island_bfs;
                island_bfs.push(make_pair(i, j));
                grid[i][j] = 0;
                while(!island_bfs.empty()){
                    auto temp = island_bfs.front();
                    island_bfs.pop();
                    int x = temp.first;
                    int y = temp.second;
                    if (x + 1 < width && grid[x + 1][y] == 1){
                        island_bfs.push(make_pair(x + 1, y));
                        grid[x + 1][y] = 0;
                        curr_area += 1;
                    }
                    if (y + 1 < height && grid[x][y + 1] == 1){
                        island_bfs.push(make_pair(x, y + 1));
                        grid[x][y + 1] = 0;
                        curr_area += 1;
                    }
                    if (x - 1 >= 0 && grid[x - 1][y] == 1){
                        island_bfs.push(make_pair(x - 1, y));
                        grid[x - 1][y] = 0;
                        curr_area += 1;
                    }
                    if (y - 1 >= 0 && grid[x][y - 1] == 1){
                        island_bfs.push(make_pair(x, y - 1));
                        grid[x][y - 1] = 0;
                        curr_area += 1;
                    }

                }
                if (curr_area > max_area)
                    max_area = curr_area;
            }
        }
    }
    return max_area;
}

//TODO: DFS iterative version, Max Island area
