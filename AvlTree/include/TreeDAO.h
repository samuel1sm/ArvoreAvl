#ifndef TREEDAO_H
#define TREEDAO_H

#include <iostream>
#include <fstream>
#include "DynamicList.h"
#include "Node.hpp"
#include "NodeList.h"
#include <locale>


using namespace std;

class TreeDAO
{
public:
    TreeDAO() {}
    void write(Node* node)
    {
      /*                  setlocale (LC_ALL,"Portuguese");

        fstream myfile;
        myfile.open("saida.txt",ios::app);
        if (myfile.is_open())
        {
            if(node->getPag().getHead()!=NULL)
            {
                myfile << node->getDado() <<" : ";

                NodeList<int>* aux = node->getPag().getHead();
                while(aux!=NULL)
                {
                    myfile << aux->getFrase() << " ";

                    aux=aux->getNoNext();

                }

                myfile<< ".\n";
            }
            myfile.close();
        }

        myfile.close();*/
                                setlocale (LC_ALL,"Portuguese");


            if(node->getPag().getHead()!=NULL){
                cout<<node->getDado() <<" : ";
                NodeList<int>* aux = node->getPag().getHead();
                while(aux!=NULL)
                {
                    cout << aux->getFrase() << " ";

                    aux=aux->getNoNext();

                }

                cout<< "\n";

            }
    }

    DynamicList<string> readText()
    {
                setlocale (LC_ALL,"Portuguese");

        dl.clearList();
        string line;
        ifstream myfile ("texto.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
       //                         cout<<line<<endl;

                dl.inserir(line);
            }
            myfile.close();

            return dl;
        }
        return dl;

    }
    DynamicList<string> readKeys()
    {
        setlocale (LC_ALL,"Portuguese");

        dl.clearList();
        string line;
        ifstream myfile ("PalavrasChave.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
       //         cout<<line<<endl;
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
