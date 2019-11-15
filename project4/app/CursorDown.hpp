#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class CursorDown : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		if (model.check_bottom())
			throw EditorException("Already at bottom");
		else
			c = model.cursorColumn();
			model.movement(1,0,0,0);
	}


	virtual void undo(EditorModel& model) override
	{
		model.movement(-1,0,1,c);
	}

private:
	int c;
};


#endif