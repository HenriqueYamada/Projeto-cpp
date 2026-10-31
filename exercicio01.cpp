#include <iostream>
#include <locale>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

const int N = 10;

struct livro {
    int id;
    string isbn;
    string nome;
    string genero;
    string autor;
    float preco;
    double nota;
};

int final = 7, aux, K;
bool sinal;
char conf;
livro val;

livro lista[N] = {
    {1, "9788582850015", "Memórias Póstumas de Brás Cubas", "Romance", "Machado de Assis", 47.90, 4.5},
    {2, "9788535902778", "1984", "Distopia", "George Orwell", 39.90, 9.2},
    {3, "9788532530783", "O Hobbit", "Fantasia", "J.R.R. Tolkien", 49.90, 9.5},
    {4, "9786555320350", "Dom Casmurro", "Romance", "Machado de Assis", 29.90, 8.8},
    {5, "9788535914849", "A Revolução dos Bichos", "Sátira", "George Orwell", 34.90, 9.1},
    {6, "9788544001820", "O Código Da Vinci", "Suspense", "Dan Brown", 44.90, 8.5},
    {7, "9788576573134", "A Culpa é das Estrelas", "Romance", "John Green", 39.90, 8.4},
    {8, "9788535911663", "O Pequeno Príncipe", "Fábula", "Antoine de Saint-Exupéry", 24.90, 9.6}
};

void consultarAnterior(); // Opção 2
void ordenarPreco();      // Opção 3
void alterarPosicao();    // Opção 6
void alterarAnterior();   // Opção 7
void alterarNome();       // Opção 10
void imprimirLista();     // Opção 11

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
                cout << "\n\n\t\tSaindo...";
                break;
            // case 1:
            //     inserirInicio();
            //     break;
            case 2:
                consultarAnterior();
                break;
            case 3:
                ordenarPreco();
                break;
            // case 4:
            //     removerFim();
            //     break;
            // case 5:
            //     inserirAnterior();
            //     break;
            case 6:
                alterarPosicao();
                break;
            case 7:
                alterarAnterior();
                break;
            // case 8:
            //     mostrarGenero();
            //     break;
            // case 9:
            //     verificarNota();
            //     break;
            case 10:
                alterarNome();
                break;
            case 11:
                imprimirLista();
                break;
            // case 12:
            //     imprimirQuantidade();
            //     break;
            // case 13:
            //     inserirFim();
            //     break;
            default:
                cout << "\n\n\t\tOpção inválida. Digite outra opção.";
                break;
        }

        cout << endl << endl;
        system("pause");
    }

    return 0;
}

// Exercício 02: consultar o nó anterior da posição K.
void consultarAnterior() {
    system("cls");
    sinal = false;
    if (final != -1) {
        cout << "\n\n\tDigite uma posição K da lista para acessar o seu anterior: ";
        cin >> K;
        if (K > 0 && K <= final) {
            val = lista[K - 1];
            cout << "\n\n\tO anterior da posição " << K << " na lista é igual a: ";
            cout << "\n\t\tId: " << val.id;
            cout << "\n\t\tISBN: " << val.isbn;
            cout << "\n\t\tNome: " << val.nome;
            cout << "\n\t\tGênero: " << val.genero;
            cout << "\n\t\tAutor: " << val.autor;
            cout << "\n\t\tNota: " << val.nota;         
            sinal = true;
        } else {
            cout << "\n\tA posição " << K << " não pertence à lista";
        }
    } else {
        cout << "Lista vazia";
    }
}

