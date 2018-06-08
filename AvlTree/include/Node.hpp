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

        left=NULL;
        right=NULL;
        h=1;
        dado=d;


    }

    int getH()
    {

        return h;
    }
    Node* getRight()
    {

        return right;
    }
    Node* getLeft()
    {

        return left;
    }
    string getDado()
    {

        return dado;
    }
    DynamicList<int> getPag()
    {

        return pag;
    }
    void setRight(Node* no)
    {

        right=no;
    }
    void setLeft(Node* no)
    {

        left=no;
    }
    void setDado(string d)
    {

        dado=d;
    }
    void setH(int d)
    {

        h =d;
    }
    void setPag(int i)
{
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
