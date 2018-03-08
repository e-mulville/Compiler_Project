#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_statement.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_declarations.hpp"
#include "ast/ast_jumps.hpp"
#include "ast/ast_assignments.hpp"
#include "ast/ast_controls.hpp"
#include "ast/ast_logics.hpp"
#include "ast/ast_operations.hpp"


extern const Statement *parseAST();

#include <string>
#include <iostream>
#include <fstream>
#endif
