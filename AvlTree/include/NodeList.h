#ifndef NODELIST_H
#define NODELIST_H

using namespace std;
class NodeList
{
    public:
        NodeList(string f) {
            frase=f;
            noNext=NULL;
        }

        NodeList* getNoNext(){return noNext;}
        string getFrase(){return frase; }
        void setNoNext(NodeList* a ){noNext =a;}
        void setFrase(string a){frase = a; }

    private:
        NodeList* noNext;
        string frase;
};

#endif // NODELIST_H
