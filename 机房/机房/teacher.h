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
	//默认构造
	Teacher();

	//有参构造
	Teacher(int empId, string name, string pwd);

	//菜单界面
	void operMenu();

	//查看预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//职工号
	int m_EmpId;
};