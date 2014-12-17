
#include "date.h"
#include <iostream>
using namespace std;
#include <time.h> //? 
date::date()
{
	mycheck = new checker();

}
bool date::set(int d, int m, int y, ofstream &fout)
{
	
	if (!mycheck->check()) return false;
	if (valid(d, m, y))
	{
		day = d;
		month = m;
		year = y;
		if (leapYear(y)) fout << day << " " << month << " " << year << " Nam nhuan \n"; else { fout << day << " " << month << " " << year << " Khong Nam nhuan \n"; };
	}
	else
	{

		fout<< d << " " << m << " " << y << " Ngay khong hop le \n";
		return false;

	}
	return true;
}

bool date::valid(int d, int m, int y)
{
	if ((d < 1) || (m < 1) || (y < 1)) return false;
	if (m > 12) return false;
	if (m == 2)
	{
		if (leapYear(y))
		{
			if (d > 29) return false;
		}
		else
		{
			if (d>28) return false;
		}
	}
	if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
	{
		if (d > 31) return false;
	}
	else
		if (d > 30) return false;
	return true;
}

bool date::leapYear(int y)
{
	if (y % 4 != 0)
		return false;
	else
		if (y % 100 == 0)
			return true;
		else if (y % 400 != 0)
			return false;
		else return true;
}


void date::Show()
{
	cout << day << "/" << month << "/" << year;
}


void date::ShowTomorrow(ofstream& fout)
{

	if (valid(day + 1, month, year))
	{
		fout << day + 1 << "/" << month << "/" << year;
	}
	else
		if (valid(1, month + 1, year))
		{
			fout << 1 << "/" << month + 1 << "/" << year;
		}
		else
			fout << 1 << "/" << 1 << "/" << year + 1;
	fout << endl;
}

void date::ShowYesterday(ofstream& fout)
{
	if (valid(day - 1, month, year))
	{
		cout << day - 1 << "/" << month << "/" << year;
		cout << endl;
		return;
	}

	if (month == 1)
	{
		cout << 31 << "/" << 12 << "/" << year - 1;
		cout << endl;
		return;
	}

	int d;
	int m = month - 1;
	int y = year;
	if (m == 2)
	{
		if (leapYear(y))
			//if (d > 29) return false;
			d = 29;
		else
			d = 28;
	}
	if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
	{
		d = 31;
	}
	else
		d = 30;

	fout << d << "/" << m << "/" << year;


	fout << endl;
}