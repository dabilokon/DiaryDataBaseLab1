#include "Functions.h"

int _stateMenu;
void Menu()
{
	cout << "наеп╡рэ д╡ч:" << endl
		<< "(0)бху╡д г опнцпюлх." << endl
		<< "(1)ббнд дюмху." << endl
		<< "(2)бхб╡д дюмху." << endl
		<< "(3)гл╡мхрх дюм╡." << endl
		<< "(4)бхдюкхрх дюм╡." << endl
		<< "(5)дндюрх дюм╡." << endl
		<< "(6)гаепефеммъ дюмху." << endl
		<< "(7)бхбедеммъ MASTER гюохяс рю о╡дкецкнцн гюохяс гц╡дмн ╡мдейяс." << endl
		<< "(8)ббед╡рэ о╡дкецк╡ гюохях." << endl
		<< "(9)гаепефеммъ дюмху дкъ о╡дкецкху гюохя╡б." << endl
		<< "(10)бхбндхлх бя╡ дюм╡ ╡г MASTER рю SLAVE." << endl
		<< "(11)бхдюкхрх о╡дкецк╡ дюм╡ SLAVE." << endl
		<< "(12)бхбндхлн о╡дкецк╡(SLAVE) дюм╡." << endl
		<< "бюь бха╡п:";
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
	// дндю╙лн йхпхкхжч дн йнмянк╡ ббедеммъ/бхбедеммъ
	SetConsoleCP(1251);//бярюмнбкч╙лн йнднбс ярнп╡мйс win-cp 1251 с онрнй ббедеммъ
	SetConsoleOutputCP(1251);//бярюмнбкч╙лн йнднбс ярнп╡мйс win-cp 1251 с онрнй бхбедеммъ

	DataInitialization();//ярнбнпеммъ астепмнцн тюикс

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//нвхыеммъ йнмянк╡

			cout << "ббндхлн бпсвмс-(1) юан г тюикс-(2)?";
			cin >> _actions;

			system("cls");//нвхыеммъ йнмянк╡

			if (_actions == 1)
			{
				//ббндхлн бпсвмс
				DataEntry();
			}
			else
			{
				//вхрюммъ г тюикс
				cout << "ббед╡рэ мюгбс тюикю --> ";
				cin >> fileName;

				DataReading(fileName);
			}

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыс╙лн йнмянкэ
			Menu();
			break;
			///////////////////////////////////////////
		case 2:
			system("cls");//нвхыс╙лн йнмянкэ

			Print();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыс╙лн йнмянкэ
			Menu();
			break;
			///////////////////////////////////////////
		case 3:
			system("cls");//нвхыеммъ йнмянк╡

			DataChange();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////
		case 4:
			system("cls");//нвхыеммъ йнмянк╡

			DeleteData();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////
		case 5:
			system("cls");//нвхыеммъ йнмянк╡

			AddData();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////
		case 6:
			system("cls");//нвхыеммъ йнмянк╡

			//гюохя б тюик
			cout << "бБЕДХРЕ МЮГБЮМХЕ ТЮИКЮ:";
			cin >> fileName;

			system("cls");//нвхыеммъ йнмянк╡

			SaveData(fileName);

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////

			/////////////////////////////////////////
		case 7:
			system("cls");//нвхыеммъ йнмянк╡

			DataSortingMaster();

			DataSortingSlave();

			PrintMasterSort();

			PrintMasterSlave();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////
		case 8:
			system("cls");//нвхыеммъ йнмянк╡

			cout << "ббндхлн бпсвмс-(1) юан г тюикс-(2)?";
			cin >> _actions;

			system("cls");//нвхыеммъ йнмянк╡

			if (_actions == 1)
			{
				//ббндхлн бпсвмс
				DataEntrySlave();
			}
			else
			{
				//вхрюммъ г тюикс
				cout << "ббед╡рэ мюгбс тюикю --> ";
				cin >> fileName;

				DataReadingSlave(fileName);
			}

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыс╙лн йнмянкэ
			Menu();
			break;
			///////////////////////////////////////////
		case 9:
			system("cls");//нвхыеммъ йнмянк╡

			//гюохя б тюик
			cout << "бБЕДХРЕ МЮГБЮМХЕ ТЮИКЮ:";
			cin >> fileName;

			system("cls");//нвхыеммъ йнмянк╡

			SaveDataSlave(fileName);

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////
		case 10:
			system("cls");//нвхыс╙лн йнмянкэ

			PrintAll();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыс╙лн йнмянкэ
			Menu();
			break;
			//////////////////////////////////////////
		case 11:
			system("cls");//нвхыеммъ йнмянк╡

			DeleteDataSlave();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыеммъ йнмянк╡
			Menu();
			break;
			//////////////////////////////////////////
		case 12:
			system("cls");//нвхыс╙лн йнмянкэ

			PrintSlave();

			system("pause");//гюрпхлйю йнмянк╡
			system("cls");//нвхыс╙лн йнмянкэ
			Menu();
			break;
			///////////////////////////////////////////

		default:
			cout << "меб╡пмн напюмн осмйр лемч" << endl;
			break;
		}
	}

	system("cls");
	if (DataCleaning())
		cout << "дюм╡ --*MASTER FILE*-- нвхыемн!" << endl;
	else
		cout << "дюм╡ --*MASTER FILE*-- ме нвхыемн!" << endl;

	if (DataCleaningSlave())
		cout << "дюм╡ --*SLAVE FILE*-- нвхыемн!" << endl;
	else
		cout << "дюм╡ --*SLAVE FILE*-- ме нвхыемн!" << endl;

	cout << "пюанрс гюбепьемн." << endl;
	system("pause");


}