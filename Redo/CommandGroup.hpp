//
//  CommandGroup.hpp
//  Redo
//
//  Created by wangyue on 2016/12/13.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#ifndef CommandGroup_hpp
#define CommandGroup_hpp

#include <stdio.h>
#include <vector>
#include "Command.hpp"

class CommandGroup : public Command {
    
private:
    
    std::vector<Command*> commands;
    
    
public:
    
    ~CommandGroup();
    void add( Command* command );
    void execute();
    void undo();
    
    
};
#endif /* CommandGroup_hpp */