// Exercício 03: classificar a lista em ordem crescente de preço.
void ordenarPreco() {
    system("cls");
    sinal = false;

    if (final > -1) {
        for (int i = 0; i < final; i++) {
            for (int j = 0; j < final - i; j++) {
                if (lista[j].preco > lista[j + 1].preco) {
                    val = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = val;
                }
            }
        }

        cout << "\n\n\t\t\tLISTAGEM DE LIVROS ";
        cout << "\n\n\t\t" << setw(7) << "ID"
             << setw(42) << "NOME DO LIVRO"
             << setw(18) << "PREÇO\n";

        for (aux = 0; aux <= final; aux++) {
            val = lista[aux];
            cout << "\n\t\t" << setw(7) << val.id
                 << setw(42) << val.nome
                 << setw(12) << "R$ "
                 << fixed << setprecision(2) << val.preco;
        }
        sinal = true;
    } else {
        cout << "\n\tLista Vazia..." << endl;
    }
}

// Exercício 06: alterar o conteúdo de um livro na posição K+2
void alterarPosicao() {
    system("cls");
    sinal = false;
    if (final != -1) {
        cout << "\n\n\tDigite uma posição K da lista para acessar o posterior do posterior: ";
        cin >> K;
        if (K >= 0 && (K + 2) <= final) {
            val = lista[K + 2];
            cout << "\n\n\tVocê deseja mesmo alterar este conteúdo?: ";
            cout << "\n\t\tId: " << val.id;
            cout << "\n\t\tISBN: " << val.isbn;
            cout << "\n\t\tNome: " << val.nome;
            cout << "\n\t\tGênero: " << val.genero;
            cout << "\n\t\tAutor: " << val.autor;
            cout << "\n\t\tNota: " << val.nota; 
            cout << "\n\tConfirmação [S/N]: ";
            cin >> conf;
            
            if (conf == 'S' || conf == 's') {
                cout << "\n\tNovo id: ";
                cin >> val.id;
                cout << "\n\tNovo ISBN: ";
                cin >> val.isbn;
                cout << "\n\tNovo nome: ";
                cin >> val.nome;
                cout << "\n\tNovo gênero: ";
                cin >> val.genero;
                cout << "\n\tNovo autor: ";
                cin >> val.autor;
                cout << "\n\tNovo nota: ";
                cin >> val.nota;
                
                lista[K + 2] = val;
                sinal = true;
            } else {
                cout << "\n\n\tDados não confirmados";
            }
        } else {
            cout << "\n\n\tDado não pertence à lista";
        }
    } else {
        cout << "\n\n\tLista vazia";
    }
}

// Exercício 07: procurar um ID X e alterar o livro da posição anterior.
void alterarAnterior() {
    system("cls");
    sinal = false;
    int X;
    int pos = 0;

    if (final > -1) {
        cout << "\n\n\t\t\tPROCURAR ID "
             << "\n\n\tDigite o ID que deseja procurar na lista: ";
        cin >> X;

        while (pos <= final && lista[pos].id != X) {
            pos++;
        }

        if (pos <= final) {
            if (pos == 0) {
                cout << "\n\tO livro encontrado está na primeira posição; não existe livro anterior.";
                return;
            }

            cout << "\n\n\t\t" << setw(7) << "ID"
                 << setw(42) << "NOME DO LIVRO"
                 << setw(35) << "AUTOR\n";

            val = lista[pos - 1];
            cout << "\n\t\t" << setw(7) << val.id
                 << setw(42) << val.nome
                 << setw(35) << val.autor;

            getch();
            cout << "\n\n\tDeseja alterar o conteúdo do livro acima? (S/N): ";
            cin >> conf;
            conf = toupper(conf);

            system("cls");
            if (conf == 'S') {
                cout << "\n\t\tInforme o ID do livro: ";
                cin >> val.id;
                cout << "\n\t\tInforme o ISBN do livro: ";
                cin >> val.isbn;
                cout << "\n\t\tInforme o nome do livro: ";
                cin >> val.nome;
                cout << "\n\t\tInforme o gênero do livro: ";
                cin >> val.genero;
                cout << "\n\t\tInforme o autor do livro: ";
                cin >> val.autor;
                cout << "\n\t\tInforme o preço do livro: ";
                cin >> val.preco;
                cout << "\n\t\tInforme a nota do livro: ";
                cin >> val.nota;

                lista[pos - 1] = val;
                sinal = true;
            } else {
                cout << "\n\t\tDados não confirmados...";
            }
        } else {
            cout << "\n\tID não encontrado na lista.";
        }
    } else {
        cout << "\n\tLista Vazia..." << endl;
    }
}

