
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> tree_set_count;
    unordered_map<string, int>::iterator itr;
    priority_queue<string, vector<string>, std::greater<string> > treeNames; //This stores strings such that strings that go
                                                                            //first, alphabetically, go to the top.
    int numTrees = 0;
    string str;
    while(getline(cin,str)){ //If tree is not in map, add it to map, and p_queue
        if (tree_set_count.find(str) != tree_set_count.end()) //If tree family has been encountered before
            tree_set_count[str]++;
        else{//We need to make sure tree's are printed alphabetically
            tree_set_count[str] = 1;
            treeNames.push(str);
        }
        numTrees++;
    }
    while(!treeNames.empty()){ //Outputs tree's and their population proportions
        cout<<treeNames.top()<<" ";
        itr = tree_set_count.find(treeNames.top());
        cout<<setprecision(6)<<fixed<<((1.0*itr->second)/numTrees)*100.0<<endl;//This is to get proportion of treeFamily vs treeCount to specs
        treeNames.pop();
    }
    return 0;
}