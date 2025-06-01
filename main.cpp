#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

void titulo();
void menu();
void jogoDaVelha();

int main(){
    titulo();
    menu();
    system("cls"); //Apaga o menu inicial para dar espaço a tela do jogo.
    titulo();
    jogoDaVelha();
    return 0;
}

//Atividade 1 - Tela de boas vindas e escolha do símbolo a ser utilizado.
void titulo(){
    cout << "===========================" << endl;
    cout << "  J O G O  D A  V E L H A  " << endl;
    cout << "===========================" << endl;
}
void menu(){
    char simbolo1, simbolo2;
    cout << "Jogador: Escolha seu símbolo: ";
        cin >> simbolo1;
        cout << "Oponente: Escolha seu símbolo: "; 
        cin >> simbolo2;
    if(simbolo1 == toupper(simbolo2) || simbolo1 == tolower(simbolo2)){ //Exclui os casos em que o usuário digita a mesma letra só que minúscula ou maiúscula, já que C++ é Case Sensitive.
        do {
            cout << "Opa! Seu símbolo deve ser diferente do escolhido pelo Jogador 1!" << endl;
            cout << "Oponente: Escolha seu símbolo: "; 
            cin >> simbolo2;
        }
        while (simbolo1 == toupper(simbolo2) || simbolo1 == tolower(simbolo2));
    }
}
//Atividade 2 - Criação da tela de configuração inicial do jogo
void jogoDaVelha(){
    cout << "  |   |  "<< endl;
    cout << "---------" << endl;
    cout << "  |   |  " << endl;
    cout << "---------" << endl;
    cout << "  |   |  " << endl;
};