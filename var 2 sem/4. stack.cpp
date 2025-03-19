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
	Stack* temp_begin = NULL;
	int i, in, n, kod, el;
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
			
		case 5:			
			while (begin  != NULL) { 
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
			break;
			//доделать  6
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
