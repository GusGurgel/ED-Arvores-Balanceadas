/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// GTabel (Header file)
//
// Criação:     21 Mai 2023
// Atualização: 26 Mai 2023
//
// Criado Por:
// Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
************************************************/

#ifndef _GTABLE_H_
#define _GTABLE_H_

#include <iostream> //entrada e saida
#include <vector>   //vetores
#include <iomanip>  //manipulação de string
#include <cmath>    //ceil e floor
#include <locale>   //acentuação
#include <codecvt>  //acentuação

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
string fillString(string str, uint length);

// ------------{ strLenght }------------
// > Essa função vem para tentar resol-
// > ver problemas de tamanho de strings
// > com caracteres especiais e acentua-
// > ção. Por exemplo, usando o método
// > size do tipo string na string literal
// > "Mário" o retono é igual a 6. Porque
// > ele considera o caractere á como sendo
// > dois caracteres separados. A função 
// > strLenght resolve isso, retonando o
// > valor esperado.
// >
// > str = "string para calcular tamanho"
// --------------------------------------
uint strLenght(string);

// ------------{ tableStyle }------------
// > Essa struct representa o estilo de
// > uma tabela. Sua existência torna po-
// > ssível alterações estetias na em como
// > as tabelas são mostradas no terminal.
// >
// > str = "string para calcular tamanho"
// ----------------------------------------
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
    GTable(uint padding);  //construtor padrão


    // ---------------{ addRow }---------------
    // > Adiciona uma linha na tabela. Cada 
    // > linha na tabela é representada por
    // > um vetor de strings de tamanho varia-
    // > do.
    // ----------------------------------------
    void addRow(vector<string>);// Adiciona uma linha na table 

    // ---------{ show }--------
    // > Mostra tabela na tela.
    // -------------------------
    void show();
private:
    tableStyle sty;               //Estilo de tabela
    uint tableMaxLength;          //Tamanho do maior vector
    int padding;                  //Espaçamento
    
    vector<vector<string>> table; //Tabela de strings
    vector<uint> lengths;         //Tabela de tamanhos horizontais 

    void showTopLine();            //Fazer linha de topo
    void showConnectLine();        //Fazer linha de conexão
    void showMiddle();             //Fazer meio da tabela
    void showDownLine();           //Fazer linha de baixo
};

#endif