#include <iostream>
#include <map>
#include "lexicalanalyzer.h"


int main(){                     //This is the lexical analyzer
    string input = "2+a+42+3";
    int peek=0;
    TOKEN t(0);

    while(peek < input.size()){
        t = ScanToken(input, &peek);
        if(t.tag == NUM)
            cout << "<NUM," <<  t.value << ">"<<endl;
        else if(t.tag == ID)
            cout << "<ID," << t.lexeme << ">"<<endl;
        else 
            cout << "<" <<  char(t.tag) << ">"<<endl;
    }  

    return 0;
}

TOKEN ScanToken(string input, int* peek){
    TOKEN t(1);
    cout<<*peek<<"test2";
    while(*peek<input.length()){
        if(input[*peek]==' '|| input[*peek]=='\t')
            *peek++;
        else if(input[*peek]=='\n')
            *peek++;
        else
            break;
    }
    while(isdigit(static_cast<unsigned char>(input[*peek]))
    {
        )
        cout<<input[*peek];
        *peek++;
    }
    return t;
}