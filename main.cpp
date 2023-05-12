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
#include "Libro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //test del funzionamento del costruttore di copia
    Libro libro1("I Promessi Sposi", "Romanzo", "Manzoni", 2000);
    cout << "Libro 1: " << libro1;
    Libro libro2(libro1);
    cout << "Libro 2: " << libro2;
    Libro libro3(libro1);
    
    //test del funzionamento del costruttore sintetico
    Libro libro4; 
    cout << "Costruttore Sintetico: " << libro4;
    
    //test del funzionamento dell'operatore != ridefinito per oggetti Libro
    Libro libro5("I Promessi Sposi", "Poliziesco", "Manzoni", 5000);
    cout << (libro1 != libro5);
    libro5.setAutore("Manzonee");
    cout << (libro1 != libro5);
    
    //test del funzionamento dell'operatore >> ridefinito per oggetti Libro
    //cin >> libro4;
    //cout << libro4;
    
    //implementazione dell'elenco di libri
    int riemp = 0;
    cout << "Quanti libri vuoi inserire: ";
    cin >> riemp;
    Libro libri[riemp];
    for(int i = 0; i < riemp; i++){
        cin >> libri[i];
    }
    
    for(int i = 0; i < riemp; i++){
        cout << libri[i];
    }
    
    
    
    return 0;
}

