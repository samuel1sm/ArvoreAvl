#ifndef TREEDAO_H
#define TREEDAO_H

#include <iostream>
#include <fstream>
#include "DynamicList.h"
#include "Node.hpp"
#include "NodeList.h"

using namespace std;

class TreeDAO
{
public:
    TreeDAO() {}
    void write(Node* node)
    {
        fstream myfile;
        myfile.open("saida.txt",ios::app);
        if (myfile.is_open())
        {
            myfile <<"A palavra da busca: " << node->getDado() <<", foi encontrado nas linhas : ";
            NodeList<int>* aux = node->getPag().getHead();
            while(aux!=NULL)
            {
                myfile << aux->getFrase() << " ";

                aux=aux->getNoNext();

            }

            myfile<< ".\n";

            myfile.close();
        }

        myfile.close();
    }

    DynamicList<string> readText()
    {
        dl.clearList();
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
    DynamicList<string> readKeys()
    {
        dl.clearList();
        string line;
        ifstream myfile ("PalavrasChave.txt");
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
