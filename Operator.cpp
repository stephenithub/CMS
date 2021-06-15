#include "Operator.h"
#include "info.h"
#include<vector>
#include<iostream>
#include "Input.h"
#include "fileHelp.h"
using namespace std;
vector<Info> per;
Input input;

string con_name 		= "姓名：";
string con_sex  		= "性别 （1.男 2.女）：";
string con_tel 			= "电话：";
string con_qq 			= "QQ：";
string con_address 		= "地址：";
string con_label 		= "关系（1.亲人、2.朋友、3.同学）：";

string con_out_sex      = "性别";
string con_out_label    = "关系";


FileHelp fileHelp;

/**
* 增加联系人
*/
void Operator::insert() {
	Info tmp;
	vector<Info>::iterator it;
loop:
	tmp.SetName(input.requestInput(con_name));
	for(it = per.begin(); it != per.end(); ++it) {
		if(!((it->GetName()).compare(tmp.GetName()))) {
			cout << "\n与已有联系人重名，请重新输入。" << endl;
			goto loop;
		}
	}
	tmp.setSex(this->getSexFromKeyboard());
	tmp.SetTel(input.requestInput(con_tel));
	tmp.setQQ(input.requestInput(con_qq));
	tmp.SetAddr(input.requestInput(con_address));
	tmp.setLabel( this->getLabelFromKeyboard());

	per.push_back(tmp);

	cout << "\n添加成功！是否继续添加联系人 y/n ：";
	char ch;
	cin >> ch;
	if('y' == ch || 'Y' == ch) {
		goto loop;
	}
}

//遍历
void Operator::iterator_info(vector<Info> per) {
	if(!per.empty()) {
		vector<Info>::iterator it;
		for(it = per.begin(); it != per.end(); ++it) {
			print_current_info(it);
		}
	}
}

void Operator::show() {
	if(per.empty() ) {
		cout <<endl;
		cout << "\n通讯录暂无联系人！" << endl;
	} else {
		

//		分类显示 亲人
		vector<Info> per_lovers;

//		分类显示 朋友
		vector<Info> per_friends;

//		分类显示 同学
		vector<Info> per_classmates;

		for(int i = 0; i < per.size(); i++) {
			string temp_label = per[i].getLabel();

			if(!temp_label.compare("亲人")) {
				per_lovers.push_back(per[i]);
			} else if(!temp_label.compare("朋友")) {
				per_friends.push_back(per[i]);
			} else {
				per_classmates.push_back(per[i]);
			}
		}
		vector<Info>::iterator it;
		
		cout <<endl;
		this->print_title_info() ;
		cout << "----------------------------------------------------------------------" <<endl;

		if(!per_lovers.empty()) {
//			cout <<endl;
			for(it = per_lovers.begin(); it != per_lovers.end(); ++it) {
				print_current_info(it);
			}
		}

		if(!per_friends.empty()) {
			cout <<endl;
			for(it = per_friends.begin(); it != per_friends.end(); ++it) {
				print_current_info(it);
			}
		}

		if(!per_classmates.empty()) {
			cout <<endl;
			for(it = per_classmates.begin(); it != per_classmates.end(); ++it) {
				print_current_info(it);
			}
		}
		char ch = input.requestInputChar("\n请按任意键退出" );
	}
}

void Operator::search() {
	vector<Info>::iterator it;
	if(per.empty()) {

		cout << "\n通讯录暂无联系人！" << endl;

	} else {

search_loop:
		string tn; //查找的姓名
		int flag = 0; //查找成功与否标志位
		cout << "请输入查找的姓名：";
		cin >> tn;
		for(it = per.begin(); it != per.end(); ++it) {
			if(!((it->GetName()).compare(tn))) {
				flag = 1;
				cout << "\n你要找的联系人为：" <<endl;
				this->print_title_info();
				print_current_info(it);
			}
		}


		if(0 == flag) {
			cout << "无找到此联系人" << endl;
		} else {
			cout << "查找成功"  << endl;
		}
		char ch = input.requestInputChar("\n请按任意键退出" );
	}
}

void Operator::delete_info() {
	if(per.empty()) {
		cout << "\n通讯录暂无联系人！" << endl;
	}
	vector<Info>::iterator it;

delete_loop:
	int flag = 0; //删除成功与否标志位
	string name = input.requestInput("请输入要删除的姓名：");
	for(it = per.begin(); it != per.end(); ++it) {
		if(!((it->GetName()).compare(name))) {
			flag = 1;
			break;
		}
	}
	if(0 == flag) {
		cout << "\n没有找到此联系人" << endl;
	} else {
		cout << "\n你要删除的联系人为：" <<endl;
		this->print_title_info();
		print_current_info(it);

		cout << "确定删除此联系人吗？y/n : ";
		char ch1;
		cin >> ch1;
		if (ch1 == 'y' || ch1 == 'Y') {
			it = per.erase(it);
			cout << "\n删除成功" << endl;
		}
	}
	char ch = input.requestInputChar("\n请按任意键退出" );
}


