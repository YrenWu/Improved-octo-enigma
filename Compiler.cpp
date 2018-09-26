#include "Compiler.h"

using namespace std;

Compiler::Compiler(string filename) 
{
  this->filename = filename;
  LexicalAnalyzer lexical;
  SyntaxicAnalyzer syntaxic;
  SemanticAnalyzer semantic;
}

void Compiler::read(bool verbose) 
{
  ifstream file(this->filename);
  string line;

  if (file.is_open()) {
    int lineNumber = 1;
  	while (getline(file, line)) {
      // Send a line to Lexical Analyzer to build lexemes set
      this->lexical.split(line, lineNumber);
      lineNumber++;
  	}

    bool lexicalErrors = this->lexical.analyze(verbose);
    if(lexicalErrors) {
      cout << "[*] Lexical analysis failed" << endl;
      return;
    }

    cout << "[*] Lexical analysis ended with success" << endl;
    vector<Lexeme*> vLexemes = this->lexical.getLexemes();

    // Start syntaxic analysis
    bool syntaxicErrors = this->syntaxic.analyze(vLexemes);

    // TODO

  	file.close();
  } else {
  	cout << "Error reading file. Please check the file name" << endl;
  }
}
