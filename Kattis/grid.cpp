#include <iostream>
#include <queue>
using namespace std;

int grid[500][500];
bool visited[500][500];

struct node{
    short first, second;
    int iteration = 0; //Iteration keeps track of the distance from this node too root
};

void printRow(int line[], const int& size){ //For Debugging
    for(int x = 0; x< size; x++)
        cout<<line[x]<<" ";
    cout<<endl;
}

void printNode(node Target){ //For Debugging
    cout<<"["<<Target.first<<"]["<<Target.second<<"] - iteration = "<<Target.iteration<<endl; 
}

node newNode(const int& row, const int& col, const int& iteration){
    node thisNode;
    thisNode.first = row;
    thisNode.second = col;
    thisNode.iteration = iteration;
    return thisNode;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    short row, col, currValue;
    char input;
    bool found = false;
    queue<node> BFS;
    node target;
    
    cin>>row>>col; //Creates grid with user defined dimensions, and read values
    for(int y = 0; y < row; y++){
        for(int x = 0; x < col; x++){
            cin>>input;
            grid[y][x] = input - '0';
            if((row == y && col == x) || input!=0)
                visited[y][x] = false;
            else
                visited[y][x] = true;
        }
    }
    
    BFS.push(newNode(0,0,0)); //Start at top left    
    while(!BFS.empty()){ //Use the iteration in struct{node} to keep track of distance. Don't need to visit a node more than once as those paths are exhausted
                        //And if they have been exhausted earlier, that means they've been exhausted sooner and require less steps
        target = BFS.front();
        BFS.pop();
        currValue = grid[target.first][target.second];
        if(target.first == row-1 && target.second == col -1){ //If we find the right node, we can quit
            found = true;
            break;
        }
        else if(currValue > 0){
            if(target.second + currValue < col  && !visited[target.first][target.second+currValue] ){ //If you can move to right
                BFS.push(newNode(target.first, target.second+currValue, target.iteration+1));
                visited[target.first][target.second+currValue] = true;
            }
            if(target.first+currValue < row && !visited[target.first+currValue][target.second] ){ //If you can move down
                BFS.push(newNode(target.first + currValue, target.second, target.iteration+1));
                visited[target.first+currValue][target.second] = true;
            }
            if(target.second - currValue >= 0 && !visited[target.first][target.second-currValue]){ //If you can move left
                BFS.push(newNode(target.first, target.second - currValue, target.iteration+1)); 
                visited[target.first][target.second-currValue] = true;
            }
            if(target.first - currValue >= 0 && !visited[target.first-currValue][target.second]){ //If you can move up
                BFS.push(newNode(target.first - currValue, target.second, target.iteration+1));
                visited[target.first- currValue][target.second] = true;
            }            
        }
    }
    (found)? cout<<target.iteration<<endl : cout<<-1<<endl;
    return 0;
}