# include "Functions.h"


//�Ͳֲ�˲��ֲ� �����----------------------------
void DataInitialization()
{
	//�����ު�� ���������� ����, � ����� ������ ���в������ ��������� �������ֲ� ����� �������� �����
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "������� ��������� ��������� �����" << endl;

	_buf.close();
}
//-----------------------------------------------

//�������� ���Ͳ ������--------------------------
void DataEntry()
{
	//������� ��Ͳ ������
	//�������² �̲�Ͳ
	int _ID;
	string _NAME;
	string _PASSWORD;
	string _EMAIL;
	int n;

	cout << "���Ĳ�� ʲ��ʲ��� �����:";
	cin >> n;

	//²��������� �������� ���� �� �����Ӫ�� � ����� ��Ͳ
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "���Ĳ�� ID --> ";
			cin >> _ID;

			cout << "���Ĳ�� NAME --> ";
			cin >> _NAME;

			cout << "���Ĳ�� PASSWORD -- > ";
			cin >> _PASSWORD;

			cout << "���Ĳ�� EMAIL -- > ";
			cin >> _EMAIL;

			record << _ID << endl;
			record << _NAME << endl;
			record << _PASSWORD << endl;

			if (i < n - 1)
				record << _EMAIL << endl;
			else
				record << _EMAIL;

			cout << "_________________________" << endl;
		}

	}
	else
		cout << "������� ²������� �����!" << endl;

	record.close();
}
//-----------------------------------------------

//���������� �����-------------------------------
void DataReading(string fileName)
{
	//���������� ����� �� �����

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n;

			//����Ӫ�� ��Ͳ �� �����

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _ID;

				reading >> _NAME;

				reading >> _PASSWORD;

				reading >> _EMAIL;

				record << _ID << endl;
				record << _NAME << endl;
				record << _PASSWORD << endl;
				if (i < n - 1)
					record << _EMAIL << endl;
				else
					record << _EMAIL;
			}
			cout << "��Ͳ �����Ͳ!" << endl;
		}
		else
			cout << "������� ²������� ������!" << endl;
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	reading.close();
	record.close();
}
//-----------------------------------------------

//�������� ��Ͳ----------------------------------
void Print()
{
	ifstream reading("Buffer.txt");

	if (reading)
	{
		//�������² �̲�Ͳ
		int _ID;
		string _NAME;
		string _PASSWORD;
		string _EMAIL;
		int n;

		reading >> n;
		cout << "ʲ��ʲ��� �����:" << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "��Ͳ ��� ID" << i + 1 << endl;

			reading >> _ID;
			cout << "ID --> " << _ID << endl;

			reading >> _NAME;
			cout << "NAME --> " << _NAME << endl;

			reading >> _PASSWORD;
			cout << "PASSWORD --> " << _PASSWORD << endl;

			reading >> _EMAIL;
			cout << "EMAIL --> " << _EMAIL << endl;

			cout << "_________________________________" << endl;
		}
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	reading.close();
}
//-----------------------------------------------

//�������� �����---------------------------------
bool DataCleaning()
{
	//�������� ������

	bool clear = false;

	//²�������� ����
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "������� ²������� ��������� �����" << endl;

	//����Ӫ��
	_buf.clear();

	//����²���, �� ���� �������
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}
//-----------------------------------------------

//�̲�ު�� ��Ͳ
void DataChange()
{
	//�̲�ު�� ��Ͳ

	//�������� ���������� �����
	//����Ӫ�� ����� �� �������� ��������� ���������� ��Ͳ � �����
	//����� ����ղ����� �� �̲�� ����

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ��������� ����������
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n, _n;

			//����Ӫ�� � ��������� ����� � �����
			reading >> n;
			cout << "���в�� ����� ��������, �� ���� �̲���� (²� 1 �� " << n << "):";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			record << n << endl;

			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _ID;
						record << _ID << endl;

						reading >> _NAME;
						record << _NAME << endl;

						reading >> _PASSWORD;
						record << _PASSWORD << endl;

						reading >> _EMAIL;
						if (i < n - 1)
							record << _EMAIL << endl;
						else
							record << _EMAIL;
					}
					else
					{
						cout << "���Ĳ�� ID -->";
						cin >> _ID;

						cout << "���Ĳ�� NAME -->";
						cin >> _NAME;

						cout << "���Ĳ�� PASSWORD -->";
						cin >> _PASSWORD;

						cout << "���Ĳ�� EMAIL -->";
						cin >> _EMAIL;

						record << _ID << endl;
						record << _NAME << endl;
						record << _PASSWORD << endl;
						if (i < n - 1)
							record << _EMAIL << endl;
						else
							record << _EMAIL;

						reading >> _ID;
						reading >> _NAME;
						reading >> _PASSWORD;
						reading >> _EMAIL;
					}
				}
				cout << "��Ͳ �̲����!" << endl;
			}
			else
				cout << "����� ������� �� ²���!" << endl;
		}
		else
			cout << "������� ²������� �����!" << endl;
	}
	else
		cout << "������� ²������� ��������� �����" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");


}
//-----------------------------------------------

