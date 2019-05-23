#ifndef PAGINA_H
#define PAGINA_H


class Pagina
{
    public:
        Pagina(int numChaves);
        ~Pagina();
        void inserir(int chave);
        Pagina** prox;
        int* chaves;



    private:
        int minChaves;
        bool ehExterno;



};

#endif // PAGINA_H
