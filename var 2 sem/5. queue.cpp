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
	Spisok* t = new Spisok;
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
void ViewList(int kod, Spisok** begin_spisok, Spisok** end_spisok) {
	//просмотр списка с начала
	if (kod == 1) {
		Spisok* t = *begin_spisok ;
		while (t != NULL) {
			cout << t->info << endl;
			t = t->next;
		}
	}

	//просмотр списка с конца
	if (kod == 2) {
		Spisok* t = *end_spisok;
		while (t != NULL) {
			cout << t->info << endl;
			t = t->prev;
		}
	}
}
void DelList(Spisok** p) { //удаление списка
	Spisok* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

int main() {
	Spisok* begin = NULL, * end = NULL, * key = NULL;
	int i, in, n, kod, kod1, num;
	while (true) {
		cout << "\n\t1. Create\n\t2. Add\n\t3. View\n\t4. Delete\n\t5. Individual task\n\t6. Sorting\n\t0. Exit\n\t";
		cin >> kod;

		switch (kod) {

		case 1://Create
			if (begin != 0) {
				cout << "the list isn't empty!";
				break;
			}
			in = rand() % 101 - 50;
			CreateList(&begin, &end, in);
			cout << "Create Begin = " << begin->info << endl;
			break;

		case 2://add
			cout << "add info\n1. to the begin of the list\n2. to the end of the list" << endl;
			cin >> kod1;
			if (kod1 != 1 && kod1 != 2) {
				cout << "Error answer!";
				break;
			}
			cout << "Enter num of elements: "; cin >> num;
			for (i = 1; i <= num; i++) {
				in = rand() % 101 - 50;
				AddElement(kod1, &begin, &end, in);
				cout << "Add " << t->info << endl;
			}
			break;

		case 3://view
			if (!begin) {
				cout << "The list is empty!" << endl;
				break;
			}
			cout << "1 - View from begin\n2 - View from the end " << endl;
			cin >> kod1;
			if (kod1 == 1) {
				cout << "\tFrom begin: " << endl;
				ViewList(kod1, &begin, &end);
			}
			else if (kod1 == 2) {
				cout << "\tFrom end: " << endl;
				ViewList(kod1, &begin, &end);
			}
			else {
				cout << "error answer!" << endl;
				break;
			}

			break;

		case 4://delete
			DelList(&begin);
			break;

		case 5: //удалить из списка элементы заканчивающиеся на 5
			t = begin; //текущий указатель выставляем на начало списка
			ViewList(1, &begin, &end);
			while (t != NULL) {
				if (t->info % 5 == 0) {
					if (t->info % 10 != 0) {
						key = t;
						if (key == begin) {
							t = t->next;
							t->prev = NULL;
						}
						else if (key == end) {
							end = end->prev;
							end->next = NULL;
						}
						else {
							key->prev->next = key->next;
							key->next->prev = key->prev;
						}
					}
				}
				t = t->next;
			}

			if (key == NULL) {
				cout << "There are no items in this list that end in 5" << endl;
				break;
			}

			cout << "\tNew stack: " << endl;
			ViewList(1, &begin, &end);
			break;

		case 0://exit
			if (begin != NULL) DelList(&begin);
			exit(0);

		default:
			cout << "The answer doesn't exist. Try again!";
			break;
		}
	}
	return 0;
}
