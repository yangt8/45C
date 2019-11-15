
#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class CursorRight : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		if (model.check_end() && model.check_bottom())
			throw EditorException("Already at end");
		else
			model.movement(0,1,0,0);
	}


	virtual void undo(EditorModel& model) override
	{
		model.movement(0,-1,0,0);
	}

private:

};


#endif