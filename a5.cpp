#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v;
	int m=0;
	string line;
	ifstream myfile("fooo.txt");
	
	if(myfile.is_open()){
		while(getline(myfile,line)){
			if(line=="" || line==" "){
				continue;
			}
			m = stoi(line);
			v.push_back(m);
		}
	
	}
	
//	for(int i=0; i<v.size();i++){
//		cout<<"v:"<<v.at(i)<<endl;
//	}
	
//	vector<vector<int>> sortedV;
	
	sort(v.begin(),v.end());

//	for(int i=0; i<v.size();i++){
//		cout<<"v: "<<v.at(i)<<endl;
//	}
	
	int max=0;
	int min=0;
	int median=0;

	min=v.at(0);
	max=v.at(v.size()-1);
	median=v.at((v.size()/2));
	cout<<min<<" "<<median<<" "<<max<<endl;
}
