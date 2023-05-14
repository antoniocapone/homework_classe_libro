/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: anton
 *
 * Created on 12 maggio 2023, 12:37
 */

#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

class Libro{
private:
    char* Titolo;
    char* Genere;
    string Autore;
    int Pagine;
public:
    Libro(); //costruttore sintetico
    Libro(char*, char*, string, int); //costruttore con parametri
    ~Libro(); //distruttore
    Libro(const Libro &); //costruttore di copia
    //metodi set
    void setTitolo(char*);
    void setGenere(char*);
    void setAutore(string);
    void setPagine(int);
    //metodi get
    char* getTitolo();
    char* getGenere();
    string getAutore();
    int getPagine();
    //overload operatori
    Libro operator=(const Libro&); //overloading operatore di assegnazione
    bool operator==(const Libro &) const;
    bool operator!=(const Libro&) const; //overloading operatore !=
    friend ostream& operator<<(std::ostream&, const Libro&);  
    friend istream& operator>>(istream&, Libro&); //overloading operatore >> per oggetti del tipo cin
    friend fstream& operator<<(std::fstream&, Libro&); //overloading operatore << per stampa su file .txt
};


#endif /* LIBRO_H */

