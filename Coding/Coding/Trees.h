#pragma once

namespace Trees
{
	struct Node
	{
		int data;
		int height;
		Node* left;
		Node* right;
	};

	class AVLTree
	{
	public:
		AVLTree() :root(0) {}

		void Insert(int data)
		{
			root = _Insert(root, data);
		}
		void Remove(int data)
		{
			root = _Remove(root, data);
		}
	private:
		Node* _Insert(Node*n, int data)
		{
			if (!n)
			{
				n = new Node();
				n->data = data;
				n->height = 1;
				n->left = 0;
				n->right = 0;
			}
			else if (data < n->data)
			{
				n->left = _Insert(n->left, data);
				if (Height(n->left) - Height(n->right) == 2) //Left
				{
					Node* left = n->left;
					if (Height(left->left) > Height(left->right))
					{
						// Left
						n = RotateRight(n);
					}
					else
					{
						// Right
						n->left = RotateLeft(n->left);
						n = RotateRight(n);
					}
				}
			}
			else if (data > n->data)
			{
				n->right = _Insert(n->right, data);
				if (Height(n->right) - Height(n->left) == 2) // Right
				{
					Node* right = n->right;
					if (right->right > right->left)
					{
						// Right
						n = RotateLeft(n);
					}
					else
					{
						// Left
						n->right = RotateRight(n->right);
						n = RotateLeft(n);
					}
				}

			}

			n->height = Max(Height(n->left), Height(n->right)) + 1;
			return n;
		}

		Node* _Remove(Node* n, int data)
		{
			if (data == n->data)
			{
				if (!n->left && !n->right)
				{
					delete n;
					return 0;
				}
				else if ((!n->left && n->right) ||
						 (n->left && !n->right))
				{
					Node* child = n->left;
					if (!child)
						child = n->right;
					delete n;
					n = child;
				}
				else
				{
					Node* current = n->right;
					while (current->left)
					{
						current = current->left;
					}
					int temp = current->data;
					Node* r = _Remove(n, temp);
					n->data = temp;
					n = r;
				}
			}
			else if (data < n->data)
			{
				if (n->left)
				{
					n->left = _Remove(n->left, data);
					if (Height(n->right) - Height(n->left) == 2) // Right
					{
						Node* right = n->right;
						if (Height(right->left) > Height(right->right))
						{
							// Left
							n->right = RotateRight(n->right);
							n = RotateLeft(n);
						}
						else
						{
							// Right
							n = RotateLeft(n);
						}
					}
				}
			}
			else if (data > n->data)
			{
				if (n->right)
				{
					n->right = _Remove(n->right, data);
					if (Height(n->left) - Height(n->right) == 2) // Left
					{
						Node* left = n->left;
						if (Height(left->left) > Height(left->right))
						{
							// Left
							n = RotateRight(n);
						}
						else
						{
							// Right
							n->left = RotateLeft(n->left);
							n = RotateRight(n);
						}
					}
				}
			}
		
			n->height = Max(Height(n->left), Height(n->right)) + 1;
			return n;
		}

		int Max(int a, int b)
		{
			if (a > b)
				return a;
			return b;
		}
		int Height(Node* n)
		{
			if (!n)
				return 0;
			return n->height;
		}

		Node* RotateRight(Node* x)
		{
			Node* y = x->left;
			x->left = y->right;
			y->right = x;

			x->height = Max(Height(x->left), Height(x->right)) + 1;
			y->height = Max(Height(y->left), Height(y->right)) + 1;

			return y;
		}

		Node* RotateLeft(Node* x)
		{
			Node* y = x->right;
			x->right = y->left;
			y->left = x;
			x->height = Max(Height(x->left), Height(x->right)) + 1;
			y->height = Max(Height(y->left), Height(y->right)) + 1;

			return y;
		}

		Node* root;

	};
}
