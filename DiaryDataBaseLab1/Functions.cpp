# include "Functions.h"


//≤Õ≤÷≤¿À≤«¿÷≤ﬂ ƒ¿Õ»’----------------------------
void DataInitialization()
{
	//—“¬Œ–ﬁ™ÃŒ “»Ã◊¿—Œ¬»… ‘¿…À, ¬ ﬂ ŒÃ” ¡”ƒ”“‹ «¡≈–≤√¿“»—‹ ¿ “”¿À‹Õ¿ ≤Õ‘Œ–Ã¿÷≤ﬂ “Œ¡“Œ —“¬Œ–»ÃŒ ¡”‘≈–
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "œŒÃ»À ¿ —“¬Œ–≈ÕÕﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	_buf.close();
}
//-----------------------------------------------

//¬¬Œƒ»Ã»Œ ƒ¿ÕÕ≤ ¬–”◊Õ”--------------------------
void DataEntry()
{
	//¬¬Œƒ»ÃŒ ƒ¿Õ≤ ¬–”◊Õ”
	//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
	int _ID;
	string _NAME;
	string _PASSWORD;
	string _EMAIL;
	int n;

	cout << "¬¬≈ƒ≤“‹  ≤À‹ ≤—“‹ ƒ¿Õ»’:";
	cin >> n;

	//¬≤ƒ –»¬¿™ÃŒ ¡”‘≈–Õ»… ‘¿…À “¿ «¿œ»—”™ÃŒ ¬ Õ‹Œ√Œ ƒ¿Õ≤
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "¬¬≈ƒ≤“‹ ID --> ";
			cin >> _ID;

			cout << "¬¬≈ƒ≤“‹ NAME --> ";
			cin >> _NAME;

			cout << "¬¬≈ƒ≤“‹ PASSWORD -- > ";
			cin >> _PASSWORD;

			cout << "¬¬≈ƒ≤“‹ EMAIL -- > ";
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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	record.close();
}
//-----------------------------------------------

//«◊»“”¬¿ÕÕﬂ ƒ¿Õ»’-------------------------------
void DataReading(string fileName)
{
	//«◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ ≤« ‘¿…À”

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n;

			//«◊»“”™ÃŒ ƒ¿Õ≤ ≤« ‘¿…À”

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
			cout << "ƒ¿Õ≤ «◊»“¿Õ≤!" << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–¿!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	reading.close();
	record.close();
}
//-----------------------------------------------

//¬»¬Œƒ»ÃŒ ƒ¿Õ≤----------------------------------
void Print()
{
	ifstream reading("Buffer.txt");

	if (reading)
	{
		//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
		int _ID;
		string _NAME;
		string _PASSWORD;
		string _EMAIL;
		int n;

		reading >> n;
		cout << " ≤À‹ ≤—“‹ ƒ¿Õ»’:" << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "ƒ¿Õ≤ œ–Œ ID" << i + 1 << endl;

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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	reading.close();
}
//-----------------------------------------------

//Œ◊»Ÿ≈ÕÕﬂ ƒ¿Õ»’---------------------------------
bool DataCleaning()
{
	//Œ◊»Ÿ≈ÕÕﬂ ¡”‘≈–¿

	bool clear = false;

	//¬≤ƒ –»¬¿™Ã ‘¿…À
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	//Œ◊»Ÿ”™ÃŒ
	_buf.clear();

	//œ≈–≈¬≤– ¿, ŸŒ ‘¿…À Œ◊»Ÿ≈ÕŒ
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}
//-----------------------------------------------

//«Ã≤Õﬁ™ÃŒ ƒ¿Õ≤
void DataChange()
{
	//«Ã≤Õﬁ™ÃŒ ƒ¿Õ≤

	//œŒ¬“Œ–Õ≈ «¡≈–≈∆≈ÕÕﬂ ƒ¿Õ»’
	//Œ◊»Ÿ”™ÃŒ ¡”‘≈– “¿ œŒ¬“Œ–ÕŒ œŒ◊»Õ¿™ÃŒ «¿œ»—”¬¿“» ƒ¿Õ≤ ¬ Õ‹Œ√Œ
	//œŒÿ”  Õ≈Œ¡’≤ƒÕŒ√Œ “¿ «Ã≤Õ¿ …Œ√Œ

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤‚ÂÏÂÌÌ˚Â ÔÂÂÏÂÌÌ˚Â
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n, _n;

			//«◊»“”™ÃŒ « ¡”‘≈–ÕŒ√Œ ‘¿…À¿ ” ÕŒ¬»…
			reading >> n;
			cout << "Œ¡≈–≤“‹ ÕŒÃ≈– ≈À≈Ã≈Õ“¿, ŸŒ ¡”ƒ≈ «Ã≤Õ≈ÕŒ (¬≤ƒ 1 ‰Ó " << n << "):";
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
						cout << "¬¬≈ƒ≤“‹ ID -->";
						cin >> _ID;

						cout << "¬¬≈ƒ≤“‹ NAME -->";
						cin >> _NAME;

						cout << "¬¬≈ƒ≤“‹ PASSWORD -->";
						cin >> _PASSWORD;

						cout << "¬¬≈ƒ≤“‹ EMAIL -->";
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
				cout << "ƒ¿Õ≤ «Ã≤Õ≈ÕŒ!" << endl;
			}
			else
				cout << "ÕŒÃ≈– ¬¬≈ƒ≈ÕŒ Õ≈ ¬≤–ÕŒ!" << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");


}
//-----------------------------------------------

