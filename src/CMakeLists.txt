include_directories (.)

add_custom_command(	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/Turing.g.d_parser.cpp 
					COMMAND /usr/local/bin/make_dparser ${CMAKE_CURRENT_SOURCE_DIR}/Turing.g -v -Xcpp)

set(MySources 
	BasicScopes.cpp 
	Executor.cpp 
	Message.cpp 
	Scope.cpp 
	ScopeManager.cpp 
	StdLib.cpp 
	TuringType.cpp 
	TypeManager.cpp 
	Turing.g.d_parser.cpp
	ast.cpp 
	codegen.cpp 
	language.cpp 
	main.cpp
	)

set(MyHeaders
	BasicScopes.h 
	Executor.h 
	Message.h 
	Scope.h 
	ScopeManager.h 
	TuringType.h 
	TypeManager.h 
	VarDecl.h 
	ast.h 
	codegen.h 
	language.h
	)

set_source_files_properties( ${MySources}
                             PROPERTIES COMPILE_FLAGS ${LLVM_COMPILE_FLAGS}
                            )

add_executable(compiler ${MySources} ${MyHeaders})
set_target_properties(compiler PROPERTIES LINK_FLAGS ${LLVM_LDFLAGS})
target_link_libraries(compiler ${LLVM_LIBS} -ldparse)