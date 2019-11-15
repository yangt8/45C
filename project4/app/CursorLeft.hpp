
#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP
#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"

class CursorLeft : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		if (model.cursorColumn()  == 1 && model.cursorLine() == 1)
		{
	    	throw EditorException("Already at beginning");
	    }
	    else
	    	model.movement(0,-1,0,0);
	}

	virtual void undo(EditorModel& model) override
	{
		model.movement(0,1,0,0);
	}

private:

};


#endif