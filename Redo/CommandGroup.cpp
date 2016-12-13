//
//  CommandGroup.cpp
//  Redo
//
//  Created by wangyue on 2016/12/13.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#include "CommandGroup.hpp"
CommandGroup::~CommandGroup() {
    for ( auto command : commands ) {
        delete command;
    }
}

void CommandGroup::add( Command* command ) {
    commands.push_back( command );
}


void CommandGroup::execute() {
    for ( unsigned int i=0; i < commands.size(); i++ ) {
        commands[ i ]->execute();
    }
}


void CommandGroup::undo() {
    for ( unsigned int i=0; i < commands.size(); i++ ) {
        commands[ i ]->undo();
    }
}
