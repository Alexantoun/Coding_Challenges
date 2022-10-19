#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct block{
    char type;
    bool visited = false;
};

//If you're next to a trap, you feel a draft and stop progressing -> You go back the way you came
bool next_to_trap(vector<vector<block>>& level, const pair<int, int>& start, const int& width, const int& height){
    if(start.first -1 >= 0 && level[start.first-1][start.second].type =='T')
        return true;
    else if(start.first +1 < height && level[start.first+1][start.second].type =='T')
        return true;
    else if (start.second +1 < width && level[start.first][start.second+1].type == 'T')
        return true;
    else if (start.second -1 >= 0 && level[start.first][start.second -1].type == 'T')
        return true;
    return false;
}
//Recursively explore the map, and collect coins
void findPath(vector<vector<block>>& level, const pair<int, int>& start, const int& width, const int& height, int& coins){
    char type;
    level[start.first][start.second].visited = true;
    if(level[start.first][start.second].type == 'G'){ //Collect the coin
        level[start.first][start.second].type = '.';
        coins++;
    }

    if(!next_to_trap(level, start, width, height)){
        //If the square above you is define and has not been visited and is not a wall... Note you don't need to check for trap, as you're not adjacent to a trap
        if(start.first - 1 >= 0 && !level[start.first-1][start.second].visited && level[start.first-1][start.second].type!='#')
            findPath(level, make_pair(start.first -1, start.second), width, height, coins);
        
        if(start.first + 1 < height && !(level[start.first+1][start.second].visited) && level[start.first+1][start.second].type != '#')
            findPath(level, make_pair(start.first +1, start.second), width, height, coins);
        
        if(start.second+1 < width && !(level[start.first][start.second+1].visited) && level[start.first][start.second+1].type != '#')
            findPath(level, make_pair(start.first, start.second+1), width, height, coins);

        if(start.second-1 >= 0 && !(level[start.first][start.second-1].visited) && level[start.first][start.second-1].type != '#')
            findPath(level, make_pair(start.first, start.second-1), width, height, coins);
    }
}

int main(){
    int w, h;
    cin>>w>>h;
    block floor;
    //Using vectors to make passing 2D arrays easier
    vector<vector<block>> level;
    vector<block> line;
    pair<int, int> start;

    for(int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            if(row > 0)
                cin>>line[col].type;
            else{
                cin>>floor.type;
                line.push_back(floor);
            }
            if(line[col].type == 'P')
                start = make_pair(row, col);
        }
        level.push_back(line);
    }
    int numGold = 0;
    findPath(level, start, w, h, numGold);
    cout<<numGold<<endl;
    return 0;
}
