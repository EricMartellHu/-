#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Identity.h"
#include"globalFile.h"
#include"orderFile.h"
using namespace std;


class Teacher : public Identity {
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);

	//�˵�����
	void operMenu();

	//�鿴ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ����
	int m_EmpId;
};