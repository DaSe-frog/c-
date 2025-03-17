#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

struct atc {
	int date[3] = { 0,0,0 };	// дата разговора {число.месяц.год}			//string surname фамилия
	int code = 0;				// код города								//string name  имя
	string city;				// название города							//string middle_name  отчество
	int time[3] = { 0,0,0 };	// время разговора {часы, минуты, секунды}	//int otdel = 0 номер отдела (ключ 1)
	int tarif = 0;				// тариф									//string post должность
	string city_num;			// номер телефона в городе					//int date[3] = { 0, 0, 0 }  дата начала работы (ключ 2) dd,mm,yy
	string subscriber_num;		// номер телефона абонента
};

void QuickSort(atc contact[], int left, int right) {
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

void LinearSearch(atc contact[], int N, int x) {					// x - номер отдела
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

void OutputTable(atc contact[], int N) {
	cout << setw(5) << left << "  #"
		<< setw(20) << left << "Дата разговора" << "|"
		<< setw(15) << "Код" << "|"
		<< setw(20) << "Город" << "|"
		<< setw(9) << "Время разговора" << "|"
		<< setw(25) << "Тариф" << "|"
		<< setw(20)<<"Номер города" << "|"
		<< setw(20) << "Номер абонента" << "|"
		<< setw(18) << "" << "|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {
		cout << setw(3) << right << i + 1 << setw(2) << left << "."
			<< right << setw(10) << contact[i].date[0] << "."
			<< right << setw(2) << contact[i].date[1] << "."
			<< setw(4) << contact[i].date[2] << "|"
			<< setw(15) << contact[i].code << "|"
			<< setw(15) << contact[i].city << "|"
			<< setw(20) << contact[i].time[0] << setw(2) << "." << contact[i].time[1] << setw(2) << "." << contact[i].time[2] << "|"
			<< setw(9) << contact[i].tarif << "|"
			<< setw(25) << contact[i].city_num << "|"
			<< setw(25) << contact[i].subscriber_num << "|"
			<< endl;
	}
}

void FileEdition(string file_name) { // работа с файлом
	int loop = 1;
	while (loop == 1) {
		int temp_answ = 0;
		int answer = 0;
		string temp_string;
		cout << "\nРабота с файлом: " << file_name << ":\n1. просмотр файла\n2. Добавить запись в файл\n3. Изменить запись в файле\n4. Удалить запись из файла\n5. Задание\n\n0. Выход в главное меню\n\n";
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
				string t_date, t_code, t_city, t_time, t_city_num, t_subscriber_num;
				int t_tarif;
				//string t_surname, t_name, t_middlename, t_post, t_date;
				//int t_otdel = 0;
				answer1 = 1;
				while (answer1 == 1) {
					cout << "Дата разговора (в формате ДД.ММ.ГГ 13.04.2025): " << endl;
					cin >> t_date;
					cout << "Код города: " << endl;
					cin >> t_code;
					cout << "Город: " << endl;
					cin >> t_city;
					cout << "Продолжительность разговора (в формате ЧАСЫ.МИНУТЫ.СЕКУНДЫ): " << endl;
					cin >> t_time;
					cout << "Тариф: " << endl;
					cin >> t_tarif;
					cout << "Номер города: " << endl;
					cin >> t_city_num;
					cout << "Номер абонента: " << endl;
					cin >> t_subscriber_num;


					cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
					cin >> temp_answ;
					if (temp_answ == 1) file << "\n" << t_date << " " << t_code << " " << t_city << " " << t_time << " " << t_tarif << " " << t_city_num << " " << t_subscriber_num;
					else cout << "Данные не были добавлены в файл!" << endl;
					cout << "Желаете добавить еще запись? \n1 - да\n2 - нет" << endl;
					cin >> answer1;
					if (answer1 == 1) file << "\n";
				}
				file.close();
			}
		}

		
		//	1 - просмотр файла					3 - изменить запись в файле
		//	4 - удалить запись из файла			5 - выполнение задания
		
		if (answer == 1 || answer == 3 || answer == 4 || answer == 5) { 

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
					atc* contact = new atc[N]; // массив структур 
					int i = 0;
					string temp_d, temp_t;
					while (!file.eof() && i <= N - 1) { // вытягиваем данные с файла в массив структур
						file >> temp_d >> contact[i].code >> contact[i].city >> temp_t >> contact[i].tarif >> contact[i].city_num >> contact[i].subscriber_num;
						contact[i].date[0] = stoi(temp_d.substr(0, 2));
						contact[i].date[1] = stoi(temp_d.substr(3, 2));
						contact[i].date[2] = stoi(temp_d.substr(6, 4));

						contact[i].time[0] = stoi(temp_t.substr(0, 2));
						contact[i].time[1] = stoi(temp_t.substr(3, 2));
						contact[i].time[2] = stoi(temp_t.substr(6, 2));
						i++;
					}
					file.close();
					i = 0;
					if (answer == 1) {				// 1 - просмотр файла
						OutputTable(contact, N);
					}
					if (answer == 3) {
						cout << "Исходный список: " << endl;
						OutputTable(contact, N);
						int index_number = 0, answer3 = 0;
						string temp_date, temp_time;
						cout << "\nВведите порядковый номер записи, которую желаете изменить: ";
						cin >> index_number;
						index_number--;
						cout << "\nЧто вы желаете изменить? \n1 - дата разговора, \n2 - код города, \n3 - название города, \n4 - время разговора, \n5 - тариф, \n6 - номер телефона города, \n7 - номер телефона абонента" << endl;
						cin >> answer3;
						switch (answer3) {
						case 1:
							cout << "Введите дату разговора в формате ДД.ММ.ГГ:" << endl;
							cin >> temp_date;
							break;
						case 2:
							cout << "Введите индекс города:" << endl;
							cin >> contact[index_number].code;
							break;
						case 3:
							cout << "Введите название города:" << endl;
							cin >> contact[index_number].city;
							break;
						case 4:
							cout << "Время разговора (ЧЧ.ММ.СС):" << endl;
							cin >> temp_time;
							break;
						case 5:
							cout << "Введите тариф:" << endl;
							cin >> contact[index_number].tarif;
							break;
						case 6:
							cout << "Введите номер телефона города: " << endl;
							cin >> contact[index_number].city_num;
							break;
						case 7:
							cout << "Введите номер телефона абонента:" << endl;
							cin >> contact[index_number].subscriber_num;
							break;
						default:
							cout << "Неверный ответ. Попробуйте еще раз.\n";
						}
						cout << "Измененная запись: " << endl
							<< temp_date << " " << contact[index_number].code << " " << contact[index_number].city << " " << temp_time << " " << contact[index_number].tarif << " " << contact[index_number].city_num << " " << contact[index_number].subscriber_num << endl;
						cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
						cin >> temp_answ;

						if (temp_answ == 1) {
							ofstream file;
							file.open(file_name);
							for (int i = 0; i < N; i++) {
								if (i == index_number && answer3 == 1) {
									file << temp_date << " "
										<< contact[i].code << " " << contact[i].city << " ";
									if (contact[i].time[0] < 10) file << "0" <<  contact[i].time[0] << "."; 
									else file << contact[i].time[0] << ".";
									if (contact[i].time[1] < 10) file << "0" << contact[i].time[1] << ".";
									else file << contact[i].time[1] << ".";
									if (contact[i].time[2] < 10) file << "0" << contact[i].time[2] << " ";
									else file << contact[i].time[2] << " ";
										
									file<< contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num << endl;
								}
								else {
									if (i == index_number && answer3 == 4) {
										if (contact[i].date[0] < 10) file << "0" << contact[i].date[0] << ".";
										else file << contact[i].date[0] << ".";
										if (contact[i].date[1] < 10) file << "0" << contact[i].date[1] << ".";
										else file << contact[i].date[1] << ".";
										file
											<< contact[i].date[2] << " "
											<< contact[i].code << " " << contact[i].city << " " << temp_time << " "
											<< contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num << endl;
									}
									else {
										if (contact[i].date[0] < 10) file << "0" << contact[i].date[0] << ".";
										else file << contact[i].date[0] << ".";
										if (contact[i].date[1] < 10) file << "0" << contact[i].date[1] << ".";
										else file << contact[i].date[1] << ".";
										file
											<< contact[i].date[2] << " "
											<< contact[i].code << " " << contact[i].city << " ";
											if (contact[i].time[0] < 10) file << "0" << contact[i].time[0] << ".";
											else file << contact[i].time[0] << ".";
										if (contact[i].time[1] < 10) file << "0" << contact[i].time[1] << ".";
										else file << contact[i].time[1] << ".";
										if (contact[i].time[2] < 10) file << "0" << contact[i].time[2] << " ";
										else file << contact[i].time[2] << " ";

										file << contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num << endl;
									}
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
					//---------------------------------------закончила тут
					if (answer == 4) {
						cout << "Исходный список: " << endl;
						OutputTable(contact, N);
						int index_number = 0;
						cout << "\nВведите порядковый номер записи, которую желаете удалить: ";
						cin >> index_number;
						cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
						cin >> temp_answ;
						if (temp_answ == 1) {
							for (int i = index_number - 1; i < N - 1; i++) {
								contact[i].date[0] = contact[i + 1].date[0];
								contact[i].date[1] = contact[i + 1].date[1];
								contact[i].date[2] = contact[i + 1].date[2];
								contact[i].code = contact[i + 1].code;
								contact[i].city= contact[i + 1].city;
								contact[i].time[0] = contact[i + 1].time[0];
								contact[i].time[1] = contact[i + 1].time[1];
								contact[i].time[2] = contact[i + 1].time[2];
								contact[i].tarif = contact[i + 1].tarif;
								contact[i].city_num = contact[i + 1].city_num;
								contact[i].subscriber_num = contact[i + 1].subscriber_num;
															}
							N--;
							cout << endl << "Новый список:" << endl;
							OutputTable(contact, N);

							ofstream file;
							file.open(file_name);
							for (int i = 0; i < N; i++) {
								if (contact[i].date[0] < 10) file << "0" << contact[i].date[0] << ".";
								else file << contact[i].date[0] << ".";
								if (contact[i].date[1] < 10) file << "0" << contact[i].date[1] << ".";
								else file << contact[i].date[1] << ".";
								file
									<< contact[i].date[2] << " "
									<< contact[i].code << " " << contact[i].city << " ";
								if (contact[i].time[0] < 10) file << "0" << contact[i].time[0] << ".";
								else file << contact[i].time[0] << ".";
								if (contact[i].time[1] < 10) file << "0" << contact[i].time[1] << ".";
								else file << contact[i].time[1] << ".";
								if (contact[i].time[2] < 10) file << "0" << contact[i].time[2] << " ";
								else file << contact[i].time[2] << " ";

								file << contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num << endl;
								if (i != N - 1) file << "\n";
							}
							cout << "Данные в файле обновлены!" << endl;
							file.close();
						}
						else cout << "Данные в файле не были обновлены" << endl;
						temp_answ = 0;
					}

					if (answer == 5) {
						QuickSort(contact, 0, N - 1);
						cout << "Введите номер отдела, о котором желаете получить информацию" << endl;
						int x = 0;
						cin >> x;
						LinearSearch(contact, N, x);
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
		if (answer == 3) exit(0);			//	выход из программы
		cout << "Введите имя фала (без .txt): ";
		cin >> file_name;
		file_name = file_name + ".txt";
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
		if (answer == 2) {					//	Работа с существующим файлом
			FileEdition(file_name);
		}
	}
	return 0;
}