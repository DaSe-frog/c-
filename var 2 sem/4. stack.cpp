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
}

//	прсомотр стека
void s_view(Stack* p) {
	Stack* t = p;
	while (t != NULL) {		
		cout << " " << t->data << endl;
		t = t->next;
	}
}


// функция освобождения памяти, занятой стеком
void s_del(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void StackSort(Stack* p) {
	Stack* t = NULL;
	Stack* tl;
	int r, i = 0;
	do {
		for (tl = p; tl->next != t; tl = tl->next) {
			if (tl->data > tl->next->data) {
				r = tl->data;
				tl->data = tl->next->data;
				tl->next->data = r;
			}
		}t = tl;
	} while (p->next != t);
}


int main() {
	Stack* begin = NULL;
	Stack* temp_begin = NULL;
	int i, in, n, kod, el;
	while (true) {
		cout << "\n\t1. Create\n\t2. Add\n\t3. View\n\t4. Delete\n\t5. Individual task\n\t6. Sorting\n\t0. Exit\n\t";
		cin >> kod;
		switch (kod) {
		
		case 1: case 2:								//create , add
			cout << "Input the num of elements: ";
			cin >> n;
			if ((kod == 1) && (begin != NULL)) {
				s_del(&begin);
			}
			for (i = 1; i <= n; i++) {
				in = rand() % 101 - 50;
				begin = s_push(begin, in);
			}
			if (kod == 1)cout << "Create " << n << " elements." << endl;
			else  cout << "Add " << n << " elements." << endl;
			cout << "The stack: " << endl;
			s_view(begin);
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

		
		case 5:
			if (!begin) {
				cout << "The Stack is empty!" << endl;
				break;
			}
			while (begin != NULL) {
				if (begin->data % 5 == 0) {
					if (begin->data % 10 != 0)	cout << "Delete " << begin->data << endl;
					else temp_begin = s_push(temp_begin, begin->data);
				}
				else temp_begin = s_push(temp_begin, begin->data);
				begin = begin->next;
			}

			while (temp_begin != NULL) {
				begin = s_push(begin, temp_begin->data);
				temp_begin = temp_begin->next;
			}
			delete temp_begin;
			cout << "\tNew stack: " << endl;
			s_view(begin);
			break;
		
		case 6:										// сортировка
			if (!begin) {
				cout << "The Stack is empty!" << endl;
				break;
			}
			StackSort(begin);
			cout << "\tNew stack: " << endl;
			s_view(begin);
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
