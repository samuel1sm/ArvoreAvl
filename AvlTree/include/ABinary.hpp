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

        root=insertNode(root,a);

    }
    void showData(bool key)

    {
        cout<<"-------------------------------------------------"<<endl;
        showData(root,key);
        cout<<"-------------------------------------------------"<<endl;
    }

    void setKeys()

    {

        NodeList<string>* aux = td.readKeys().getHead();
        while(aux!=NULL)
        {

            if(wordSize<aux->getFrase().length())
                wordSize=aux->getFrase().length();

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
    bool keyNumber = false;
    int wordSize=0;

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


    void showData(Node* node,bool key)
    {

        if(node->getLeft())
            showData(node->getLeft(),key);

        if(key)
            td.write(node,wordSize);
        else
            cout<<node->getDado()<<": Altura = "<<node->getH()<<endl;

        if(node->getRight())
            showData(node->getRight(),key);



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

        setlocale (LC_ALL,"");
        for(int i=0; i<tamanhoFrase; i++)
        {
            if(!isalnum(frase[i]) && frase[i]!='-' && (frase[i]<'0' || frase[i]>'9') && frase[i]!='`')

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

            else
            {

                frase[i]= lowerCase(frase[i]);

                if(frase[i]>='0' && frase[i]<='9')
                {
                    if((frase[i-1]!=' ' && (frase[i-1]<'0' || frase[i-1]>'9')) || keyNumber==true)
                    {
                        palavra+=frase[i];
                        keyNumber=true;
                    }
                }
                else
                {
                    palavra+=frase[i];
                }

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

     char lowerCase(char aux){
        string vetorMaiusculas = "ÇÄÅÉÆÖÜÑÁÂÀÃÊËÈÓÔÒÕÚÛÙÝ";
        string vetorMinusculas = "çäåéæöüñáâàãêëèóôòõúûùý";

        for(int i = 0; i<vetorMaiusculas.length();i++)
        {
            if(aux == vetorMaiusculas.at(i))
                return vetorMinusculas.at(i);
        }

        if(aux>=65 && aux<=90)
            return aux + 32;
         else
            return aux;
    }
};

#endif // ABINARY_H
