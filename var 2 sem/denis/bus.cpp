// список рейсов на автовокзале включает:
// - номер рейса
// - пункт назначения
// - время отправления и время прибытия
// 
// вывести информацию о рейсах, которыми можно воспользоваться для прибытия в пункт назначения раньше заданного врмени
// 
// ключ: время прибытия
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct BusList {
	int number = 0;
	string destination;								//	пункт назначения
	string departure;								//	отправление
	string arrival;									//	прибытие
};


void CreateFile() {									
	string filename;
	cout << "Enter file name (file.txt): ";
	cin >> filename;
	ofstream file;
	file.open(filename);
	if (!file.is_open()) {
		cout << "Error! The file was not opened." << endl;
	}
	else {
		cout << "File creation is successful." << endl;
		file.close();
	}
}


void ViewFile(BusList bus[], int N) {
	cout << endl
		<< setw(5) << left << "  №"
		<< setw(14) << left << "Bus Number"
		<< setw(21) << "End Station"
		<< setw(17) << "Departure Time"
		<< setw(13) << "Arrival Time" << endl;
	for (int i = 0; i < N; i++) {
		cout
			<< setw(3) << right << i + 1 << left << ") "
			<< setw(14) << left << bus[i].number
			<< setw(25) << left << bus[i].destination
			<< setw(17) << left << bus[i].departure
			<< setw(8) << left << bus[i].arrival << endl;
	}
	cout << endl;
}


void LinearSearch(BusList bus[], int N) {
	string arr_time;
	int k = 0;
	cout << "Enter the arrival time like (HH:MM): " << endl;
	cin >> arr_time;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (stoi(bus[i].arrival.substr(0, 2)) * 100 + stoi(bus[i].arrival.substr(3, 2)) < stoi(arr_time.substr(0, 2)) * 100 + stoi(arr_time.substr(3, 2))) {
			if (k == 0) {
				cout << endl
					<< setw(5) << left << "  №"
					<< setw(14) << left << "Bus Number"
					<< setw(21) << "End Station"
					<< setw(17) << "Departure Time"
					<< setw(13) << "Arrival Time" << endl;
			}
			cout
				<< setw(3) << right << i + 1 << left << ") "
				<< setw(14) << left << bus[i].number
				<< setw(25) << left << bus[i].destination
				<< setw(17) << left << bus[i].departure
				<< setw(8) << left << bus[i].arrival << endl;
			count++;
			k++;
		}
	}
	cout << endl;
	if (count == 0) cout << "There are no buses arriving earlier than the specified time." << endl;
}


void QuickSort(BusList bus[], int left, int right) {
	if (left > right) return;
	BusList m_bus = bus[(left + right) / 2];
	BusList temp_bus;
	int l = left, r = right;
	while (l <= r) {
		while (stoi(bus[l].arrival.substr(0, 2)) * 100 + stoi(bus[l].arrival.substr(3, 2)) < stoi(m_bus.arrival.substr(0, 2)) * 100 + stoi(m_bus.arrival.substr(3, 2))) l++;
		while (stoi(bus[r].arrival.substr(0, 2)) * 100 + stoi(bus[r].arrival.substr(3, 2)) > stoi(m_bus.arrival.substr(0, 2)) * 100 + stoi(m_bus.arrival.substr(3, 2))) r--;

		if (l <= r) {
			temp_bus = bus[l];
			bus[l] = bus[r];
			bus[r] = temp_bus;
			l++;
			r--;
		}
	}
	QuickSort(bus, left, r);
	QuickSort(bus, l, right);
}


void individualTask(BusList bus[], int N) {
	QuickSort(bus, 0, N - 1);
	BusList* temp_BusList = new BusList[N];
	string find_station;
	cout << "Enter the end station: " << endl;
	cin >> find_station;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (bus[i].destination == find_station) {
			temp_BusList[k] = bus[i];
			k++;
		}
	}
	if (k == 0) {
		cout << "There are no buses going to this station." << endl;
	}
	else {
		LinearSearch(temp_BusList, k);
	}
}


