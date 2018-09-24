#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <fstream>

class Compiler {
  std::string filename;	
  public:
  	Compiler(std::string filename);
	void read();
};

#endif 
