// KeypressInteractionReader.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "InsertCharacter.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "NewLine.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"
// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'I':
                return Interaction::command(new CursorUp());
            case 'K':
                return Interaction::command(new CursorDown());
            case 'U':
                return Interaction::command(new CursorLeft());
            case 'O':
                return Interaction::command(new CursorRight());
            case 'Y':
                return Interaction::command(new CursorHome());
            case 'P':
                return Interaction::command(new CursorEnd());
            case 'J':
                return Interaction::command(new NewLine());
            case 'M':
                return Interaction::command(new NewLine());
            case 'H':
                return Interaction::command(new Backspace());
            case 'D':
                return Interaction::command(new DeleteLine());
            case 'Z':
                return Interaction::undo();
            case 'A':
                return Interaction::redo();
            default:
                break;
            }
        }
        else
        {
            return Interaction::command(new InsertCharacter(keypress.code()));
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
        }
    }
}

