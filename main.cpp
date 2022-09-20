#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

string nomeCliente(string name) {
    cout << "Seja bem vindo ao CineCajá!" << endl;
    cout << "------------------------------------" << endl;

    cout << "Informe seu nome: ";
    cin >> name; 
    cout << "------------------------------------" << endl;

    cout << "Seja bem vindo(a), " << name << "." << endl;

    return name;
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

void mostrarArray(int array[][10]) {
    for (int i = 0; i < 7; i++) {
        for(int j = 0; j < 10; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    bool condicao = true;
    int lugares[7][10] = {0};
    float soma;
    float valorArrecadadoCinema = 0;

    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 10; j++) {
            while (lugares[i][j] == 0) {
                string setName;
                string nome = nomeCliente(setName);

                int numBilhete, quantidadeIngressos;
                float valorEntrada = 12.50;

                cout << "O valor da entrada é: R$" << valorEntrada << ". Certo?" << endl;

                int quantidade = numEntradas(quantidadeIngressos);
                int sort = numeroBilhete(numBilhete);

                cout << "Os lugares disponiveis são os seguintes: " << endl;

                mostrarArray(lugares);

                cout << "------------------------------------" << endl;
                int coluna, fileira;
                cout << "Escolha a coluna (1 a 7): ";
                cin >> coluna;
                cout << endl;
                cout << "Agora escolha a fileira (1 ao 10): ";
                cin >> fileira;

                cout << "------------------------------------" << endl;                

                while (lugares[coluna - 1][fileira -1] != 0) {
                    cout << "Este lugar já está ocupado, tente outro!" << endl;
                    cout << "Informe a coluna (1 a 7): ";
                    cin >> coluna;
                    cout << endl;
                    cout << "Agora escolha a fileira (1 ao 10): ";
                    cin >> fileira;
                }
                
                lugares[coluna - 1][fileira -1] = sort;

                if (quantidade != 1) {
                    for (int i = 1; i < quantidade; i++) {
                        cout << "Escolha seu outro lugar: " << endl;
                        cout << "Informe a coluna (1 a 7): ";
                        cin >> coluna;
                        cout << endl;
                        cout << "Agora escolha a fileira (1 ao 10): ";
                        cin >> fileira;

                        while (lugares[coluna - 1][fileira -1] != 0) {
                            cout << "Este lugar já está ocupado, tente outro!" << endl;
                            cout << "Informe a coluna (1 a 7): ";
                            cin >> coluna;
                            cout << endl;
                            cout << "Agora escolha a fileira (1 ao 10): ";
                            cin >> fileira;
                        }
                        
                        lugares[coluna - 1][fileira -1] = sort;
                    }
                }
                
                mostrarArray(lugares);

                cout << "------------------------------------" << endl;

                char confirm;
                float valorTotal = valorEntrada * quantidade;

                cout << "O valor total é: R$" << valorTotal << ". Certo?" << endl;
                cout << "(Digite 'S' para confirmar ou 'N' para negar) -> ";
                cin >> confirm;

                if (confirm == 'S' || confirm == 's') {
                    cout << "Bom filme!" << endl;
                } else if (confirm == 'N' || confirm == 'n')  {
                    cout << "Certo, muito obrigado!" << endl;
                }

                cout << "Certo " << nome << ". Sua ficha é a de número: " << sort << "." << endl;
                cout << "------------------------------------" << endl;

                valorArrecadadoCinema = valorEntrada * quantidade;
                soma = soma + valorArrecadadoCinema;
                cout << "Valor arrecadado pelo cinema: R$" << soma << " reais." << endl;
                cout << "------------------------------------" << endl;
            }
        }
    }



    
    return 0;
}