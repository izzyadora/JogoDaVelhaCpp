#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

int modo;
bool vitoria = false, empate = false;
char simboloJogador, simboloOponente, nomeJogador[21], nomeOponente[21], input[6], atual;
char tabuleiro[3][3];

void titulo();
int menu_inicial();
void escolhaSimbNome();
void imprimeTabuleiro(char tabuleiro[3][3]);
void inicializaTabuleiro(char tabuleiro[3][3]);
void modoPVP();
void modoIA();
bool lerJogada(char input[6], char tabuleiro[3][3], char atual);
bool verificaVitoria(char tabuleiro[3][3]);
bool verificaEmpate(char tabuleiro[3][3]);

int main(){
    titulo();
    do {
        modo = menu_inicial();
        if (modo < 1 || modo > 2) {
            system("cls");
            titulo();
            cout << "ESCOLHA INVÁLIDA, tente novamente." << endl;
        }
    } 
    while (modo < 1 || modo > 2);

    system("cls");
    titulo();
    escolhaSimbNome();

    switch(modo){
        case 1:
            modoPVP();
            break;

        case 2:
            modoIA();
            break;
    }

    cin.ignore();
    return 0;
}

void titulo(){ 
    cout << "+---------====*====-------+" << endl;
    cout << "  J O G O  D A  V E L H A  " << endl;
    cout << "+---------====*====-------+" << endl;
}

int menu_inicial(){
    int escolhaModo;
    cout << "Escolha o modo de jogo: " << endl;
    cout << "[1] Modo Jogador X Jogador" << endl;
    cout << "[2] Modo Jogador x IA" << endl;
    cout << "\nModo: ";
    cin >> escolhaModo;
    cin.ignore();

    return escolhaModo;
}

void escolhaSimbNome(){ 
    do{
        cout << "Jogador: Digite o simbolo que deseja utilizar ('X' ou 'O'): ";
        cin >> simboloJogador;
        simboloJogador = toupper(simboloJogador);
        cin.ignore();
    }
    while(simboloJogador != 'X' && simboloJogador != 'O');

    if(simboloJogador == 'X'){
        simboloOponente = 'O';
    }
    else{
        simboloOponente = 'X';
    }
    
    cout << "Digite o nome do Jogador (no máximo 20 caracteres): ";
    cin.getline(nomeJogador, 21);

    if(modo == 1){
        cout << "Digite o nome do Oponente (no máximo 20 caracteres): ";
        cin.getline(nomeOponente, 21);
    }
    else{
        strcpy(nomeOponente, "BOT");
    }
        
    }


void imprimeTabuleiro(char tabuleiro[3][3]){
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) 
            cout << "---+---+---\n";
    }
    cout << "\n";
}

void inicializaTabuleiro(char tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

bool lerJogada(char input[6], char tabuleiro[3][3], char atual){
    int linha, coluna;
    if(input[0] != '(' || input[2] != ',' || input[4] != ')'){
        cout << "Formato inválido! Use (L,C)\n";
        return false;
    }

    linha = input[1] - '0';
    coluna = input[3] - '0';
    
    if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
        cout << "Posição inválida! Use valores entre 0 e 2.\n";
        return false;
    }
    if(tabuleiro[linha][coluna] != ' '){
        cout << "Posição ocupada! Escolha outra.\n";
        return false;
    }

    tabuleiro[linha][coluna] = atual; 
    return true;
}      

void jogadaIA(char tabuleiro[3][3], int jogadaNumero) {
    if (jogadaNumero == 1) {
        if (tabuleiro[1][1] == simboloJogador) {
            tabuleiro[0][0] = simboloOponente; 
            return;
        }

        if (tabuleiro[0][0] == simboloJogador || tabuleiro[0][2] == simboloJogador ||
            tabuleiro[2][0] == simboloJogador || tabuleiro[2][2] == simboloJogador) {
            tabuleiro[1][1] = simboloOponente; 
            return;
        }

        if (tabuleiro[0][1] == simboloJogador || tabuleiro[1][0] == simboloJogador ||
            tabuleiro[1][2] == simboloJogador || tabuleiro[2][1] == simboloJogador) {
            tabuleiro[1][1] = simboloOponente; 
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = simboloJogador;
                if (verificaVitoria(tabuleiro)) {
                    tabuleiro[i][j] = simboloOponente;
                    return;
                }
                tabuleiro[i][j] = ' ';
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = simboloOponente;
                return;
            }
        }
    }
}


