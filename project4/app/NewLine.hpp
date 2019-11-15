#ifndef NEWLINE_HPP
#define NEWLINE_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class NewLine : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		r = model.cursorLine();
	    c = model.cursorColumn();
		model.new_line();
	}

	virtual void undo(EditorModel& model) override
	{
		model.redo_newline(r,c);
	}

private:
	int r,c;
};


#endif