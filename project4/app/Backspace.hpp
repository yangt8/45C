
#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class Backspace : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		if (model.cursorColumn()  == 1 && model.cursorLine() == 1)
		{
	    	throw EditorException("Already at beginning");
	    }
	    else
	    	r = model.cursorLine();
	        x = model.returnchar(r,model.cursorColumn());
	    	model.backspace();
	}

	virtual void undo(EditorModel& model) override
	{
		if (model.cursorLine()==r)
			model.insert_character(x);
		else
			model.undo_backspace(x);
	}

private:
	char x;
	int r;

};


#endif