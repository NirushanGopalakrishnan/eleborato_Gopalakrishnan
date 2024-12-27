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

string Task::toString() const {
    stringstream risultato;

    risultato << left << setw(15) << "Titolo:" << titolo << "\n"
              << left << setw(15) << "Descrizione:" << descrizione << "\n"
              << left << setw(15) << "Priorita':" << to_string(priorita) << "\n"
              << left << setw(15) << "Completato:" << (completato ? "Si'" : "No") << "\n";
    return risultato.str();
}

string Task::toFileString() const {
    ostringstream oss;
    oss << titolo << "|" << descrizione << "|" << priorita << "|" << completato;
    return oss.str();
}

Task Task::fromFileString(const string& line) {
    istringstream iss(line);
    string titolo, descrizione;
    int priorita;
    bool completato;
    char delimiter;

    getline(iss, titolo, '|');
    getline(iss, descrizione, '|');
    iss >> priorita >> delimiter >> completato;

    return Task(titolo, descrizione, priorita, completato);
    //da finire
}
