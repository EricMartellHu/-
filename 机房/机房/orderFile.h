#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include"globalFile.h"
using namespace std;

class OrderFile {
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������
	map<int, map<string, string> >m_orderData;

	//ԤԼ��¼����
	int m_size;
};