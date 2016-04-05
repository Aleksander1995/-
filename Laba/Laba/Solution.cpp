#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include <Windows.h>
#include<cctype>
using namespace std;

struct Data
{
	string name;
	string surname;
	string patronymic;
	string date_of_birth;
	string phone_number;
	string group_number;
};
Data *people = new Data[100];

void print(int count){
	cout << "№\tФамилия\t\tИмя\t\tОтчество\tДата рождения\tНомер телефона\tНомер группы\n";
	for (int i = 0; i < count; i++){
		cout << i + 1 << '\t';
		if (people[i].surname.length()>10){
			for (int j = 0; j < 10; j++){ cout << people[i].surname[j]; }
			cout << "..." << '\t';
		}
		else{ cout << people[i].surname; for (int k = people[i].surname.length(); k<10; k++){ cout << " "; }cout << '\t'; }

		if (people[i].name.length()>10){
			for (int j = 0; j < 10; j++){ cout << people[i].name[j]; }
			cout << "..." << '\t';
		}
		else{ cout << people[i].name; for (int k = people[i].name.length(); k<10; k++){ cout << " "; }cout << '\t'; }

		if (people[i].patronymic.length()>10){
			for (int j = 0; j < 10; j++){ cout << people[i].patronymic[j]; }
			cout << "..." << '\t';
		}
		else{ cout << people[i].patronymic; for (int k = people[i].patronymic.length(); k<10; k++){ cout << " "; }cout << '\t'; }

		cout << people[i].date_of_birth << '\t';

		if (people[i].phone_number.length()>11){
			for (int j = 0; j < 10; j++){ cout << people[i].phone_number[j]; }
			cout << "..." << '\t';
		}
		else{ cout << people[i].phone_number; for (int k = people[i].phone_number.length(); k<11; k++){ cout << " "; }cout << '\t'; }

		cout << people[i].group_number << endl;
	}
}
int remove(int N){
	cout << "Удаление по id(id-уникален)"<<endl<<"выберите id= ";
	char choice [50];
	while ((atoi(choice) < 1) || (atoi(choice) > N)){
		cin >> choice;
		if ((atoi(choice) < 1) || (atoi(choice) > N) || (isdigit(choice[0] == 0))){ cout << "Попробуйте еще раз" << endl; }
	};
	
	for (int i = atoi(choice); i < N + 1; i++){
		people[i - 1].surname = people[i].surname;
		people[i - 1].name = people[i].name;
		people[i - 1].patronymic = people[i].patronymic;
		people[i - 1].date_of_birth = people[i].date_of_birth;
		people[i - 1].phone_number = people[i ].phone_number;
		people[i - 1].group_number = people[i].group_number;
	}
	N--;
	cout << endl;

	return N;
}
int addition(int N){
	cout << "Добавление " << endl << "выберите количество добавляемых= ";
	char choice[50];
	long long amount = -1;
	while (amount < 0){
		cin >> choice;
		if (isdigit(choice[0] )== 0){ cout << "Попробуйте еще раз" << endl; }
		else{ amount = atoi(choice); }
	}
	for (int i = N; i < N + atoi(choice); i++){
		cout << "Введите " << i + 1 << " человека(Фамилия, Имя, Отчество, Дата рождения, Номер телефона, Номер группы): ";
		cin >> people[i].surname >> people[i].name >> people[i].patronymic >> people[i].date_of_birth >> people[i].phone_number >> people[i].group_number;
	}
	N = N + atoi(choice);
	cout << endl;
	return N;
}
void editing(int N){
	cout << "Редактирование по id(id-уникален)" << endl << "выберите id= ";
	char choice[50];
	while ((atoi(choice) < 1) || (atoi(choice) > N)){
		cin >> choice;
		if ((atoi(choice) < 1) || (atoi(choice) > N) || (isdigit(choice[0] == 0))){ cout << "Попробуйте еще раз" << endl; }
	};
	choice[0]--;
	cout << "выберите: [1]Фамилия, [2]Имя, [3]Отчество, [4]Дата рождения, [5]Номер телефона, [6]Номер группы" << endl;
	char choice2 [50];
	while ((atoi(choice2) < 1) || (atoi(choice2) > 6)){
		cin >> choice2;
		if ((atoi(choice2) < 1) || (atoi(choice2) > 6) || (isdigit(choice2[0] == 0))){ cout << "Попробуйте еще раз" << endl; }
	};
	cout << "измените : ";
	switch (atoi(choice2)){
	case 1: cin >> people[atoi(choice)].surname; break;
	case 2: cin >> people[atoi(choice)].name; break;
	case 3: cin >> people[atoi(choice)].patronymic; break;
	case 4: cin >> people[atoi(choice)].date_of_birth; break;
	case 5: cin >> people[atoi(choice)].phone_number; break;
	case 6: cin >> people[atoi(choice)].group_number; break;
	}
	cout << endl;
}
void sorting(int N){
	if (N < 2){cout << endl << "СОРТИРОВКА НЕВОЗМОЖНА, Т.К. НЕОБХОДИМО КАК МИНИМУМ 2 ПОЛЬЗОВАТЕЛЯ" << endl; return; }
	cout << "Сортировка" << endl << "выберите [1]Фамилия, [2]Имя, [3]Отчество, [4]Дата рождения, [5]Номер телефона, [6]Номер группы: ";

	char choice[50];
	while ((atoi(choice) < 1) || (atoi(choice) > 6)){
		cin >> choice;
	}
	
		Data swap;
		for (int i = 0; i < N; i++){
			for (int j = i + 1; j < N; j++){
				
				if (atoi(choice) == 1){
					
					if (strcmp(people[i].surname.c_str(), people[j].surname.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
					
				}
				if (atoi(choice) == 2){
					if (strcmp(people[i].name.c_str(), people[j].name.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (atoi(choice) == 3){
					if (strcmp(people[i].patronymic.c_str(), people[j].patronymic.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (atoi(choice) == 4){
					if (strcmp(people[i].date_of_birth.c_str(), people[j].date_of_birth.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (atoi(choice) == 5){
					if (strcmp(people[i].phone_number.c_str(), people[j].phone_number.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
				if (atoi(choice) == 6){
					if (strcmp(people[i].group_number.c_str(), people[j].group_number.c_str()) > 0){
						swap = people[i];
						people[i] = people[j];
						people[j] = swap;
					}
				}
			}
		}

		cout << endl;
}

int menu(int N){
	cout << "[1]Удалить элемент" << endl << "[2]Добавить запись" << endl << "[3]Редактировать запись" << endl << "[4]Сортировать" << endl << "[5]Выход" << endl << "[1]/[2]/[3]/[4]/[5]: ";
	char choice[50];
	while ((atoi(choice) < 1) || (atoi(choice) > 5)){
		cin >> choice;
		if ((atoi(choice) < 1) || (atoi(choice) > 5) || (isdigit(choice[0]) == 0) ) { cout << "Попробуйте еще раз" << endl; }
	}
	if (atoi(choice) == 1){ N = remove(N); }
	if (atoi(choice) == 2){ N = addition(N); }
	if (atoi(choice) == 3){ editing(N); }
	if (atoi(choice) == 4){sorting(N); }
	if (atoi(choice) == 5){ exit(0); }
	return N;
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

	print(count);
	cout << endl;

	return count;
}
int readingConsole(){
	cout << "Введите данные"<<endl;
	cout << "Введите количество людей: ";
	char choice[50];
	long long count = -1;
	while (count < 0){
		cin >> choice;
		if (isdigit(choice[0]) == 0){ cout << "Попробуйте еще раз" << endl; }
		else{ count = atoi(choice); }
	}
	for (int i = 0; i < count; i++){
		cout << "Введите " << i+1 << " человека(Фамилия, Имя, Отчество, Дата рождения, Номер телефона, Номер группы): "; 
		cin >> people[i].surname >> people[i].name >> people[i].patronymic >> people[i].date_of_birth >> people[i].phone_number >> people[i].group_number;
		system("cls");
	}
	print(count);
	cout << endl;
	
	return count;
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "[1] чтение с файла" << endl << "[2] чтение с консоли"<<endl<<"[1]/[2]: ";
	int count;
	char choice[50];
	while ((atoi(choice) < 1) || (atoi(choice) > 2)){
		cin >> choice;
		if ((atoi(choice) < 1) || (atoi(choice) > 2) || (isdigit(choice[0]) == 0)){ cout << "Попробуйте еще раз" << endl; }
	}
	if (atoi(choice) == 1){ count=readingFile(); }
	else{ count=readingConsole();}

	while (1){ 
		count=menu(count);
		print(count);
		
	}

	system("pause");
	return 0;
}

