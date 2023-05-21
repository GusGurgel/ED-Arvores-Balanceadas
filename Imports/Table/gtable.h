#ifndef _GTABLE_H_
#define _GTABLE_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> //ceil e floor
//acentuação
#include <locale>
#include <codecvt>


using std::string;
using std::cout;
using std::endl;
using std::vector;

typedef unsigned int uint;

void showRepeat(string, int);

string strRepeat(string, int);

string repeatStr(string, int);

string fillString(string, int);

//Pega o tamho de uma string desconsiderando
//problemas de acentuação
uint strLenght(string);

struct tableStyle{
    string horizontalLine;
    string verticalLine;

    string leftUpEdge;
    string leftDownEdge;

    string rightUpEdge;
    string rightDownEdge;

    string leftUpDownEdge;
    string rightUpDownEdge;

    string leftRightDownEdge;
    string leftRightUpEdge;

    string fullEdge;
};

class GTable {
public:
    GTable(uint padding);

    addRow(vector<string>);

    void show();
private:
    tableStyle sty;               //Estilo de tabela
    uint tableMaxLength;
    int padding;
    
    vector<vector<string>> table; //Tabela de strings
    vector<uint> lengths;         //Tabela de tamanhos horizontais 

    void showTopLine();            //Fazer linha de topo
    void showConnectLine();         //Fazer linha do meio da tabela
    void showMiddle();             //Fazer meio da tabela
    void showDownLine();           //Fazer linha de baixo
};

#endif