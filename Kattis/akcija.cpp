#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    int amount, price;
    vector<int> list;
    cin >> amount;

    for(int i = 0; i < amount; i++) 
    {
        cin >> price;
        list.push_back(price);
    }

    sort(list.rbegin(), list.rend());
    int cost = 0;

    for(int i = 0; i < amount; i++) 
    {
        if(i % 3 != 2) 
            cost += list[i];
    }

    cout << cost << endl;

    return 0;
}