//��ϲ������ �����------------------------------
void Copy()
{
	//��ϲ������ �� ����� �����
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n;

			//����Ӫ�� � ��������� ����� �� � �����
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _ID;
				record << _ID << endl;

				reading >> _NAME;
				record << _NAME << endl;

				reading >> _PASSWORD;
				record << _PASSWORD << endl;

				reading >> _EMAIL;
				if (i < n - 1)
					record << _EMAIL << endl;
				else
					record << _EMAIL;
			}
		}
		else
			cout << "������� ²������� �����!" << endl;
	}
	else
		cout << "������� ²������� ��������� �����!" << endl;

	record.close();
	reading.close();
}
//-----------------------------------------------

//ʲ��ʲ��� �����--------------------------------
int AmountOfData()
{
	//�������� ʲ��ʲ��� ����� �� �����
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
	{
		_buf >> n;
	}
	else
		cout << "������� ²������� ��������� �����!" << endl;

	_buf.close();

	return n;
}
//-----------------------------------------------

//��������� �����--------------------------------
void DeleteData()
{
	//��������� �����

	//���������Ӫ�� ��Ͳ
	//���������Ӫ�� � ��ղ���� �����
	//��в� �����ߪ����

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n, _n;

			//����Ӫ�� � ��������� ����� � �����
			reading >> n;
			int b = n - 1;
			cout << "���в�� ����� ��������, �� �̲�ު�� (²� 1 �� " << n << "):";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _ID;
						record << _ID << endl;

						reading >> _NAME;
						record << _NAME << endl;

						reading >> _PASSWORD;
						record << _PASSWORD << endl;

						reading >> _EMAIL;
						if (i < n - 1)
							record << _ID << endl;
						else
							record << _EMAIL;
					}
					else
					{
						reading >> _ID;
						reading >> _NAME;
						reading >> _PASSWORD;
						reading >> _EMAIL;
					}
				}
				cout << "��Ͳ ������Ͳ!" << endl;
			}
			else
				cout << "����� ������ �� ²���!" << endl;
		}
		else
			cout << "������� ²������� �����" << endl;
	}
	else
		cout << "������� ²������� ��������� �����" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}
//-----------------------------------------------

//��������� �����--------------------------------
void AddData()
{
	//������ ��Ͳ

	//�������² �̲�Ͳ
	int _ID;
	string _NAME;
	string _PASSWORD;
	string _EMAIL;
	int n = AmountOfData() + 1;

	//²��������� �������� ����
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
	{
		record_ << n << endl;
	}
	else
		cout << "������� ²������� ��������� �����!" << endl;

	if (record)
	{
		record << endl;

		cout << "���Ĳ�� ���Ͳ ID --> ";
		cin >> _ID;

		cout << "���Ĳ�� ���Ͳ NAME --> ";
		cin >> _NAME;

		cout << "���Ĳ�� ���Ͳ PASSWORD --> ";
		cin >> _PASSWORD;

		cout << "���Ĳ�� ���Ͳ EMAIL --> ";
		cin >> _EMAIL;

		record << _ID << endl;
		record << _NAME << endl;
		record << _PASSWORD << endl;
		record << _EMAIL;
	}
	else
		cout << "������� ²������� �����" << endl;

	record.close();
	record_.close();
}
//-----------------------------------------------

