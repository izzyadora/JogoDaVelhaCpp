#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

char a11, a12, a13, a21, a22, a23, a31, a32, a33, j;
char simbolo1, simbolo2;
int linha, coluna;
bool vitoria1, vitoria2, empate;

void titulo();
void menu();
void tabuleiro();
void perguntaJogada();
void jogador1();
void jogador2();
bool verificaVitoria1();
bool verificaVitoria2();
bool verificaEmpate();

int main(){
    a11 = ' '; 
    a12 = ' '; 
    a13 = ' ';
    a21 = ' '; 
    a22 = ' '; 
    a23 = ' ';
    a31 = ' '; 
    a32 = ' '; 
    a33 = ' ';
    vitoria1 = false;
    vitoria2 = false;
    empate = false;


    titulo();
    menu();
    system("cls"); 

    titulo();
    tabuleiro();

    while (vitoria1 == false && vitoria2 == false && empate == false){
        cout << "Vez do Jogador1" << endl;
        perguntaJogada();
        system("cls");
        jogador1();
        tabuleiro();
        vitoria1 = verificaVitoria1();
        empate = verificaEmpate();

        if (vitoria1 == true) {
            cout << "\n";
            cout << "Vitória do Jogador1!" << endl;
            break;
        }

        if (empate == true){
            cout << "\n";
            cout << "Empate!";
            break;
        }
        

        cout << "Vez do Jogador2" << endl;
        perguntaJogada();
        system("cls");
        jogador2();
        tabuleiro();
        vitoria2 = verificaVitoria2();
        empate = verificaEmpate();

        if (vitoria2 == true) {
            cout << "\n";
            cout << "Vitória do Jogador2!" << endl;
            break;
        }
        
        if (empate == true){
            cout << "\n";
            cout << "Empate!";
            break;
        }
    }
    return 0;
}

void titulo(){ 
    cout << "+---------====*====-------+" << endl;
    cout << "  J O G O  D A  V E L H A  " << endl;
    cout << "+---------====*====-------+" << endl;
}
void menu(){
    cout << "Jogador: Escolha seu símbolo: ";
        cin >> simbolo1;
        cout << "Oponente: Escolha seu símbolo: "; 
        cin >> simbolo2;
    if(simbolo1 == toupper(simbolo2) || simbolo1 == tolower(simbolo2)){
        do {
            cout << "Opa! Seu símbolo deve ser diferente do escolhido pelo Jogador 1!" << endl;
            cout << "Oponente: Escolha seu símbolo: "; 
            cin >> simbolo2;
        }
        while (simbolo1 == toupper(simbolo2) || simbolo1 == tolower(simbolo2));
    }
}


void tabuleiro(){ 
    cout << " " << a11 << " |" << a12 << " |" << a13 << endl;
    cout << "---*--*---" << endl;
    cout << " " << a21 << " |" << a22 << " |" << a23 << endl;
    cout << "---*--*---" << endl;
    cout << " " << a31 << " |" << a32 << " |" << a33 << endl;
}

void perguntaJogada(){
    cout << "Linha = ";
    cin >> linha; 
    cout << "Coluna = ";
    cin >> coluna;

}

