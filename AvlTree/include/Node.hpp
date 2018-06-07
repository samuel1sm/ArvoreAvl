#ifndef NODE_H
#define NODE_H
#include "DynamicList.h"
#include <locale>

using namespace std;
class Node
{
public:
    Node(string d)
    {

         setlocale (LC_ALL,"Portuguese");
        left=NULL;
        right=NULL;
        h=1;
        dado=d;


    }

    int getH()
    {
                 setlocale (LC_ALL,"Portuguese");

        return h;
    }
    Node* getRight()
    {
                 setlocale (LC_ALL,"Portuguese");

        return right;
    }
    Node* getLeft()
    {
                 setlocale (LC_ALL,"Portuguese");

        return left;
    }
    string getDado()
    {
                                        setlocale (LC_ALL,"Portuguese");

        return dado;
    }
    DynamicList<int> getPag()
    {
                                        setlocale (LC_ALL,"Portuguese");

        return pag;
    }
    void setRight(Node* no)
    {
                 setlocale (LC_ALL,"Portuguese");

        right=no;
    }
    void setLeft(Node* no)
    {
                 setlocale (LC_ALL,"Portuguese");

        left=no;
    }
    void setDado(string d)
    {
                                        setlocale (LC_ALL,"Portuguese");

        dado=d;
    }
    void setH(int d)
    {
                 setlocale (LC_ALL,"Portuguese");

        h =d;
    }
    void setPag(int i)
    {         setlocale (LC_ALL,"Portuguese");

        pag.inserir(i);
    }

private:
    Node* left;
    Node* right;
    int h;
    string dado;
    DynamicList<int> pag;
};

#endif // NODE_H
