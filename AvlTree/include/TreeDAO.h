#ifndef TREEDAO_H
#define TREEDAO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "DynamicList.h"

using namespace std;

class TreeDAO
{
public:
    TreeDAO() {}
    void write()
    {
        fstream myfile;
        myfile.open("texto.txt",ios::app);

        myfile.close();
    }
    DynamicList<string> read()
    {
        string line;
        ifstream myfile ("texto.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                dl.inserir(line);
            }
            myfile.close();

            return dl;
        }

    }


private:
    DynamicList<string> dl;


};

#endif // TREEDAO_H
