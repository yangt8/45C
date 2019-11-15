#include "Redo.hpp"


void Redo::save(Command* command)
{
	redovec.push_back(command);
}


Command* Redo::pop()
{
	if (redovec.size()!=0)
		return redovec.at(redovec.size()-1);
	else
		return nullptr;
}


void Redo::del()
{
	if (redovec.size()!=0)
	{
    	redovec.pop_back();
	}
}

void Redo::clear()
{
	for (unsigned int i=0; i<redovec.size();i++)
	{
		delete redovec.at(i);
	}
}