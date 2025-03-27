/*
	 Разработать проект для работы с деревом поиска, содержащий следующие обработчики, которые должны:
	+ ввести информацию из компоненты StringGrid в массив. 
		Каждый элемент массива должен содержать строку текста и целочисленный ключ (например, ФИО и номер паспорта);
	+ внести информацию из массива в дерево поиска;
	– сбалансировать дерево поиска;
	– добавить в дерево поиска новую запись;
	– по заданному ключу найти информацию и отобразить ее;
	– удалить из дерева поиска информацию с заданным ключом;
	– распечатать информацию прямым, обратным обходом и в порядке возрастания ключа;
	– решить одну из поставленных задач и решение оформить в виде блоксхемы.

	Определить число узлов на каждом уровне дерева.

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string.h>

using namespace std;

struct Data {
	string FIO;
	int num;//ключ
};

/*
struct Tree {
	int info;
	Tree* left, * right;
} *root; // root -  указатель корня
*/
//-------------------------------------------------------------------------

/*
В общем случае при работе с деревьями необходимо уметь :
– сформировать дерево(добавить новый элемент);
– обойти все элементы дерева(например, для просмотра или выполнения
	некоторой операции);
– выполнить поиск элемента с указанным значением в узле;
– удалить заданный элемент.


Формирование дерева поиска состоит из двух этапов : создание корня,
являющегося листом, и добавление нового элемента(листа) в найденное место.*/

// функция формирования листа :
/*
Tree * List(int inf) {
	Tree* t = new Tree; // Захват памяти
	t->info = inf; // Формирование информационной части
	t->left = t->right = NULL; // Формирование адресных частей
	return t; // Возврат созданного указателя
}

void Add_List(Tree* root, int key) {
	Tree* prev, * t; // p - указатель предка нового листа
	bool find = true;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->info) {
			find = false;
			cout << "Повторяющийся ключ!" << endl;
		}
		else {
			if (key < t->info) t = t->left;
			else prev->right = t;
		}
	}
}

void MakeTree(int information) {
	if (root == NULL) root = List(information);
	else Add_List(root, information);

}

//---------------------------------------------------------
// 
//функция просмотра элементов дерева

void View(Tree* p, int level) { //обращение View(root,0)
	string str;
	if (p) {
		View(p->right, level + 1);
		for (int i = 0; i < level; i++) {
			str = str + ' ';
		}
		// что-то тут еще
		View(p->left, level + 1);
	}
}

//-------------------------------------------------------------------------------------

//Удаление узла с заданным ключом из дерева поиска с сохранением его
//свойств, выполняется в зависимости от того, сколько сыновей(потомков) имеет
//удаляемый узел.

//1. Удаляемый узел является листом – просто удаляем ссылку на него.
//Приведем пример схемы удаления листа с ключом key :

//2. Удаляемый узел имеет только одного потомка, т.е.из удаляемого узла
//выходит ровно одна ветвь.Пример схемы удаления узла key, имеющего одного
//сына :

//3. Удаление узла, имеющего двух потомков, значительно сложнее приведенных вариантов. Если key – удаляемый узел, то его следует заменить узлом w,
//который содержит либо наибольший ключ(самый правый, у которого указатель Right равен NULL) в левом поддереве, либо наименьший ключ(самый левый, у которого указатель Left равен NULL) в правом поддереве.
//Используя первое условие, находим узел w, который является самым правым узлом поддерева key, у него имеется только левый потомок :

//Функция удаления узла по заданному ключу key может иметь вид

Tree* Del_Info(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	// Del, Prev_Del – удаляемый узел и его предыдущий (предок);
	// R, Prev_R – элемент, на который заменяется удаленный узел, и его предок;
	Del = root;
	Prev_Del = NULL;
	//-------- Поиск удаляемого элемента и его предка по ключу key ---------
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info > key) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) { // Элемент не найден
		cout << "NOT Key!" << endl;
		return root;
	}
	//-------------------- Поиск элемента R для замены --------------------------------
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			//---------------- Ищем самый правый узел в левом поддереве -----------------
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			//----------- Нашли элемент для замены R и его предка Prev_R -------------
			if (Prev_R == Del) R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == root) root = R; // Удаляя корень, заменяем его на R
	else
		//------- Поддерево R присоединяем к предку удаляемого узла -----------
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R; // На левую ветвь
		else Prev_Del->right = R; // На правую ветвь
	delete Del;
	return root;
}

//-------
// 
//Поиск узла с минимальным (максимальным) ключом:
Tree* Min_Key(Tree* p) { // Tree* Max_Key(Tree *p)
	while (p->left != NULL) p = p->left; // p=p->right;
	return p;
}
//Тогда для получения минимального ключа p_min->info:
//Tree * p_min = Min_Key(root);
// 
//------------------------------------------------------------------------
// 
// Построение сбалансированного дерева поиска 
// для заданного(созданного) массива ключей «а» можно осуществить, 
// если этот массив предварительно
// отсортирован в порядке возрастания ключа с помощью 
// следующей рекурсивной процедуры(при обращении n = 0, k – размер массива) :
void Make_Blns(Tree** p, int n, int k, int* a) {
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = a[m];
		Make_Blns(&(*p)->left, n, m, a);
		Make_Blns(&(*p)->right, m + 1, k, a);
	}
}

// Алгоритмы обхода дерева
// Существуют три алгоритма обхода деревьев, которые естественно следуют из самой структуры дерева.
// 1. Обход слева направо : Left - Root - Right(сначала посещаем левое поддерево, затем – корень и, наконец, правое поддерево).
// 2. Обход сверху вниз   : Root - Left - Right(посещаем корень до поддеревьев).
// 3. Обход снизу вверх   : Left - Right - Root(посещаем корень после поддеревьев).

// Функция освобождения памяти, занятой деревом
void Del_Tree(Tree* t) {
	if (t != NULL) {
		Del_Tree(t->left); // На левую ветвь
		Del_Tree(t->right); // На правую ветвь
		delete t;
	}
}

*/
//-----------------------
//--------------------- Шаблон структуры ----------------------------------------------
struct Tree {
	int info;
	Tree* left, * right;
}*root; // Корень


