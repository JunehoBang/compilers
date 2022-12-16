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
        Token(int t){
            tag = t;
        }
};

class Num:Token{
    public:
        int value;
        Num(int v):Token(NUM){
            value = v;
        }
};

class Word:Token{
    public:
        string lexeme;
        Word(int t, string s):Token(t){
            lexeme = s;
        }
};

typedef Token TOKEN;
TOKEN ScanToken(string input, int* peek);