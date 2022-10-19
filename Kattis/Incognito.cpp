#include <iostream>
#include <map>
#include <string>
using namespace std;
//Assumption I'm making is that the problem will not shove in multiple of the same item.
	//e.g. there will only be 1 piece of headgear called "hat"
hash<string> hasher;
struct attributeData{
	int number_of_elements = 0;
	string name = "";
};



//Failed --> Try using the key value pairs as <int*, string> and 
//where int* is number of items of the string family
int main(){
	int numTestCases, numAttributes;
	attributeData current;
	string item, type;
	map<attributeData, size_t> wardrobe;

	cin>>numTestCases;
	while(numTestCases > 0){
		cin>>numAttributes;
		while(numAttributes > 0){
			cin>>item>>type;
			current.name = type;
			auto itr = wardrobe.find(current);
			if(itr == wardrobe.end())
				wardrobe.insert(pair<attributeData,size_t>(current, hasher(current.name)));
			else if (itr !=wardrobe.end())
				itr->first.number_of_elements++;
			else
				cout<<"Error finding shit in map"<<endl;
			numAttributes--;
		}
		numTestCases--;
	}	
	return 0;
}
