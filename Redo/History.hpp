//
//  History.hpp
//  Redo
//
//  Created by wangyue on 2016/12/13.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#ifndef History_hpp
#define History_hpp

#include <stdio.h>
#include <vector>

class Command;

class History {
    
private:
    
    std::vector<Command*> history;
    int lastExecuted;
    int lastSaved;
    
public:
    
    History();
    ~History();
    
    void clear();
    void save();
    bool modified();
    void limit( unsigned int numCommands );
    void add( Command* command, bool execute );
    void revert();
    void undo();
    void redo();
    
};

#endif /* History_hpp */
