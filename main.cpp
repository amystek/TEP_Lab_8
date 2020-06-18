#include "main.h"

int main()
{
    i_ms_test();
    return 0;
} //int main()

CTab cCreateTab()
{
    CTab c_result;
    c_result.bSetSize(5);
    return(c_result);
} //CTab cCreateTab()

CTab cCreateTabMove()
{
    CTab c_result;
    c_result.bSetSize(5);
    return(std::move(c_result));
} //CTab cCreateTabMove()

int i_ms_test()
{
    cout << "cCreateTab():" << endl;
    CTab c_tab = cCreateTab();
    cout << endl << "cCreateTabMove():" << endl;
    CTab c_tab2 = cCreateTabMove();
    cout << endl << "end of program" << endl;
    return 0;
} //int i_ms_test()


