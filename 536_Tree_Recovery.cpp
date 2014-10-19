#include<cstdio>
#include<string>
#include<iostream>
#define debug false
using namespace std;
void post_order(string preorder, string inorder){
	if (preorder.size() > 0){
		char root = preorder[0];
		int indexRoot = inorder.find(root);
		string leftTree, rightTree;
		if (indexRoot > 0 && inorder.size() > 1){
			leftTree = inorder.substr(0, indexRoot);
		}
		else{
			leftTree = "";
		}
		if (indexRoot + 1 < inorder.size()){
			rightTree = inorder.substr(indexRoot + 1, inorder.size() - indexRoot - 1);
		}
		else{
			rightTree = "";
		}
		if (!leftTree.empty()){
			string leftTreePreorder = preorder.substr(1, leftTree.size());
			post_order(leftTreePreorder, leftTree);
		}
		if (!rightTree.empty()){
			string rightTreePreorder = preorder.substr(1 + leftTree.size(), rightTree.size());
			post_order(rightTreePreorder, rightTree);
		}
		//if (rightTree.empty() && leftTree.empty()){
			printf("%c", root);
		//}
	}
}
int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	string preorder, inorder;
	while (cin >> preorder >> inorder){
		post_order(preorder, inorder);
		printf("\n");
	}
	return 0;
}