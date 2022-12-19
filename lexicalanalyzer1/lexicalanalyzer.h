#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

#define NUM 256
#define ID 257
#define TRUE 258
#define FALSE 259

using namespace std; 

class Token{
    public:
        int tag;
        int value;
        string lexeme;

        Token(int t){
            tag = t;
            value = 0;
            lexeme = "";
        }
};

class Num:Token{
    public:
        Num(int v):Token(NUM){
            value = v;
        }
};

class Word:Token{
    public:
        Word(int t, string s):Token(t){
            lexeme = s;
        }
};

typedef Token TOKEN;
TOKEN ScanToken(string input, int* peek);