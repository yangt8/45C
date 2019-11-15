#ifndef CURSOREND_HPP
#define CURSOREND_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class CursorEnd : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		r = model.cursorLine();
	    c = model.cursorColumn();
		model.home_end(1);
	}


	virtual void undo(EditorModel& model) override
	{
		model.setposition(r,c);
	}

private:
	int r,c;

};


#endif