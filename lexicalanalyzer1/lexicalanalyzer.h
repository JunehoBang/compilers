#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

#define NUM 256
#define ID 257
#define TRUE 258
#define FALSE 259

class Token{
    public:
        int tag;
        Token(){tag = t;}
};

class Num:Token{
    public:
        int value;
        Num(int v){
            tag = NUM;
            value = v;
            }
    
};

class Word:Token{
    public:
        string lexeme;
        Word(string s){
            lexeme = s;
        }
};