// Œœ≤ﬁ¬¿ÕÕﬂ ƒ¿Õ»’------------------------------
void Copy()
{
	// Œœ≤ﬁ¬¿ÕÕﬂ ƒŒ ÕŒ¬√Œ ‘¿…À”
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n;

			//«◊»“”™ÃŒ « ¡”‘≈–ÕŒ√Œ ‘¿…À” “¿ ¬ ÕŒ¬»…
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
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”!" << endl;

	record.close();
	reading.close();
}
//-----------------------------------------------

// ≤À‹ ≤—“‹ ƒ¿Õ»’--------------------------------
int AmountOfData()
{
	//¬»¬Œƒ»“‹  ≤À‹ ≤—“‹ ƒ¿Õ»’ ≤« ‘¿…À”
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
	{
		_buf >> n;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”!" << endl;

	_buf.close();

	return n;
}
//-----------------------------------------------

//¬»ƒ¿À≈ÕÕﬂ ƒ¿Õ»’--------------------------------
void DeleteData()
{
	//¬»ƒ¿À≈ÕÕﬂ ƒ¿Õ»’

	//«¿œ¿Ãﬂ“Œ¬”™ÃŒ ƒ¿Õ≤
	//œ≈–≈«¿œ»—”™ÃŒ ” ¬»’≤ƒÕ»… ¡”‘≈–
	//Œ –≤Ã ¬»ƒ¿Àﬂ™ÃŒ√Œ

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
			int _ID;
			string _NAME;
			string _PASSWORD;
			string _EMAIL;
			int n, _n;

			//«◊»“”™ÃŒ « ¡”‘≈–ÕŒ√Œ ‘¿…À¿ ” ÕŒ¬»…
			reading >> n;
			int b = n - 1;
			cout << "Œ¡≈–≤“‹ ÕŒÃ≈– ≈À≈Ã≈Õ“¿, ŸŒ «Ã≤Õﬁ™ÃŒ (¬≤ƒ 1 ƒŒ " << n << "):";
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
				cout << "ƒ¿Õ≤ ¬»ƒ¿À≈Õ≤!" << endl;
			}
			else
				cout << "ÕŒÃ≈– ¬≈ƒ≈ÕŒ Õ≈ ¬≤–ÕŒ!" << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}
//-----------------------------------------------

