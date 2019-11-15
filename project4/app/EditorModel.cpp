// EditorModel.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"

EditorModel::EditorModel()
{
	row = column = size = 1;
	eMessage = "";
	vec.push_back("");
}


int EditorModel::cursorLine() const
{
    return row;
}


int EditorModel::cursorColumn() const
{
    return column;
}


int EditorModel::lineCount() const
{
    return size;
}


const std::string& EditorModel::line(int lineNumber) const
{
    return vec.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return eMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	eMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
	eMessage = "";
}

void EditorModel::setposition(int x, int y)
{
	row = x;
	column = y;
}

void EditorModel::movement(int x, int y, int z, int c)
{
	if (x==0)
	{
		if (column+y == 0)
		{
			row--;
		    column = vec.at(row-1).length()+1;
		}
		else if (column+y == vec.at(row-1).length()+2)
    	{
	    	row++;
	    	column = 1;
	    }
	    else
	    	column += y;
	}
	else
	{
		if (z==0)
		{
			if (x==-1 && vec.at(row-2).length()<column)
				column = vec.at(row-2).length()+1;
			else if (x==1 && vec.at(row).length()<column)
				column = vec.at(row).length()+1;
			else
				column += y;
		}
		else
			column = c;
		row += x;
	}
}


bool EditorModel::check_end()
{
	return column == vec.at(row-1).length()+1;
}


bool EditorModel::check_bottom()
{
	return row == vec.size();
}


void EditorModel::home_end(int x)
{
	if (x==0)
		column = 1;
	else
    	column = vec.at(row-1).length()+1;
}


void EditorModel::insert_character(char& x)
{
	if (vec.at(row-1)=="")
	{
		vec.at(row-1) = x;
	}
	else
	{
		if (column <= vec.at(row-1).length()-1)
		{
			std::string s(1,x);
			vec.at(row-1).insert(column-1, s);
		}
		else
		{
			for (unsigned int i=1; i < column-vec.at(row-1).length(); i++)
			{
				vec.at(row-1)+=" ";
		    }
		    vec.at(row-1) += x;
		}
	}
	column ++;
}

char EditorModel::returnchar(int x,int y)
{
	return vec.at(x-1)[y-2];
}


void EditorModel::new_line()
{
	vec.insert(vec.begin()+row,vec.at(row-1).substr(column-1,-1));
	vec.at(row-1) = vec.at(row-1).substr(0,column-1);
	row++;
	column = 1;
	size++;
}

void EditorModel::redo_newline(int x, int y)
{
	vec.at(x-1) = vec.at(x-1)+vec.at(x);
	vec.erase(vec.begin()+x);
	row--;
	column = y;
	size--;
}


void EditorModel::backspace()
{
	if (column==1)
	{
		column = vec.at(row-2).length()+1;
		vec.at(row-2) = vec.at(row-2)+ vec.at(row-1);
		vec.erase(vec.begin()+row-1);
		row--;
		size--;
	}
	else
	{
		std::string s = vec.at(row-1).substr(0,column-2)+vec.at(row-1).substr(column-1,-1);
		vec.at(row-1) = s;
		column --;
	}
}

void EditorModel::undo_backspace(char& x)
{
	std::string y;
	y = vec.at(row-1).substr(column-1,-1);
	vec.insert(vec.begin()+row,y);
	vec.at(row) = y;
	vec.at(row-1) = vec.at(row-1).substr(0,column-1);
	column=1;
	size++;
	row++;
}

void EditorModel::delete_line()
{
	if (row == 1 && size == 1)
	{
		vec.at(row-1) = "";
		column = 1;
	}
	else
	{
		vec.erase(vec.begin()+row-1);
		if (row < size)
		{
			if (column > vec.at(row-1).length())
				column = vec.at(row-1).length()+1;
		}
		else if (row == size)
		{
			if (column > vec.at(row-2).length())
				column = vec.at(row-2).length()+1;
			row--;
		}
		size--;
	}
}

std::string EditorModel::returnline(int x)
{
	return vec.at(x-1);
}

void EditorModel::redo_deleteline(std::string x, int y, int z)
{
	if (row == 1 && column ==1 && returnline(1)=="")
	{
		vec.at(0)=x;
	}
	else
	{
		vec.insert(vec.begin()+z-1,x);
		size++;
    }
    column = y;
	row = z;
}