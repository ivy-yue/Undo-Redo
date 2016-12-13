//
//  History.cpp
//  Redo
//
//  Created by wangyue on 2016/12/13.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#include "History.hpp"
#include "Command.hpp"



History::History() : lastExecuted(-1), lastSaved(-1) {
}


History::~History() {
    for ( auto command : history ) {
        delete command;
    }
}


void History::clear() {
    for ( auto command : history ) {
        delete command;
    }
    history.clear();
    lastExecuted = -1;
    lastSaved = -1;
}


void History::save() {
    lastSaved = lastExecuted;
}


bool History::modified() {
    return lastSaved != lastExecuted;
}


void History::limit( unsigned int numCommands ) {
    while ( history.size() > numCommands ) {
        delete history[ 0 ];
        history.erase( history.begin() );
        if ( lastExecuted >= 0 ) {
            lastExecuted--;
        }
        if ( lastSaved >= 0 ) {
            lastSaved--;
        }
    }
}


void History::add( Command* command, bool execute ) {
    if ( lastExecuted + 1 < history.size() ) {
        int count = (int)history.size() - ( lastExecuted + 1 );
        int begin = lastExecuted + 1;
        int end = begin + count;
        
        for ( size_t i=0; i < count; i++ ) {
            delete history[ begin + i ];
        }
        history.erase( history.begin() + begin, history.begin() + end );
        lastSaved = -1;
    }
    
    if ( execute ) {
        command->execute();
    }
    
    history.push_back( command );
    lastExecuted = (int)history.size() - 1;
}


void History::revert() {
    while ( lastExecuted > 0 ) {
        history[ lastExecuted ]->undo();
        lastExecuted--;
    }
}


void History::undo() {
    if ( lastExecuted >= 0 ) {
        if ( history.size() > 0 ) {
            history[ lastExecuted ]->undo();
            lastExecuted--;
        }
    }
}


void History::redo() {
    if ( lastExecuted + 1 < history.size() ) {
        history[ lastExecuted + 1 ]->execute();
        lastExecuted++;
    }
}
