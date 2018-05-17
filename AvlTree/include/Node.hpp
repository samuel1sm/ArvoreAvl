#ifndef NODE_H
#define NODE_H
#include "DynamicList.h"
using namespace std;
class Node
{
    public:
        Node(string d) {
        left=NULL;
        right=NULL;
        dado=d;
        }

        Node* getRight(){return right;}
        Node* getLeft(){return left;}
        string getDado(){return dado;}
        DynamicList<int> getPag(){return pag;}
        void setRight(Node* no){right=no;}
        void setLeft(Node* no){left=no;}
        void setDado(string d){dado=d;}
        void setHeight(int d){height =d;}
        void setPag(int i){ pag.inserir(i);}

    private:
        Node* left;
        Node* right;
        int height;
        string dado;
        DynamicList<int> pag;
};

#endif // NODE_H
