#include "TaskManager.h"
#include <iostream>

using namespace std;

void mostraMenu() {
    cout << "GESTORE TODO LIST\n\n";
    cout << "********************************************\n";
    cout << "1. Aggiungi Task\n";
    cout << "2. Lista Task\n";
    cout << "3. Segna Task come Completato\n";
    cout << "4. Salva Task su File\n";
    cout << "5. Carica Task da File\n";
    cout << "6. Esci\n";
    cout << "********************************************\n";
    cout << "Inserisci la tua scelta: ";
}

int main() {
    TaskManager manager;
    int scelta;

    do {
        system("clear");
        mostraMenu();
        cin >> scelta;
        cin.ignore();

        system("clear");
        switch (scelta) {
            case 1: {
                string titolo, descrizione;
                int priorita;

                cout << "Inserisci il titolo del task: ";
                getline(cin, titolo);
                cout << "Inserisci la descrizione del task: ";
                getline(cin, descrizione);
                cout << "Inserisci la priorità del task (1-5): ";
                cin >> priorita;

                manager.aggiungiTask(Task(titolo, descrizione, priorita));
                break;