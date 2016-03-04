#ifndef A77_HPP
#define A77_HPP

#include "symbol.hpp"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef bnode<symbol> HTnode;
/**
void sumNode(bnode<symbol>* root){
	if(root==NULL){
		return;
	}
	sumNode(root->left);
	sumNode(root->right);

	if(root->left != NULL){
		root->value.count += root->left->value.count;
	}
	if(root->right != NULL){
		root->value.count += root->right->value.count;
	}

}
**/
struct comp{
	bool operator()(HTnode* lhs, HTnode* rhs){
		return ((lhs->value.count > rhs->value.count) || (!(rhs->value.count > lhs->value.count) && (lhs->value.value > rhs->value.value)));
	}
};

template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last){
	
	priority_queue<HTnode*,vector<HTnode*>, comp > qqq;

//	priority_queue<HTnode*> q;

//	vector<HTnode*> v;	
//	queue<HTnode*> qq;
//	stack<HTnode*> s;
	
	for(; first!=last; ++ first){
		qqq.push(new HTnode(*first));
	}
/**
	HTnode* z = q.top();
	while(q.size()!=0){
		HTnode* a = q.top();
		q.pop();
		s.push(a);
	}

	while(s.size()!=0){
		HTnode* a = s.top();
		s.pop();
		qq.push(a);
		cout<<qq.front()->value.value<<endl;
	}
	
//	while(q.size()!=0){
//		HTnode* a;
//		a= q.top();
//		v.push_back(a);
//		q.pop();
//	}

	HTnode* x = qq.front();
	if(z==x){
		cout<<"something is wrong"<<endl;
	}
**/
	while(qqq.size()>1){
		HTnode* left = qqq.top();
		qqq.pop();
		HTnode* right = qqq.top();
		qqq.pop();
	//	if(a<b){
	//		left = a;
	//		right = b;
	//	}else{
	//		cout<<"Why is it here"<<endl;
	//		left = b;
	//		right = a;
	//	}
		symbol* s = new symbol(0, left->value.count+right->value.count);
		HTnode* res = new HTnode(*s, left, right);
		qqq.push(res);
		delete s;
	}
	return qqq.top();
}

void release_tree(bnode<symbol>* root){
	HTnode* n = root;
	if(n->left !=0){
		release_tree(n->left);
	}
	if(n->right !=0){
		release_tree(n->right);
	}
	delete n;
/**
	HTnode* n = root;
	if (n->left != NULL) {
		release_tree(n->left);
	}
	if (n->right != NULL) {
		release_tree(n->right);
	}
	cout << "Delete the following node: " << n->value.value << endl;
	delete n;
	root = NULL;
//	delete root->value;	
**/
}

#endif // A77_HPP
