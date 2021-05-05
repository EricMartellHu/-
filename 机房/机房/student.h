#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Identity.h"
#include"globalFile.h"
#include"computerRoom.h"
#include"orderFile.h"
using namespace std;



class Student : public Identity {
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���  ������ѧ�ţ�����������
	Student(int id, string name, string pwd);

	//�˵� 
	void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�Լ���ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllorder();

	//ȡ��ԤԼ 
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;


};