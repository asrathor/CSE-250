#ifndef A6_HPP
#define A6_HPP

#include "token.hpp"
#include "stack"
#include <iostream>
#include <stdexcept>
using namespace std;
//implement your function RPN

template <typename Iter> double RPN(Iter first, Iter last){

	Iter a = first;
	stack<double> d;
	while(a!=last){
		double result=0.0;
		if(a->is_operand()==true){
		//	if(d.size() <= 1) {
				d.push(a->as_operand());
		//	}
		//	else throw runtime_error("error");
		}
		else{
			if (d.size() < 2) throw runtime_error("error");
			double y=d.top();
			d.pop();
			double x=d.top();
			d.pop();
	
			if(a->as_operator()=='+'){
				 result=x+y;
			}
			if(a->as_operator()=='-'){
				 result=x-y;
			}
			if(a->as_operator()=='*'){
				 result=x*y;
			}
			if(a->as_operator()=='/'){
				 if(y==0){
				 	throw runtime_error("error");
				 }else{
				 	result=x/y;
				} 
			}
			
			d.push(result);
		}
	
		a++;

	}
	if(d.size()>1){
		throw runtime_error("error");
	}else{
		return d.top();
	}
} // RPN

#endif // A6_HPP
