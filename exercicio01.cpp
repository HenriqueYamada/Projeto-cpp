#include <iostream>
#include <locale>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

struct livro {
    int id;
    string isbn;
    string nome;
    string genero;
    string autor;
    float preco;
    double nota;
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op = -1;

    while (op != 0) {
        system("cls");

        cout << "\n\n\t\t\tGerenciamento de Livros";
        cout << "\n\n\t\t0 - Sair";
        cout << "\n\t\t1 - Inserir no início";
        cout << "\n\t\t2 - Consultar o nó anterior da posição K";
        cout << "\n\t\t3 - Classificar a lista em ordem crescente de preço";
        cout << "\n\t\t4 - Remover o nó no fim";
        cout << "\n\t\t5 - Procurar o nó por nome/descrição do livro e inserir o novo na posição anterior à do nó encontrado";
        cout << "\n\t\t6 - Alterar o conteúdo de um livro na posição K+2";
        cout << "\n\t\t7 - Procurar um nó com ID igual a X e alterar o conteúdo do nó anterior ao encontrado";
        cout << "\n\t\t8 - Mostrar todos os livros do gênero X";
        cout << "\n\t\t9 - Verificar/imprimir a quantidade e as informações de nós com nota maior ou igual a X";
        cout << "\n\t\t10 - Alterar conteúdo de um nó com o nome igual a X";
        cout << "\n\t\t11 - Imprimir a lista de livros";
        cout << "\n\t\t12 - Imprimir os valores dos nós com quantidade menor ou igual que Z";
        cout << "\n\t\t13 - Inserir um nó no fim da lista";

        cout << "\n\n\tEscolha uma opção: ";
        cin >> op;

        switch (op) {
            case 0:
                cout << "\n\n\t\tSaindo..";
                break;
            case 1:
                inicio();
                break;
            case 2:
                consultar();
                break;
            case 3:
                ilista();
                break;
            case 4:
                klista();
                break;
            case 5:
                riflista();
                break;
            case 6:
                rflista();
                break;
            case 7:
                rklista();
                break;
            case 8:
                uplista();
                break;
            case 9:
                uplista();
                break;
            case 10:
                uplista();
                break;
            case 11:
                uplista();
                break;
            case 12:
                uplista();
                break;
            case 13:
                uplista();
                break;
            default:
                cout << "\n\n\t\tOpção inválida. Digite outra opção.";
                break;
        }

        cout << endl << endl;
        system("pause");
    }

    return 0;
}