#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void def (unordered_map<string,int>& vars){
  string input;
  int value;

  cin>>input>>value;
  vars[input] = value; //This notation will add the key (here its called input) into map, and assign the value on the right of the assignment operator 
}

//Finds the correct word or returns "unknown"
string find(unordered_map<string,int>& vars, int target){
  unordered_map<string, int>:: iterator itr;
  for (itr = vars.begin(); itr != vars.end(); itr++){
    if(itr->second == target)
      return (itr->first);
  }
  return "unknown";
}

void calc(unordered_map<string,int>& vars){
  char operation;
  string word, line="";
  int value, sum = 0;
  bool unknown = false;
  // Read the string and operation and check operation for =='=' to see if you need to keep reading
  cin>>word;
  if (vars.find(word) != vars.end())
      sum = vars[word];
  else
    unknown = true;
  line += word;

  do{ //Read operation first, if its not '=', read another word and try to find that value -> add/subt that value to sum if found, add to line
      // if operation is '=' then output the line and then sum
    cin>>operation;
    if (operation == '+'){ 
      cin>>word;
      ((!unknown) && (vars.find(word) != vars.end())) ? sum += vars[word] : unknown = true; //Uses short-circuit evaluation
    }
    else if (operation == '-'){
      cin>>word;
      ((!unknown) && (vars.find(word) != vars.end())) ? sum -= vars[word] : unknown = true; //Uses short-circuit evaluation
    }
    else{
      cout<<line<< " = ";
      break;
    }
    line += " ";
    line += operation;
    line +=" ";
    line += word;
  }while (true);

  //Challenge requires a defined word or "unknown" to be output 
  if (!unknown){
    word = find(vars, sum);
    cout<<word<<endl;
  } 
  else
    cout<<"unknown"<<endl;
}

//For debugging 
void printMap(unordered_map<string, int>& variables){
  unordered_map<string, int>:: iterator itr;
  for (itr = variables.begin(); itr != variables.end(); itr++){
      // itr works as a pointer to pair<string, double>
      // type itr->first stores the key part  and
      // itr->second stores the value part
      cout << itr->first << "  " << itr->second << endl;
    }
}

int main(){
  unordered_map<string, int> variables;
  string instr = "";
  while(cin>>instr){
    switch (instr[1]){ //Only need to look at 2nd index of instr to determine the instructions - better than entire comparison
      case 'e':
        def(variables);
        break;
      case 'a':
        calc(variables);
        break;
      case 'l':
        variables.clear();
        break;
      default:
        cerr<<"Error in main: reading instruction"<<endl;
        break;
    }
  }

  return 0;
}