#include "Operator.h"
#include "info.h"
#include<vector>
#include<iostream>
#include "Input.h"
#include "fileHelp.h"
using namespace std;
vector<Info> per;
Input input;

string con_name 		= "������";
string con_sex  		= "�Ա� ��1.�� 2.Ů����";
string con_tel 			= "�绰��";
string con_qq 			= "QQ��";
string con_address 		= "��ַ��";
string con_label 		= "��ϵ��1.���ˡ�2.���ѡ�3.ͬѧ����";

string con_out_sex      = "�Ա�";
string con_out_label    = "��ϵ";


FileHelp fileHelp;

/**
* ������ϵ��
*/
void Operator::insert() {
	Info tmp;
	vector<Info>::iterator it;
loop:
	tmp.SetName(input.requestInput(con_name));
	for(it = per.begin(); it != per.end(); ++it) {
		if(!((it->GetName()).compare(tmp.GetName()))) {
			cout << "\n��������ϵ�����������������롣" << endl;
			goto loop;
		}
	}
	tmp.setSex(this->getSexFromKeyboard());
	tmp.SetTel(input.requestInput(con_tel));
	tmp.setQQ(input.requestInput(con_qq));
	tmp.SetAddr(input.requestInput(con_address));
	tmp.setLabel( this->getLabelFromKeyboard());

	per.push_back(tmp);

	cout << "\n��ӳɹ����Ƿ���������ϵ�� y/n ��";
	char ch;
	cin >> ch;
	if('y' == ch || 'Y' == ch) {
		goto loop;
	}
}

//����
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
		cout << "\nͨѶ¼������ϵ�ˣ�" << endl;
	} else {
		

//		������ʾ ����
		vector<Info> per_lovers;

//		������ʾ ����
		vector<Info> per_friends;

//		������ʾ ͬѧ
		vector<Info> per_classmates;

		for(int i = 0; i < per.size(); i++) {
			string temp_label = per[i].getLabel();

			if(!temp_label.compare("����")) {
				per_lovers.push_back(per[i]);
			} else if(!temp_label.compare("����")) {
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
		char ch = input.requestInputChar("\n�밴������˳�" );
	}
}

void Operator::search() {
	vector<Info>::iterator it;
	if(per.empty()) {

		cout << "\nͨѶ¼������ϵ�ˣ�" << endl;

	} else {

search_loop:
		string tn; //���ҵ�����
		int flag = 0; //���ҳɹ�����־λ
		cout << "��������ҵ�������";
		cin >> tn;
		for(it = per.begin(); it != per.end(); ++it) {
			if(!((it->GetName()).compare(tn))) {
				flag = 1;
				cout << "\n��Ҫ�ҵ���ϵ��Ϊ��" <<endl;
				this->print_title_info();
				print_current_info(it);
			}
		}


		if(0 == flag) {
			cout << "���ҵ�����ϵ��" << endl;
		} else {
			cout << "���ҳɹ�"  << endl;
		}
		char ch = input.requestInputChar("\n�밴������˳�" );
	}
}

void Operator::delete_info() {
	if(per.empty()) {
		cout << "\nͨѶ¼������ϵ�ˣ�" << endl;
	}
	vector<Info>::iterator it;

delete_loop:
	int flag = 0; //ɾ���ɹ�����־λ
	string name = input.requestInput("������Ҫɾ����������");
	for(it = per.begin(); it != per.end(); ++it) {
		if(!((it->GetName()).compare(name))) {
			flag = 1;
			break;
		}
	}
	if(0 == flag) {
		cout << "\nû���ҵ�����ϵ��" << endl;
	} else {
		cout << "\n��Ҫɾ������ϵ��Ϊ��" <<endl;
		this->print_title_info();
		print_current_info(it);

		cout << "ȷ��ɾ������ϵ����y/n : ";
		char ch1;
		cin >> ch1;
		if (ch1 == 'y' || ch1 == 'Y') {
			it = per.erase(it);
			cout << "\nɾ���ɹ�" << endl;
		}
	}
	char ch = input.requestInputChar("\n�밴������˳�" );
}


void Operator::modify() {
	vector<Info>::iterator it;
	if(per.empty()) {
		cout << "\nͨѶ¼������ϵ�ˣ�" << endl;
	} else {
modify_loop:
		int flag2 = 0;
		int flag = 0; //�޸Ķ�����ҳɹ�����־λ
		string tn = input.requestInput("������Ҫ�޸ĵ��˵�������");
		for(it = per.begin(); it != per.end(); ++it) {
			if(!((it->GetName()).compare(tn))) {
				flag = 1;
				break;
			}
		}

		cout << "\n��Ҫ�޸ĵ���ϵ��Ϊ��\n" <<endl;
		this->print_title_info();
		print_current_info(it);
		char ch1 = input.requestInputChar("ȷ���޸Ĵ���ϵ����y/n : ");
		if (ch1 == 'y' || ch1 == 'Y') {
			this->modify_contact_info(it);
			this->go_on_modify_contact_info(it);

			cout << "\n�޸ĳɹ����޸ĳɹ������ϢΪ��" << endl;
			this->print_title_info();
			print_current_info(it);
			cout<<endl;
			flag2 = 1;
		}

		if(0 == flag) {
			cout << "\nû���ҵ�����ϵ��" << endl;
		}
		if(1 == flag2) {
			cout << "\n�޸ĳɹ�!" << endl;
		}
		char ch = input.requestInputChar("\n�밴������˳�" );
	}
}

void Operator::exit_info() {
	cout << "ȷ���˳���ͨѶ¼��y/n: " ;
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
	action = input.requestInputChar("����������ʵ�ֵĹ���(1-6)��");
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
			cout << "\n����ָ���������������룡" << endl;
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
				return "��";
			}
			case '2': {
				return "Ů";
			}
			default: {
				cout << "\n����ָ���������������룡" << endl;
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
				return "����";
			}
			case '2': {
				return "����";
			}
			case '3': {
				return "ͬѧ";
			}
			default: {
				cout << "\n����ָ���������������룡" << endl;
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
		switch(input.requestInputChar( "��Ҫ�޸ĵ��ǣ�1.���� 2.�Ա� 3.�绰 4.QQ 5.��ַ 6.��ϵ���� \n")) {
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
				cout << "\nָ���������" << endl;
				break;
			}

		}
	}
}

void Operator:: go_on_modify_contact_info(vector<Info>::iterator it) {

	while(true) {
		char ch_mf = input.requestInputChar("�����޸Ĵ���ϵ����Ϣ��y/n��");
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
				cout << "\n��������ϵ�����������������롣" << endl;
				flag = true;
			}
		}
		if(!flag) {
			return name1;
		}
	}
}

