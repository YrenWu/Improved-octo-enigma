#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void checkLexeme(string line)
{
    cout << line << endl;
}

void read(string filename) 
{
  ifstream file(filename);
  string line; 
  if (file.is_open()) {
  	while (getline(file, line)) {
  	  checkLexeme(line);
  	}
  	file.close();
  } else {
  	cout << "Error reading file. Please check the file name" << endl;
  }
}

int main(int argc, char *argv[]) 
{
  string filename;
  if (argc > 1) {
	filename = argv[1];
	read(filename);
  } else {
	cout << "No file specified. Please enter an input file" << endl;
  }
}
