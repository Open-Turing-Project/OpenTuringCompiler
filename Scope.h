//
//  Scope.h
//  Turing Compiler
//
//  Created by Tristan Hume on 12-02-07.
//  Copyright 2012 15 Norwich Way. All rights reserved.
//

#ifndef Turing_Compiler_Scope_H
#define Turing_Compiler_Scope_H

#include <string>


#include <llvm/Function.h>
#include <llvm/Value.h>

#include "TuringType.h"

//! scope interface
class Scope {
public:
    //! uses resolveVarThis and isDeclared to search up the scope tree
    //! returns the address to be loaded/stored
    virtual llvm::Value *resolve(std::string name);
    virtual bool isDeclared(std::string name);
    
    //! generates a variable declaration and adds it to the symbol table
    virtual llvm::Value *declareVar(std::string name, TuringType *type) = 0;
    //! returns a child scope of the correct type. Used for things like if statements.
    //! I.E global scopes have global children and locals have local children
    virtual Scope *createChildScope() = 0;
    
    Scope *Parent;
protected:
    //! resolves a variable in the current scope only
    virtual llvm::Value *resolveVarThis(std::string name) = 0;
    //! checks if a variable is declared in the current scope only
    virtual bool isDeclaredThis(std::string name) = 0;
    
    Scope(Scope *parent);
};



#endif
