#include <iostream>
using namespace std;

int main()
{

  int b, k, g;
  int d = 0;
  cin>>b>>k>>g;
  //determines amount of groups that can actually fight
  int canFight = k/g;
  //if there are x amount of suitable groups, then x amount of
  //bridges can be searched per day
  for(int i = 1; i <b; i += canFight)
    d++;

  cout<<d;

  return 0;
}