//���������� �����-------------------------------
void SaveData(string fileName)
{
	//���������� �����
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _ID;
				record << _ID << endl;

				reading >> _NAME;
				record << _NAME << endl;

				reading >> _PASSWORD;
				record << _PASSWORD << endl;

				reading >> _EMAIL;
				if (i < n - 1)
					record << _EMAIL << endl;
				else
					record << _EMAIL;
			}
			cout << "��Ͳ ���������� � ���˲! --> " << fileName << endl;
		}
		else
			cout << "������� ²������� ��������� �����!" << endl;
	}
	else
		cout << "������� ²������� �����!" << endl;

	record.close();
	reading.close();

}
//-----------------------------------------------


///////////////////////////////////////////////////////////////
//////////****SLAVE_FUNCTION*************************//////////
///////////////////////////////////////////////////////////////


//�Ͳֲ�˲��ֲ� ����� ��� ϲ������������� �������--
void DataInitializationSlave()
{
	//�����ު�� ���������� ����, � ����� ������ ���в������ ��������� �������ֲ� ����� �������� �����
	ofstream _bufSlave("BufferSlave.txt");

	if (!_bufSlave)
		cout << "������� ��������� ��������� �����" << endl;

	_bufSlave.close();
}
//----------------------------------------------

//���������� ϲ�����Ѳ� ��� ��������� �� �����
void DataSortingMaster()
{
	string index;
	cout << "���Ĳ�� ID ��� ���������� MASTER ����� �� ��������" << endl;
	cin >> index;

	int s;//ʲ��ʲ��� ����в� ����� � ���˲
	int domen = 4;//ʲ��ʲ��� �����ֲ � �����ֲ
	setlocale(LC_ALL, "rus");
	ifstream file; // �����ު�� ����� ����� ifstream
	file.open("Master.txt"); // ²��������� ����
	ofstream record("Master1.txt", ios::out);
	ofstream rec("Master2.txt", ios::out);
	ofstream write("MasterSort.txt", ios::out);
	file >> s;
	string str;

	int n;
	n = s * 4;

	//²������� ����� �� ���������� ����� (1.txt)
	if (!file)
	{
		cout << "���� �� ������\n\n";
		//return -1;
	}
	else
	{
		cout << "��� ��! ���� ������!\n\n";
	}

	//������ ����̲���� �����
	int size = n + 1;
	string* st = new string[size];
	for (int i = 0; i < n + 1; i++)
	{
		getline(file, str);
		if (str == "")
		{
			continue;
		}
		st[i] = str;
		//cout << "st -->" << i << "-->" << st[i] << endl;
		record << str << endl;
	}
	file.close();

	//²������� ����� �� ���������� ����� (Buffer.txt)
	ifstream buffer; // �����ު�� ����� ����� ifstream
	buffer.open("Master1.txt"); // ²�������� ����
	if (!buffer)
	{
		cout << "���� �� ������\n\n";
	}
	else
	{
		cout << "��� ��! ���� Buffer ������!\n\n";
	}

	//������ ����̲���� �����
	int siz = n;
	string* stt = new string[siz];
	for (int j = 0; j < siz; j++)
	{
		getline(buffer, str);
		stt[j] = str;
		//cout << "stt -->" << j << "-->" << stt[j] << endl;
		rec << str << endl;

	}
	buffer.close();


	//���������� ϲ�����Ѳ� �� ��������
	for (int k = 1; k <= s; k++)
	{
		int razmer = 4 * k;

		for (int i = razmer - 4; i < razmer; i++)
		{
			if (stt[razmer - 4] == index)
			{
				//cout << "--> stt111 -->" << i << "-->" << stt[i] << endl;
				write << stt[i] << endl;

			}

		}
	}

	//���Ӫ�� ʲ��ʲ��� ���ʲ� ���������� �����
	//int nLines = AmountOfDataMasterSort((char*)"MasterSort.txt");
	//cout << "--> pcsTableSortMaster -->" << pcsTableSortMaster << endl;
	//cout << "--> count -->"<< nLines/domen << endl;

}

//-----------------------------------------------

