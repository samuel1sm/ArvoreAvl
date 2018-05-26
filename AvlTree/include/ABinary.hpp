#ifndef ABINARY_H
#define ABINARY_H
#include "Node.hpp"
#include "DynamicList.h"
#include <string.h>
#include "NodeList.h"
#include "TreeDAO.h"

using namespace std;
class ABinary
{
public:
    ABinary() {}

    void insertNewNode(string a)
    {
        if(!root)
            root=new Node(a);
        else
            insertNewNode(a,root);

    }
    void setList()
    {
        TreeDAO td;
        NodeList<string>* aux = td.read().getHead();
        while(aux!=NULL)
        {
            tamanhoFrase=aux->getFrase().length();
            char aux2[tamanhoFrase];
            strcpy(aux2,aux->getFrase().c_str());
            fraseParaPalavra(aux2);

            aux=aux->getNoNext();
        }

    }

    void printLista(){
        NodeList<string>* aux = dl.getHead();
        while(aux!=NULL)
        {
            cout<<aux->getFrase()<<endl;
            aux=aux->getNoNext();
        }
    }

private:
    Node* root=NULL;
    DynamicList<string> dl;
    string palavra="";
    int tamanhoFrase;

    void insertNewNode(string a,Node* no)
    {
        if(no->getDado()>a)
        {
            if(no->getLeft())
                insertNewNode(a,no->getLeft());
            else
                no->setLeft(new Node(a));
        }
        else
        {
            if(no->getRight())
                insertNewNode(a,no->getRight());
            else
                no->setRight(new Node(a));
        }

    }

    void fraseParaPalavra(char frase[])
    {
        for(int i=0; i<tamanhoFrase; i++)
        {
            if(frase[i]<65 )
            {
                if(palavra!="")
                    dl.inserir(palavra);
                palavra="";
            }
            else
            {
                if(frase[i]>=65 && frase[i]<=90)
                    frase[i]+=32;
                palavra+=frase[i];

                if(i+1==tamanhoFrase)
                {
                    dl.inserir(palavra);
                    palavra="";
                }
            }
        }


    }

};

#endif // ABINARY_H
