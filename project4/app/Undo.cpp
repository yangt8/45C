#include "Undo.hpp"


void Undo::save(Command* command)
{
	undovec.push_back(command);
}



Command* Undo::pop()
{
	if (undovec.size()!=0)
		return undovec.at(undovec.size()-1);
	else
		return nullptr;
}


void Undo::del()
{
	if (undovec.size()!=0)
	{
    	undovec.pop_back();
	}
}

void Undo::clear()
{
	for (unsigned int i=0; i<undovec.size();i++)
	{
		delete undovec.at(i);
	}
}