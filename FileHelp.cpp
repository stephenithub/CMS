#include "FileHelp.h"
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include "info.h"
#include "Operator.h"
#include <vector>
#include <ctime>
#include <sys/stat.h>
using namespace std;

string con_name2 		= "����";
string con_sex2  		= "�Ա�";
string con_tel2 		= "�绰";
string con_qq2 			= "QQ";
string con_address2 	= "��ַ";
string con_label2 		= "��ϵ";

FileHelp::FileHelp() {
}

FileHelp::~FileHelp() {
}

string contacts_list_path = "./Contacts_List.txt";
string contacts_list_backup_path = "./Contacts_List_backup.txt";

void FileHelp::read_text(vector<Info> & per) {
	ifstream fin(contacts_list_path.c_str(), ios::in);
	if(fin) {
		char s[100];
		fin.getline(s,100);
		fin.getline(s,100);
		char name[20], sex[20], tel[20], qq[20], address[20], label[20];
		while(fin>>name>>sex>>tel>>qq>>address>>label&&strcmp(name,"Noname")!=0) {
			Info info;
			info.SetName(name);
			info.setSex(sex);
			info.SetTel(tel);
			info.setQQ(qq);
			info.SetAddr(address);
			info.setLabel(label);
			per.push_back(info);
		}
		fin.close();
		struct stat buffer;
		if (!stat (contacts_list_backup_path.c_str(), &buffer) == 0) {
			this->backup_contacts(per); //���α��� 
		}
	}
}

void FileHelp::save_text(vector<Info> per) {
	ofstream fout(contacts_list_path,ios::out);

	if(fout && (!per.empty())) {
		fout << con_name2 << "\t" << con_sex2 <<  "\t\t\t"<< con_tel2 <<  "\t\t\t\t"<< con_qq2 <<  "\t\t\t\t"<< con_address2 << "\t\t\t\t"<< con_label2 << endl;
		fout<<"--------------------------------------------------------------------------------------"<<endl;
		for(int i=0; i<per.size(); i++) {
			fout<<per[i]<<endl;
		}
		fout.close();
	}
	this->backup_contacts(per);
}

void FileHelp::backup_contacts(vector<Info> per) {
	ofstream fout_backup(contacts_list_backup_path.c_str(),ios::app);
	if(fout_backup && (!per.empty())) {
		fout_backup <<"*******************************************ͨѶ¼����*******************************************\n";
		fout_backup<<"--------------------------------------------------------------------------------------"<<endl;
		fout_backup <<con_name2 << "\t" << con_sex2 <<  "\t\t\t"<< con_tel2 <<  "\t\t\t\t"<< con_qq2 <<  "\t\t\t\t"<< con_address2 << "\t\t\t\t"<< con_label2 << endl;
		for(int i=0; i<per.size(); i++) {
			fout_backup<<per[i]<<endl;
		}
		time_t now = time(0);  // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
		char* dt = ctime(&now); // �� now ת��Ϊ�ַ�����ʽ
		fout_backup << "����ʱ�䣺" << dt << endl;
		fout_backup.close();
	}
};



