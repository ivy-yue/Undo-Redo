//
//  Command.hpp
//  Redo
//
//  Created by wangyue on 2016/12/13.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>

class Command {
    
public:
    
    virtual void execute() = 0;
    
    
    virtual void undo() = 0;
    
    
    virtual ~Command() { }
    
};

#endif /* Command_hpp */
