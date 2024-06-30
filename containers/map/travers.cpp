#include <iostream>
#include <queue>

struct	TreeNode
{
	int	value;
    TreeNode*	left;
    TreeNode*	right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
	public:
		BinaryTree() : _root(nullptr) {}

		void insert(int value) {_root = insertRecursive(_root, value);}

		void inorder() {inorderRecursive(_root);}

		void preorder() {preorderRecursive(_root);}

		void postorder() {postorderRecurive(_root);}

		void layerOrder() {layerOrderRecursive(_root);}

	private:
		TreeNode* insertRecursive(TreeNode* node, int value)
		{
			if (node == nullptr)
			{
				return new TreeNode(value);
			}
			if (value < node->value)
			{
				node->left = insertRecursive(node->left, value);
			}
			else
			{
				node->right = insertRecursive(node->right, value);
			}
			return node;
		}

		void inorderRecursive(TreeNode* node)
		{
			if (node == nullptr)
				return;
			inorderRecursive(node->left);
			std::cout << node->value << " ";
			inorderRecursive(node->right);
		}

		void preorderRecursive(TreeNode* node)
		{
			if (node == nullptr)
				return;
			std::cout << node->value << " ";
			preorderRecursive(node->left);
			preorderRecursive(node->right);
		}

		void postorderRecurive(TreeNode* node)
		{
			if (node == nullptr)
				return;
			postorderRecurive(node->left);
			postorderRecurive(node->right);
			std::cout << node->value << " ";
		}

		void layerOrderRecursive(TreeNode* node)
		{
			if (node == nullptr)
			{
				return;
			}
			std::queue<TreeNode*> q;
			q.push(node);

			while (!q.empty())
			{
				TreeNode* curr = q.front();
				q.pop();
				std::cout << curr->value << " ";

				if (curr->left != nullptr)
				{
					q.push(curr->left);
				}
				if (curr->right != nullptr)
				{
					q.push(curr->right);
				}
        	}
		}

	public:
		TreeNode* _root;
};

int	main()
{
	BinaryTree	tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(10);
    tree.insert(4);
    tree.insert(8);

    std::cout << "In-order traversal: ";
    tree.inorder();
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    tree.preorder();
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postorder();
    std::cout << std::endl;

	std::cout << "By layer traversal: ";
    tree.layerOrder();
    std::cout << std::endl;

    return 0;
}
