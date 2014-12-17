#include <fstream>
using namespace std;
#include "checker.h"
class date:
	protected checker
{
private:
	int day;
	int month;
	int year;
	checker* mycheck;
	bool valid(int d, int m, int y);
	bool leapYear(int y);
	friend ifstream& operator>>(ifstream&, date&);//?
	friend ofstream& operator<<(ofstream&, date&);//?
public:
	date();
	bool set(int d,int m,int y,ofstream& fout);
	void Show();
	void ShowTomorrow(ofstream& fout);
	void ShowYesterday(ofstream& fout);
};