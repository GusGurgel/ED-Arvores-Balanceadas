#include "gtable.h"

void showRepeat(string str, int times){
    for(int i = 0; i < times; i++){
        cout << str;
    }
}
string strRepeat(string str, int times){
    string ret = "";
    
    for(int i = 0; i < times; i++){
        ret += str;
    }

    return ret;
}

uint strLenght(string str){
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring s = converter.from_bytes(str);
    return s.size();
}

GTable::GTable(uint padding){
    //Define o tipo de tabela padrão
    this->sty = tableStyle {
        "─", //horizontalLine
        "│", //verticalLine

        "┘", //leftUpEdge
        "┐", //leftDownEdge

        "└", //rightUpEdge
        "┌", //rightDownEdge

        "┤", //leftUpDownEdge
        "├", //rightUpDownEdge

        "┬", //leftRightDownEdge
        "┴", //leftRightUpEdge

        "┼"  //fullEdge
    };

    this->tableMaxLength = 0;
    this->padding = 2*padding;
}


GTable::addRow(vector<string> row){
    if(row.size() > tableMaxLength){
        tableMaxLength = row.size();
    }
    
    if(row.size() > lengths.size()){
        int timesToAdd = row.size()-lengths.size();
        for(int i = 0; i < timesToAdd; i++){
            lengths.push_back(0);   
        }   
    }

    for(int i = 0; i < row.size(); i++){
        if(row[i].size() > lengths[i]){
            lengths[i] = row[i].size();
        }
    }

    this->table.push_back(row);
}

void GTable::showTopLine(){
    int size = lengths.size();

    for(int i = 0; i < size; i++){
        //make first
        if(i == 0){
            cout << sty.rightDownEdge;
            showRepeat(sty.horizontalLine, lengths[i]+padding);
            cout << (size == 1 ? sty.rightDownEdge : sty.leftRightDownEdge);  
        }
        //make last
        else if(size > 1 && i == size-1){
            showRepeat(sty.horizontalLine, lengths[i]+padding);
            cout << sty.leftDownEdge;
        }else{
            showRepeat(sty.horizontalLine, lengths[i]+padding);
            cout << sty.leftRightDownEdge;
        }
    }
    cout << endl;
}

void GTable::showDownLine(){
    int size = lengths.size();

    for(int i = 0; i < size; i++){
        //make first
        if(i == 0){
            cout << sty.rightUpEdge;
            showRepeat(sty.horizontalLine, lengths[i]+padding);
            cout << (size == 1 ? sty.rightUpEdge : sty.leftRightUpEdge);  
        }
        //make last
        else if(size > 1 && i == size-1){
            showRepeat(sty.horizontalLine, lengths[i]+padding);
            cout << sty.leftUpEdge;
        }else{
            showRepeat(sty.horizontalLine, lengths[i]+padding);
            cout << sty.leftRightUpEdge;
        }
    }
}

void GTable::showMiddle(){
    uint rowLen = table.size();
    uint cont = 0;

    cout << std::setfill(' ');

    for(vector<string>& curRow : table){
        for(int j = 0; j < tableMaxLength; j++){
            cout << sty.verticalLine;
            if(j < curRow.size()){
                // cout << std::setw(lengths[j]+padding);
                cout << fillString(curRow[j], lengths[j]+padding);
            }else{
                showRepeat(" ", lengths[j]+padding);
            }
        }
        cout << sty.verticalLine;
        cout << endl;
        if(cont != table.size()-1){
            showConnectLine();
            cout << endl;
        }
        cont++;
    }
}

void GTable::showConnectLine(){
    cout << sty.rightUpDownEdge;
    for(int i = 0; i < lengths.size(); i++){
        showRepeat(sty.horizontalLine, lengths[i]+padding);
        if(i < lengths.size()-1){
            cout << sty.fullEdge;
        }
    }
    cout << sty.leftUpDownEdge;
}

void GTable::show(){
    showTopLine();
    showMiddle();
    showDownLine();
}

string fillString(string str, int len){
    string ret = "";
    uint sizeString = strLenght(str);

    if(str.size() >= len){
        return str;
    }

    float spaces = len - sizeString;

    for(int i = 0; i < floor(spaces/2); i++){
        ret += " ";
    }
    ret += str;
    for(int i = 0; i < ceil(spaces/2); i++){
        ret += " ";
    }

    return ret;
}