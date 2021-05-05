#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;

class Identity {
public:
	
	virtual void operMenu() = 0;
	
	string m_Name;
	string m_Pwd;
};