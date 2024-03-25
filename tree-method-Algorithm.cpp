#include <iostream>

using namespace std;

// Структура Дерева 
struct tnode
{
	int field;
	struct tnode* left;
	struct tnode* right;
};

// Вывод узлов дерева
void rootprint(tnode* root)
{
	if (root != NULL)
	{
		rootprint(root->left); //Рекурсивная функция вывода левого поддерева
		cout << root->field << " ";
		rootprint(root->right); //Рекурсивная функция вывода правого поддерева
	}
}

// Добавление узлов в дерево
struct tnode* addnode(double x, tnode* root) {
	if (root == NULL)     // Если дерева нет, то формируем корень
	{
		root = new tnode;
		root->field = x;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (x < root->field)   //Если элемент x меньше корневого, уходим влево
		{
			root->left = addnode(x, root->left);
		}
		else
		{
			root->right = addnode(x, root->right);
		}
		return(root);
	}
}

//Освобождение памяти дерева
void freemem(tnode* root)
{
	if (root != NULL)
	{
		freemem(root->left);
		freemem(root->right);
		delete root;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Сориторвка методом дерева!!!\n";

	struct tnode* root = 0;
	double y = 0;
	int n = 0;

	cout << "Введите количество узлов =  ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Введите узел = " << i + 1 << ": ";
		cin >> y;
		root = addnode(y, root);
	}

	rootprint(root);
	freemem(root);
	cin.get();

	return 0;
}