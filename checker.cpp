#include "checker.h"


checker::checker()
{
	source = "https://github.com/ttpro1995/CNTT2-Ca-2";
}


checker::~checker()
{
}

bool checker::check()
{
	if (source != "https://github.com/ttpro1995/CNTT2-Ca-2") return false;
	return true;
}