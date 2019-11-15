// InvisibleEditorView.hpp
//
// ICS 45C Winter 2019
// Project #4: People Just Want to Play with Words
//
// A derived class of EditorView, which has empty implementations of all of
// its virtual member functions.  Setting up BooEdit with an InvisibleEditorView
// will result in a version of BooEdit that displays no user interface, which is
// exactly what you want if you're going to unit test parts of BooEdit.
//
// DO NOT MODIFY THIS FILE

#ifndef INVISIBLEEDITORVIEW_HPP
#define INVISIBLEEDITORVIEW_HPP

#include "EditorView.hpp"



class InvisibleEditorView : public EditorView
{
public:
    virtual void start() override { }
    virtual void stop() override { }
    virtual void refresh() override { }
};



#endif // INVISIBLEEDITORVIEW_HPP

