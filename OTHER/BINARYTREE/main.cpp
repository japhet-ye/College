#include<iostream>

class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x),left(NULL),right(NULL){}

};

void go_through_tree(TreeNode* Node);

int main(){

	TreeNode temp(10);TreeNode* point = &temp;
	TreeNode branch1(12);TreeNode* point2 = &branch1;
	TreeNode branch2(11);
	TreeNode branch3(13);
	TreeNode branch4(15);


	point->left = &branch1;point->right = &branch2;
	point2->left = &branch3; point2->right = &branch4;

	TreeNode* k = point;
	go_through_tree(k);
/*
	while(k != NULL){
		std::cout<<k->val<<std::endl;
		if(k->left != NULL){
			k = k->left;
		}
		else if(k->right != NULL){
			k = k->right;
		}
		else{
			k = NULL;
		}
	}
*/
	// std::cout<<"Hello World"<<std::endl;
	return 0;

}


void go_through_tree(TreeNode* Node){
	std::cout<<Node->val<<std::endl;
	if(Node->left != NULL){
		go_through_tree(Node->left);
	}
	if(Node->right != NULL){\
		go_through_tree(Node->right);
	}
	if(Node->left == NULL && Node->right == NULL){
		// std::cout<<Node->val<<std::endl;
	}
}
