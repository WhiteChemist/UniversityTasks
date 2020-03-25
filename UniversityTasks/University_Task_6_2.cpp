#include "University_Task_6_2.h"
#include <iostream>
#include <ctime>


using namespace std;
using namespace ut6_2;


BinaryTree* ut6_2::addNode(BinaryTree* tree, int value)
{
	if (tree == NULL)
	{
		tree = new BinaryTree(value);
	}
	else
	{
		if (value == tree->value)
		{
			cout << "Error! Value must be unique!" << endl;
		}
		else if (value < tree->value)
		{
			tree->left = addNode(tree->left, value);
		}
		else if (value > tree->value)
		{
			tree->right = addNode(tree->right, value);
		}
	}
	return tree;
}

BinaryTree* ut6_2::balanceTree(BinaryTree* tree)
{
	auto ptr = tree->right;
	tree->right = ptr->left;
	ptr->left = tree;
	return ptr;
}

BinaryTree* ut6_2::initializeTree(int value)
{
	BinaryTree* tree = new BinaryTree();
	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

<<<<<<< HEAD
<<<<<<< HEAD
BinaryTree* ut6_2::getPtrToNode(BinaryTree* node, int key)
{
	BinaryTree* result=NULL;
	auto temp = node;
	if (temp != NULL)
	{
		if (temp->value > key)
		{
			result=getPtrToNode(temp->left,key);
		}
		else if (temp->value < key)
		{
			result = getPtrToNode(temp->right, key);
		}
		else if (temp->value = key)
		{
			result = temp;
		}
	}
	return result;
}

void ut6_2::searchInfoByKey(BinaryTree* tree, int key)
{

}

void ut6_2::directByPass(BinaryTree* tree)
=======
=======
>>>>>>> refs/remotes/origin/master
BinaryTree* ut6_2::freeMemory(BinaryTree* tree)
{
	return nullptr;
}

BinaryTree* ut6_2::getPointerByKey(BinaryTree* tree,int value)
{
	auto ptr = tree;
	bool isFound = false;
	while (tree!=NULL)
	{
		if (ptr->value == value)
		{
			isFound = true;
			break;
		}
		else if (ptr->value< value)
		{
			ptr = ptr->right;
		}
		else if (ptr->value > value)
		{
			ptr = ptr->left;
		}
	}
	if (isFound == false)
		cout << "Value not found!" << endl;
	return ptr;
}

void ut6_2::showTree(BinaryTree* tree)
>>>>>>> abf6a25413ab6682933106ee327a195f4a22ccfc
{
	auto ptr = tree;
	if (ptr != NULL)
	{
<<<<<<< HEAD
<<<<<<< HEAD
		cout << ptr->value << ends;
		backwardByPass(ptr->left);
		backwardByPass(ptr->right);
		
=======
=======
>>>>>>> refs/remotes/origin/master
		cout << tree->value << " ";
		showTree(tree->left);
		showTree(tree->right);
>>>>>>> abf6a25413ab6682933106ee327a195f4a22ccfc
	}
}

void ut6_2::backwardByPass(BinaryTree* tree)
{
	auto ptr = tree;
	if (ptr != NULL)
	{
		backwardByPass(ptr->left);
		backwardByPass(ptr->right);
		cout << ptr->value<<ends;
	}
}

void ut6_2::deleteNode(BinaryTree* tree,int key)
{
	auto ptr = tree;
	auto prev = tree;
	while (true){
		if (ptr != NULL){
			if (ptr->value < key){
				prev = ptr;
				ptr = ptr->right;
			}
			else if (ptr->value > key){
				prev = ptr;
				ptr = ptr->left;
			}
			else if (ptr->value == key){
				if (prev->value < key){
					if (ptr->left != NULL)
					{
						prev->right = ptr->left;
						ptr->left = ptr->left->right;
					}
					else
					{
						prev->right = ptr->left;
					}
				}
				else if (prev->value > key){
					if (ptr->left != NULL)
					{
						prev->left = ptr->left;
						ptr->left = ptr->left->right;
					}
					else
					{
						prev->left = ptr->left;
					}
				}
				delete ptr;
				break;
			}
		}
		else{
			cout << "Node has been NULL!" << endl;
			break;
		}
	}
	
}

void ut6_2::showTree(BinaryTree* tree)
{
	if (tree != NULL) {
		if (tree->left == NULL && tree->right != NULL)
		{
			showTree(tree->right);
			cout << tree->value << " " << tree << endl;
		}
		else if(tree->left!=NULL&&tree->right==NULL)
		{
			showTree(tree->left);
			cout << tree->value << " " << tree << endl;
		}
		else
		{
			showTree(tree->left);
			cout << tree->value << " " << tree << endl;
			showTree(tree->right);
		}
				
	}
	
}

void ut6_2::start()
{
	srand(time(0));
<<<<<<< HEAD
	auto tree = initializeTree(8);
	tree = addNode(tree, 3);
	tree = addNode(tree, 10);
	tree = addNode(tree, 1);
	tree = addNode(tree, 6);
	tree = addNode(tree, 14);
	tree = addNode(tree, 4);
	tree = addNode(tree, 7);
	tree = addNode(tree, 13);
	showTree(tree);
	cout << endl;
	backwardByPass(tree);
	cout << endl;
	directByPass(tree);
	cout << endl;
	balanceTree(tree);
	cout << endl;
	directByPass(tree);
=======
	auto tree = initializeTree(7);
	for (int i = 0; i < 20; i++)
		tree = addNode(tree, i);

	showTree(tree);
	cout << endl;
	auto ptr = getPointerByKey(tree, 9);
	
<<<<<<< HEAD
>>>>>>> abf6a25413ab6682933106ee327a195f4a22ccfc
=======
>>>>>>> refs/remotes/origin/master
}
