#ifndef OPERATOR_H
#define OPERATOR_H
#include "info.h"
#include<vector>
#include<iostream>

class Operator {
	public:
		
		Operator();
		~Operator();
		
		void choose();
		void insert();
		void show();
		void search();
		void interface();
		void delete_info();
		void exit_info();
		void modify();
		
        void print_title_info();
		void print_current_info(vector<Info>::iterator it);
		string getSexFromKeyboard();
		string getLabelFromKeyboard();
		void iterator_info(vector<Info> per);
		void modify_contact_info(vector<Info>::iterator it);
		void go_on_modify_contact_info(vector<Info>::iterator it);
		string request_input_name();
	protected:
};

#endif
