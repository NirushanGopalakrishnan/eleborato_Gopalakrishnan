//
// Created by thabr on 22/12/2024.
//

#include "Task.h"
#include <sstream>
#include <iomanip>

using namespace std;

Task::Task(const string& titolo, const string& descrizione, int priorita, bool completato)
        : titolo(titolo), descrizione(descrizione), priorita(priorita), completato(completato) {}

void Task::segnaComeCompletato() {
    completato = true;
}

string Task::getTitolo() const {
    return titolo;
}

string Task::getDescrizione() const {
    return descrizione;
}

int Task::getPriorita() const {
    return priorita;
}

bool Task::getCompletato() const {
    return completato;
}

string Task::toString() const {
    stringstream risultato;

    risultato << left << setw(15) << "Titolo:" << titolo << "\n"
              << left << setw(15) << "Descrizione:" << descrizione << "\n"
              << left << setw(15) << "Priorita':" << priorita << "\n"
              << left << setw(15) << "Completato:" << (completato ? "Si" : "No") << "\n";

    return risultato.str();
}

string Task::serializzaPerFile() const {
    ostringstream stringaConcatenata;

    stringaConcatenata << titolo << "|" << descrizione << "|" << priorita << "|" << completato;

    return stringaConcatenata.str();
}

Task Task::deserializzaDaFile(const string& testo) {
    istringstream stringaDiIngresso(testo);
    string titolo, descrizione, prioritaStr, completatoStr;

    getline(stringaDiIngresso, titolo, '|');
    getline(stringaDiIngresso, descrizione, '|');
    getline(stringaDiIngresso, prioritaStr, '|');
    getline(stringaDiIngresso, completatoStr, '|');

    int priorita = stoi(prioritaStr);
    bool completato = stoi(completatoStr);

    return Task(titolo, descrizione, priorita, completato);
}
