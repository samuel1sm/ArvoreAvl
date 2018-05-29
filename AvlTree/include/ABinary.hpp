#ifndef ABINARY_H
#define ABINARY_H
#include "Node.hpp"
#include "TreeDAO.h"
#include "NodeList.h"
#include <string.h>


using namespace std;
class ABinary
{
public:
    ABinary() {}

    void insertNode(string a)
    {

        root=insertNode(root,a);

    }
    void showTree()
    {
        showTree(root);
    }

    void setKeys()
    {
        NodeList<string>* aux = td.readKeys().getHead();
        while(aux!=NULL)
        {
            tamanhoFrase=aux->getFrase().length();
            char aux2[tamanhoFrase];
            strcpy(aux2,aux->getFrase().c_str());
            fraseParaPalavra(aux2,true);

            aux=aux->getNoNext();
        }


    }

    void checkText()
    {
        NodeList<string>* aux = td.readText().getHead();
        while(aux!=NULL)
        {
            tamanhoFrase=aux->getFrase().length();
            char aux2[tamanhoFrase];
            strcpy(aux2,aux->getFrase().c_str());
            fraseParaPalavra(aux2,false);

            comparePhrase();

            aux=aux->getNoNext();
        }

    }

private:
    Node* root=NULL;
    TreeDAO td;
    DynamicList<string> dl;
    string palavra="";
    int linha=1;
    int tamanhoFrase;

    void comparePhrase()
    {
        NodeList<string>* aux = dl.getHead();
        while(aux!=NULL)
        {
            serchWord(root,aux->getFrase());

            aux=aux->getNoNext();
        }
        dl.clearList();
        linha++;
    }

    void serchWord(Node* node,string word)
    {
        if(node!=NULL)
        {
            if(word==node->getDado())
                node->setPag(linha);
            else
            {
                if(word<node->getDado())
                    serchWord(node->getLeft(),word);
                else
                    serchWord(node->getRight(),word);
            }
        }

    }

    void showTree(Node* node)
    {

        if(node->getLeft())
            showTree(node->getLeft());
        if(node->getRight())
            showTree(node->getRight());
        td.write(node);

        cout<<node->getDado()<<": Altura = "<<node->getH()<<endl;


    }

    Node* insertNode(Node* node,string word)
    {

        if(!node)
        {
            return new Node(word);
        }
        else if(word < node->getDado())
        {

            node->setLeft(insertNode(node->getLeft(),word));

        }
        else
        {
            node->setRight(insertNode(node->getRight(),word));

        }
        node->setH(calculateHeight(node));

        if(node->getH()!=1)
        {
            int aux=getbF(node);
            if(aux==2)
            {
                if(getbF(node->getLeft())<0)
                    return doubleRotateRight(node);
                else
                    return rotateRight(node);
            }
            else if(aux==-2)
            {
                if(getbF(node->getRight())>0)
                    return doubleRotateLeft(node);
                else
                    return rotateLeft(node);
            }
        }
        return node;




    }

    Node* rotateRight(Node* x)
    {
        cout<<"Roda para direita"<<endl;
        Node* aux = x->getLeft();
        x->setLeft(x->getLeft()->getRight());
        aux->setRight(x);
        aux->setH(calculateHeight(aux));
        x->setH(calculateHeight(x));
        return aux;
    }

    Node* rotateLeft(Node* x)
    {
        cout<<"Roda para esquerda"<<endl;
        Node* aux = x->getRight();
        x->setRight(x->getRight()->getLeft());
        aux->setLeft(x);

        aux->setH(calculateHeight(aux));
        x->setH(calculateHeight(x));
        return aux;
    }

    Node* doubleRotateLeft(Node* x)
    {
        x->setRight(rotateRight(x->getRight()));
        x= rotateLeft(x);
        return x;
    }

    Node* doubleRotateRight(Node* x)
    {
        x->setLeft(rotateLeft(x->getLeft()));
        x=rotateRight(x);
        return x;

    }


    int calculateHeight(Node* node)
    {

        if (node == NULL)
            return 0;
        else
        {
            int l = calculateHeight (node->getLeft());
            int r = calculateHeight (node->getRight());
            if (l < r)
                return r + 1;
            else
                return l + 1;
        }

    }

    int getbF(Node* node)
    {

        if(node->getLeft() && !node->getRight())
        {
            return node->getLeft()->getH()-0;
        }
        else if(!node->getLeft() && node->getRight())
        {
            return 0-node->getRight()->getH();
        }
        else
        {
            return node->getLeft()->getH()-node->getRight()->getH();
        }

    }

    void fraseParaPalavra(char frase[],bool modo)
    {
        for(int i=0; i<tamanhoFrase; i++)
        {
            if(frase[i]<65 && frase[i]!='-' )
            {
                if(palavra!="")
                {
                    if(modo)
                        insertNode(palavra);
                    else
                        dl.inserir(palavra);
                }

                palavra="";
            }
            else
            {
                if(frase[i]>=65 && frase[i]<=90)
                    frase[i]+=32;
                palavra+=frase[i];

                if(i+1==tamanhoFrase)
                {
                    if(modo)
                        insertNode(palavra);
                    else
                        dl.inserir(palavra);
                    palavra="";
                }
            }
        }


    }
};

#endif // ABINARY_H
