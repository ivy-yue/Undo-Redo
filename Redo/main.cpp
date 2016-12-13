//
//  main.cpp
//  Redo
//
//  Created by wangyue on 2016/12/13.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#include <iostream>
#include "Command.hpp"
#include "CommandGroup.hpp"
#include "History.hpp"

using namespace std;

class TestDocument {
public:
    string text;
    
    void print() const {
        cout << "Document text: " << text << "\n";
    }
};


class TestCommandBase : public Command {
protected:
    TestDocument & document;
    
public:
    TestCommandBase( TestDocument & document ) : document( document ) {
    }
};


class TestCommandAppend : public TestCommandBase {
private:
    string s;
    
public:
    TestCommandAppend( TestDocument & document, string const & s ) : TestCommandBase(document), s(s) {
    }
    
    void execute() {
        document.text += s;
    }
    
    void undo() {
        auto len = document.text.length() - s.length();
        document.text.erase( len );
    }
};

int main() {
    TestDocument document;
    document.text = "Hello, world";
    
    History history;
    
    cout<<"\n*********************Original Text:***********************\n"<<endl;
    document.print();
    
    cout<<"\n\n*******************Appending '!' to Text:****************\n"<<endl;
    history.add( new TestCommandAppend( document, "!" ), true ); // !
    document.print();
    history.add( new TestCommandAppend( document, "!" ), true ); // !!
    document.print();
    history.add( new TestCommandAppend( document, "!" ), true ); // !!!
    document.print();
    
    cout<<"\n\n********************Undo Once:***************************\n"<<endl;
    history.undo(); // !!
    document.print();
    
    cout<<"\n\n********************Redo Once:***************************\n"<<endl;
    history.redo(); // !!!
    document.print();
    
    cout<<"\n\n********************Undo Second Times:*******************\n"<<endl;
    history.undo(); // !!
    history.undo(); // !
    document.print();
    
    cout<<"\n\n*******************Appending 'X' to Text:****************\n"<<endl;
    history.add( new TestCommandAppend( document, "X" ), true ); // !X
    document.print();
    
    cout<<"\n\n*******If I Redo Now, Nothing should be changed**********\n"<<endl;
    history.redo(); // !X
    document.print();
    
    
    cout<<"\n\n********************Undo Once:***************************\n"<<endl;
    history.undo(); // !
    document.print();
    
    cout<<"\n\n********************Undo Once:***************************\n"<<endl;
    history.undo(); //
    document.print();
    
    cout<<"\n\n********************Redo Once:***************************\n"<<endl;
    history.redo(); // !
    document.print();
    
    cout<<"\n\n********************Redo Once:***************************\n"<<endl;
    history.redo(); // !X
    document.print();

    cout<<"\n\n********************Save Once:***************************\n"<<endl;
    history.save(); // !X
    document.print();
    
    cout<<"\n\n********************Redo Once:***************************\n"<<endl;
    history.redo(); // !X
    document.print();
    
    cout<<endl;
    
    
}
