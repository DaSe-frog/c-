/*
Написать программу по созданию, добавлению (в начало, в конец), 
просмотру (с начала, с конца) и решению приведенной в подразделе 3.3.задачи для  двунаправленных линейных списков
Из созданного списка удалить элементы, заканчивающиеся на цифру 5

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
struct Spisok {
	int info;
	Spisok* next;
	Spisok* prev;

} *t;

void CreateList(Spisok** begin_spisok, Spisok** end_spisok, int in) { // создание первого элемента
	t = new Spisok;
	t->info = in;
	t->next = t->prev = NULL;
	*begin_spisok = *end_spisok = t;
}

//добавление элемента в список
void AddElement(int kod, Spisok** begin_spisok, Spisok** end_spisok, int in) {
	t = new Spisok;
	t->info = in;
	if (kod == 0) {
		t->prev = NULL;
		t->next = *begin_spisok;
		(*begin_spisok)->prev = t;
		(*begin_spisok) = t;
	}
	else {
		t->next = NULL;
		t->prev = *end_spisok;
		(*end_spisok)->next = t;
		*end_spisok = t;
	}
}
//просмотр списка
void ViewList(int kod, Spisok* t) {
	while (t != NULL) {
		cout << t->info << endl;
		if (kod == 0) t = t->next;
		else t = t->prev;
	}
}
void DelList(Spisok** p) { //удаление списка
	//Spisok* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

int main() {
	Spisok* begin, * end, * t,*temp_begin;
	int i, in, n, kod, kod1;
	char Str[2][10] = { "Begin", "End" };
	while (true) {
		cout << "\n\t1. Create\n\t2. Add\n\t3. View\n\t4. Delete\n\t5. Individual task\n\t6. Sorting\n\t0. Exit\n\t";
		cin >> kod;
		switch (kod) {
		case 1://Create
			if (begin != 0) cout << "the list isn't empty!"; break;
			cout << "Begin info: "; cin >> in;
			CreateList(&begin, &end, in);
			cout << "Create Begin = " << begin->info << endl;
			break;
		case 2://add
			cout << "Enter indo: "; cin >> in;
			cout << "add info\n0. to the begin of the list\n2. to tne end of the list" << endl; cin >> kod1;
			AddElement(kod1, &begin, &end, in);
			if (kod1 == 0) t = begin;
			else t = end;
			cout << "Add to " << Str[kod1] << " " << t->info << endl;
			break;
		case 3://view
			if (!begin) cout << "The list is empty!" << endl; break;
			cout << "1 - View from begin\n2 - View from the end " << endl; cin >> kod1;
			if (kod1 == 1) {
				t = begin;
				cout << "\tFrom begin: " << endl;
			}
			if (kod1 == 2) {
				t = begin;
				cout << "\tFrom end: " << endl;
			}
			else cout << "error answer!" << endl; break;
			ViewList(kod1, t);
			break;
		case 4://delete
			DelList(&begin);
			break;/*
		case 5:
			
			if (!begin) {
				cout << "The List is empty!" << endl;
				break;
			}
			while (begin != NULL) {
				if (begin->info % 5 == 0) {
					if (begin->info % 10 != 0)	cout << "Delete " << begin->info << endl;
					else temp_begin = AddElement(1, &begin, &end, begin->info);
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

			*/
		case 6:
			/*
			if (!begin) {
				cout << "The Stack is empty!" << endl;
				break;
			}
			StackSort(begin);
			cout << "\tNew stack: " << endl;
			s_view(begin);
			break;

			*/
		case 0://exit
			if (begin != NULL) DelList(&begin);
			exit(0);
		default:
			cout << "The answer doesn't exist. Try again!";
			break;
		}
	}
}
