#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

void parse(string str){
    stringstream ss(str);
    while(getline(ss, str, ','))
    {
        int val = atoi(str.c_str());
        cout << val << endl;
    }

}

int main()
{
    ifstream arquivo;
    arquivo.open("ratings.csv");

    if(arquivo.is_open()){
        //int contador = 0;
        while(!arquivo.eof())
        {
            string str;
            getline(arquivo, str);
            parse(str);
            /*while(contador<str.size()){
                if(str.at(contador)!=','){
                cout << str.at(contador);
                contador++;
                }

            else {
                cout << " ";
                contador++;
            }

            }
            */
        }
    }
    else
    {
        cerr << "Erro ao abrir arquivo!" << endl;
    }
    arquivo.close();
    return 0;
}
