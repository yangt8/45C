#ifndef UNDO_HPP
#define UNDO_HPP

#include "EditorModel.hpp"
#include "Command.hpp"
#include <vector>
#include <iostream>

class Undo
{
public:
	void save(Command* command);
	Command* pop();
	void del();
	void clear();

private:
	std::vector<Command*> undovec;

};



#endif 
