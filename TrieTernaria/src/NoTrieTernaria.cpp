#include "NoTrieTernaria.h"

NoTrieTernaria::NoTrieTernaria(char dado)
{
    valor = dado;
    fim = false;
}

NoTrieTernaria::~NoTrieTernaria()
{
    //dtor
}

char NoTrieTernaria::getValor()
{
    return valor;
}

void NoTrieTernaria::setValor(char dado)
{
    valor = dado;
}

NoTrieTernaria* NoTrieTernaria::getDir()
{
    return dir;
}

NoTrieTernaria* NoTrieTernaria::getEsq()
{
    return esq;
}

NoTrieTernaria* NoTrieTernaria::getProx()
{
    return prox;
}

void NoTrieTernaria::setDir(NoTrieTernaria* no)
{
    dir = no;
}

void NoTrieTernaria::setEsq(NoTrieTernaria* no)
{
    esq = no;
}

void NoTrieTernaria::setProx(NoTrieTernaria* no)
{
    prox = no;
}

void NoTrieTernaria::setFim(bool f)
{
    fim = f;
}

bool NoTrieTernaria::getFim(){
    return fim;
}