void jogador1(){
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
        cout << "Jogada inválida!" << endl;
    }

    if (linha == 1 && coluna == 1){
        if (a11 == ' '){
            a11 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 1 && coluna == 2){
        if (a12 == ' '){
            a12 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 1 && coluna == 3){
        if (a13 == ' '){
            a13 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 2 && coluna == 1){
        if (a21 == ' '){
            a21 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 2 && coluna == 2){
        if (a22 == ' '){
            a22 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 2 && coluna == 3){
        if (a23 == ' '){
            a23 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 3 && coluna == 1){
        if (a31 == ' '){
            a31 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 3 && coluna == 2){
        if (a32 == ' '){
            a32 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 3 && coluna == 3){
        if (a33 == ' '){
            a33 = simbolo1;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
}

void jogador2(){
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
        cout << "Jogada inválida!" << endl;
    }

    if (linha == 1 && coluna == 1){
        if (a11 == ' '){
            a11 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 1 && coluna == 2){
        if (a12 == ' '){
            a12 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 1 && coluna == 3){
        if (a13 == ' '){
            a13 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 2 && coluna == 1){
        if (a21 == ' '){
            a21 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 2 && coluna == 2){
        if (a22 == ' '){
            a22 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 2 && coluna == 3){
        if (a23 == ' '){
            a23 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 3 && coluna == 1){
        if (a31 == ' '){
            a31 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 3 && coluna == 2){
        if (a32 == ' '){
            a32 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
    else if (linha == 3 && coluna == 3){
        if (a33 == ' '){
            a33 = simbolo2;
        }
        else {
        cout << "Posição já ocupada!"<< endl;
        }
    }
}

bool verificaVitoria1(){
    if (a11 == simbolo1 && a12 == simbolo1 && a13 == simbolo1){ //horizontais 
        vitoria1 = true;
        return vitoria1;
    }
    else if (a21 == simbolo1 && a22 == simbolo1 && a23 == simbolo1){
        vitoria1 = true;
        return vitoria1;
    }
    else if (a31 == simbolo1 && a32 == simbolo1 && a33 == simbolo1){ 
        vitoria1 = true;
        return vitoria1;
    }
    else if (a13 == simbolo1 && a22 == simbolo1 && a31 == simbolo1){ //diagonais
        vitoria1 = true;
        return vitoria1;
    }
    else if (a11 == simbolo1 && a22 == simbolo1 && a33 == simbolo1){
        vitoria1 = true;
        return vitoria1;
    }
    else if (a11 == simbolo1 && a21 == simbolo1 && a31 == simbolo1){ //verticais
        vitoria1 = true;
        return vitoria1;
    }
    else if (a12 == simbolo1 && a22 == simbolo1 && a32 == simbolo1){ 
        vitoria1 = true;
        return vitoria1;
    }
    else if (a13 == simbolo1 && a23 == simbolo1 && a33 == simbolo1){
        vitoria1 = true;
        return vitoria1;
    }
    else {
        vitoria1 = false;
        return vitoria1;
    }
}

bool verificaVitoria2(){
    if (a11 == simbolo2 && a12 == simbolo2 && a13 == simbolo2){ //horizontais, meu deus eu to perdida ja
        vitoria2 = true;
        return vitoria2;
    }
    else if (a21 == simbolo2 && a22 == simbolo2 && a23 == simbolo2){
        vitoria2 = true;
        return vitoria2;
    }
    else if (a31 == simbolo2 && a32 == simbolo2 && a33 == simbolo2){ 
        vitoria2 = true;
        return vitoria2;
    }
    else if (a13 == simbolo2 && a22 == simbolo2 && a31 == simbolo2){ //diagonais
        vitoria2 = true;
        return vitoria2;
    }
    else if (a11 == simbolo2 && a22 == simbolo2 && a33 == simbolo2){
        vitoria2 = true;
        return vitoria2;
    }
    else if (a11 == simbolo2 && a21 == simbolo2 && a31 == simbolo2){ //vertical
        vitoria2 = true;
        return vitoria2;
    }
    else if (a12 == simbolo2 && a22 == simbolo2 && a32 == simbolo2){ 
        vitoria2 = true;
        return vitoria2;
    }
    else if (a13 == simbolo2 && a23 == simbolo2 && a33 == simbolo2){
        vitoria2 = true;
        return vitoria2;
    }
    else {
        vitoria2 = false;
        return vitoria2;
    }
}

bool verificaEmpate(){
    if (a11 != ' ' && a12 != ' ' && a13 != ' ' && a21 != ' ' && a22 != ' ' && a23 != ' ' && a31 != ' ' && a32 != ' ' && a33 != ' ') {
        if (vitoria1 == false && vitoria2 == false) {
            empate = true;
            return empate;
        }
    }
    return false;
}
