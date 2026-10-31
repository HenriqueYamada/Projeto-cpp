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
    int quantidade;
};

int final = 7, aux, K;
bool sinal;
char conf;
livro val;

livro lista[N] = {
    {0, "9788582850015", "Memórias Póstumas de Brás Cubas", "Romance", "Machado de Assis", 47.90, 4.5, 10},
    {1, "9788535902778", "1984", "Distopia", "George Orwell", 39.90, 9.2, 5},
    {2, "9788532530783", "O Hobbit", "Fantasia", "J.R.R. Tolkien", 49.90, 9.5, 8},
    {3, "9786555320350", "Dom Casmurro", "Romance", "Machado de Assis", 29.90, 8.8, 12},
    {4, "9788535914849", "A Revolução dos Bichos", "Sátira", "George Orwell", 34.90, 9.1, 3},
    {5, "9788544001820", "O Código Da Vinci", "Suspense", "Dan Brown", 44.90, 8.5, 7},
    {6, "9788576573134", "A Culpa é das Estrelas", "Romance", "John Green", 39.90, 8.4, 15},
    {7, "9788535911663", "O Pequeno Príncipe", "Fábula", "Antoine de Saint-Exupéry", 24.90, 9.6, 2}
};

void inserirInicio();       // Opção 1
void consultarAnterior();   // Opção 2
void ordenarPreco();        // Opção 3
void removerFim();          // Opção 4
void inserirAnterior();     // Opção 5
void alterarPosicao();      // Opção 6
void alterarAnterior();     // Opção 7
void mostrarGenero();       // Opção 8
void verificarNota();       // Opção 9
void alterarNome();         // Opção 10
void imprimirLista();       // Opção 11
void consultarQuantidade(); // Opção 12
void inserirFim();          // Opção 13

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
        cout << "\n\t\t5 - Procurar o nó por nome do livro e inserir o novo na posição anterior à do nó encontrado";
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
                cout << "\n\n\tSaindo...";
                break;
            case 1:
                inserirInicio();
                break;
            case 2:
                consultarAnterior();
                break;
            case 3:
                ordenarPreco();
                break;
            case 4:
                removerFim();
                break;
            case 5:
                inserirAnterior();
                break;
            case 6:
                alterarPosicao();
                break;
            case 7:
                alterarAnterior();
                break;
            case 8:
                mostrarGenero();
                break;
            case 9:
                verificarNota();
                break;
            case 10:
                alterarNome();
                break;
            case 11:
                imprimirLista();
                break;
            case 12:
                consultarQuantidade();
                break;
            case 13:
                inserirFim();
                break;
            default:
                cout << "\n\n\tOpção inválida. Digite outra opção.";
                break;
        }

        cout << endl << endl;
        system("pause");
    }

    return 0;
}

// Opção 1: Inserir no início
void inserirInicio() {
    system("cls");
    if (final == N - 1) {
        cout << "\n\tLista cheia!";
        return;
    }

    final++;

    for (int i = final; i >= 0; i--) {
        lista[i + 1] = lista[i];
    }

    cout << "\n\tDigite o ID: ";
    cin >> lista[0].id;
    cout << "\tDigite o ISBN: ";
    cin >> lista[0].isbn;
    cin.ignore();
    cout << "\tDigite o nome: ";
    getline(cin, lista[0].nome);
    cout << "\tDigite o gênero: ";
    getline(cin, lista[0].genero);
    cout << "\tDigite o autor: ";
    getline(cin, lista[0].autor);
    cout << "\tDigite o preço: ";
    cin >> lista[0].preco;
    cout << "\tDigite a nota: ";
    cin >> lista[0].nota;
    cout << "\tDigite a quantidade: ";
    cin >> lista[0].quantidade;

    cout << "\n\tLivro inserido no início com sucesso!";
}

// Opção 2: Consultar o nó anterior da posição K
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
            cout << "\n\t\tQuantidade: " << val.quantidade;
            sinal = true;
        } if (K == 0) {
            cout << "\n\tA posição 0 não possui anterior.";
        } else {
            cout << "\n\tA posição " << K << " não pertence à lista";
        }
    } else {
        cout << "\n\tLista vazia";
    }
}

