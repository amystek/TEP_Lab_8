#ifndef LAB_8_CTABLE_H
#define LAB_8_CTABLE_H

#include <iostream>
#include <string>

using namespace std;

const string DEFAULT_VALUE = "default name value";
const int DEFAULT_LENGTH = 5;

class CTable
{
public:
    CTable();
    CTable(string sName, int iTableLen);
    CTable (CTable &pcOther);
    ~CTable();
    void vSetName(string sName);
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();
    int i_getTableSize();
    void vPrint();
    void vSetValueAt(int iOffset, int iNewVal);
    int iGetValue(int iOffset);
    CTable* operator=(CTable &&pcOther);
    CTable operator+(CTable pcOther);

private:
    string s_name;
    int i_tab_length;
    int* pi_table;
}; //class CTable


#endif //LAB_8_CTABLE_H
