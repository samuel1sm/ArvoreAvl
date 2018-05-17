#ifndef NODE_H
#define NODE_H

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
        void setRight(Node* no){right=no;}
        void setLeft(Node* no){left=no;}
        void setDado(string d){dado=d;}
        void setHeight(int d){height =d;}

    private:
        Node* left;
        Node* right;
        int height;
        string dado;
};

#endif // NODE_H