//���������� ϲ�����Ѳ� ��� ��������� �� �����
void DataSortingSlave()
{
	string index;
	cout << "���Ĳ�� ID ��� ���������� SLAVE ����� �� ��������" << endl;
	cin >> index;

	int s;//ʲ��ʲ��� ����в� ����� � ���˲
	int domen = 4;//ʲ��ʲ��� �����ֲ � �����ֲ
	setlocale(LC_ALL, "rus");
	ifstream file; // �����ު�� ����� ����� ifstream
	file.open("Slave.txt"); // ��������� ����
	ofstream record("Slave1.txt", ios::out);
	ofstream rec("Slave2.txt", ios::out);
	ofstream write("SlaveSort.txt", ios::out);
	file >> s;
	string str;

	int n;
	n = s * 5;

	//²������� ����� �� ���������� ����� (1.txt)
	if (!file)
	{
		cout << "���� �� ������\n\n";
		//return -1;
	}
	else
	{
		cout << "��� ��! ���� ������!\n\n";
	}

	//������ ����̲���� �����
	int size = n + 1;
	string* st = new string[size];
	for (int i = 0; i < n + 1; i++)
	{
		getline(file, str);
		if (str == "")
		{
			continue;
		}
		st[i] = str;
		cout << "st -->" << i << "-->" << st[i] << endl;
		record << str << endl;
	}
	file.close();

	//²������� ����� �� ���������� ����� (Buffer.txt)
	ifstream buffer; // �����ު�� ����� ����� ifstream
	buffer.open("Slave1.txt"); // ²�������� ����
	if (!buffer)
	{
		cout << "���� �� ������\n\n";
	}
	else
	{
		cout << "��� ��! ���� Buffer ������!\n\n";
	}

	//������ ����̲���� �����
	int siz = n;
	string* stt = new string[siz];
	for (int j = 0; j < siz; j++)
	{
		getline(buffer, str);
		stt[j] = str;
		//cout << "stt -->" << j << "-->" << stt[j] << endl;
		rec << str << endl;

	}
	buffer.close();


	//���������� ϲ�����Ѳ� �� ��������
	for (int k = 1; k <= s; k++)
	{
		int razmer = 5 * k;
		for (int i = razmer - 5; i < razmer; i++)
		{
			if (stt[razmer - 5] == index)
			{
				//cout << "--> stt111 -->" << i << "-->" << stt[i] << endl;
				write << stt[i] << endl;
			}

		}
	}


}
//-----------------------------------------------

//�������� ���Ͳ ��� ϲ������� ����Ѳ� ������---
void DataEntrySlave()
{
	//������� ��Ͳ ������
	//�������² �̲�Ͳ
	int _ID;
	string _NAMEBOOK;
	string _AUTHOR;
	string _GENRE;
	string _LANGUAGE;
	int n;

	cout << "���Ĳ�� ʲ��ʲ��� �����:";
	cin >> n;

	//²��������� �������� ���� �� �����Ӫ�� � ����� ��Ͳ
	ofstream recordSlave("BufferSlave.txt", ios::app);
	if (recordSlave)
	{
		recordSlave << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "���Ĳ�� ID --> ";
			cin >> _ID;

			cout << "���Ĳ�� NAMEBOOK --> ";
			cin >> _NAMEBOOK;

			cout << "���Ĳ�� AUTHOR -- > ";
			cin >> _AUTHOR;

			cout << "���Ĳ�� GENRE -- > ";
			cin >> _GENRE;

			cout << "���Ĳ�� LANGUAGE -- > ";
			cin >> _LANGUAGE;

			recordSlave << _ID << endl;
			recordSlave << _NAMEBOOK << endl;
			recordSlave << _AUTHOR << endl;
			recordSlave << _GENRE << endl;

			if (i < n - 1)
				recordSlave << _LANGUAGE << endl;
			else
				recordSlave << _LANGUAGE;

			cout << "_________________________" << endl;
		}

	}
	else
		cout << "������� ²������� �����!" << endl;

	recordSlave.close();
}
//----------------------------------------------

