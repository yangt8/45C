
#ifndef DELETELINE_HPP
#define DELETELINE_HPP
#include "Command.hpp"
#include "EditorModel.hpp"

class DeleteLine : public Command
{
public:
	virtual void execute(EditorModel& model) override
	{
		if (model.cursorColumn()  == 1 && model.cursorLine() == 1 && model.lineCount() ==1 && model.returnline(1)=="")
		{
	    	throw EditorException("Already empty");
	    }
	    else
	    {
	        c = model.cursorColumn();
	        r = model.cursorLine();
	        x = model.returnline(r);
	    	model.delete_line();
	    }
	}

	virtual void undo(EditorModel& model) override
	{
		model.redo_deleteline(x, c, r);
	}

private:
	int c,r;
	std::string x;

};


#endif
