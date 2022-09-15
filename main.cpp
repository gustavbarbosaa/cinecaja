#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void nomeCliente(string name) {
    cout << "Seja bem vindo ao CineCajá!" << endl;
    cout << "------------------------------------" << endl;

    cout << "Informe seu nome: ";
    cin >> name; 
    cout << "------------------------------------" << endl;

    cout << "Seja bem vindo(a), " << name << "." << endl;
}

int numEntradas(int quantidade) {
    cout << "Quantas entradas você deseja? ";
    cin >> quantidade;

    return quantidade;
}

int numeroBilhete(int sort) {
    srand(time(NULL));
    sort = 70 + rand() % 10000;

    cout << "O seu ingresso é o : " << sort << "." << endl;
    cout << "------------------------------------" << endl;

    return sort;
}


int main() {

    bool condicao = true;
    int lugares[7][10] = {0};
    int contador = 1;

     for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 10; j++) {
            lugares[i][j] = contador++;
        }
    }

    while (condicao) {
        string name;
        nomeCliente(name);

        int numBilhete, quantidadeIngressos;
        float valorEntrada = 12.50;
        cout << "O valor da entrada é: R$" << valorEntrada << ". Certo?" << endl;
        int quantidade = numEntradas(quantidadeIngressos);
        float valorTotal = valorEntrada * quantidade;

        int sort = numeroBilhete(numBilhete);

        cout << "Os lugares disponiveis são os seguintes: " << endl;

        for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 10; j++) {
            if (contador <= 10) { 
                cout << "0" << lugares[i][j] << " ";
            } else {
                cout << lugares[i][j] << " ";
            }
        }
        cout << endl;
        }
        cout << "------------------------------------" << endl;

        int cadeira;
        cout << "Escolha o sua cadeira: ";
        cin >> cadeira;

        for (int i = 0; i < 7; i++) {
            for(int j = 0; j < 10; j++) {
                if (lugares[i][j] == cadeira) {
                    lugares[i][j] = sort;
                }

                if (contador <= 10) { 
                    cout << "0" << lugares[i][j] << " ";
                } else {
                    cout << lugares[i][j] << " ";
                }
            }
            cout << endl;
        }

        char confirm;
        cout << "O valor total é: R$" << valorTotal << ". Certo? (Digite 'S' para confirmar ou 'N' para negar -> ";
        cin >> confirm;

        if (confirm == 'S' || confirm == 's') {
            cout << "Bom filme!" << endl;
        } else if (confirm == 'N' || confirm == 'n')  {
            cout << "Certo, muito obrigado!" << endl;
        }

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 10; j++) {
                if (lugares[i][j] > 70) {
                    condicao = true;
                }
            }
        }
    }
    return 0;
}