//--------------------- Текст функции-обработчика кнопки Создать -------------
int main2() {
	int info = 0;

	cin >> info;
	if (root != NULL) Del_Tree(root);
	root = List(info);
	//--------------------- Текст функции-обработчика кнопки Просмотреть -----

	if (root == NULL) cout << " Create TREE !" << endl;
	else {
		cout << "view" << endl;
		View_Tree(root, 0);
	}
	//--------------------- Текст функции-обработчика кнопки Добавить -----------
	cin >> info;
	if (root == NULL) root = List(info);
	else Add_List(root, info);
	//--------------------- Текст функции-обработчика кнопки Удалить INFO ----

	int b = info;
	root = Del_Info(root, b);
	//--------------------- Текст функции-обработчика кнопки ОЧИСТИТЬ -------

	Del_Tree(root);
	cout << "Tree Delete!" << endl;
	root = NULL;
	//--------------------- Текст функции-обработчика кнопки EXIT -----------------

	if (root != NULL) {
		Del_Tree(root);
		cout << " Tree Delete!" << endl;;
	}
	return 0;
}

Tree* List(int inf) {
	Tree* t = new Tree; // Захват памяти
	t->info = inf; // Формирование информационной части
	t->left = t->right = NULL; // Формирование адресных частей
	return t; // Возврат созданного указателя
}

void Add_List(Tree* root, int key) {
	Tree* prev, * t; // p - указатель предка нового листа
	bool find = true;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->info) {
			find = false;
			cout << "Повторяющийся ключ!" << endl;
		}
		else {
			if (key < t->info) t = t->left;
			else prev->right = t;
		}
	}
}