bool EditFile() {
	system("chcp 1251");
	string filename;
	cout << "Enter file name (like file.txt): ";
	cin >> filename;
	int answ = 0, a = 0;
	while (1) {
		cout << "\n1. View the file\n2. Add note\n3. Delete note\n4. Change note\n5. Individual task\n6. Exit in main menu" << endl;
		cin >> answ;
		if (answ == 2) {
			ofstream file;
			file.open(filename, ios::app);
			if (!file.is_open()) {
				cout << "Error! The file was not opened." << endl;
			}
			else {
				int t_num;
				string t_dest;										//	пункт назначения
				string t_depart;									//	отправление
				string t_arr;										//	прибытие
				cout << "Enter tne bus number: ";
				cin >> t_num;
				cout << "Enter tne destination: ";
				cin >> t_dest;
				cout << "Enter tne departure time (like 00:00): ";
				cin >> t_depart;
				cout << "Enter tne arrival time (like 00:00): ";
				cin >> t_arr;
				cout << "The new string: " << t_num << " " << t_dest << " " << t_depart << " " << t_arr << endl;
				cout << "Do you want to save changes?\n1. yes\n2. no " << endl;
				cin >> a;
				if (a == 1) {
					file << "\n" << t_num << " " << t_dest << " " << t_depart << " " << t_arr;
					cout << "The file has been updated!" << endl;
				}
				else cout << "The note wasn't added to the file!" << endl;
				file.close();
			}
		}

		if (answ == 6) return false;

		if (answ == 1 || answ == 3 || answ == 4 || answ == 5) {
			ifstream file;
			file.open(filename);
			if (!file.is_open()) {
				cout << "Error! The file was not opened." << endl;
				return false;
			}
			else {
				file.seekg(0);
				int count = 0, N = 0;
				string f_str;
				getline(file, f_str);
				string temp_string;
				file.seekg(0);
				while (!file.eof()) {								//	узнаем, сколько строк в файле, чтобы знать, сколько элементов в массиве структур
					getline(file, temp_string, '\n');
					count++;
				}
				N = count;
				count = 0;
				file.seekg(0);
				BusList* bus = new BusList[N];
				int i = 0;
				while (!file.eof() && i <= N - 1) {
					file >> bus[i].number >> bus[i].destination >> bus[i].departure >> bus[i].arrival;
					i++;
				}
				file.close();
				if (answ == 1) ViewFile(bus, N);
				if (answ == 3) {
					cout << "Old list: " << endl;
					ViewFile(bus, N);
					int num = 0;
					cout << "\nEnter the serial number of the note you want to delete: ";
					cin >> num;
					cout << "Do you want to save changes?\n1. yes\n2. no " << endl;
					cin >> a;
					if (a == 1) {
						for (int i = num - 1; i < N - 1; i++) {
							bus[i].number = bus[i + 1].number;
							bus[i].destination = bus[i + 1].destination;
							bus[i].departure = bus[i + 1].departure;
							bus[i].arrival = bus[i + 1].arrival;
						}
						N--;
						cout << endl << "New list:" << endl;
						ViewFile(bus, N);
						ofstream file;
						file.open(filename);
						for (int i = 0; i < N; i++) {
							file << bus[i].number << " " << bus[i].destination << " " << bus[i].departure << " " << bus[i].arrival;
							if (i != N - 1) file << "\n";
						}
						cout << "The data in the file has been updated!" << endl;

					}
					else cout << "The note wasn't added to the file!" << endl;
					file.close();

				}
				if (answ == 4) {
					cout << "Old list: " << endl;
					ViewFile(bus, N);
					int num = 0, answer = 0;
					cout << "Enter the serial number of the note you want to change: ";
					cin >> num;
					num = num - 1;
					cout << "\nWhat do you want to change: \n1. Bus number \n2. Destination \n3. Departure time \n4. Arrival time" << endl;
					cin >> answer;
					switch (answer) {
					case 1:
						cout << "Enter bus number" << endl;
						cin >> bus[num].number;
						break;
					case 2:
						cout << "Enter destination" << endl;
						cin >> bus[num].destination;
						break;
					case 3:
						cout << "Enter departure time" << endl;
						cin >> bus[num].departure;
						break;
					case 4:
						cout << "Enter arrival time" << endl;
						cin >> bus[num].arrival;
						break;

					default:
						cout << "Incorrect answer.\n";
					}
					cout << "New note: " << endl << bus[num].number << " " << bus[num].destination << " " << bus[num].departure << " " << bus[num].arrival << endl;
					cout << "Do you want to save changes?\n1. yes\n2. no " << endl;
					cin >> a;
					if (a == 1) {
						ofstream file;
						file.open(filename);
						for (int i = 0; i < N; i++) {
							file << bus[i].number << " " << bus[i].destination << " " << bus[i].departure << " " << bus[i].arrival;

							if (i != N - 1) {
								file << endl;
							}
						}
						cout << "The data in the file has been updated!" << endl << endl;
						file.close();
					}
					else cout << "The note wasn't added to the file!" << endl;
				}
				if (answ == 5) {
					cout << "answer 5" << endl;
					individualTask(bus, N);
				}
			}
		}
		cout << endl;
	}
	return true;
}


int main() {
	int key = 0;
	while (1) {
		cout << "\nMAIN MENU" << endl << "1. Create file\n2. Edit file\n3. Exit" << endl;
		cin >> key;
		switch (key) {
		case 1:
			cout << endl;
			CreateFile();
			continue;
		case 2:
			cout << endl;
			while (EditFile() != false) EditFile();
			continue;
		case 3:
			return 0;
		default:
			cout << "There is no such answer, try again!" << endl;
			continue;
		}
		cout << endl;
	}
	return 0;
}