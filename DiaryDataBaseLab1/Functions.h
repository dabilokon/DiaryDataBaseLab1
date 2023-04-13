#pragma once

//ϲ��������� �Ѳ� ����ղ���� ���˲����
#include <iostream>//������ ����� � ������
#include <fstream>//���������� �� ����� �� ����� � ���� 
#include <string>//������
#include <Windows.h>//��� ��������� ����ֲ�
#include <list>
#include<iterator>
#include <vector>

using namespace std;

//��������� ����ֲ�
void DataInitialization();//�Ͳֲ�˲��ֲ� �����
void DataEntry();//������� ��Ͳ ������
void DataReading(string fileName);//���������� �����
void Print();//�������� ��Ͳ
bool DataCleaning();//����Ӫ�� ���Ͳ
void DataChange();//�̲�ު�� ��Ͳ
void Copy();//��ϲު�� ��Ͳ
int AmountOfData();//ʲ��ʲ��� �����
void DeleteData();//��������� �����
void AddData();//��������� �����
void SaveData(string fileName);//���������� �����
//.................SLAVE.........................................................
void DataInitializationSlave();//�Ͳֲ�˲��ֲ� ����� ��� ϲ������������� �������
void DataSortingMaster();//���������� ����Ѳ� MASTER ��� ��������� �� �����
void DataSortingSlave();//���������� ϲ�����Ѳ� SLAVE ��� ��������� �� �����
void DataEntrySlave();//�������� ���Ͳ ��� ϲ������� ����Ѳ� ������
void DataReadingSlave(string fileName);//���������� ����� ��� ϲ������� ����Ѳ�
void SaveDataSlave(string fileName);// ���������� ����� ��� SLAVE
bool DataCleaningSlave();//�������� ����� ��� SLAVE �����
void PrintAll();// ������ �� ����� ��� ���� �����
void PrintMasterSort();//����Ӫ MASTER ����� �� ��������
void PrintMasterSlave();//����Ӫ SLAVE ����� �� ��������
int AmountOfDataMasterSort(char* filename);//ϲ������Ӫ�� ʲ��ʲ��� ���ʲ� � MASTER ���˲
int AmountOfDataSlaveSort(char* filename);//ϲ������Ӫ�� ʲ��ʲ��� ���ʲ� � SLAVE ���˲
void DeleteDataSlave();//�����ߪ�� ϲ����˲ ������ � SLAVE ���˲
void PrintSlave();//�������� SLAVE ��Ͳ
void CopySlave();//��ϲ������ SLAVE �����