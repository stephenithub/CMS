#include "info.h"

void Info::SetName(string name1) {
	name = name1;
}
string Info::GetName()  {
	string tmp = name;
	return tmp;
}

void Info::setSex(string sex1) {
	sex = sex1;
}
string Info::getSex()  {
	string tmp = sex;
	return tmp;
}

void Info::SetTel(string  tel1) {
	tel = tel1;
}
string Info::GetTel()  {
	string tmp = tel;
	return tmp;
}

void Info::setQQ(string qq1) {
	qq = qq1;
}
string Info::getQQ()  {
	string tmp = qq;
	return tmp;
}

void Info::SetAddr(string address1) {
	address = address1;
}
string Info::GetAddr()  {
	string tmp = address;
	return tmp;
}

void Info::setLabel(string label1) {
	label = label1;
}
string Info::getLabel()  {
	string tmp = label;
	return tmp;
}

Info::Info() {

}

Info::Info(string name1, string sex1, string tel1, string qq1, string address1, string label1) {
	name = name1;
	sex = sex1;
	tel = tel1;
	qq = qq1;
	address = address1;
	label = label1;
}

Info::~Info() {

}

void Info::setInfoData(string name1, string sex1, string tel1, string qq1, string address1, string label1){
	name = name1;
	sex = sex1;
	tel = tel1;
	qq = qq1;
	address = address1;
	label = label1;
}

ostream & operator<<(ostream & output, Info &info) {
	output<<info.GetName()<<"\t"<<info.getSex()<<"\t\t\t"<<info.GetTel()<<"\t\t\t"<<info.getQQ()<<"\t\t\t"<<info.GetAddr()<<"\t\t\t\t"<<info.getLabel()<<endl;
	return output;
}

istream & operator >>(istream &input, Info &info) {
	char name[20], sex[20], tel[20], qq[20], address[20], label[20];
	input>>name>>sex>>tel>>qq>>address>>label;
	info.setInfoData(name, sex, tel, qq, address, label);
	return input;
}


