#include <iostream>
#include "ABinary.hpp"
#include "TreeDAO.h"
#include <locale>


using namespace std;
int main()
{
    locale b ;
    setlocale (LC_ALL,"Portuguese");
    TreeDAO t;
    // t.readKeys();
    ABinary a;
    a.setKeys();
    a.checkText();

    a.showTree();

    return 0;
}
