#include <iostream>
#include "ABinary.hpp"
#include "TreeDAO.h"

using namespace std;
int main()
{
    TreeDAO t;
    ABinary a;
    a.setKeys();
    a.checkText();

    a.showTree();

    return 0;
}
