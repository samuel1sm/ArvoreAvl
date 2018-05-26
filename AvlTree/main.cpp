#include <iostream>
#include "ABinary.hpp"
#include "TreeDAO.h"

using namespace std;
int main()
{
    TreeDAO t;
    ABinary a;
    a.insertNode("d");
   // a.insertNode("b");
   // a.insertNode("c");
    a.insertNode("f");
    a.insertNode("e");
    a.a();

    return 0;
}
