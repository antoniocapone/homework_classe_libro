/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: anton
 * 
 * Created on 12 maggio 2023, 12:37
 */

#include "Libro.h"

Libro::Libro(char* tit, char* gen, string aut, int pag){
    Titolo = new char[strlen(tit)+1];
    strcpy(Titolo, tit);
    Genere = new char[strlen(gen)+1];
    strcpy(Genere, gen);
    Autore=aut;
    Pagine=pag;
}

Libro::~Libro(){
    delete[] Titolo;
    delete[] Genere;
}

Libro::Libro(const Libro &mioLibro){
    Titolo = new char[strlen(mioLibro.Titolo)+1];
    strcpy(Titolo, mioLibro.Titolo);
    Genere = new char[strlen(mioLibro.Genere)+1];
    strcpy(Genere, mioLibro.Genere);
    Autore=mioLibro.Autore;
    Pagine=mioLibro.Pagine;
}

Libro::Libro(){
    Titolo = new char;
    strcpy(Titolo, "");
    Genere = new char;
    strcpy(Genere, "");
    Autore = "";
    Pagine = 0;
}

char* Libro::getTitolo(){
    return this->Titolo;
}

char* Libro::getGenere(){
    return this->Genere;
}

string Libro::getAutore(){
    return Autore;
}

int Libro::getPagine(){
    return Pagine;
}

void Libro::setTitolo(char *tit) {
    delete[] Titolo;
    Titolo = new char[strlen(tit)+1];
    strcpy(Titolo, tit);
}

void Libro::setGenere(char *gen) {
    delete[] Genere;
    Genere = new char[strlen(gen)+1];
    strcpy(Genere, gen);
}

void Libro::setAutore(string aut){
    Autore=aut;
}

void Libro::setPagine(int pag){
    Pagine=pag;
}

bool Libro::operator==(const Libro & libroDaConfrontare) const {
    if(strcmp(Titolo, libroDaConfrontare.Titolo)==0 && Autore.compare(libroDaConfrontare.Autore)==0){
        return true;
    } else return false;
}

bool Libro::operator!=(const Libro& libroDaConfrontare) const {
    if(strcmp(Titolo, libroDaConfrontare.Titolo)==0 && Autore.compare(libroDaConfrontare.Autore)==0){
        return false;
    } else return true;
}

Libro Libro::operator=(const Libro& lib){
    Autore = lib.Autore;
    Pagine = lib.Pagine;
    delete[] Genere;
    Genere = new char[strlen(lib.Genere)+1];
    strcpy(Genere, lib.Genere);
    delete[] Titolo;
    Titolo = new char[strlen(lib.Titolo)+1];
    strcpy(Titolo, lib.Titolo);
}

ostream& operator<<(ostream& os, const Libro& lib) {
    os << "Titolo:" << lib.Titolo<<"\t";
    os << "Autore:" << lib.Autore<<endl;
    return os; 
}

istream& operator>>(istream& is, Libro& lib){
    Libro temp;
    char *appoggio = new char[25];
    
    is >> appoggio;
    lib.setTitolo(appoggio);
    is >> appoggio;
    lib.setAutore(appoggio);
    is >> appoggio;
    lib.setGenere(appoggio);
    is >> appoggio;
    lib.setPagine((int)appoggio);
    
    delete[] appoggio;
    
    return is;
}

fstream& operator<<(fstream& out, Libro& lib){
    out << "Titolo: " << lib.Titolo << endl;
    out << "Genere: " << lib.Genere << endl;
    out << "Autore: " << lib.Autore << endl;
    out << "Pagine: " << lib.Pagine << endl;
    return out;
}