bool verificaEmpate(char tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool verificaVitoria(char tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        if(tabuleiro[i][0] != ' ' &&  tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
           return true;

        if(tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
           return true;
    }
    if(tabuleiro[0][0] != ' ' && 
       tabuleiro[0][0] == tabuleiro[1][1] && 
       tabuleiro[1][1] == tabuleiro[2][2])
       return true;

    if(tabuleiro[0][2] != ' ' && 
       tabuleiro[0][2] == tabuleiro[1][1] && 
       tabuleiro[1][1] == tabuleiro[2][0])
       return true;

    return false;
}

void modoPVP(){
    inicializaTabuleiro(tabuleiro); 
    vitoria = false;
    empate = false;
    bool valido = false;
    int turno = 0;

    do {
        system("cls");
        titulo();
        imprimeTabuleiro(tabuleiro);

        char atual;
        char nome[21];

        if (turno % 2 == 0) {
            atual = simboloJogador;
            strcpy(nome, nomeJogador);
        } else {
            atual = simboloOponente;
            strcpy(nome, nomeOponente);
        }

        do {
            valido = false;
            cout << "Rodada do(a) " << nome << " (" << atual << "):\n";
            cout << "Digite a posição (l,c): ";
            cin.getline(input, 6);
            valido = lerJogada(input, tabuleiro, atual);

            if (valido == false) {
                system("cls");
                titulo();
                imprimeTabuleiro(tabuleiro);
                cout << "Jogada inválida. Tente novamente.\n";
            }
        } while (valido == false);

        vitoria = verificaVitoria(tabuleiro);
        if (vitoria == true) {
            system("cls");
            titulo();
            imprimeTabuleiro(tabuleiro);
            cout << "Parabéns, " << nome << ", você venceu!\n";
            break;
        }

        empate = verificaEmpate(tabuleiro);
        if (empate == true) {
            system("cls");
            titulo();
            imprimeTabuleiro(tabuleiro);
            cout << "Empate!\n";
            break;
        }

        turno++;
    } while (vitoria == false && empate == false);
}
        

void modoIA() {
    inicializaTabuleiro(tabuleiro); 
    vitoria = false;
    empate = false;
    int turno = 0;
    bool valido = false;

    do {
        system("cls");
        titulo();
        imprimeTabuleiro(tabuleiro);

        if (turno % 2 == 0) {
            do {
                valido = false;
                cout << "Sua vez (" << simboloJogador << "):\n";
                cout << "Digite a posição (l,c): ";
                cin.getline(input, 6);
                valido = lerJogada(input, tabuleiro, simboloJogador);

                if (valido == false) {
                    system("cls");
                    titulo();
                    imprimeTabuleiro(tabuleiro);
                    cout << "Jogada inválida. Tente novamente.\n";
                }
            } while (valido == false);
        } else {
            jogadaIA(tabuleiro, turno + 1);
        }

        vitoria = verificaVitoria(tabuleiro);
        if (vitoria == true) {
            system("cls");
            titulo();
            imprimeTabuleiro(tabuleiro);
            if (turno % 2 == 0)
                cout << "Parabéns, você venceu!\n";
            else
                cout << nomeOponente << " venceu!\n";
            break;
        }

        empate = verificaEmpate(tabuleiro);
        if (empate == true) {
            system("cls");
            titulo();
            imprimeTabuleiro(tabuleiro);
            cout << "Empate!\n";
            break;
        }

        turno++;
    } while (vitoria == false && empate == false);
}