//���������� ����� ��� ϲ������� ����Ѳ�--------
void DataReadingSlave(string fileName)
{
	//���������� ����� �� �����

	ifstream readingSlave(fileName);
	ofstream recordSlave("BufferSlave.txt", ios::out);

	if (readingSlave)
	{
		if (recordSlave)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n;

			//����Ӫ�� ��Ͳ �� �����

			readingSlave >> n;
			recordSlave << n << endl;

			for (int i = 0; i < n; i++)
			{
				readingSlave >> _ID;

				readingSlave >> _NAMEBOOK;

				readingSlave >> _AUTHOR;

				readingSlave >> _GENRE;

				readingSlave >> _LANGUAGE;

				recordSlave << _ID << endl;
				recordSlave << _NAMEBOOK << endl;
				recordSlave << _AUTHOR << endl;
				recordSlave << _GENRE << endl;
				if (i < n - 1)
					recordSlave << _LANGUAGE << endl;
				else
					recordSlave << _LANGUAGE;
			}
			cout << "��Ͳ �����Ͳ!" << endl;
		}
		else
			cout << "������� ²������� ������!" << endl;
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	readingSlave.close();
	recordSlave.close();
}
//-----------------------------------------------

//���������� ����� SLAVE-------------------------------
void SaveDataSlave(string fileName)
{
	//���������� �����
	ifstream readingSlave("BufferSlave.txt");
	ofstream recordSlave(fileName, ios::out);

	if (readingSlave)
	{
		if (recordSlave)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n;

			readingSlave >> n;
			recordSlave << n << endl;

			for (int i = 0; i < n; i++)
			{
				readingSlave >> _ID;
				recordSlave << _ID << endl;

				readingSlave >> _NAMEBOOK;
				recordSlave << _NAMEBOOK << endl;

				readingSlave >> _AUTHOR;
				recordSlave << _AUTHOR << endl;

				readingSlave >> _GENRE;
				recordSlave << _GENRE << endl;

				readingSlave >> _LANGUAGE;
				if (i < n - 1)
					recordSlave << _LANGUAGE << endl;
				else
					recordSlave << _LANGUAGE;
			}
			cout << "��Ͳ ���������� � ���˲! --> " << fileName << endl;
		}
		else
			cout << "������� ²������� ��������� �����!" << endl;
	}
	else
		cout << "������� ²������� �����!" << endl;

	recordSlave.close();
	readingSlave.close();

}
//-----------------------------------------------

//�������� ����� ��� SLAVE �����----------------
bool DataCleaningSlave()
{
	//�������� ������

	bool clear = false;

	//²�������� ����
	fstream _bufSlave("BufferSlave.txt", ios::out);

	if (!_bufSlave)
		cout << "������� ²������� ��������� �����" << endl;

	//����Ӫ��
	_bufSlave.clear();

	//����²���, �� ���� �������
	if (_bufSlave.peek() == EOF)
		clear = true;
	else
		clear = false;

	_bufSlave.close();

	return clear;
}
//----------------------------------------------

//�������� �Ѳ ��Ͳ-----------------------------
void PrintAll()
{
	ifstream reading("Master.txt");
	ifstream read("Slave.txt");

	if (reading)
	{
		//�������² �̲�Ͳ
		int _ID;
		string _NAME;
		string _PASSWORD;
		string _EMAIL;
		int n;

		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "������� �������� ����Ѳ� MASTER FILE:" << endl;
		reading >> n;
		cout << "ʲ��ʲ��� ����� MASTER FILE:" << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "��Ͳ ��� ID" << i + 1 << endl;

			reading >> _ID;
			cout << "ID --> " << _ID << endl;

			reading >> _NAME;
			cout << "NAME --> " << _NAME << endl;

			reading >> _PASSWORD;
			cout << "PASSWORD --> " << _PASSWORD << endl;

			reading >> _EMAIL;
			cout << "EMAIL --> " << _EMAIL << endl;

			cout << "_________________________________" << endl;
		}
	}
	else
		cout << "������� ²������� �����!" << endl;
	//ϲ����˲ ������

	if (read)
	{
		//�������² �̲�Ͳ
		int _ID;
		string _NAMEBOOK;
		string _AUTHOR;
		string _GENRE;
		string _LANGUAGE;
		int n;

		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "������� ϲ������� ����Ѳ� SLAVE FILE:" << endl;
		read >> n;
		cout << "ʲ��ʲ��� ����� SLAVE FILE:" << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "��Ͳ ��� ID" << i + 1 << endl;

			read >> _ID;
			cout << "ID --> " << _ID << endl;

			read >> _NAMEBOOK;
			cout << "NAMEBOOK --> " << _NAMEBOOK << endl;

			read >> _AUTHOR;
			cout << "AUTHOR --> " << _AUTHOR << endl;

			read >> _GENRE;
			cout << "GENRE --> " << _GENRE << endl;

			read >> _LANGUAGE;
			cout << "LANGUAGE --> " << _LANGUAGE << endl;

			cout << "_________________________________" << endl;
		}
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	reading.close();
	read.close();
}
//-----------------------------------------------