// Opção 3: Classificar a lista em ordem crescente de preço
void ordenarPreco() {
    system("cls");

    if (final > -1) {
        for (int i = 0; i < final; i++) {
            for (int j = 0; j < final; j++) {
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
            cout << "\n\t\t" << setw(7) << lista[aux].id
                 << setw(42) << lista[aux].nome
                 << setw(12) << "R$ "
                 << fixed << setprecision(2) << lista[aux].preco;
        }
    } else {
        cout << "\n\tLista Vazia..." << endl;
    }
}

// Opção 4: Remover o nó no fim
void removerFim() {
    system("cls");
    if (final == -1) {
        cout << "\n\tLista vazia!";
        return;
    }

    cout << "\n\tLivro removido do fim: " << lista[final].nome;
    final--;
}

// Opção 5: Procurar nó por nome e inserir na posição anterior
void inserirAnterior() {
    system("cls");
    if (final == N - 1) {
        cout << "\n\tLista cheia!";
        return;
    }

    string nomeBusca;
    sinal = false;

    cin.ignore();
    cout << "\n\tDigite o nome do livro que deseja procurar: ";
    getline(cin, nomeBusca);

    for (int i = 0; i <= final; i++) {
        if (lista[i].nome == nomeBusca) {
            aux = i;
            sinal = true;
            break;
        }
    }

    if (sinal == false) {
        cout << "\n\tLivro não encontrado!";
        return;
    }

    for (int i = final; i >= aux; i--) {
        lista[i + 1] = lista[i];
    }

    cout << "\n\tDigite o ID: ";
    cin >> lista[aux].id;
    
    cout << "\tDigite o ISBN: ";
    cin >> lista[aux].isbn;

    cin.ignore();
    cout << "\tDigite o nome: ";
    getline(cin, lista[aux].nome);

    cout << "\tDigite o gênero: ";
    getline(cin, lista[aux].genero);

    cout << "\tDigite o autor: ";
    getline(cin, lista[aux].autor);
    
    cout << "\tDigite o preço: ";
    cin >> lista[aux].preco;

    cout << "\tDigite a nota: ";
    cin >> lista[aux].nota;
    
    cout << "\tDigite a quantidade: ";
    cin >> lista[aux].quantidade;

    final++;
    cout << "\n\tLivro inserido na posição anterior com sucesso!";
}

// Opção 6: Alterar o conteúdo de um livro na posição K+2
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
            cout << "\n\t\tQuantidade: " << val.quantidade;
            cout << "\n\tConfirmação [S/N]: ";
            cin >> conf;

            if (conf == 'S' || conf == 's') {
                cout << "\n\tNovo id: ";
                cin >> val.id;
                cout << "\tNovo ISBN: ";
                cin >> val.isbn;
                cin.ignore();
                cout << "\tNovo nome: ";
                getline(cin, val.nome);
                cout << "\tNovo gênero: ";
                getline(cin, val.genero);
                cout << "\tNovo autor: ";
                getline(cin, val.autor);
                cout << "\tNovo preço: ";
                cin >> val.preco;
                cout << "\tNova nota: ";
                cin >> val.nota;
                cout << "\tNova quantidade: ";
                cin >> val.quantidade;

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

// Opção 7: Procurar um ID X e alterar o livro da posição anterior
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

            system("cls");
            if (conf == 'S') {
                cout << "\n\t\tInforme o ID do livro: ";
                cin >> val.id;
                cout << "\t\tInforme o ISBN do livro: ";
                cin >> val.isbn;
                cin.ignore();
                cout << "\t\tInforme o nome do livro: ";
                getline(cin, val.nome);
                cout << "\t\tInforme o gênero do livro: ";
                getline(cin, val.genero);
                cout << "\t\tInforme o autor do livro: ";
                getline(cin, val.autor);
                cout << "\t\tInforme o preço do livro: ";
                cin >> val.preco;
                cout << "\t\tInforme a nota do livro: ";
                cin >> val.nota;
                cout << "\t\tInforme a quantidade do livro: ";
                cin >> val.quantidade;

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

// Opção 8: Mostrar os livros de um gênero informado
void mostrarGenero() {
    system("cls");
    if (final == -1) {
        cout << "\n\tLista vazia!\n";
        return;
    }

    string X;
    bool encontrou = false;

    cin.ignore();
    cout << "\n\tDigite o gênero desejado: ";
    getline(cin, X);

    for (int i = 0; i <= final; i++) {
        if (lista[i].genero == X) {
            cout << "\n\tID: " << lista[i].id;
            cout << "\n\tISBN: " << lista[i].isbn;
            cout << "\n\tNome: " << lista[i].nome;
            cout << "\n\tGênero: " << lista[i].genero;
            cout << "\n\tAutor: " << lista[i].autor;
            cout << "\n\tPreço: R$ " << fixed << setprecision(2) << lista[i].preco;
            cout << "\n\tNota: " << lista[i].nota;
            cout << "\n\tQuantidade: " << lista[i].quantidade;
            cout << "\n\t----------------------\n";
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "\n\tNenhum livro encontrado para esse gênero.\n";
    }
}

// Opção 9: Verificar/imprimir a quantidade e informações com nota >= X
void verificarNota() {
    system("cls");
    if (final == -1) {
        cout << "\n\tLista vazia!";
        return;
    }

    double X;
    int contador = 0;

    cout << "\n\tDigite a nota mínima: ";
    cin >> X;

    for (int i = 0; i <= final; i++) {
        if (lista[i].nota >= X) {
            contador++;

            cout << "\n\tID: " << lista[i].id;
            cout << "\n\tISBN: " << lista[i].isbn;
            cout << "\n\tNome: " << lista[i].nome;
            cout << "\n\tGênero: " << lista[i].genero;
            cout << "\n\tAutor: " << lista[i].autor;
            cout << "\n\tPreço: R$ " << fixed << setprecision(2) << lista[i].preco;
            cout << "\n\tNota: " << lista[i].nota;
            cout << "\n\tQuantidade: " << lista[i].quantidade;
            cout << "\n\t----------------------\n";
        }
    }

    cout << "\n\tQuantidade de livros encontrados: " << contador;

    if (contador == 0) {
        cout << "\n\tNenhum livro encontrado!";
    }
}

// Opção 10: Alterar conteúdo de um nó com o nome igual a X
void alterarNome() {
    system("cls");
    string x;
    sinal = false;

    if (final != -1) {
        cin.ignore();
        cout << "\n\tDigite o nome de um livro: ";
        getline(cin, x);

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
            cout << "\n\tPreço: R$ " << fixed << setprecision(2) << lista[aux].preco;
            cout << "\n\tNota: " << lista[aux].nota;
            cout << "\n\tQuantidade: " << lista[aux].quantidade;

            cout << "\n\n\tDeseja confirmar a alteração? [S/N]: ";
            cin >> conf;

            if (conf == 'S' || conf == 's') {
                cout << "\n\n\tDigite os novos dados do livro: \n";

                cout << "\tId: ";
                cin >> val.id;
                cout << "\tISBN: ";
                cin >> val.isbn;
                cin.ignore();
                cout << "\tNome: ";
                getline(cin, val.nome);
                cout << "\tGênero: ";
                getline(cin, val.genero);
                cout << "\tAutor: ";
                getline(cin, val.autor);
                cout << "\tPreço: ";
                cin >> val.preco;
                cout << "\tNota: ";
                cin >> val.nota;
                cout << "\tQuantidade: ";
                cin >> val.quantidade;

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

// Opção 11: Imprimir a lista de livros e permitir consultar detalhes
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
            cout << "\nPREÇO = R$ " << fixed << setprecision(2) << val.preco;
            cout << "\nNOTA = " << val.nota;
            cout << "\nQUANTIDADE = " << val.quantidade;
        }
    } else {
        cout << "\n\tLista Vazia..." << endl;
    }
}

// Opção 12: Mostrar os nós cuja quantidade seja menor ou igual a Z
void consultarQuantidade() {
    system("cls");
    if (final == -1) {
        cout << "\n\tLista vazia!\n";
        return;
    }

    int Z;
    bool encontrou = false;

    cout << "\n\tDigite a quantidade limite Z: ";
    cin >> Z;

    for (int i = 0; i <= final; i++) {
        if (lista[i].quantidade <= Z) {
            cout << "\n\tID: " << lista[i].id;
            cout << "\n\tNome: " << lista[i].nome;
            cout << "\n\tQuantidade: " << lista[i].quantidade;
            cout << "\n\tPreço: R$ " << fixed << setprecision(2) << lista[i].preco;
            cout << "\n\t----------------------\n";
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "\n\tNenhum livro encontrado com quantidade menor ou igual a " << Z << ".\n";
    }
}

// Opção 13: Inserir no fim
void inserirFim() {
    system("cls");
    if (final == N - 1) {
        cout << "\n\tLista cheia!";
        return;
    }

    final++;

    cout << "\n\tDigite o ID: ";
    cin >> lista[final].id;
    cout << "\tDigite o ISBN: ";
    cin >> lista[final].isbn;
    cin.ignore();
    cout << "\tDigite o nome: ";
    getline(cin, lista[final].nome);
    cout << "\tDigite o gênero: ";
    getline(cin, lista[final].genero);
    cout << "\tDigite o autor: ";
    getline(cin, lista[final].autor);
    cout << "\tDigite o preço: ";
    cin >> lista[final].preco;
    cout << "\tDigite a nota: ";
    cin >> lista[final].nota;
    cout << "\tDigite a quantidade: ";
    cin >> lista[final].quantidade;

    cout << "\n\tLivro inserido no fim com sucesso!";
}