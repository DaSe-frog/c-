#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

struct person {
	string surname;                 // фамилия
	string name;					// имя
	string middle_name;				// отчество
	int otdel = 0;					// номер отдела (ключ 1)
	string post;                    // должность
	int date[3] = { 0, 0, 0 };		// дата начала работы (ключ 2) dd,mm,yy
};



void QuickSort(person employee[], int left, int right) {
	if (left > right) return;
	person p = employee[(left + right) / 2];
	int i = left;
	int j = right;
	person temp;
	while (i <= j) {
		while (employee[i].date[0] + employee[i].date[1] * 100 + employee[i].date[2] * 10000 < p.date[0] + p.date[1] * 100 + p.date[2] * 10000) i++;
		while (employee[j].date[0] + employee[j].date[1] * 100 + employee[j].date[2] * 10000 > p.date[0] + p.date[1] * 100 + p.date[2] * 10000)j--;

		if (i <= j) {
			temp = employee[i];
			employee[i] = employee[j];
			employee[j] = temp;
			i++;
			j--;
		}
	}
	QuickSort(employee, left, j);
	QuickSort(employee, i, right);
}


void OutputTable(person employee[], int N) {
	cout << setw(5) << left << "  #"
		<< setw(20) << left << "Фамилия" << "|"
		<< setw(15) << "Имя" << "|"
		<< setw(20) << "Отчество" << "|"
		<< setw(9) << "№ отдела" << "|"
		<< setw(25) << "Должность" << "|"
		<< setw(18) << "Дата начала работы" << "|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {
		cout << setw(3) << right << i + 1 << setw(2) << left << "."
			<< setw(20) << left << employee[i].surname << "|"
			<< setw(15) << employee[i].name << "|"
			<< setw(20) << employee[i].middle_name << "|"
			<< setw(9) << employee[i].otdel << "|"
			<< setw(25) << employee[i].post << "|"
			<< right << setw(10) << employee[i].date[0] << "."
			<< right << setw(2) << employee[i].date[1] << "."
			<< setw(4) << employee[i].date[2] << "|" << endl;
	}
}


void LinearSearch(person employee[], int N, int x) {					// x - номер отдела
	int k = 0;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (employee[i].otdel == x) {
			if (temp == 0) {
				cout
					<< setw(20) << left << "Фамилия" << "|"
					<< setw(15) << "Имя" << "|"
					<< setw(20) << "Отчество" << "|"
					<< setw(9) << "№ отдела" << "|"
					<< setw(25) << "Должность" << "|"
					<< setw(18) << "Дата начала работы" << "|" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			}
			cout
				<< setw(20) << left << employee[i].surname << "|"
				<< setw(15) << employee[i].name << "|"
				<< setw(20) << employee[i].middle_name << "|"
				<< setw(9) << employee[i].otdel << "|"
				<< setw(25) << employee[i].post << "|"
				<< right << setw(10) << employee[i].date[0] << "."
				<< right << setw(2) << employee[i].date[1] << "."
				<< setw(4) << employee[i].date[2] << "|" << endl;
			k++;
			temp++;
		}
	}
	if (k == 0) {
		cout << "Нет такого отдела." << endl;
	}
}


