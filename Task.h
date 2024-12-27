//
// Created by thabr on 22/12/2024.
//

#ifndef ELEBORATO_GOPALAKRISHNAN_TASK_H
#define ELEBORATO_GOPALAKRISHNAN_TASK_H

#include <string>

using namespace std;

class Task {
private:
    string titolo;
    string descrizione;
    int priorita;
    bool completato;

public:
    Task(const string& titolo, const string& descrizione, int priorita, bool completato = false);

    void segnaComeCompletato();

    string getTitolo() const;

    string toString() const;

    string serializzaPerFile() const;

    static Task deserializzaDaFile(const string& testo);
};

#endif //ELEBORATO_GOPALAKRISHNAN_TASK_H
