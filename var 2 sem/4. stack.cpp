/*
Написать программу по созданию, добавление, 
просмотру и решению приведенных дальше задач для однонаправленного линейного списка типа Stack. 
Реализовать сортировку стека методами, рассмотренными в подразделе 3.1.

Из созданного списка удалить элементы, заканчивающиеся на цифру 5
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

struct Stack {
	int data;
	Stack* next;
};

//	функция формирования элемента стека
Stack* s_push(Stack* p, int in){	// указатель на вершину и введенное значение
	Stack* t = new Stack;		// захватываем память для элемента
	t->data = in;				// формирование информационной части
	t->next = p;				// формирование адресной части
	return t;					// возвращаем измененное значение вершины
	// если хотим из основной функции добавить в стек новый элемент а, при этом вершиной стека является указатель бегин, то:
	// begin = s_push(begin,a)
}

//	прсомотр стека
void s_view(Stack* p) {
	Stack* t = p;
	while (t != NULL) {		//	пока список не окончился
		cout << " " << t->data << endl;
		t = t->next;		//	текущий указатель переставляем на следующий элемент, адрес которого хранится в поле next текущего элемента
	}
}
// получение информации из вершины стека с извлечением
Stack* OutStack(Stack* p, int* out) {
	Stack* t = p;			// устанавливаем указатель т на веришну п
	*out = p->data;			//	
	p = p->next;			//	переставляем вершину п на следующий элемент
	delete t;				//	удаляем бывшую вершину т
	return p;				// возвращаем новую вершину п

	// обращение к этой функции begin=OutStack(begin,&a);
}

// функция освобождения памяти, занятой стеком
void s_del(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
	
	// обращение к этой функции: s_del(&begin) после выполнения которой указатель на вершину begin будет равен NULL
}

// 1ый способ сортировки
// сортировка однонаправленного списка - перестановка адресов двух соседних элементов, следующих за известным указателем. 
// первый элемент стека НЕ СОРТИРУЕТСЯ. для того, чтобы и первый элемент оказался отсортированным, следует перед
// обращением к функции сортировки добавить один элемент в стек, а после сортировки - удалить его
void stack_sort1(Stack** p) {
	Stack* t = NULL, * tl, * r;
	if ((*p)->next->next = NULL) return;
	do {
		for (tl = *p; tl->next->next != t; tl = tl->next) {
			if (tl->next->data > tl->next->next->data) {
				r = tl->next->next;
				tl->next->next = r->next;
				r->next = tl->next;
				tl->next = r;
			}
		}
		t = tl->next;
	} while ((*p)->next->next != t);
	// обращенире: stack_sort(&begin)
}

// 2ой способ
//обмен информацией между текущим и следующим элементами. 
void stack_sort2(Stack** p) {
	Stack* t = NULL;
	//Stack* tl = *p;

	int r;
	do {
		for (*p; (*p)->next != t; (*p) = (*p)->next) {
			if ((*p)->data > (*p)->next->data) {
				r = (*p)->data;
				cout << "r = " << r << endl;
				(*p)->data = (*p)->next->data;
				cout << "(*p)->data = " << (*p)->data << endl;
				(*p)->next->data = r;
				cout << "(*p)->next->data = " << (*p)->next->data << endl;
			}
		}
		t = (*p);
	} while ((*p)->next != NULL);
	cout << "end of sort2" << endl;
}

void stack_sort3(Stack** p) {
	Stack* t = NULL;
	int temp_stack;
	for ((*p)->data; (*p)->next != NULL; (*p) = (*p)->next) {
		if ((*p)->data > (*p)->next->data) {
			OutStack(*p, &(*p)->next->data);
		}
		
	}
	s_view(*p);
}

int main() {
	Stack* begin = NULL;
	int i, in, n, kod;
	while (true) {
		cout << "\n\t1. Create\n\t2. Add\n\t3. View\n\t4. Delete\n\t5. Individual task\n\t6. Sorting\n\t0. Exit\n\t";
		cin >> kod;
		switch (kod) {
		case 1: case 2:								//create , add
			cout << "Input the num of elements: ";
			cin >> n;
			for (i = 1; i <= n; i++) {
				in = rand() % 101 - 50;
				begin = s_push(begin, in);
			}
			if (kod == 1)cout << "Create " << n << " elements." << endl;
			else  cout << "Add " << n << " elements." << endl;
			break;
		case 3:										// view
			if (!begin) {
				cout << "The Stack is empty!" << endl;
				break;
			}
			s_view(begin);
			break;
		case 4:										//delete
			s_del(&begin);
			cout << "The memory is free!" << endl;
			break;
			//доделать 5 и 6
		case 5:										// элементы которые делятся на 5
			//begin=OutStack(begin);
			break;
		case 6:										// сортировка
			cout << "1" << endl;
			s_view(begin);
			stack_sort3(&begin);
			cout << "2 after _sort3" << endl;
			s_view(begin);
			//}

			// обращение к этой функции: s_del(&begin) после выполнения которой указатель на вершину begin будет равен NULL
		//}
			break;
		case 0:
			if (begin != NULL) s_del(&begin);
			exit(0);
		default:
			cout << "The answer doesn't exist. Try again!";
			break;
		}
	}
}
