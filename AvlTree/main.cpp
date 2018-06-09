#include <iostream>
#include "ABinary.hpp"
#include "TreeDAO.h"
#include <locale>


using namespace std;
int main()
{

    //Em caso de erro copie os arquivos "key" e "texto" para um novo txt com o mesmo nome
    locale b ;
    setlocale (LC_ALL,"Portuguese");
    TreeDAO t;

    ABinary a;
    a.setKeys();
    a.checkText();

    a.showData(false);
    a.showData(true);


    return 0;
}
