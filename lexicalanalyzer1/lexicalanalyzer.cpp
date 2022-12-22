#include <iostream>
#include <map>
#include <ctype.h>
#include "lexicalanalyzer.h"
#include <map>

map<string, TOKEN*> words;

int main(){                     //This is the lexical analyzer
    string input = "2+abs2 +42+3";
    int peek=0;
    TOKEN* t;

    reserve("true",new WORDV(TRUE,"true"));
    reserve("false",new WORDV(FALSE,"false"));

    while(peek < input.size()){
        t = ScanToken(input, &peek);
        t->printContent();
    }

    //flushing the words
    cout <<endl<<"------words---------"<<endl;
    while(!words.empty()){
        (words.begin())->second->printContent();
        free(words.begin()->second);
        words.erase(words.begin());
    }
    return 0;
}

TOKEN* ScanToken(string input, int* peek){
    TOKEN* t;

    while(*peek<input.length()){
        if(input[*peek]==' '|| input[*peek]=='\t')
            (*peek)++;
        else if(input[*peek]=='\n')
            (*peek)++;
        else
            break;
    }
    
    if(isdigit(static_cast<unsigned char>(input[*peek]))){        
        int v = 0;
        do {
            v = v*10 + ((int)input[*peek] - 48); // digits in ASCII code begins with 48. That is, '0'...'9' --> 49 ... 58
            (*peek)++;
        } while(isdigit(static_cast<unsigned char>(input[*peek])));
        t = new Num(v);
        return t;        
    }

    else if(isalpha(input[*peek])){
        string s;
        do{
            s.push_back(input[*peek]);
            (*peek)++;
        }while(isalpha(input[*peek])||isdigit(static_cast<unsigned char>(input[*peek])));

        map<string, TOKEN*>::iterator existing = words.find(s);
        if(existing != words.end()){
            return existing->second;
        } 
        t = new Word(ID, s);
        reserve(s, t); 
        return t;
    }
    else{
        t = new Token((int)(input[*peek]));
        (*peek)++;
        return  t;
    }
    return t;
}

void reserve(string s, TOKEN* t){
    words[s] = t;
    return;
}