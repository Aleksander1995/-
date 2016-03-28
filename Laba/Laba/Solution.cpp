#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include <Windows.h>


using namespace std;

struct Data
{
	int id;
	string name;
	string surname;
	string patronymic;
	string date_of_birth;
	string phone_number;
	string group_number;
};
Data *people = new Data[100];

void remove(int N){
	cout << "Удаление по id(id-уникален)"<<endl<<"выберите id= ";
	int choice = 0;
	while ((choice < 1) || (choice > N)){
		cin >> choice;
	};
	
	for (int i = choice; i < N + 1;i++){
		people[i - 1].id = people[i].id;
		people[i - 1].surname = people[i].surname;
		people[i - 1].name = people[i].name;
		people[i - 1].patronymic = people[i].patronymic;
		people[i - 1].date_of_birth = people[i].date_of_birth;
		people[i - 1].phone_number = people[i ].phone_number;
		people[i - 1].group_number = people[i].group_number;
	}
	N--;

	cout << "№" << '\t' << "Фамилия" << '\t' << "Имя" << '\t' << "Отчество" << '\t' << "Дата рождения" << '\t' << "Номер телефона" << '\t' << "Номер группы" << endl;
	for (int i = 0; i < N; i++){
		cout << people[i].id << '\t' << people[i].surname << '\t' << people[i].name << '\t' << people[i].patronymic << '\t' << people[i].date_of_birth << '\t' << '\t' << people[i].phone_number << '\t' << '\t' << people[i].group_number << endl;
	}
	cout << endl;
	
}
void addition(int N){
	cout << "Добавление " << endl << "выберите количество добавляемых= ";
	int choice = -1;
	while (choice < 0){
		cin >> choice;
	};
	for (int i = N; i < N + choice; i++){
		people[i].id = i+1;
		cout << "Введите " << i + 1 << " человека(Фамилия, Имя, Отчество, Дата рождения, Номер телефона, Номер группы): ";
		cin >> people[i].surname >> people[i].name >> people[i].patronymic >> people[i].date_of_birth >> people[i].phone_number >> people[i].group_number;
	}
	N = N + choice;
	cout << endl;
	cout << "№" << '\t' << "Фамилия" << '\t' << "Имя" << '\t' << "Отчество" << '\t' << "Дата рождения" << '\t' << "Номер телефона" << '\t' << "Номер группы" << endl;
	for (int i = 0; i < N; i++){
		cout << people[i].id << '\t' << people[i].surname << '\t' << people[i].name << '\t' << people[i].patronymic << '\t' << people[i].date_of_birth << '\t' << '\t' << people[i].phone_number << '\t' << '\t' << people[i].group_number << endl;
	}
	cout << endl;
}
void editing(int N){
	cout << "Редактирование по id(id-уникален)" << endl << "выберите id= ";
	int choice = 0;
	while ((choice < 1) || (choice > N)){
		cin >> choice;
	};
	choice--;
	cout << "выберите: [1]Фамилия, [2]Имя, [3]Отчество, [4]Дата рождения, [5]Номер телефона, [6]Номер группы" << endl;
	int choice2 = 0;
	while ((choice2 < 1) || (choice2 > 6)){
		cin >> choice2;
	};
	cout << "измените : ";
	switch (choice2){
	case 1: cin >> people[choice].surname; break;
	case 2: cin >> people[choice].name; break;
	case 3: cin >> people[choice].patronymic; break;
	case 4: cin >> people[choice].date_of_birth; break;
	case 5: cin >> people[choice].phone_number; break;
	case 6: cin >> people[choice].group_number; break;
	}
	cout << endl;
	cout << "№" << '\t' << "Фамилия" << '\t' << "Имя" << '\t' << "Отчество" << '\t' << "Дата рождения" << '\t' << "Номер телефона" << '\t' << "Номер группы" << endl;
	for (int i = 0; i < N; i++){
		cout << people[i].id << '\t' << people[i].surname << '\t' << people[i].name << '\t' << people[i].patronymic << '\t' << people[i].date_of_birth << '\t' << '\t' << people[i].phone_number << '\t' << '\t' << people[i].group_number << endl;
	}
	cout << endl;
}
void sorting(int N){

	cout << "Сортировка" << endl << "выберите [1]Фамилия, [2]Имя, [3]Отчество, [4]Дата рождения, [5]Номер телефона, [6]Номер группы: ";

	int choice = 0;
	while ((choice < 1) || (choice > 6)){
		cin >> choice;
	};
	
		Data swap;
		for (int i = 0; i < N; i++){
			for (int j = i + 1; j < N; j++){
				if (choice == 1){
					if (strcmp(people[i].surname.c_str(), people[j].surname.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (choice == 2){
					if (strcmp(people[i].name.c_str(), people[j].name.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (choice == 3){
					if (strcmp(people[i].patronymic.c_str(), people[j].patronymic.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (choice == 4){
					if (strcmp(people[i].date_of_birth.c_str(), people[j].date_of_birth.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (choice == 5){
					if (strcmp(people[i].phone_number.c_str(), people[j].phone_number.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (choice == 6){
					if (strcmp(people[i].group_number.c_str(), people[j].group_number.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
			}
			people[i].id = i + 1;
		}
		cout << "№" << '\t' << "Фамилия" << '\t' << "Имя" << '\t' << "Отчество" << '\t' << "Дата рождения" << '\t' << "Номер телефона" << '\t' << "Номер группы" << endl;
		for (int i = 0; i < N; i++){
			cout << people[i].id << '\t' << people[i].surname << '\t' << people[i].name << '\t' << people[i].patronymic << '\t' << people[i].date_of_birth << '\t' << '\t' << people[i].phone_number << '\t' << '\t' << people[i].group_number << endl;
		}
		cout << endl;
}

void menu(int N){
	cout << "[1]Удалить элемент" << endl << "[2]Добавить запись" << endl << "[3]Редактировать запись" << endl << "[4]Сортировать" << endl << "[5]Выход" << endl << "[1]/[2]/[3]/[4]/[5]: ";
	int choice = 0;
	while ((choice < 1) || (choice > 5)){
		cin >> choice;
	};
	if (choice == 1){ remove(N); }
	if (choice == 2){ addition(N); }
	if (choice == 3){ editing(N); }
	if (choice == 4){ sorting(N); }
	if (choice == 5){ exit(0); }
}

int readingFile(){
	string *s=new string[100];
	string *el = new string[100];
	string str;
	string temp;
	int count;

	ifstream input(".//database.txt");
	
	if (input.is_open()){
		count = 0;
		while (input.good()){
			getline(input, s[count]);
			count++;
		}

		for (int i = 0; i < count; i++){
			
			int k = 0;
			int pos = s[i].find(" ");
			while(pos>0){
				int N = s[i].length();
				for (int j = 0; j < pos; j++){ temp+= s[i][j]; }
				el[k] = temp;
				temp = "";
				str = "";
				for (int w = pos + 1; w < N; w++){ str+= s[i][w];  }
				s[i] = str;
				pos = s[i].find(" ");
				k++;
			}
			str = "";
			for (int w = 0; w < s[i].length(); w++){str += s[i][w]; }
			el[k] = str;
			k++;

			people[i].id = i+1;
			people[i].surname = el[1];
			people[i].name = el[2];
			people[i].patronymic = el[3];
			people[i].date_of_birth = el[4];
			people[i].phone_number = el[5];
			people[i].group_number = el[6];
	
		}
		input.close();
	}
	else{ cout << "Файл не найден" << endl; }
	cout << "№" <<'\t'<< "Фамилия"<<'\t'<<"Имя"<<'\t'<< "Отчество" <<'\t'<< "Дата рождения" <<'\t'<< "Номер телефона" <<'\t'<< "Номер группы" << endl;
	for (int i = 0; i < count;i++){
		cout << people[i].id << '\t' << people[i].surname << '\t' << people[i].name << '\t' << people[i].patronymic << '\t' << people[i].date_of_birth << '\t' << '\t' << people[i].phone_number << '\t' << '\t' << people[i].group_number << endl;
	}
	cout << endl;

	return count;
}
int readingConsole(){
	cout << "Введите данные"<<endl;
	cout << "Введите количество людей: ";
	int count;
	cin >>count;
	for (int i = 0; i < count; i++){
		people[i].id = i + 1;
		cout << "Введите " << i+1 << " человека(Фамилия, Имя, Отчество, Дата рождения, Номер телефона, Номер группы): "; 
		cin >> people[i].surname >> people[i].name >> people[i].patronymic >> people[i].date_of_birth >> people[i].phone_number >> people[i].group_number;
		system("cls");
	}
	cout << "№" << '\t' << "Фамилия" << '\t' << "Имя" << '\t' << "Отчество" << '\t' << "Дата рождения" << '\t' << "Номер телефона" << '\t' << "Номер группы" << endl;
	for (int i = 0; i < count; i++){
		cout << people[i].id << '\t' << people[i].surname << '\t' << people[i].name << '\t' << people[i].patronymic << '\t' << people[i].date_of_birth << '\t' << '\t' << people[i].phone_number << '\t' << '\t' << people[i].group_number << endl;
	}
	cout << endl;
	
	return count;
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "[1] чтение с файла" << endl << "[2] чтение с консоли"<<endl<<"[1]/[2]: ";
	int count;
	int choice = 0;
	while ((choice < 1) || (choice > 2)){
		cin >> choice;
	};
	if (choice == 1){ count=readingFile(); }
	else{ count=readingConsole();}

	while (1){ menu(count); }

	system("pause");
	return 0;
}

