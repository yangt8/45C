#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class CursorHome : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		r = model.cursorLine();
	    c = model.cursorColumn();
		model.home_end(0);
	}


	virtual void undo(EditorModel& model) override
	{
		model.setposition(r,c);
	}

private:
	int r,c;
};

#endif