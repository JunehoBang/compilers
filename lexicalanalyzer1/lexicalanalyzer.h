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

        Token(){tag = 0;}
        Token(int t){
            tag = t;
        //     value = 0;
        //     lexeme = "";
        }
        virtual void printContent(){
            cout << "<" << (char)tag << "> ";
        }
};

class Num : public Token{
    public:
        int value;

        Num(int v):Token(NUM){
            value = v;
        }
        void printContent(){
            cout <<"<NUM," << value << "> ";
        }
};

class Word : public Token{
    public:
        string lexeme;

        Word(int t, string s):Token(t){
            lexeme = s;
        }
        void printContent(){
            cout<< "<ID," << lexeme << "> ";
        }

};

typedef Token TOKEN;
typedef Num NUMV;
typedef Word WORDV;
TOKEN* ScanToken(string input, int* peek);
void reserve(string s, TOKEN* t);