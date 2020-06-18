#include "CTable.h"

CTable::CTable()
{
    s_name = DEFAULT_VALUE;
    i_tab_length = DEFAULT_LENGTH;
    pi_table = new int[DEFAULT_LENGTH];
    cout << "bezp:'" << s_name << "'" << endl;
} //CTable::CTable()

CTable::CTable(string sName, int iTableLen)
{
    if (iTableLen > 0)
    {
        s_name = sName;
        i_tab_length = iTableLen;
        pi_table = new int[iTableLen];
        cout << "parametr:'" << s_name << "'" << endl;
    } //if (iTableLen > 0)
    // przy błędnej długości konstruktor nic nie robi
} //CTable::CTable(string sName, int iTableLen)

CTable::CTable(CTable &pcOther)
{
    s_name = pcOther.s_name + "_copy";
    int i_pcOther_tab_lenght = pcOther.i_tab_length;
    i_tab_length = i_pcOther_tab_lenght;
    pi_table = new int[i_tab_length];
    for (int ix = 0; ix < i_pcOther_tab_lenght; ix++)
    {
        pi_table[ix] = pcOther.pi_table[ix];
    } //for (int ix = 0; ix < i_pcOther_tab_lenght; ix++)
    cout << "kopiuj:'" << s_name << "'" << endl;
} //CTable::CTable(CTable &pcOther)

CTable::~CTable()
{
    delete [] pi_table;
    cout << "usuwam:'" << s_name << "'" << endl;
} //CTable::~CTable()

void CTable::vSetName(string sName)
{
    s_name = sName;
} //void CTable::vSetName(string sName)

bool CTable::bSetNewSize(int iTableLen)
{
    if (iTableLen < 1) return false;
    if (iTableLen == i_tab_length) return false;
    int* pi_tab_tmp = new int[iTableLen];

    bool increase = false;
    if (i_tab_length < iTableLen) increase = true;

    if (!increase)
    {
        for (int ii = 0; ii < iTableLen; ii++)
        {
            pi_tab_tmp[ii] = pi_table[ii];
        } //for (int ii = 0; ii < iTableLen; i++)
    } //if (!increase)

    if (increase)
    {
        for (int ii = 0; ii < i_tab_length; ii++)
        {
            pi_tab_tmp[ii] = pi_table[ii];
        } //for (int ii = 0; ii < i_tab_length; i++)
        for (int ii = i_tab_length; ii < iTableLen; ii++)
        {
            pi_tab_tmp[ii] = -1;
        } //for (int ii = 0; ii < i_tab_length; i++)

    } //if (increase)

    i_tab_length = iTableLen;
    delete [] pi_table;
    pi_table = pi_tab_tmp;
    return true;
} //bool CTable::bSetNewSize(int iTableLen)

CTable *CTable::pcClone()
{
    CTable *pc_tab_clone = new CTable(s_name, i_tab_length);

    pc_tab_clone->vSetName(s_name);
    pc_tab_clone->bSetNewSize(i_tab_length);

    for (int ii = 0; ii < i_tab_length; ii++)
    {
        pc_tab_clone->pi_table[ii] = pi_table[ii];
    } //for (int ii = 0; ii < i_tab_length; ii++)

    return pc_tab_clone;

} //CTable *CTable::pcClone()

int CTable::i_getTableSize()
{
    return i_tab_length;
} //int CTable::i_getTableSize()

void CTable::vPrint()
{
    cout << "CTable size:" << i_tab_length << ", " << s_name << ": ";
    for (int ii = 0; ii < i_tab_length; ii++)
    {
        cout << pi_table[ii] << " ";
    } //for (int ii = 0; ii < i_tab_length; ii++)
    cout << endl;
} //void CTable::vPrint()

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
    if (iOffset >= 0 && iOffset <= i_tab_length)
    {
        pi_table[iOffset] = iNewVal;
    } //if (iOffset < 0 | iOffset > i_tab_length)
} //void CTable::vSetValueAt(int iOffset, int iNewVal)

int CTable::iGetValue(int iOffset)
{
    if (iOffset < i_tab_length)
    {
        return pi_table[iOffset];
    } //if (iOffset < i_tab_length)

    return 0;
} //int CTable::iGetValue(int iOffset)

CTable* CTable::operator=(CTable &&pcOther)
{
    if (pi_table != NULL) { delete pi_table; }
    s_name = pcOther.s_name;
    i_tab_length = pcOther.i_tab_length;
    pi_table = pcOther.pi_table;
    pcOther.pi_table = NULL;

    return this;
} //CTable operator=(CTable pcOther)

CTable CTable::operator+(CTable pcOther)
{
    int i_new_tab_lenght = i_tab_length + pcOther.i_getTableSize();
    CTable c_tab("concatenation", i_new_tab_lenght);

    for (int ii = 0; ii < i_tab_length; ii++)
    {
        c_tab.vSetValueAt(ii, pi_table[ii]);
    } //for (int ii = 0; ii < i_tab_length; ii++)

    for (int ii = i_tab_length; ii < i_new_tab_lenght ; ii++)
    {
        c_tab.vSetValueAt(ii, pcOther.iGetValue(ii - i_tab_length));
    }

    return c_tab;
} //CTable CTable::operator+(CTable pcOther)

