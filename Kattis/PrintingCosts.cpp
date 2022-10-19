#include <iostream>
#include <string>
using namespace std;

void assignCost(int[]);

int main()
{
  int cost[95];
  assignCost(cost);
  int linTot=0, n, temp;
  string input;
  getline(cin, input);
  while (true)
  {
    n = input.length();
    for (int i=0;i<n;i++)
    {
    temp = (int)input[i];
    linTot+=cost[temp-32];
    }
    cout<<linTot<<endl;
    linTot=0;
    getline(cin, input);
    if (cin.fail()) break;
  }
  return 0;
}




void assignCost (int cost[])
{
//A script to quickly generate the script from the kattis questions table
//The code underneath this function is what was used to generate this array
    cost[0] = 0;
    cost[1] = 9;
    cost[2] = 6;
    cost[3] = 24;
    cost[4] = 29;
    cost[5] = 22;
    cost[6] = 24;
    cost[7] = 3;
    cost[8] = 12;
    cost[9] = 12;
    cost[10] = 17;
    cost[11] = 13;
    cost[12] = 7;
    cost[13] = 7;
    cost[14] = 4;
    cost[15] = 10;
    cost[16] = 22;
    cost[17] = 19;
    cost[18] = 22;
    cost[19] = 23;
    cost[20] = 21;
    cost[21] = 27;
    cost[22] = 26;
    cost[23] = 16;
    cost[24] = 23;
    cost[25] = 26;
    cost[26] = 8;
    cost[27] = 11;
    cost[28] = 10;
    cost[29] = 14;
    cost[30] = 10;
    cost[31] = 15;
    cost[32] = 32;
    cost[33] = 24;
    cost[34] = 29;
    cost[35] = 20;
    cost[36] = 26;
    cost[37] = 26;
    cost[38] = 20;
    cost[39] = 25;
    cost[40] = 25;
    cost[41] = 18;
    cost[42] = 18;
    cost[43] = 21;
    cost[44] = 16;
    cost[45] = 28;
    cost[46] = 25;
    cost[47] = 26;
    cost[48] = 23;
    cost[49] = 31;
    cost[50] = 28;
    cost[51] = 25;
    cost[52] = 16;
    cost[53] = 23;
    cost[54] = 19;
    cost[55] = 26;
    cost[56] = 18;
    cost[57] = 14;
    cost[58] = 22;
    cost[59] = 18;
    cost[60] = 10;
    cost[61] = 18;
    cost[62] = 7;
    cost[63] = 8;
    cost[64] = 3;
    cost[65] = 23;
    cost[66] = 25;
    cost[67] = 17;
    cost[68] = 25;
    cost[69] = 23;
    cost[70] = 18;
    cost[71] = 30;
    cost[72] = 21;
    cost[73] = 15;
    cost[74] = 20;
    cost[75] = 21;
    cost[76] = 16;
    cost[77] = 22;
    cost[78] = 18;
    cost[79] = 20;
    cost[80] = 25;
    cost[81] = 25;
    cost[82] = 13;
    cost[83] = 21;
    cost[84] = 17;
    cost[85] = 17;
    cost[86] = 13;
    cost[87] = 19;
    cost[88] = 13;
    cost[89] = 24;
    cost[90] = 19;
    cost[91] = 18;
    cost[92] = 12;
    cost[93] = 18;
    cost[94] = 9;
    cost[94] = 9;
    return;
}

/*
To quickly generate the printing cost of each letter
for the array run this code:
#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    if (!in)
        cerr<<"Error reading"<<endl;
    else if (!out)
        cerr<<"Error creating"<<endl;
    char item;
    int num;
    out<<"cost[0] = 0<<endl;"
    do
    {
        in>>item;
        out<<"cost["<<static_cast<int>(item)-32<<"] = ";
        in>>num;
        out<<num<<";"<<endl;
    }while (in);
    return 0;
}
*/