void MakeTree(int information) {
	if (root == NULL) root = List(information);
	else Add_List(root, information);

}

//функция просмотра элементов дерева
void View(Tree* p, int level) { //обращение View(root,0)
	string str;
	if (p) {
		View(p->right, level + 1);
		for (int i = 0; i < level; i++) {
			str = str + ' ';
		}
		// что-то тут еще
		View(p->left, level + 1);
	}
}

//Функция удаления узла по заданному ключу key  

Tree* Del_Info(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	// Del, Prev_Del – удаляемый узел и его предыдущий (предок);
	// R, Prev_R – элемент, на который заменяется удаленный узел, и его предок;
	Del = root;
	Prev_Del = NULL;
	//-------- Поиск удаляемого элемента и его предка по ключу key ---------
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info > key) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) { // Элемент не найден
		cout << "NOT Key!" << endl;
		return root;
	}
	//-------------------- Поиск элемента R для замены --------------------------------
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			//---------------- Ищем самый правый узел в левом поддереве -----------------
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			//----------- Нашли элемент для замены R и его предка Prev_R -------------
			if (Prev_R == Del) R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == root) root = R; // Удаляя корень, заменяем его на R
	else
		//------- Поддерево R присоединяем к предку удаляемого узла -----------
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R; // На левую ветвь
		else Prev_Del->right = R; // На правую ветвь
	delete Del;
	return root;
}


//Поиск узла с минимальным (максимальным) ключом:
Tree* Min_Key(Tree* p) { // Tree* Max_Key(Tree *p)
	while (p->left != NULL) p = p->left; // p=p->right;
	return p;
}

//Тогда для получения минимального ключа p_min->info:
//Tree * p_min = Min_Key(root);


// Построение сбалансированного дерева поиска 
// для заданного(созданного) массива ключей «а» можно осуществить, 
// если этот массив предварительно
// отсортирован в порядке возрастания ключа с помощью 
// следующей рекурсивной процедуры(при обращении n = 0, k – размер массива) :
void Make_Blns(Tree** p, int n, int k, int* a) {
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = a[m];
		Make_Blns(&(*p)->left, n, m, a);
		Make_Blns(&(*p)->right, m + 1, k, a);
	}
}

// Функция освобождения памяти, занятой деревом
void Del_Tree(Tree* t) {
	if (t != NULL) {
		Del_Tree(t->left); // На левую ветвь
		Del_Tree(t->right); // На правую ветвь
		delete t;
	}
}

int main() {
	cout << "Создание массива:" << endl;
	int N = 0;
	cout << "Введите число элментов массива: ";
	cin >> N;
	Data* person = new Data[N];
	
	cout << "Заполнение массива:" << endl;
	for (int i = 0; i < N; i++) {
		cout << "Введите фамилию: ";
		cin >> person->FIO;
		cout << "Введите номер паспорта: ";
		cin >> person->num;
	}

	//создание дерева
	for (int i = 0; i < N; i++) {
		if (root != NULL) Del_Tree(root);
		root = List(person[i].num);
	}

	//сбалансировать дерево 
	Make_Blns(&root, 0, N, per son.num)


	int answ = 0;
	cout << "Enter:" << endl;
	cin >> answ;
	switch (answ) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:

	}
	//--------------------- Текст функции-обработчика кнопки Добавить -----------
	cin >> info;
	if (root == NULL) root = List(info);
	else Add_List(root, info);
	//--------------------- Текст функции-обработчика кнопки Удалить INFO ----

	int b = info;
	root = Del_Info(root, b);
	//--------------------- Текст функции-обработчика кнопки ОЧИСТИТЬ -------

	Del_Tree(root);
	cout << "Tree Delete!" << endl;
	root = NULL;
	//--------------------- Текст функции-обработчика кнопки EXIT -----------------

	if (root != NULL) {
		Del_Tree(root);
		cout << " Tree Delete!" <
	return 0;
}
