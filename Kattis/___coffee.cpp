#include <iostream>
using namespace std;

struct plot
{
    bool needCoverage = true, visited=false;
    char type = '0';
    plot *north = NULL, *south = NULL, *east = NULL, *west = NULL;
};

/*void placeMe(plot *&c)
{
//    cout<<"I work here"<<endl;
    c->visited = true;
    if(c->type != '#' && c->needCoverage)
    {
        c->type = 'E';
        if(c->north != NULL)
            c->north->needCoverage = false;
        if(c->south != NULL)
            c->south->needCoverage = false;
        if(c->east != NULL)
            c->east->needCoverage = false;
        if(c->west != NULL)
            c->west->needCoverage = false;
    }
    if(c->north!=NULL && !c->north->visited)
        placeMe(c->north);
    if(c->east!=NULL && !c->east->visited)
        placeMe(c->east);
    if(c->west!=NULL && !c->west->visited)
        placeMe(c->west);
    if(c->south!=NULL && !c->south->visited)
        placeMe(c->south);
}*/

int main()
{
    int n,m;
    plot *c = NULL;
    cin>>n>>m;
    plot map[n][m];

    for(int y=0; y<n; y++)
    {
        for(int x=0; x<m; x++)
        {
            cin>>map[y][x].type;
            if(map[y][x].type =='#')
                map[y][x].needCoverage=false;
            if(y > 0)
                map[y][x].north = &map[y-1][x];
            if(y < n-2)
                map[y][x].south = &map[y+1][x];
            if(x > 0)
                map[y][x].west = &map[y][x-1];
            if(x < m-2)
                map[y][x].east = &map[y][x+1];
        }
    }
    cout<<"Finished initLoop"<<endl;
    c = &map[n/2][m/2];
    
    for(int y = 0; y<n;y++)
    {
        for(int x = 0; x<m; x++)
            cout<<map[y][x].type;
        cout<<endl;
    }

    return 0;
}