#ifndef FILEHELP_H
#define FILEHELP_H
#include "info.h"
#include<vector>
#include "Operator.h"

class FileHelp {
	public:
		FileHelp();
		~FileHelp();
		void read_text(vector<Info> &per);
		void save_text(vector<Info> per);
		void backup_contacts(vector<Info> per);
	protected:
};

#endif
