#pragma once

//о╡дйкчвеммъ бя╡у менау╡дмху а╡ак╡нрей
#include <iostream>//онрнйх ббндс ╡ бхбндс
#include <fstream>//гвхрсбюммъ ╡г тюикю рю гюохя с тюик 
#include <string>//ярпнйх
#include <Windows.h>//дкъ яхярелмху тсмйж╡и
#include <list>
#include<iterator>
#include <vector>

using namespace std;

//опнрнрхох тсмйж╡и
void DataInitialization();//╡м╡ж╡юк╡гюж╡ъ дюмху
void DataEntry();//ббндхлн дюм╡ бпсвмс
void DataReading(string fileName);//гвхрсбюммъ дюмху
void Print();//бхбндхлн дюм╡
bool DataCleaning();//нвхыс╙лн дюмм╡
void DataChange();//гл╡мч╙лн дюм╡
void Copy();//йно╡ч╙лн дюм╡
int AmountOfData();//й╡кэй╡ярэ дюмху
void DeleteData();//бхдюкеммъ дюмху
void AddData();//днднбюммъ дюмху
void SaveData(string fileName);//гаепефеммъ дюмху
//.................SLAVE.........................................................
void DataInitializationSlave();//╡м╡ж╡юк╡гюж╡ъ дюмху дкъ о╡донпъдйнбюмху рюакхжэ
void DataSortingMaster();//янпрсбюммъ гюохя╡б MASTER дкъ бхбедеммъ мю ейпюм
void DataSortingSlave();//янпрсбюммъ о╡дгюохя╡б SLAVE дкъ бхбедеммъ мю ейпюм
void DataEntrySlave();//ббндхлхн дюмм╡ дкъ о╡дкецкху гюохя╡б бпсвмс
void DataReadingSlave(string fileName);//гвхрсбюммъ дюмху дкъ о╡дкецкху гюохя╡б
void SaveDataSlave(string fileName);// гаепефеммъ дюмху дкъ SLAVE
bool DataCleaningSlave();//нвхыеммъ дюмху дкъ SLAVE тюикс
void PrintAll();// бхбнде мю ейпюм бяч аюгс дюмху
void PrintMasterSort();//янпрс╙ MASTER тюикх гю ╡мдейянл
void PrintMasterSlave();//янпрс╙ SLAVE тюикх гю ╡мдейянл
int AmountOfDataMasterSort(char* filename);//о╡дпюунбс╙лн й╡кэй╡ярэ пъдй╡б с MASTER тюик╡
int AmountOfDataSlaveSort(char* filename);//о╡дпюунбс╙лн й╡кэй╡ярэ пъдй╡б с SLAVE тюик╡
void DeleteDataSlave();//бхдюкъ╙лн о╡дкецк╡ гюохях с SLAVE тюик╡
void PrintSlave();//бхбндхлн SLAVE дюм╡
void CopySlave();//йно╡чбюммъ SLAVE дюмху