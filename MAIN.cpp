#include <iostream>
using namespace std;
#include "date.h"



ofstream fout("output.txt");

ifstream& operator>>(ifstream&aaa, date& ttpro){
	int a, b, c;
	aaa >> a >> b >> c;
	ttpro.set(a, b, c, fout);
	return aaa;

};//?


ofstream& operator<<(ofstream&bbb, date& ttpro){
	int a, b, c;
	bbb << ttpro.day << " " << ttpro.month << "  " << ttpro.year;
	return bbb;

};//?


int main()
{
	
	ifstream fin;
	fin.open("input.txt");
	date a[4];
	for (int i = 0; i < 4; i++)
	{
		fin >> a[i];
		
	}
	fout << "cac ngay ke tiep la :\n";
	for (int i = 0; i < 3; i++)
	{
		a[i].ShowTomorrow(fout);
	}
}