#ifndef ABINARY_H
#define ABINARY_H
#include "Node.hpp"
#include "TreeDAO.h"
#include "NodeList.h"
#include <string.h>
#include <locale>


using namespace std;
class ABinary
{
public:
    ABinary() {}

    void insertNode(string a)
    {
        setlocale (LC_ALL,"Portuguese");

        root=insertNode(root,a);

    }
    void showTree()

    {
        setlocale (LC_ALL,"Portuguese");

        showTree(root);
    }

    void setKeys()

    {
        setlocale (LC_ALL,"Portuguese");

        NodeList<string>* aux = td.readKeys().getHead();
        while(aux!=NULL)
        {

            tamanhoFrase=aux->getFrase().length();
            char aux2[tamanhoFrase];


            strcpy(aux2,aux->getFrase().c_str());

            setlocale (LC_ALL,"Portuguese");

            fraseParaPalavra(aux2,true);

            aux=aux->getNoNext();
        }


    }

    void checkText()


    {
        setlocale (LC_ALL,"Portuguese");

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
    bool keyNumber = false;

    void comparePhrase()
    {
        setlocale (LC_ALL,"Portuguese");

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
        setlocale (LC_ALL,"Portuguese");

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
        setlocale (LC_ALL,"Portuguese");


        if(node->getLeft())
            showTree(node->getLeft());

        td.write(node);

        //cout<<node->getDado()<<": Altura = "<<node->getH()<<endl;
        if(node->getRight())
            showTree(node->getRight());



    }

    Node* insertNode(Node* node,string word)
    {
        setlocale (LC_ALL,"Portuguese");


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
        setlocale (LC_ALL,"Portuguese");

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
        setlocale (LC_ALL,"Portuguese");

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
        setlocale (LC_ALL,"Portuguese");

        x->setRight(rotateRight(x->getRight()));
        x= rotateLeft(x);
        return x;
    }

    Node* doubleRotateRight(Node* x)
    {
        setlocale (LC_ALL,"Portuguese");

        x->setLeft(rotateLeft(x->getLeft()));
        x=rotateRight(x);
        return x;

    }

    int calculateHeight(Node* node)
    {
        setlocale (LC_ALL,"Portuguese");

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
        setlocale (LC_ALL,"Portuguese");

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


        setlocale (LC_ALL,"Portuguese");

        for(int i=0; i<tamanhoFrase; i++)
        {
            if((frase[i]<'a' ||  frase[i]>'z') &&  (frase[i]<'A' || frase[i]>'Z') && frase[i]!='é' )/*&&  (frase[i]<128 || frase[i]>144) && (frase[i]<'0' || frase[i]>'9')
                    && (frase[i]<147 || frase[i]>154) && (frase[i]<160 || frase[i]>165) && (frase[i]<181 || frase[i]>183) && (frase[i]<198 || frase[i]>199)
                    && (frase[i]<210 || frase[i]>216) && (frase[i]<226 || frase[i]>229) && (frase[i]<233 || frase[i]>235) && frase[i]!='-' && frase[i]!=224 )*/
            {
                if(palavra!="")
                {
                    palavra = compareApostrophe();

                    if(modo)
                        insertNode(palavra);
                    else
                        dl.inserir(palavra);
                }
                keyNumber=false;
                palavra="";

            }
            else if(frase[i]>='0' && frase[i]<='9')
            {
                if(frase[i-1]!=' ' || keyNumber==true)
                {

                    palavra+=frase[i];

                    keyNumber=true;

                    if(i+1==tamanhoFrase)
                    {
                        palavra = compareApostrophe();

                        if(modo)
                            insertNode(palavra);
                        else
                            dl.inserir(palavra);
                        keyNumber=false;
                        palavra="";
                    }

                }

            }
            else
            {

                if(frase[i]>=65 && frase[i]<=90)
                    frase[i]+=32;
                palavra+=frase[i];


                if(i+1==tamanhoFrase)
                {
                    palavra = compareApostrophe();
                    if(modo)
                        insertNode(palavra);
                    else
                        dl.inserir(palavra);
                    keyNumber=false;
                    palavra="";
                }
            }
        }


    }

    string compareApostrophe()
    {


        setlocale (LC_ALL,"Portuguese");

        char aux [palavra.length()];
        strcpy(aux,palavra.c_str());
        string aux2="";

        for(int i = 0; i < palavra.length() ; i++)
        {
            if(aux[i]=='`')
                return aux2;
            else
                aux2+=aux[i];
        }

        return aux2;

    }
};

#endif // ABINARY_H
