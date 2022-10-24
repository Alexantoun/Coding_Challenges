#include <iostream>
#include <unordered_map>
using namespace std;

void initMap(unordered_map<char,int>& roman_num){
    roman_num['I'] = 1;
    roman_num['V'] = 5;
    roman_num['X'] = 10;
    roman_num['L'] = 50;
    roman_num['C'] = 100;
    roman_num['D'] = 500;
    roman_num['M'] = 1000;
}

int main(){
    unordered_map<char, int>roman;
    unordered_map<char, int>::iterator itr;
    initMap(roman);
    for(itr = roman.begin(); itr != roman.end(); itr++)
        cout<< itr->first <<" = "<< itr->second <<endl;
        
    return 0;
}