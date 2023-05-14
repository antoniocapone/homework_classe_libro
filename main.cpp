/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: anton
 *
 * Created on 12 maggio 2023, 12:12
 */

#include <iostream>
#include <fstream>
#include "Libro.h"

using namespace std;

/*
 * 
 */

void inserisci_libri(int, Libro[]);
void stampa_libri(int, Libro[]);
void cancella_libri_duplicati(int&, Libro[]);
bool stampa_su_file(int, Libro[], char[]);

int main(int argc, char** argv) {
    
    //test overloading operatore = e operatore <<
    Libro lib1("I Promessi Sposi", "Alessandro Manzoni", "Romanzo", 10000);
    Libro lib2;
    cout << lib1;
    lib2 = lib1;
    cout << lib2;
    
    //test overloading operatore !=
    if(lib1 != lib2){
        cout << "(1)I libri inseriti sono diversi\n";
    }
    lib2.setAutore("Dante Alighieri");
    if(lib1 != lib2){
        cout << "(2)I libri inseriti sono diversi\n";
    }
    
    //test overloading operatore >>
    Libro lib3;
    cout << "Inserisci le caratteristiche di un libro[Titolo, Autore, Genere, Pagine]:\n";
    cin >> lib3;
    cout << "Il libro inserito è:\n" << lib3;
    
    //realizziamo un elenco di libri
    int riemp = 0;
    cout << "Numero di libri che vuoi inserire: ";
    cin >> riemp;
    Libro libri[riemp];
    inserisci_libri(riemp, libri);
    stampa_libri(riemp, libri);
    cancella_libri_duplicati(riemp, libri);
    cout << "Vettore dei libri post-cancellazione dei duplicati:\n";
    stampa_libri(riemp, libri);
    
    //stampiamo il vettore dei libri filtrato all'interno di un file di testo
    char nome_file[20];
    cout << "Inserisci il nome del file su cui printare il vettore di libri: ";
    cin >> nome_file;
    if(stampa_su_file(riemp, libri, nome_file)){
        cout << "\nPrinting eseguito";
    }else{
        cout << "Errore in apertura di file";
    }

    return 0;
}

void inserisci_libri(int riemp, Libro libri[]){
    for(int i = 0; i < riemp; i++){
        cout << "Inserisci il libro numero " << i+1 << "[Titolo, Autore, Genere, Pagine]:\n";
        cin >> libri[i];
    }
}

void stampa_libri(int riemp, Libro libri[]){
    for(int i = 0; i < riemp; i++){
        cout << "Libro numero: " << i+1 << ":\n";
        cout << libri[i];
    }
}

void cancella_libri_duplicati(int &riemp, Libro libri[]){
    
    for(int i = 0; i < riemp-1; i++){
        
        for(int j = i+1; j < riemp; j++){
            
            if(libri[i] == libri[j]){ //allora libri[j] deve essere eliminato
                for(int k=j; k < riemp-1; k++){
                    libri[k] = libri[k+1];
                }
                riemp--;
                j--;
                i--;
            }
        }
    }
}

bool stampa_su_file(int riemp, Libro libri[], char nome_file[]){
    fstream file;
    file.open(nome_file, ios::out);
    if(file){
        for(int i = 0; i < riemp; i++){
            file << libri[i] << "\n";
        }
        return true;
    }else{
        return false;
    }
}

