#include<iostream>
#include<string>
using namespace std;

#define MAX 100

struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_phone;
	string m_Addr;
};

struct Addressbooks {
	struct Person peronArray[MAX];
	int m_Size;
};

// 1: Show the menu
void showMenu()
{
	cout << "*******************" << endl;
	cout << "***** 1,Add   *****" << endl;
	cout << "***** 2,Show  *****" << endl;
	cout << "***** 3,Delete*****" << endl;
	cout << "***** 4,Find  *****" << endl;
	cout << "***** 5,Change*****" << endl;
	cout << "***** 6,Clear *****" << endl;
	cout << "***** 0,Exit  *****" << endl;
	cout << "*******************" << endl;
}


void addPerson(Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "The Address book is full!" << endl;
		return;
	}
	else
	{
		// Name
		string name;
		cout << "Please enter the name:" << endl;
		cin >> name;
		abs->peronArray[abs->m_Size].m_Name = name;
		// Sex
		int sex;
		cout << "Please enter the gender:" << endl;
		cout << "1 -- MAN" << endl;
		cout << "2 -- WOMAN" << endl;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->peronArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "Invalid input, please enter the gender again!" << endl;
				cout << "1 -- MAN" << endl;
				cout << "2 -- WOMAN" << endl;
			}
		}
		// Age
		cout << "Please enter the age:" << endl;
		int age = 0;
		cin >> age;
		abs->peronArray[abs->m_Size].m_Age = age;

		// Tel
		cout << "Please enter the Telephone number:" << endl;
		string phone;
		cin >> phone;
		abs->peronArray[abs->m_Size].m_phone = phone;

		// Addr
		cout << "Please enter the address:" << endl;
		string addr;
		cin >> addr;
		abs->peronArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "You've added contact succesffully!" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks * abs) 
{
	if (abs->m_Size == 0) 
	{
		cout << "The address book is empty now!" << endl;
	}
	else 
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "Name: " << abs->peronArray[i].m_Name << endl;
			cout << "Sex: " << abs->peronArray[i].m_Sex << endl;
			cout << "Age: " << abs->peronArray[i].m_Age << endl;
			cout << "Phone: " << abs->peronArray[i].m_phone << endl;
			cout << "Address: " << abs->peronArray[i].m_Addr << endl;
		}

		system("pause");
		system("cls");
	}
}

void DeletePerson(Addressbooks * abs) 
{
	cout << "Please enter the name you want to delete:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "No body called " << name << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->peronArray[i] = abs->peronArray[i + 1];
		}

		abs->m_Size -= 1;
		cout << "Successfully deleted!" << endl;
	}
}

void FindPerson(Addressbooks * abs)
{
	cout << "Please enter the name you want to find:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "No body called " << name << endl;
	}
	else
	{
		cout << "Name: " << abs->peronArray[ret].m_Name << endl;
		cout << "Tel: " << abs->peronArray[ret].m_phone << endl;
		cout << "Sex: " << abs->peronArray[ret].m_Sex << endl;
		cout << "Age: " << abs->peronArray[ret].m_Age << endl;
		cout << "Addr: " << abs->peronArray[ret].m_Addr << endl;
	}

	system("pause");
	system("cls");
}

void ChangePerson(Addressbooks * abs) 
{
	cout << "Please enter the name you want to change:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "No body called " << name << endl;
	}
	else
	{
		// Name
		string name;
		cout << "Please enter the new name:" << endl;
		cin >> name;

		abs->peronArray[ret].m_Name = name;

		// ...

		cout << "Successfully Changed!";
	}

	// Press any key to clear the screen
	system("pause");
	system("cls");
}

void ClearPerson(Addressbooks * abs)
{
	abs->m_Size = 0;
	cout << "The address have been cleared." << endl;

	system("pause");
	system("cls");
}

int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->peronArray[i].m_Name == name)
		{
			return i;
		}
	}

	return -1;
}


int main()
{
	Addressbooks abs;
	abs.m_Size = 0;

	while (true)
	{
		showMenu();
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 0:
			cout << "See you next time!" << endl;
			system("pause"); // Press any key to continue
			return 0;
		case 1:
			addPerson(&abs);
		case 2:
			showPerson(&abs);
		case 3: 
			DeletePerson(&abs);
		case 4: 
			FindPerson(&abs);
		case 5: 
			ChangePerson(&abs);
		case 6: 
			ClearPerson(&abs);
		}
	}

	
}

