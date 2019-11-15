
#ifndef INSERTCHARACTER_HPP
#define INSERTCHARACTER_HPP
#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"

class InsertCharacter : public Command
{
public:
	InsertCharacter(char x)
	     :x{x}
	{
	}

	virtual void execute(EditorModel& model) override
	{
		model.insert_character(x);
	}

	virtual void undo(EditorModel& model) override
	{
		if (model.cursorColumn()  == 1 && model.cursorLine() == 1)
		{
	    	throw EditorException("Already at beginning");
	    }
	    else
	    	model.backspace();
	}

private:
	char x;
};


#endif