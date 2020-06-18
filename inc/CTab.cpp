#include "CTab.h"

using namespace std;

void CTab::v_copy(const CTab &cOther)
{
    pi_tab = new int[cOther.i_size]; i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++) pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)

CTab::CTab(const CTab &cOther)
{
    v_copy(cOther);
    std::cout << "Copy ";
}//CTab::CTab(const CTab &cOther)

CTab::~CTab()
{
    if (pi_tab != NULL) delete pi_tab;
    std::cout << "Destr ";
}//CTab::~CTab()

CTab CTab::operator=(const CTab &cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    std::cout << "op= ";
    return(*this);
}//CTab CTab::operator=(const CTab &cOther)

CTab* CTab::operator=(CTab &&cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    cout << "op= MOVE ";
    return this;
} //CTab operator=(const CTab &&cOther)

CTab::CTab(CTab &&cOther)
{
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    cout << "MOVE ";
} //CTab::CTab(CTab &&cOther)

bool CTab::bSetSize(int iNewSize)
{
    if (iNewSize < 1) return false;
    if (iNewSize == i_size) return false;

    delete pi_tab;
    pi_tab = new int[iNewSize];
    i_size = iNewSize;

    return true;
} //bool CTab::bSetSize(int iNewSize)


