#include "Functions.h"

int _stateMenu;
void Menu()
{
	cout << "���в�� Ĳ�:" << endl
		<< "(0)��ղ� � ��������." << endl
		<< "(1)���� �����." << endl
		<< "(2)��²� �����." << endl
		<< "(3)�̲���� ��Ͳ." << endl
		<< "(4)�������� ��Ͳ." << endl
		<< "(5)������ ��Ͳ." << endl
		<< "(6)���������� �����." << endl
		<< "(7)��������� MASTER ������ �� ϲ�������� ������ �ò��� �������." << endl
		<< "(8)���Ĳ�� ϲ����˲ ������." << endl
		<< "(9)���������� ����� ��� ϲ������� ����Ѳ�." << endl
		<< "(10)�������� �Ѳ ��Ͳ �� MASTER �� SLAVE." << endl
		<< "(11)�������� ϲ����˲ ��Ͳ SLAVE." << endl
		<< "(12)�������� ϲ����˲(SLAVE) ��Ͳ." << endl
		<< "��� �����:";
	cin >> _stateMenu;
}
/*
		*--------------------
		DATA IN MASTER FILE:
		*ID
		*NAME
		*PASWORD
		*EMAIL
		*-------------------
		* DATA IN SLAVE FILE:
		*ID
		*NAMEBOOK
		*AUTHOR
		*GENRE
		*LANGUAGE
		*-------------------
*/

int main() {
	// ������� �������� �� �����˲ ��������/���������
	SetConsoleCP(1251);//��������ު�� ������ ���в��� win-cp 1251 � ����� ��������
	SetConsoleOutputCP(1251);//��������ު�� ������ ���в��� win-cp 1251 � ����� ���������

	DataInitialization();//���������� ��������� �����

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//�������� �����˲

			cout << "������� ������-(1) ��� � �����-(2)?";
			cin >> _actions;

			system("cls");//�������� �����˲

			if (_actions == 1)
			{
				//������� ������
				DataEntry();
			}
			else
			{
				//������� � �����
				cout << "���Ĳ�� ����� ����� --> ";
				cin >> fileName;

				DataReading(fileName);
			}

			system("pause");//�������� �����˲
			system("cls");//����Ӫ�� �������
			Menu();
			break;
			///////////////////////////////////////////
		case 2:
			system("cls");//����Ӫ�� �������

			Print();

			system("pause");//�������� �����˲
			system("cls");//����Ӫ�� �������
			Menu();
			break;
			///////////////////////////////////////////
		case 3:
			system("cls");//�������� �����˲

			DataChange();

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////
		case 4:
			system("cls");//�������� �����˲

			DeleteData();

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////
		case 5:
			system("cls");//�������� �����˲

			AddData();

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////
		case 6:
			system("cls");//�������� �����˲

			//����� � ����
			cout << "������� �������� �����:";
			cin >> fileName;

			system("cls");//�������� �����˲

			SaveData(fileName);

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////

			/////////////////////////////////////////
		case 7:
			system("cls");//�������� �����˲

			DataSortingMaster();

			DataSortingSlave();

			PrintMasterSort();

			PrintMasterSlave();

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////
		case 8:
			system("cls");//�������� �����˲

			cout << "������� ������-(1) ��� � �����-(2)?";
			cin >> _actions;

			system("cls");//�������� �����˲

			if (_actions == 1)
			{
				//������� ������
				DataEntrySlave();
			}
			else
			{
				//������� � �����
				cout << "���Ĳ�� ����� ����� --> ";
				cin >> fileName;

				DataReadingSlave(fileName);
			}

			system("pause");//�������� �����˲
			system("cls");//����Ӫ�� �������
			Menu();
			break;
			///////////////////////////////////////////
		case 9:
			system("cls");//�������� �����˲

			//����� � ����
			cout << "������� �������� �����:";
			cin >> fileName;

			system("cls");//�������� �����˲

			SaveDataSlave(fileName);

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////
		case 10:
			system("cls");//����Ӫ�� �������

			PrintAll();

			system("pause");//�������� �����˲
			system("cls");//����Ӫ�� �������
			Menu();
			break;
			//////////////////////////////////////////
		case 11:
			system("cls");//�������� �����˲

			DeleteDataSlave();

			system("pause");//�������� �����˲
			system("cls");//�������� �����˲
			Menu();
			break;
			//////////////////////////////////////////
		case 12:
			system("cls");//����Ӫ�� �������

			PrintSlave();

			system("pause");//�������� �����˲
			system("cls");//����Ӫ�� �������
			Menu();
			break;
			///////////////////////////////////////////

		default:
			cout << "��²��� ������ ����� ����" << endl;
			break;
		}
	}

	system("cls");
	if (DataCleaning())
		cout << "��Ͳ --*MASTER FILE*-- �������!" << endl;
	else
		cout << "��Ͳ --*MASTER FILE*-- �� �������!" << endl;

	if (DataCleaningSlave())
		cout << "��Ͳ --*SLAVE FILE*-- �������!" << endl;
	else
		cout << "��Ͳ --*SLAVE FILE*-- �� �������!" << endl;

	cout << "������ ���������." << endl;
	system("pause");


}