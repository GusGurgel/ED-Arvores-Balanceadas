#ifndef _GTABLE_H_
#define _GTABLE_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> //ceil e floor
//acentuação
#include <locale>
#include <codecvt>

#include "gdate.h" //typedef uint

using std::string;
using std::cout;
using std::endl;
using std::vector;


// ------------{ showRepeat }------------
// > Mostra uma string repetidas 
// > vezes no termial
// >
// > str = "string repetida"
// > times = "quantidade de repetições"
// --------------------------------------
void showRepeat(string str, int times);

// ------------{ showRepeat }------------
// > Retorna um string feita pela repe-
// > petição de outra string.
// > 
// > str = "string repetida"
// > times = "quantidade de repetições"
// --------------------------------------
string strRepeat(string, int);

// ------------{ fillString }------------
// > Retorna uma string cirada do preen-
// > chimento de outra string. Lembrando
// > que esse preenchimento é feito com
// > caracteres vaios e a string é cen-
// > tralizada.
// > 
// > exemplo de retorno:
// > parâmetros: str="gustavo", length=10
// > retorno = "  gustavo "
// > 
// > str = "string que vai ser preenchida"
// > length = "tamanho esperado"
// --------------------------------------
string fillString(string str, int length);

// ------------{ strLenght }------------
// > Essa função vem para tentar resol-
// > ver problemas de tamanho de strings
// > com caracteres especiais e acentua-
// > ção. Por exemplo, usando o método
// > size da tipo string na string literal
// > "Mário" o retono é igual a 6. Porque
// > ele considera o caractere á como sendo
// > dois. A função strLenght resolve isso,
// > pois ela converte a string em uma
// > wstring.
// >
// > str = "string para calcular tamanho"
// --------------------------------------
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