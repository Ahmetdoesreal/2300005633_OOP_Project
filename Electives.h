#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif 
#ifndef E_EXTENSION
#define E_EXTENSION
class Electives :public OnlineCourse {
private:
	bool Departmental;
	string Origin[2];//index 0 which dep. index 1=prefix

public:
	void changeRate(int ratei)override;
	void giverating(int ratei)override;
	bool checkPrefixID(string checkprefix, int checkid);
	Electives();

	Electives(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string origini, string prefixi, bool depi);
	void displayInfo() override;
	bool addStudent() override;
	int checkCapacity() override;
	//int getCalculatedID() override;
};

#endif 