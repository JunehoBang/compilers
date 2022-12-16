#include <iostream>
#include <map>
#include "lexicalanalyzer.h"

TOKEN ScanToken(string input, int* peek);

int main(){                     //This is the lexical analyzer
    string input = "a+42+3";
    int peek=0;
    TOKEN t(0);

    while(peek < input.size()){
        t = ScanToken(input, &peek);
    }  

    return 0;
}

TOKEN ScanToken(string input, int* peek){
    TOKEN t(0);
    return t;    
}