void Operator::modify() {
	vector<Info>::iterator it;
	if(per.empty()) {
		cout << "\n通讯录暂无联系人！" << endl;
	} else {
modify_loop:
		int flag2 = 0;
		int flag = 0; //修改对象查找成功与否标志位
		string tn = input.requestInput("请输入要修改的人的姓名：");
		for(it = per.begin(); it != per.end(); ++it) {
			if(!((it->GetName()).compare(tn))) {
				flag = 1;
				break;
			}
		}

		cout << "\n你要修改的联系人为：\n" <<endl;
		this->print_title_info();
		print_current_info(it);
		char ch1 = input.requestInputChar("确定修改此联系人吗？y/n : ");
		if (ch1 == 'y' || ch1 == 'Y') {
			this->modify_contact_info(it);
			this->go_on_modify_contact_info(it);

			cout << "\n修改成功！修改成功后的信息为：" << endl;
			this->print_title_info();
			print_current_info(it);
			cout<<endl;
			flag2 = 1;
		}

		if(0 == flag) {
			cout << "\n没有找到此联系人" << endl;
		}
		if(1 == flag2) {
			cout << "\n修改成功!" << endl;
		}
		char ch = input.requestInputChar("\n请按任意键退出" );
	}
}

void Operator::exit_info() {
	cout << "确定退出此通讯录吗？y/n: " ;
	char ch1;
	cin >> ch1;
	if (ch1 == 'y' || ch1 == 'Y') {
		fileHelp.save_text(per);
		exit(1);
	}
}

void Operator:: print_title_info() {
	cout << con_name << "\t" << con_out_sex <<  "\t"<< con_tel <<  "\t\t"<< con_qq <<  "\t\t"<< con_address << "\t\t"<< con_out_label << endl;
}

//print current info
void Operator::print_current_info(vector<Info>::iterator it) {
	cout << it->GetName()<< "\t" <<it->getSex()<< "\t"<< it->GetTel()<< "\t"<<  it->getQQ() << "\t"<<  it->GetAddr()<< "\t\t"<< it->getLabel() << endl;
}

# include "menu.h"
void Operator::choose() {
	char action;
	Menu menu;
	action = input.requestInputChar("请输入你想实现的功能(1-6)：");
	switch(action) {
		case '1': {
			insert();
			menu.interface();
			choose();
			break;
		}
		case '2': {
			show();
			menu.interface();
			choose();
			break;
		}
		case '3': {
			delete_info();
			menu.interface();
			choose();
		}
		case '4': {
			search();
			menu.interface();
			choose();
			break;
		}
		case '5': {
			modify();
			menu.interface();
			choose();
			break;
		}
		case '6': {
//			fileHelp.save_text(per);
			exit_info();
//			exit(1);
			break;
		}
		default: {
			cout << "\n输入指令有误，请重新输入！" << endl;
			choose();
			break;
		}
	}
}

//get sex from keyboard
string Operator::getSexFromKeyboard() {
	while(true) {
		switch(input.requestInputChar(con_sex)) {
			case '1': {
				return "男";
			}
			case '2': {
				return "女";
			}
			default: {
				cout << "\n输入指令有误，请重新输入！" << endl;
				break;
			}
		}
	}
}

//get label from keyboard
string Operator:: getLabelFromKeyboard() {
	while(true) {
		switch(input.requestInputChar(con_label)) {
			case '1': {
				return "亲人";
			}
			case '2': {
				return "朋友";
			}
			case '3': {
				return "同学";
			}
			default: {
				cout << "\n输入指令有误，请重新输入！" << endl;
				break;
			}
		}
	}
}

Operator::Operator() {
	fileHelp.read_text(per);
}
Operator::~Operator() {
	fileHelp.save_text(per);
}

void Operator::modify_contact_info(vector<Info>:: iterator it) {
	while(true) {
		switch(input.requestInputChar( "你要修改的是：1.姓名 2.性别 3.电话 4.QQ 5.地址 6.关系类型 \n")) {
			case '1': {
				it->SetName(this->request_input_name());
				return;
			}
			case '2': {
				it->setSex(this->getSexFromKeyboard());
				return;
			}
			case '3': {
				it->SetTel(input.requestInput(con_tel));
				return;
			}
			case '4': {
				it->setQQ(input.requestInput(con_qq));
				return;
			}
			case '5': {
				it->SetAddr(input.requestInput(con_address));
				return;
			}
			case '6': {
				it->setLabel(this->getLabelFromKeyboard());
				return;
			}
			default : {
				cout << "\n指令输入错误！" << endl;
				break;
			}

		}
	}
}

void Operator:: go_on_modify_contact_info(vector<Info>::iterator it) {

	while(true) {
		char ch_mf = input.requestInputChar("继续修改此联系人信息？y/n：");
		if(ch_mf != 'y' && ch_mf != 'Y') {
			return;
		}
		this->modify_contact_info(it);
	}
}

string Operator:: request_input_name() {
	while(true) {
		bool flag = false;
		string name1 = input.requestInput(con_name);
		vector<Info>::iterator it;
		for(it = per.begin(); it != per.end(); ++it) {
			if(!((it->GetName()).compare(name1))) {
				cout << "\n与已有联系人重名，请重新输入。" << endl;
				flag = true;
			}
		}
		if(!flag) {
			return name1;
		}
	}
}

