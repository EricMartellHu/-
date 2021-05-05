#include<iostream>
#include<fstream>
#include<string>
#include"Identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;


void studentMenu(Identity * &student) {
	while (true) {
		//学生菜单
		student->operMenu();
		Student * stu = (Student*)student; //stu类指针指向student
		int select = 0;
		cin >> select;

		if (select == 1) { //申请预约
			stu->applyOrder();
		}
		else if (select == 2) { //查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3) { //查看所有预约
			stu->showAllorder();
		}
		else if (select == 4) { //取消预约
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity * &teacher){

	while (true) {
		//教师菜单
		teacher->operMenu();
		Teacher * tea = (Teacher*)teacher;
		int select = 0;
	    cin >> select;

		if (select == 1) {
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

void managerMenu(Identity * &manager) {
	while (true){
		manager->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Manager * man = (Manager*)manager; 

		int select = 0;
		cin >> select;

		if (select == 1) { //添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) { //查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) { //查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if(select == 4){ // 清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}


	}
}

//登录功能
void LoginIn(string fileName, int type) {
	//父类指针指向子类
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" <<endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) { //学生
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if(type == 2){
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名"<<endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生认证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd){
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if(type == 2){
		 //教职工认证 
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师身份的子菜单
				TeacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进入管理员身份的子菜单
				managerMenu(person);


				return;
			}
		}

	}

	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");

	return;

}

int main() {
	while (true){
		int select = 0;
		cout << "=====================欢迎来到机房预约系统=====================" << endl;
		cout <<endl<<"请输入您的身份" << endl;
		cout << "\t\t -------------------------" << endl;
		cout << "\t\t |       1.学生代表      |" << endl;
		cout << "\t\t |                       |" << endl;
		cout << "\t\t |       2.老    师      |" << endl;
		cout << "\t\t |                       |" << endl;
		cout << "\t\t |       3.管理员        |" << endl;
		cout << "\t\t |                       |" << endl;
		cout << "\t\t |       0.退出          |" << endl;
		cout << "\t\t |                       |" << endl;
		cout << "\t\t -------------------------" << endl;
		cout << "输入您的选择" << endl;
		
		cin >> select;

		switch (select){
		case 1:  //学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！"<<endl;
			system("pause");
			system("cls");
			break;
		}

	}


	system("pause");

}