#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Info {
	private:
		string name;
		string sex; 
		string tel;
		string qq;
		string address;
		string label;
		
	public:
		Info();
Info(string name, string sex, string tel, string qq, string address, string label);
		~Info();

		void SetName(string name);
		string GetName();

		void setSex(string sex);
		string getSex();

		void SetTel(string tel);
		string GetTel();

		void setQQ(string qq);
		string getQQ();

		void SetAddr(string address);
		string GetAddr();


		void setLabel(string label);
		string getLabel();
		
		void setInfoData( string name, string sex, string tel, string qq, string address, string label);
		
		friend ostream & operator<<(ostream & output, Info &); 
		friend istream & operator >>(istream & input, Info &); 
};

#endif