void FileEdition(string file_name) {
	int loop = 1;
	while (loop == 1) {
		int temp_answ = 0;
		int answer = 0;
		string temp_string;
		cout << "\nРедактирование файла " << file_name << ":\n1. просмотр файла\n2. Добавить запись в файл\n3. Изменить запись в файле\n4. Удалить запись из файла\n5. Задание\n\n0. Выход в главное меню\n\n";
		cin >> answer;
		if (answer == 0) {
			loop = 0;
		}
		if (answer == 2) {
			int answer1 = 1;

			ofstream file;                                                 // поток записи в файл
			file.open(file_name, ios::app);                                // открыть файл в режиме app, чтобы указатель переместился в конец файла и предыдущие данные не стерлись
			if (!file.is_open()) {
				cout << "Ошибка. Файл не был открыт!" << endl;
			}
			else {
				string t_surname, t_name, t_middlename, t_post, t_date;
				int t_otdel = 0;
				answer1 = 1;
				while (answer1 == 1) {
					cout << "Фамилия: " << endl;
					cin >> t_surname;
					cout << "Имя: " << endl;
					cin >> t_name;
					cout << "Отчество: " << endl;
					cin >> t_middlename;
					cout << "Отдел: " << endl;
					cin >> t_otdel;
					cout << "должность: " << endl;
					cin >> t_post;

					cout << "Дата начала работы в формате ДД.ММ.ГГ: " << endl;
					cin >> t_date;
					cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
					cin >> temp_answ;
					if (temp_answ == 1) {
						file << "\n" << t_surname << " " << t_name << " " << t_middlename << " " << t_otdel << " " << t_post << " " << t_date;

						
					}
					else cout << "Данные не были добавлены в файл!" << endl;
					cout << "Желаете добавить еще запись? \n1 - да\n2 - нет" << endl;
					cin >> answer1;
					if (answer1 == 1) file << "\n";
				}
				file.close();
			}
		}

		if (answer == 1 || answer == 3 || answer == 4 || answer == 5 ) {
			
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
					while (!file.eof()) {
						getline(file, temp_string, '\n');
						oN++;
					}
					N = oN;
					oN = 0;
					file.seekg(0);
					person* employee = new person[N];
					int i = 0;
					while (!file.eof() && i <= N - 1) {
						file >> employee[i].surname >> employee[i].name >> employee[i].middle_name >> employee[i].otdel >> employee[i].post >> temp_string;
						employee[i].date[0] = stoi(temp_string.substr(0, 2));
						employee[i].date[1] = stoi(temp_string.substr(3, 2));
						employee[i].date[2] = stoi(temp_string.substr(6, 4));
						i++;
					}
					file.close();
					i = 0;
					if (answer == 1) {
						OutputTable(employee, N);
					}
					if (answer == 3) {
						cout << "Исходный список: " << endl;
						OutputTable(employee, N);
						int index_number = 0, answer3 = 0;
						string temp_date;
						cout << "\nВведите порядковый номер сотрудника, запись о котором желаете изменить: ";
						cin >> index_number;
						index_number--;
						cout << "\nЧто вы желаете изменить? \n1 - фамилия, \n2 - имя, \n3 - отчество, \n4 - отдел, \n5 - должность, \n6 - дата начала работы" << endl;
						cin >> answer3;
						switch (answer3) {
						case 1:
							cout << "Введите фамилию:" << endl;
							cin >> employee[index_number].surname;
							break;
						case 2:
							cout << "Введите имя:" << endl;
							cin >> employee[index_number].name;
							break;
						case 3:
							cout << "Введите отчество:" << endl;
							cin >> employee[index_number].middle_name;
							break;
						case 4:
							cout << "Введите отдел:" << endl;
							cin >> employee[index_number].otdel;
							break;
						case 5:
							cout << "Введите должность:" << endl;
							cin >> employee[index_number].post;
							break;
						case 6:
							cout << "Введите дату начала работы в формате ДД.ММ.ГГ:" << endl;
							cin >> temp_date;
							break;
						default:
							cout << "Неверный ответ. Попробуйте еще раз.\n";
						}
						cout << "Измененная запись: " << endl
							<< employee[index_number].surname << " " << employee[index_number].name << " " << employee[index_number].middle_name << " " << employee[index_number].otdel << " " << employee[index_number].post << " " << temp_date << endl;
						cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
						cin >> temp_answ;
						if (temp_answ == 1) {
							ofstream file;
							file.open(file_name);
							for (int i = 0; i < N; i++) {
								file << employee[i].surname << " " << employee[i].name << " " << employee[i].middle_name << " " << employee[i].otdel << " " << employee[i].post << " ";
								if (i == index_number && answer3 == 6) file << temp_date;
								else {
									if (employee[i].date[0] < 10) {
										file << "0";
									}
									file << employee[i].date[0] << ".";
									if (employee[i].date[1] < 10) {
										file << "0";
									}
									file << employee[i].date[1] << ".";
									file << employee[i].date[2];
								}
								if (i != N - 1) {
									file << endl;
								}
							}
							cout << "Данные в файле обновлены!" << endl << endl;
							file.close();
						}
						else cout << "Данные в файле не были обновлены" << endl;
						temp_answ = 0;
					}
					if (answer == 4) {
						cout << "Исходный список: " << endl;
						OutputTable(employee, N);
						int index_number = 0;
						cout << "\nВведите порядковый номер сотрудника, запись о котором желаете удалить: ";
						cin >> index_number;
						cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
						cin >> temp_answ;
						if (temp_answ == 1) {
							for (int i = index_number - 1; i < N - 1; i++) {
								employee[i].surname = employee[i + 1].surname;
								employee[i].name = employee[i + 1].name;
								employee[i].middle_name = employee[i + 1].middle_name;
								employee[i].otdel = employee[i + 1].otdel;
								employee[i].post = employee[i + 1].post;
								employee[i].date[0] = employee[i + 1].date[0];
								employee[i].date[1] = employee[i + 1].date[1];
								employee[i].date[2] = employee[i + 1].date[2];
							}
							N--;
							cout << endl << "Новый список:" << endl;
							OutputTable(employee, N);
							ofstream file;
							file.open(file_name);
							for (int i = 0; i < N; i++) {
								file
									<< employee[i].surname << " " << employee[i].name << " " << employee[i].middle_name
									<< " " << employee[i].otdel << " " << employee[i].post << " ";
								if (employee[i].date[0] < 10) file << "0";
								file << employee[i].date[0] << ".";
								if (employee[i].date[1] < 10) file << "0";
								file << employee[i].date[1] << "." << employee[i].date[2];
								if (i != N - 1) file << "\n";
							}
							cout << "Данные в файле обновлены!" << endl;
							file.close();
						}
						else cout<< "Данные в файле не были обновлены" << endl;
						temp_answ = 0;
					}
					if (answer == 5) {
						QuickSort(employee, 0, N - 1);
						cout << "Введите номер отдела, о котором желаете получить информацию" << endl;
						int x = 0;
						cin >> x;
						LinearSearch(employee, N, x);
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
	string file_name, temp_string;
	while (1) {
		cout << "\n-------- МЕНЮ -----------" << endl;
		cout << "\n1. Создать файл\n2. Работа с существующим файлом\n3. Выход из программы" << endl;
		cin >> answer;
		if (answer == 3) exit(0);
		cout << "Введите имя фала: ";
		cin >> file_name;
		file_name = file_name + ".txt";
		if (answer == 1) {
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
		if (answer == 2) {
			FileEdition(file_name);
		}
	}
	return 0;
}