//�������� MASTER ��Ͳ �������Ͳ-----------------------------
void PrintMasterSort()
{
	ifstream reading("MasterSort.txt");

	if (reading)
	{
		//�������² �̲�Ͳ
		string _ID;
		string _NAME;
		string _PASSWORD;
		string _EMAIL;

		int domen = 4;
		//���Ӫ�� ʲ��ʲ��� ���ʲ� ���������� �����
		int inLine = AmountOfDataMasterSort((char*)"MasterSort.txt");
		int p = inLine / domen;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << "ʲ��ʲ��� ����� MASTER:" << p << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;

		for (int i = 0; i < p; i++)
		{
			//cout << "��Ͳ ��� ID ----" << _ID << endl;

			reading >> _ID;
			cout << "��Ͳ ��� ID ----" << _ID << endl;
			cout << "ID --> " << _ID << endl;

			reading >> _NAME;
			cout << "NAME --> " << _NAME << endl;

			reading >> _PASSWORD;
			cout << "PASSWORD --> " << _PASSWORD << endl;

			reading >> _EMAIL;
			cout << "EMAIL --> " << _EMAIL << endl;

			cout << "_________________________________" << endl;
		}
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	reading.close();
}
//-----------------------------------------------

//�������� SLAVE ��Ͳ �������Ͳ-------------------
void PrintMasterSlave()
{
	ifstream reading("SlaveSort.txt");

	if (reading)
	{
		//�������² �̲�Ͳ
		int _ID;
		string _NAMEBOOK;
		string _AUTHOR;
		string _GENRE;
		string _LANGUAGE;

		int domen = 5;
		//���Ӫ�� ʲ��ʲ��� ���ʲ� ���������� �����
		int inLine = AmountOfDataSlaveSort((char*)"SlaveSort.txt");
		int p = inLine / domen;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << "ʲ��ʲ��� ����� SLAVE:" << p << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;

		for (int i = 0; i < p; i++)
		{
			//cout << "��Ͳ ��� ID" << i + 1 << endl;

			reading >> _ID;
			cout << "��Ͳ ��� ID ----" << _ID << endl;
			cout << "ID --> " << _ID << endl;

			reading >> _NAMEBOOK;
			cout << "NAMEBOOK --> " << _NAMEBOOK << endl;

			reading >> _AUTHOR;
			cout << "AUTHOR --> " << _AUTHOR << endl;

			reading >> _GENRE;
			cout << "GENRE --> " << _GENRE << endl;

			reading >> _LANGUAGE;
			cout << "LANGUAGE --> " << _LANGUAGE << endl;

			cout << "_________________________________" << endl;
		}
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	reading.close();
}
//-----------------------------------------------

//ʲ��ʲ��� ���������� ����� MASTERSORT--------------------------------
int AmountOfDataMasterSort(char* filename)
{
	// 1. �������� ��������� F, ������� ������ � ������ filename.
	// ���� ����������� ��� ������ � ��������� �������.
	ifstream F(filename, ios::in);
	// 2. ��������, ���������� �� ����
	if (!F)
	{
		return -1;
	}

	// 3. ��������� ���������� ����� � �����
	// 3.1. �������� �������������� ����������
	int count = 0;
	char buffer[1000]; // ����� ��� ���������� ����� ������

	// 3.2. ���� ������ �����.
	// ������ ������ ����� �������� �������� getline().
	// �������� ����� ����� �������������� �������� eof().
	while (!F.eof())
	{
		// ��������� ������� �����
		count++;

		// ������� ���� ������ � �����
		F.getline(buffer, 1000);
	}
	// 4. ������� ���� F
	F.close();
	// 5. ������� ���������
	return count;
}
//-----------------------------------------------

//ʲ��ʲ��� ���������� ����� MASTERSORT--------------------------------
int AmountOfDataSlaveSort(char* filename)
{
	// 1. �������� ��������� F, ������� ������ � ������ filename.
	// ���� ����������� ��� ������ � ��������� �������.
	ifstream F(filename, ios::in);
	// 2. ��������, ���������� �� ����
	if (!F)
	{
		return -1;
	}

	// 3. ��������� ���������� ����� � �����
	// 3.1. �������� �������������� ����������
	int count = 0;
	char buffer[1000]; // ����� ��� ���������� ����� ������

	// 3.2. ���� ������ �����.
	// ������ ������ ����� �������� �������� getline().
	// �������� ����� ����� �������������� �������� eof().
	while (!F.eof())
	{
		// ��������� ������� �����
		count++;

		// ������� ���� ������ � �����
		F.getline(buffer, 1000);
	}
	// 4. ������� ���� F
	F.close();
	// 5. ������� ���������
	return count;
}
//-----------------------------------------------

//��������� �����--------------------------------
void DeleteDataSlave()
{
	//��������� �����

	//���������Ӫ�� ��Ͳ
	//���������Ӫ�� � ��ղ���� �����
	//��в� �����ߪ����

	CopySlave();

	ifstream reading("BufferSlave_.txt");
	ofstream record("BufferSlave.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n, _n;

			//����Ӫ�� � ��������� ����� � �����
			reading >> n;
			int b = n - 1;
			cout << "���в�� ����� ��������, �� �̲�ު�� (²� 1 �� " << n << "):";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _ID;
						record << _ID << endl;

						reading >> _NAMEBOOK;
						record << _NAMEBOOK << endl;

						reading >> _AUTHOR;
						record << _AUTHOR << endl;

						reading >> _GENRE;
						record << _GENRE << endl;

						reading >> _LANGUAGE;
						if (i < n - 1)
							record << _ID << endl;
						else
							record << _LANGUAGE;
					}
					else
					{
						reading >> _ID;
						reading >> _NAMEBOOK;
						reading >> _AUTHOR;
						reading >> _GENRE;
						reading >> _LANGUAGE;
					}
				}
				cout << "��Ͳ ������Ͳ!" << endl;
			}
			else
				cout << "����� ������ �� ²���!" << endl;
		}
		else
			cout << "������� ²������� �����" << endl;
	}
	else
		cout << "������� ²������� ��������� �����" << endl;

	record.close();
	reading.close();

	remove("BufferSlave_.txt");
}
//-----------------------------------------------