// Exercício 10: alterar conteúdo de um nó com o nome igual a X
void alterarNome() {
    system("cls");
    string x;
    sinal = false;

    if (final != -1) {
        cout << "\n\tDigite o nome de um livro: ";
        cin >> x;

        aux = 0;
        while (aux <= final && lista[aux].nome != x) {
            aux++;
        }

        if (aux <= final && lista[aux].nome == x) {
            val = lista[aux];

            cout << "\n\n\tOs dados deste livro são: ";
            cout << "\n\tId: " << lista[aux].id;
            cout << "\n\tISBN: " << lista[aux].isbn;
            cout << "\n\tNome: " << lista[aux].nome;
            cout << "\n\tGênero: " << lista[aux].genero;
            cout << "\n\tAutor: " << lista[aux].autor;
            cout << "\n\tNota: " << lista[aux].nota;

            cout << "\n\n\tDeseja confirmar a alteração? [S/N]: ";
            cin >> conf;

            if (conf == 'S' || conf == 's') {
                cout << "\n\n\tDigite os novos dados do livro: \n";

                cout << "\tId: ";
                cin >> val.id;
                cout << "\tISBN: ";
                cin >> val.isbn;
                cout << "\tNome: ";
                cin >> val.nome;
                cout << "\tGênero: ";
                cin >> val.genero;
                cout << "\tAutor: ";
                cin >> val.autor;
                cout << "\tPreço: ";
                cin >> val.preco;
                cout << "\tNota: ";
                cin >> val.nota;

                lista[aux] = val;
                sinal = true;
            } else {
                cout << "\n\n\tAlteração não confirmada";
            }
        } else {
            cout << "\n\n\tDado não pertence à lista";
        }
    } else {
        cout << "\n\n\tLista vazia";
    }
}

// Exercício 11: imprimir a lista de livros e permitir consultar seus detalhes.
void imprimirLista() {
    system("cls");
    sinal = false;

    if (final > -1) {
        cout << "\n\n\t\t\tLISTA DOS LIVROS ";

        cout << "\n\n\t\t" << setw(7) << "ID"
             << setw(42) << "NOME DO LIVRO"
             << setw(18) << "PREÇO\n";

        for (aux = 0; aux <= final; aux++) {
            val = lista[aux];
            cout << "\n\t\t" << setw(7) << val.id
                 << setw(42) << val.nome
                 << setw(12) << "R$ "
                 << fixed << setprecision(2) << val.preco;
        }

        cout << "\n\n\tMostrar mais detalhes do livro? (S/N): ";
        cin >> conf;
        conf = toupper(conf);

        if (conf == 'S') {
            system("cls");

            for (aux = 0; aux <= final; aux++) {
                val = lista[aux];
                cout << "\n\t\t" << aux << " - " << val.nome;
            }

            cout << "\n\n\t\tSelecione o Livro: ";
            cin >> aux;

            if (aux < 0 || aux > final) {
                cout << "\n\tÍndice inválido.";
                return;
            }

            val = lista[aux];
            system("cls");

            cout << "\tDETALHES DO LIVRO\n\n";
            cout << "ID = " << val.id;
            cout << "\nISBN = " << val.isbn;
            cout << "\nNOME = " << val.nome;
            cout << "\nGÊNERO = " << val.genero;
            cout << "\nAUTOR = " << val.autor;
            cout << "\nPREÇO = R$ " << val.preco;
            cout << "\nNOTA = " << val.nota;
        }
    } else {
        cout << "\n\tLista Vazia..." << endl;
    }
}