//ƒŒƒ¿¬¿ÕÕﬂ ƒ¿Õ»’--------------------------------
void AddData()
{
	//ƒŒƒ¿“» ƒ¿Õ≤

	//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
	int _ID;
	string _NAME;
	string _PASSWORD;
	string _EMAIL;
	int n = AmountOfData() + 1;

	//¬≤ƒ –»¬¿™ÃŒ ¡”‘≈–Õ»… ‘¿…À
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
	{
		record_ << n << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”!" << endl;

	if (record)
	{
		record << endl;

		cout << "¬¬≈ƒ≤“‹ ƒ¿ÕÕ≤ ID --> ";
		cin >> _ID;

		cout << "¬¬≈ƒ≤“‹ ƒ¿ÕÕ≤ NAME --> ";
		cin >> _NAME;

		cout << "¬¬≈ƒ≤“‹ ƒ¿ÕÕ≤ PASSWORD --> ";
		cin >> _PASSWORD;

		cout << "¬¬≈ƒ≤“‹ ƒ¿ÕÕ≤ EMAIL --> ";
		cin >> _EMAIL;

		record << _ID << endl;
		record << _NAME << endl;
		record << _PASSWORD << endl;
		record << _EMAIL;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”" << endl;

	record.close();
	record_.close();
}
//-----------------------------------------------

//«¡≈–≈∆≈ÕÕﬂ ƒ¿Õ»’-------------------------------
void SaveData(string fileName)
{
	//«¡≈–≈∆≈ÕÕﬂ ƒ¿Õ»’
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
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
			cout << "ƒ¿Õ≤ «¡≈–≈∆≈ÕÕŒ ” ‘¿…À≤! --> " << fileName << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À¿!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	record.close();
	reading.close();

}
//-----------------------------------------------


///////////////////////////////////////////////////////////////
//////////****SLAVE_FUNCTION*************************//////////
///////////////////////////////////////////////////////////////


//≤Õ≤÷≤¿À≤«¿÷≤ﬂ ƒ¿Õ»’ ƒÀﬂ œ≤ƒœŒ–ﬂƒ Œ¬¿Õ»’ “¿¡À»÷‹--
void DataInitializationSlave()
{
	//—“¬Œ–ﬁ™ÃŒ “»Ã◊¿—Œ¬»… ‘¿…À, ¬ ﬂ ŒÃ” ¡”ƒ”“‹ «¡≈–≤√¿“»—‹ ¿ “”¿À‹Õ¿ ≤Õ‘Œ–Ã¿÷≤ﬂ “Œ¡“Œ —“¬Œ–»ÃŒ ¡”‘≈–
	ofstream _bufSlave("BufferSlave.txt");

	if (!_bufSlave)
		cout << "œŒÃ»À ¿ —“¬Œ–≈ÕÕﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	_bufSlave.close();
}
//----------------------------------------------

//—Œ–“”¬¿ÕÕﬂ œ≤ƒ«¿œ»—≤¬ ƒÀﬂ ¬»¬≈ƒ≈ÕÕﬂ Õ¿ ≈ –¿Õ
void DataSortingMaster()
{
	string index;
	cout << "¬¬≈ƒ≤“‹ ID ƒÀﬂ √–”œ”¬¿ÕÕﬂ MASTER ƒ¿Õ»’ «¿ ≤Õƒ≈ —ŒÃ" << endl;
	cin >> index;

	int s;// ≤À‹ ≤—“‹ Õ¿¡Œ–≤¬ ƒ¿Õ»’ ” ‘¿…À≤
	int domen = 4;// ≤À‹ ≤—“‹ —“Œ¬¡÷≤ ” “¿¡À»÷≤
	setlocale(LC_ALL, "rus");
	ifstream file; // —“¬Œ–ﬁ™ÃŒ Œ¡™ “  À¿—” ifstream
	file.open("Master.txt"); // ¬≤ƒ –»¬¿™ÃŒ ‘¿…À
	ofstream record("Master1.txt", ios::out);
	ofstream rec("Master2.txt", ios::out);
	ofstream write("MasterSort.txt", ios::out);
	file >> s;
	string str;

	int n;
	n = s * 4;

	//¬≤ƒ –»““ﬂ ‘¿…À” “¿ «◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ (1.txt)
	if (!file)
	{
		cout << "‘‡ÈÎ ÌÂ ÓÚÍ˚Ú\n\n";
		//return -1;
	}
	else
	{
		cout << "¬ÒÂ Œ ! ‘‡ÈÎ ÓÚÍ˚Ú!\n\n";
	}

	//œ≈–ÿ»… ƒ»Õ¿Ã≤◊Õ»… Ã¿—»¬
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

	//¬≤ƒ –»““ﬂ ‘¿…À” “¿ «◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ (Buffer.txt)
	ifstream buffer; // —“¬Œ–ﬁ™ÃŒ Œ¡™ “  À¿—” ifstream
	buffer.open("Master1.txt"); // ¬≤ƒ –»¬¿™Ã ‘¿…À
	if (!buffer)
	{
		cout << "‘‡ÈÎ ÌÂ ÓÚÍ˚Ú\n\n";
	}
	else
	{
		cout << "¬ÒÂ Œ ! ‘‡ÈÎ Buffer ÓÚÍ˚Ú!\n\n";
	}

	//ƒ–”√»… ƒ»Õ¿Ã≤◊Õ»… Ã¿—»¬
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


	//—Œ–“”¬¿ÕÕﬂ œ≤ƒ«¿œ»—≤¬ «¿ ≤Õƒ≈ —ŒÃ
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

	//–¿’”™ÃŒ  ≤À‹ ≤—“‹ –ﬂƒ ≤¬ √–”œŒ¬¿Õ»’ ƒ¿Õ»’
	//int nLines = AmountOfDataMasterSort((char*)"MasterSort.txt");
	//cout << "--> pcsTableSortMaster -->" << pcsTableSortMaster << endl;
	//cout << "--> count -->"<< nLines/domen << endl;

}

//-----------------------------------------------

//—Œ–“”¬¿ÕÕﬂ œ≤ƒ«¿œ»—≤¬ ƒÀﬂ ¬»¬≈ƒ≈ÕÕﬂ Õ¿ ≈ –¿Õ
void DataSortingSlave()
{
	string index;
	cout << "¬¬≈ƒ≤“‹ ID ƒÀﬂ √–”œ”¬¿ÕÕﬂ SLAVE ƒ¿Õ»’ «¿ ≤Õƒ≈ —ŒÃ" << endl;
	cin >> index;

	int s;// ≤À‹ ≤—“‹ Õ¿¡Œ–≤¬ ƒ¿Õ»’ ” ‘¿…À≤
	int domen = 4;// ≤À‹ ≤—“‹ —“Œ¬¡÷≤ ” “¿¡À»÷≤
	setlocale(LC_ALL, "rus");
	ifstream file; // —“¬Œ–ﬁ™ÃŒ Œ¡™ “  À¿—” ifstream
	file.open("Slave.txt"); // ÓÚÍ˚‚‡ÂÏ Ù‡ÈÎ
	ofstream record("Slave1.txt", ios::out);
	ofstream rec("Slave2.txt", ios::out);
	ofstream write("SlaveSort.txt", ios::out);
	file >> s;
	string str;

	int n;
	n = s * 5;

	//¬≤ƒ –»““ﬂ ‘¿…À” “¿ «◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ (1.txt)
	if (!file)
	{
		cout << "‘‡ÈÎ ÌÂ ÓÚÍ˚Ú\n\n";
		//return -1;
	}
	else
	{
		cout << "¬ÒÂ Œ ! ‘‡ÈÎ ÓÚÍ˚Ú!\n\n";
	}

	//œ≈–ÿ»… ƒ»Õ¿Ã≤◊Õ»… Ã¿—»¬
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

	//¬≤ƒ –»““ﬂ ‘¿…À” “¿ «◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ (Buffer.txt)
	ifstream buffer; // —“¬Œ–ﬁ™ÃŒ Œ¡™ “  À¿—” ifstream
	buffer.open("Slave1.txt"); // ¬≤ƒ –»¬¿™Ã ‘¿…À
	if (!buffer)
	{
		cout << "‘‡ÈÎ ÌÂ ÓÚÍ˚Ú\n\n";
	}
	else
	{
		cout << "¬ÒÂ Œ ! ‘‡ÈÎ Buffer ÓÚÍ˚Ú!\n\n";
	}

	//ƒ–”√»… ƒ»Õ¿Ã≤◊Õ»… Ã¿—»¬
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


	//—Œ–“”¬¿ÕÕﬂ œ≤ƒ«¿œ»—≤¬ «¿ ≤Õƒ≈ —ŒÃ
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

//¬¬Œƒ»Ã»Œ ƒ¿ÕÕ≤ ƒÀﬂ œ≤ƒÀ≈√À»’ «¿œ»—≤¬ ¬–”◊Õ”---
void DataEntrySlave()
{
	//¬¬Œƒ»ÃŒ ƒ¿Õ≤ ¬–”◊Õ”
	//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
	int _ID;
	string _NAMEBOOK;
	string _AUTHOR;
	string _GENRE;
	string _LANGUAGE;
	int n;

	cout << "¬¬≈ƒ≤“‹  ≤À‹ ≤—“‹ ƒ¿Õ»’:";
	cin >> n;

	//¬≤ƒ –»¬¿™ÃŒ ¡”‘≈–Õ»… ‘¿…À “¿ «¿œ»—”™ÃŒ ¬ Õ‹Œ√Œ ƒ¿Õ≤
	ofstream recordSlave("BufferSlave.txt", ios::app);
	if (recordSlave)
	{
		recordSlave << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "¬¬≈ƒ≤“‹ ID --> ";
			cin >> _ID;

			cout << "¬¬≈ƒ≤“‹ NAMEBOOK --> ";
			cin >> _NAMEBOOK;

			cout << "¬¬≈ƒ≤“‹ AUTHOR -- > ";
			cin >> _AUTHOR;

			cout << "¬¬≈ƒ≤“‹ GENRE -- > ";
			cin >> _GENRE;

			cout << "¬¬≈ƒ≤“‹ LANGUAGE -- > ";
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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	recordSlave.close();
}
//----------------------------------------------

//«◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ ƒÀﬂ œ≤ƒÀ≈√À»’ «¿œ»—≤¬--------
void DataReadingSlave(string fileName)
{
	//«◊»“”¬¿ÕÕﬂ ƒ¿Õ»’ ≤« ‘¿…À”

	ifstream readingSlave(fileName);
	ofstream recordSlave("BufferSlave.txt", ios::out);

	if (readingSlave)
	{
		if (recordSlave)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n;

			//«◊»“”™ÃŒ ƒ¿Õ≤ ≤« ‘¿…À”

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
			cout << "ƒ¿Õ≤ «◊»“¿Õ≤!" << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–¿!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	readingSlave.close();
	recordSlave.close();
}
//-----------------------------------------------

//«¡≈–≈∆≈ÕÕﬂ ƒ¿Õ»’ SLAVE-------------------------------
void SaveDataSlave(string fileName)
{
	//«¡≈–≈∆≈ÕÕﬂ ƒ¿Õ»’
	ifstream readingSlave("BufferSlave.txt");
	ofstream recordSlave(fileName, ios::out);

	if (readingSlave)
	{
		if (recordSlave)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
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
			cout << "ƒ¿Õ≤ «¡≈–≈∆≈ÕÕŒ ” ‘¿…À≤! --> " << fileName << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À¿!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	recordSlave.close();
	readingSlave.close();

}
//-----------------------------------------------

//Œ◊»Ÿ≈ÕÕﬂ ƒ¿Õ»’ ƒÀﬂ SLAVE ‘¿…À”----------------
bool DataCleaningSlave()
{
	//Œ◊»Ÿ≈ÕÕﬂ ¡”‘≈–¿

	bool clear = false;

	//¬≤ƒ –»¬¿™Ã ‘¿…À
	fstream _bufSlave("BufferSlave.txt", ios::out);

	if (!_bufSlave)
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	//Œ◊»Ÿ”™ÃŒ
	_bufSlave.clear();

	//œ≈–≈¬≤– ¿, ŸŒ ‘¿…À Œ◊»Ÿ≈ÕŒ
	if (_bufSlave.peek() == EOF)
		clear = true;
	else
		clear = false;

	_bufSlave.close();

	return clear;
}
//----------------------------------------------

//¬»¬Œƒ»ÃŒ ¬—≤ ƒ¿Õ≤-----------------------------
void PrintAll()
{
	ifstream reading("Master.txt");
	ifstream read("Slave.txt");

	if (reading)
	{
		//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
		int _ID;
		string _NAME;
		string _PASSWORD;
		string _EMAIL;
		int n;

		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "“¿¡À»÷ﬂ Œ—ÕŒ¬Õ»’ «¿œ»—≤¬ MASTER FILE:" << endl;
		reading >> n;
		cout << " ≤À‹ ≤—“‹ ƒ¿Õ»’ MASTER FILE:" << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "ƒ¿Õ≤ œ–Œ ID" << i + 1 << endl;

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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;
	//œ≤ƒÀ≈√À≤ «¿œ»—»

	if (read)
	{
		//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
		int _ID;
		string _NAMEBOOK;
		string _AUTHOR;
		string _GENRE;
		string _LANGUAGE;
		int n;

		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "////////////////////////////////////////////////////////////////" << endl;
		cout << "“¿¡À»÷ﬂ œ≤ƒÀ≈√À»’ «¿œ»—≤¬ SLAVE FILE:" << endl;
		read >> n;
		cout << " ≤À‹ ≤—“‹ ƒ¿Õ»’ SLAVE FILE:" << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "ƒ¿Õ≤ œ–Œ ID" << i + 1 << endl;

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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	reading.close();
	read.close();
}
//-----------------------------------------------


//¬»¬Œƒ»ÃŒ MASTER ƒ¿Õ≤ √–”œŒ¬¿Õ≤-----------------------------
void PrintMasterSort()
{
	ifstream reading("MasterSort.txt");

	if (reading)
	{
		//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
		string _ID;
		string _NAME;
		string _PASSWORD;
		string _EMAIL;

		int domen = 4;
		//–¿’”™ÃŒ  ≤À‹ ≤—“‹ –ﬂƒ ≤¬ √–”œŒ¬¿Õ»’ ƒ¿Õ»’
		int inLine = AmountOfDataMasterSort((char*)"MasterSort.txt");
		int p = inLine / domen;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << " ≤À‹ ≤—“‹ ƒ¿Õ»’ MASTER:" << p << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;

		for (int i = 0; i < p; i++)
		{
			//cout << "ƒ¿Õ≤ œ–Œ ID ----" << _ID << endl;

			reading >> _ID;
			cout << "ƒ¿Õ≤ œ–Œ ID ----" << _ID << endl;
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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	reading.close();
}
//-----------------------------------------------

//¬»¬Œƒ»ÃŒ SLAVE ƒ¿Õ≤ √–”œŒ¬¿Õ≤-------------------
void PrintMasterSlave()
{
	ifstream reading("SlaveSort.txt");

	if (reading)
	{
		//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
		int _ID;
		string _NAMEBOOK;
		string _AUTHOR;
		string _GENRE;
		string _LANGUAGE;

		int domen = 5;
		//–¿’”™ÃŒ  ≤À‹ ≤—“‹ –ﬂƒ ≤¬ √–”œŒ¬¿Õ»’ ƒ¿Õ»’
		int inLine = AmountOfDataSlaveSort((char*)"SlaveSort.txt");
		int p = inLine / domen;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;
		cout << " ≤À‹ ≤—“‹ ƒ¿Õ»’ SLAVE:" << p << endl;
		cout << "///////////////////////////////////////////////////////////" << endl;

		for (int i = 0; i < p; i++)
		{
			//cout << "ƒ¿Õ≤ œ–Œ ID" << i + 1 << endl;

			reading >> _ID;
			cout << "ƒ¿Õ≤ œ–Œ ID ----" << _ID << endl;
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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	reading.close();
}
//-----------------------------------------------

// ≤À‹ ≤—“‹ √–”œŒ¬¿Õ»’ ƒ¿Õ»’ MASTERSORT--------------------------------
int AmountOfDataMasterSort(char* filename)
{
	// 1. Œ·˙ˇ‚ËÚ¸ ˝ÍÁÂÏÔÎˇ F, ÍÓÚÓ˚È Ò‚ˇÁ‡Ì Ò Ù‡ÈÎÓÏ filename.
	// ‘‡ÈÎ ÓÚÍ˚‚‡ÂÚÒˇ ‰Îˇ ˜ÚÂÌËˇ ‚ ÚÂÍÒÚÓ‚ÓÏ ÙÓÏ‡ÚÂ.
	ifstream F(filename, ios::in);
	// 2. œÓ‚ÂÍ‡, ÒÛ˘ÂÒÚ‚ÛÂÚ ÎË Ù‡ÈÎ
	if (!F)
	{
		return -1;
	}

	// 3. ¬˚˜ËÒÎËÚ¸ ÍÓÎË˜ÂÒÚ‚Ó ÒÚÓÍ ‚ Ù‡ÈÎÂ
	// 3.1. Œ·˙ˇ‚ËÚ¸ ‰ÓÔÓÎÌËÚÂÎ¸Ì˚Â ÔÂÂÏÂÌÌ˚Â
	int count = 0;
	char buffer[1000]; // ·ÛÙÂ ‰Îˇ ÒÓı‡ÌÂÌËˇ Ó‰ÌÓÈ ÒÚÓÍË

	// 3.2. ÷ËÍÎ ˜ÚÂÌËˇ ÒÚÓÍ.
	//  ‡Ê‰‡ˇ ÒÚÓÍ‡ Ù‡ÈÎ‡ ˜ËÚ‡ÂÚÒˇ ÙÛÌÍˆËÂÈ getline().
	// œÓ‚ÂÍ‡ ÍÓÌˆ‡ Ù‡ÈÎ‡ ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÙÛÌÍˆËÂÈ eof().
	while (!F.eof())
	{
		// ”‚ÂÎË˜ËÚ¸ Ò˜ÂÚ˜ËÍ ÒÚÓÍ
		count++;

		// —˜ËÚ‡Ú¸ Ó‰ÌÛ ÒÚÓÍÛ ‚ ·ÛÙÂ
		F.getline(buffer, 1000);
	}
	// 4. «‡Í˚Ú¸ Ù‡ÈÎ F
	F.close();
	// 5. ¬ÂÌÛÚ¸ ÂÁÛÎ¸Ú‡Ú
	return count;
}
//-----------------------------------------------

// ≤À‹ ≤—“‹ √–”œŒ¬¿Õ»’ ƒ¿Õ»’ MASTERSORT--------------------------------
int AmountOfDataSlaveSort(char* filename)
{
	// 1. Œ·˙ˇ‚ËÚ¸ ˝ÍÁÂÏÔÎˇ F, ÍÓÚÓ˚È Ò‚ˇÁ‡Ì Ò Ù‡ÈÎÓÏ filename.
	// ‘‡ÈÎ ÓÚÍ˚‚‡ÂÚÒˇ ‰Îˇ ˜ÚÂÌËˇ ‚ ÚÂÍÒÚÓ‚ÓÏ ÙÓÏ‡ÚÂ.
	ifstream F(filename, ios::in);
	// 2. œÓ‚ÂÍ‡, ÒÛ˘ÂÒÚ‚ÛÂÚ ÎË Ù‡ÈÎ
	if (!F)
	{
		return -1;
	}

	// 3. ¬˚˜ËÒÎËÚ¸ ÍÓÎË˜ÂÒÚ‚Ó ÒÚÓÍ ‚ Ù‡ÈÎÂ
	// 3.1. Œ·˙ˇ‚ËÚ¸ ‰ÓÔÓÎÌËÚÂÎ¸Ì˚Â ÔÂÂÏÂÌÌ˚Â
	int count = 0;
	char buffer[1000]; // ·ÛÙÂ ‰Îˇ ÒÓı‡ÌÂÌËˇ Ó‰ÌÓÈ ÒÚÓÍË

	// 3.2. ÷ËÍÎ ˜ÚÂÌËˇ ÒÚÓÍ.
	//  ‡Ê‰‡ˇ ÒÚÓÍ‡ Ù‡ÈÎ‡ ˜ËÚ‡ÂÚÒˇ ÙÛÌÍˆËÂÈ getline().
	// œÓ‚ÂÍ‡ ÍÓÌˆ‡ Ù‡ÈÎ‡ ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÙÛÌÍˆËÂÈ eof().
	while (!F.eof())
	{
		// ”‚ÂÎË˜ËÚ¸ Ò˜ÂÚ˜ËÍ ÒÚÓÍ
		count++;

		// —˜ËÚ‡Ú¸ Ó‰ÌÛ ÒÚÓÍÛ ‚ ·ÛÙÂ
		F.getline(buffer, 1000);
	}
	// 4. «‡Í˚Ú¸ Ù‡ÈÎ F
	F.close();
	// 5. ¬ÂÌÛÚ¸ ÂÁÛÎ¸Ú‡Ú
	return count;
}
//-----------------------------------------------

//¬»ƒ¿À≈ÕÕﬂ ƒ¿Õ»’--------------------------------
void DeleteDataSlave()
{
	//¬»ƒ¿À≈ÕÕﬂ ƒ¿Õ»’

	//«¿œ¿Ãﬂ“Œ¬”™ÃŒ ƒ¿Õ≤
	//œ≈–≈«¿œ»—”™ÃŒ ” ¬»’≤ƒÕ»… ¡”‘≈–
	//Œ –≤Ã ¬»ƒ¿Àﬂ™ÃŒ√Œ

	CopySlave();

	ifstream reading("BufferSlave_.txt");
	ofstream record("BufferSlave.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n, _n;

			//«◊»“”™ÃŒ « ¡”‘≈–ÕŒ√Œ ‘¿…À¿ ” ÕŒ¬»…
			reading >> n;
			int b = n - 1;
			cout << "Œ¡≈–≤“‹ ÕŒÃ≈– ≈À≈Ã≈Õ“¿, ŸŒ «Ã≤Õﬁ™ÃŒ (¬≤ƒ 1 ƒŒ " << n << "):";
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
				cout << "ƒ¿Õ≤ ¬»ƒ¿À≈Õ≤!" << endl;
			}
			else
				cout << "ÕŒÃ≈– ¬≈ƒ≈ÕŒ Õ≈ ¬≤–ÕŒ!" << endl;
		}
		else
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”" << endl;

	record.close();
	reading.close();

	remove("BufferSlave_.txt");
}
//-----------------------------------------------

//¬»¬Œƒ»ÃŒ ƒ¿Õ≤----------------------------------
void PrintSlave()
{
	ifstream reading("BufferSlave.txt");

	if (reading)
	{
		//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
		int _ID;
		string _NAMEBOOK;
		string _AUTHOR;
		string _GENRE;
		string _LANGUAGE;
		int n;

		reading >> n;
		cout << " ≤À‹ ≤—“‹ ƒ¿Õ»’:" << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "ƒ¿Õ≤ œ–Œ ID" << i + 1 << endl;

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
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;

	//«¿ –»““ﬂ ‘¿…À”
	reading.close();
}
//-----------------------------------------------

// Œœ≤ﬁ¬¿ÕÕﬂ ƒ¿Õ»’------------------------------
void CopySlave()
{
	// Œœ≤ﬁ¬¿ÕÕﬂ ƒŒ ÕŒ¬√Œ ‘¿…À”
	ifstream reading("BufferSlave.txt");
	ofstream record("BufferSlave_.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//“»Ã◊¿—Œ¬≤ «Ã≤ÕÕ≤
			int _ID;
			string _NAMEBOOK;
			string _AUTHOR;
			string _GENRE;
			string _LANGUAGE;
			int n;

			//«◊»“”™ÃŒ « ¡”‘≈–ÕŒ√Œ ‘¿…À” “¿ ¬ ÕŒ¬»…
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
			cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ‘¿…À”!" << endl;
	}
	else
		cout << "œŒÃ»À ¿ ¬≤ƒ –»““ﬂ ¡”‘≈–ÕŒ√Œ ‘¿…À”!" << endl;

	record.close();
	reading.close();
}
//-----------------------------------------------



