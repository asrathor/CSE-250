#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

string to_string(const string& s){
	
	//separate string from the frequency
	string str="";
	int i=0;	
		while(s.at(i)!=' '){
			str=str+s.at(i);
			i++;
		}
	return str;
}

int to_frequency(const string& s){

	string str="";
	int i =s.length()-1;
		while(s.at(i)!=' '){
			str=s.at(i)+str;
			i--;
		}
		
	int j=0;
	j = stoi(str);
	
	return j;
		
}

bool edit_dis(const string& s, const string& st){

	int i = s.length();
	int j = st.length();
	int k=0;
	
	if(i>j){
		k=i-j;
	}else{
		k=j-i;
	}
	
	if(k<=1){
		return true;
	}
	
	return false;

}

//define a method that checks whether query is of edit distance of 1 or not

bool edit_distance(const string& s, const string& st){
		
	if(edit_dis(s,st)==false){
		return false;
	}
	//if only one character is different
	int count = 0;
	int i = 0;
	int j = 0;
//	sort(s.begin(),s.end());
//	sort(st.begin(),st.end());
	
	if(s.length()<st.length()){
	
		j = st.length();
	}else{
	
		j = s.length();
	}
	
	while(i<j-1){
			
		if(s.at(i)==st.at(i)){
			i++;
		}else{
			count++;
			i++;
		}
	}
	
	if(count!=1){
		return false;
	}
	return true;
}

//function for giving out output with maximum frequency
string max_frequency(vector<string> v){
	vector<int> vvv;
	int max = 0;
	string s="";	
	for(int a = 0; a<v.size();a++){
		string b = v.at(a);
		vvv.push_back(to_frequency(b));
	}
	for(int i=0; i<vvv.size();i++){
		
		if(vvv.at(i)<max){
			continue;	
		}else{
			max=vvv.at(i);
		}
	
	}

	for(int j=0; j<vvv.size();j++){
		
		if(max==vvv.at(j)){
			
			return v.at(j);
		}
	
	}

	return s;
}
//function to check if frequency are same
bool same_frequency(vector<string> v){
	int count =0;
	int max=0;
	vector<int> vv;
	for(int a=0;a<v.size();a++ ){
		string b = v.at(a);
		vv.push_back(to_frequency(b));
	}
	for(int i =0; i<vv.size();i++){
	
		if(vv.at(i)<max){
			continue;
		}else{
			max=vv.at(i);
			i++;
		}
	}
	for(int j=0; j<vv.size();j++){
		
		if(max==vv.at(j)){
			count++;
		}
	}

	if(count>1){
		return true;
	}
	return false;
}


//function for giving out output which is l smaller
string lex_smallest(vector<string> vvv, vector<string>v,vector<int> vv){
	string smallest =v.at(0);
//	for(int a=0;a<vvv.size();a++){
	
//		cout<<"out"<<vvv.at(a)<<endl;
//	}

	for(int i =1; i<v.size();i++){
			if(smallest<v.at(i)){
				continue;
			}else{
				smallest=v.at(i);
			}
		
		}
	int l=0;
	for(int j =0; j<vv.size();j++){
		if(smallest==v.at(j)){
			l=j;
		}
	}
	cout<<smallest<<" "<<vv.at(l)<<endl;
	return smallest;
}

int main(int argc,char* argv[]){

	vector<string> v;
	//store dict
	vector<string> vd;
	string s;	
	//store words
	vector<string> vw;
	//store frequency
	vector<int> vf;
	string line;
	ifstream myfile(argv[1]);
//	for(int i = 0; i<2;i++){
//		cout<<i<<argv[i]<<endl;
//	}
	if(myfile.is_open()){

		while(getline(myfile,line)){
			vd.push_back(line);
			vw.push_back(to_string(line));
			vf.push_back(to_frequency(line));
		}
	}
	
//	cout<<"It safely reaches here"<<endl;
	//store cin queries
	queue<string> vq;
	
	while(cin>>s){
		
		vq.push((s));
//		cout<<vq.back()<<endl;
	}
	
	//if query name already exists then increase corrsponding frequecy by 1
	//if query does not exist then do something..
	while(vq.size()!=0){
	
		string q= vq.front();
		bool found = false;
		for(int i =0; i < vw.size(); ++i){	
			if(q==vw.at(i)){
				cout<<q<<" "<<vf.at(i)<<endl;
				vf.at(i)++;
				found = true;
			//	cout<<q<<" "<<vf.at(i)<<endl;
			}
		
		}
		int count = 0;
		if(found==false){
			for(int j = 0; j<vw.size();++j){
				string tried= vw.at(j);
				//if the edit distance is 1
				if(tried.length()<q.length()){
				if(edit_distance(tried,q)==true){
					v.push_back(vd.at(j));
					count++;
				}
				}else{
					if(edit_dis(tried,q)==true){
						v.push_back(vd.at(j));
						count++;
					}
				
				}
				
			}
		// TO DO- GIVE OUTPUT WITH HIGHEST FREQUENCY 
			
			if(count>0 && same_frequency(v)==true){
				
				string s = lex_smallest(v,vw,vf);
				
			}	
			else if(count>0 && same_frequency(v)==false){	

				cout<<max_frequency(v)<<endl;
//			
			}
			else{
				cout<<"-"<<endl;
				vd.push_back(q+" "+"1");
				vw.push_back(q);
				vf.push_back(1);
			}

		}
		
		vq.pop();
	
	}
	
}
