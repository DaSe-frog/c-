/*
Написать программу обработки файла записей, содержащую следующие подпункты меню : 
«Создание», «Просмотр», «Добавление», «Решение индивидуального задания».
Каждая запись должна содержать следующую информацию о студентах :
	- фамилия
	- номер группы
	- оценки за семестр : по физике, математике и информатике
	- средний балл
Организовать ввод исходных данных, средний балл рассчитать по введенным оценкам.Содержимое всего файла и результаты решения индивидуального задания записать в текстовый файл.

	Найти информацию о студентах, имеющих отметку 4 или 5 по физике и больше 8 по остальным предметам.
	*/
/*
Написать программу обработки файла записей, содержащую следующие подпункты меню : 
«Создание», «Просмотр», «Добавление», «Решение индивидуального задания».
Каждая запись должна содержать следующую информацию о студентах :
	- фамилия
	- номер группы
	- оценки за семестр : по физике, математике и информатике
	- средний балл
Организовать ввод исходных данных, средний балл рассчитать по введенным оценкам.Содержимое всего файла и результаты решения индивидуального задания записать в текстовый файл.

	Найти информацию о студентах, имеющих отметку 4 или 5 по физике и больше 8 по остальным предметам.
	*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct student {
	string surname;
	int group = 0;
	int math = 0;
	int phys = 0;
	
	int inf = 0;
	double sr_ball;
};

void OutputTableHead() {
	cout << setw(5) << left << "  #"
		<< setw(16) << left << "Фамилия" << "|"
		<< setw(6) << "Группа" << "|"
		<< setw(10) << "Мат" << "|"
		<< setw(17) << "Физ" << "|"
		<< setw(9) << "Инф" << "|"
		<< setw(14) << "Ср. балл" << "|"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;

}

void OutputTableBody(student s[], int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(5) << left << "  #"
			<< setw(16) << left << s[i].surname << "|"
			<< setw(6) << s[i].group<< "|"
			<< setw(10) << s[i].math << "|"
			<< setw(17) << s[i].phys << "|"
			<< setw(9) << s[i].inf << "|"
			<< setw(14) << s[i].sr_ball << "|"
			<< endl;
	}
}

void FileEdition(string file_name) { // работа с файлом
	int loop = 1;

	while (loop == 1) {
		int temp_answ = 0;
		int answer = 0;
		string temp_string;
		cout << "\nРабота с файлом: " << file_name
			<< ":\n1. просмотр файла\n2. Добавить запись в файл\n3. Задание\n\n0. Выход в главное меню\n\n";
		cin >> answer;

		if (answer == 0) { // 0 - выход в главное меню
			loop = 0;
		}
		if (answer == 2) { // 2 - добавить запись в файл
			int answer1 = 1;

			ofstream file;                                                 // поток записи в файл
			file.open(file_name, ios::app);                                // открыть файл в режиме app, чтобы указатель переместился в конец файла и предыдущие данные не стерлись
			if (!file.is_open()) {
				cout << "Ошибка. Файл не был открыт!" << endl;
			}
			else {
				string t_surname;
				int t_group = 0, t_phys = 0, t_math = 0, t_inf = 0;
				double t_sr_ball;
				answer1 = 1;
				while (answer1 == 1) {
					cout << "Фамилия: " << endl;
					cin >> t_surname;
					cout << "# группы: " << endl;
					cin >> t_group;
					cout << "Оценка по математике:" << endl;
					cin >> t_math;
					cout << "Оценка по физике: " << endl;
					cin >> t_phys;

					cout << "Оценка по информатике: " << endl;
					cin >> t_inf;

					t_sr_ball = (t_phys + t_math + t_inf) / 3;
					cout << "Средний балл равен: " << t_sr_ball << endl;
					cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
					cin >> temp_answ;

					if (temp_answ == 1) {
						if (!file.eof()) file << "\n";
						file << t_surname << " " << t_group << " " << t_math << " " << t_phys << " " << t_inf << " " << t_sr_ball;
					}
					else cout << "Данные не были добавлены в файл!" << endl;
					cout << "Желаете добавить еще запись? \n1 - да\n2 - нет" << endl;
					cin >> answer1;
					if ((temp_answ == 1) && (answer1 == 1)) file << "\n";
				}
				file.close();
			}
		}


		//	1 - просмотр файла
		//	3 - выполнение задания

		if (answer == 1 || answer == 3 ) {

			int N = 0;
			ifstream file;
			file.open(file_name);
			if (!file.is_open()) cout << "Ошибка. Файл не был открыт!" << endl;

			else {
				file.seekg(0);
				int oN = 0;
				string f_str;
				getline(file, f_str);
				if (file.eof() || f_str == "") cout << "Файл пуст!" << endl;
				else {
					file.seekg(0);
					while (!file.eof()) {					//	считаем количество строк в файле
						getline(file, temp_string, '\n');
						oN++;
					}
					N = oN;
					oN = 0;
					file.seekg(0);
					student* s = new student[N];// массив структур 
					int i = 0;
					while (!file.eof() && i <= N - 1) { // вытягиваем данные с файла в массив структур
						file >> s[i].surname >> s[i].group >> s[i].math >> s[i].phys >> s[i].inf >> s[i].sr_ball;
						i++;
					}
					file.close();
					i = 0;
					if (answer == 1) {				// 1 - просмотр файла
						OutputTableHead();
						OutputTableBody(s, N);
					}

					

					if (answer == 3) {
						int t = 0;
						//Найти информацию о студентах, имеющих отметку 4 или 5 по физике и больше 8 по остальным предметам.
						for (i = 0; i < N; i++) {
							if ((s[i].phys == 4 || s[i].phys == 5) && (s[i].math > 8) && (s[i].inf > 8)) {
								if (t==0) OutputTableHead();
								t++;
								cout << setw(5) << left << "  #"
									<< setw(16) << left << s[i].surname << "|"
									<< setw(6) << s[i].group << "|"
									<< setw(10) << s[i].math << "|"
									<< setw(17) << s[i].phys << "|"
									<< setw(9) << s[i].inf << "|"
									<< setw(14) << s[i].sr_ball << "|"
									<< endl;
							}
							else cout << "Нет студентов, имеющих отметку 4 или 5 по физике и больше 8 по остальным предметам" << endl;
						}
					}
				}
			}
		}
	}
}



int main() {

	setlocale(LC_ALL, "RU");
	system("chcp 1251");


	int answer, N = 0, i = 0;
	string file_name;

	while (1) {
		cout << "\n-------- МЕНЮ -----------" << endl;
		cout << "\n1. Создать файл\n2. Работа с существующим файлом\n3. Выход из программы" << endl;
		cin >> answer;
		if (answer == 3) exit(0);			//	выход из программы
		if (answer == 1 || answer == 2) {
			cout << "Введите имя фала (без .txt): ";
			cin >> file_name;
			file_name = file_name + ".txt";
		}

		if (answer == 1) {					//	создать файл
			ofstream file;
			file.open(file_name);
			if (!file.is_open()) {
				cout << "Ошибка. Файл не был открыт!" << endl;
			}
			else {
				cout << "Файл был создан." << endl;
				file.close();
			}
		}

		else if (answer == 2) {					//	Работа с существующим файлом
			FileEdition(file_name);
		}
		else cout << "Неверный ответ!" << endl;
	}
	return 0;
}