//�������� ��Ͳ----------------------------------
void PrintSlave()
{
	ifstream reading("BufferSlave.txt");

	if (reading)
	{
		//�������² �̲�Ͳ
		int _ID;
		string _NAMEBOOK;
		string _AUTHOR;
		string _GENRE;
		string _LANGUAGE;
		int n;

		reading >> n;
		cout << "ʲ��ʲ��� �����:" << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "��Ͳ ��� ID" << i + 1 << endl;

			reading >> _ID;
			cout << "ID --> " << _ID << endl;

			reading >> _NAMEBOOK;
			cout << "NAMEBOOK --> " << _NAMEBOOK << endl;

			reading >> _AUTHOR;
			cout << "AUTHOR --> " << _AUTHOR << endl;

			reading >> _GENRE;
			cout << "GENRE --> " << _GENRE << endl;

			reading >> _LANGUAGE;
			cout << "LANGUAGE --> " << _LANGUAGE << endl;

			cout << "_________________________________" << endl;
		}
	}
	else
		cout << "������� ²������� �����!" << endl;

	//�������� �����
	reading.close();
}
//-----------------------------------------------

//��ϲ������ �����------------------------------
void CopySlave()
{
	//��ϲ������ �� ����� �����
	ifstream reading("BufferSlave.txt");
	ofstream record("BufferSlave_.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//�������² �̲�Ͳ
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n;

			//����Ӫ�� � ��������� ����� �� � �����
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _ID;
				record << _ID << endl;

				reading >> _NAMEBOOK;
				record << _NAMEBOOK << endl;

				reading >> _AUTHOR;
				record << _AUTHOR << endl;

				reading >> _GENRE;
				record << _GENRE << endl;

				reading >> _LANGUAGE;
				if (i < n - 1)
					record << _LANGUAGE << endl;
				else
					record << _LANGUAGE;
			}
		}
		else
			cout << "������� ²������� �����!" << endl;
	}
	else
		cout << "������� ²������� ��������� �����!" << endl;

	record.close();
	reading.close();
}
//-----------------------------------------------



