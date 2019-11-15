#ifndef CURSORUP_HPP
#define CURSORUP_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class CursorUp : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		if (model.cursorLine() == 1)
		{
	    	throw EditorException("Already at top");
	    }
	    else
	    	c = model.cursorColumn();
	    	model.movement(-1,0,0,0);
	}


	virtual void undo(EditorModel& model) override
	{
		model.movement(1,0,1,c);
	}

private:
	int c;

};


#endif