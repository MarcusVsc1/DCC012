#ifndef NOTRIETERNARIA_H
#define NOTRIETERNARIA_H


class NoTrieTernaria
{
    public:
        NoTrieTernaria(char dado);
        ~NoTrieTernaria();
        char getValor();
        void setValor(char dado);
        NoTrieTernaria* getEsq();
        NoTrieTernaria* getProx();
        NoTrieTernaria* getDir();
        void setEsq(NoTrieTernaria* no);
        void setProx(NoTrieTernaria* no);
        void setDir(NoTrieTernaria* no);
        void setFim(bool f);
        bool getFim();


    private:
        NoTrieTernaria* esq;
        NoTrieTernaria* prox;
        NoTrieTernaria* dir;
        char valor;
        bool fim;
};

#endif // NOTRIETERNARIA_H
