#ifndef REDO_HPP
#define REDO_HPP

#include "EditorModel.hpp"
#include "Command.hpp"
#include <vector>
#include <iostream>

class Redo
{
public:
	void save(Command* command);
	Command* pop();
	void del();
	void clear();

private:
	std::vector<Command*> redovec;

};



#endif 