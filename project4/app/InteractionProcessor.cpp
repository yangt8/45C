// InteractionProcessor.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include "Undo.hpp"
#include "Redo.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    Undo undo_v = Undo();
    Redo redo_v = Redo();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            Command* p = undo_v.pop();
            try
            {
                if (p!=nullptr)
                {
                    undo_v.del();
                    p -> undo(model);
                    redo_v.save(p);
                }
                else
                    delete p;
                model.clearErrorMessage();
            }
            catch (...)
            {
                delete p;
            }
            view.refresh();

        }
        else if (interaction.type() == InteractionType::redo)
        {
            Command* p = redo_v.pop();
            try
            {
                if (p!=nullptr)
                {
                    redo_v.del();
                    p -> execute(model);
                    undo_v.save(p);
                }
                else
                    delete p;
                model.clearErrorMessage();
            }
            catch (...)
            {
                delete p;
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                undo_v.save(command);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            //delete command;
        }
    }

    undo_v.clear();
    redo_v.clear();
}

