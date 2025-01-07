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
        system("cls");
        mostraMenu();
        cin >> scelta;
        cin.ignore();

        system("cls");
        switch (scelta) {
            case 1: {
                string titolo, descrizione;
                int priorita;

                cout << "Inserisci il titolo del task: ";
                getline(cin, titolo);
                cout << "Inserisci la descrizione del task: ";
                getline(cin, descrizione);
                cout << "Inserisci la priorita del task (1-5): ";
                cin >> priorita;

                manager.aggiungiTask(Task(titolo, descrizione, priorita));
                break;
            }
            case 2: {
                manager.listaTask();
                break;
            }
            case 3: {
                manager.segnaTaskComeCompletato();
                break;
            }
            case 4: {
                string nomeFile;
                cout << "Inserisci il nome del file per salvare i task: ";
                cin >> nomeFile;
                manager.salvaSuFile(nomeFile);
                break;
            }
            case 5: {
                string nomeFile;
                cout << "Inserisci il nome del file per caricare i task: ";
                cin >> nomeFile;
                manager.caricaDaFile(nomeFile);
                break;
            }
            case 6: {
                cout << "\nUscita dal programma. Arrivederci!\n";
                break;
                default:
                    cout << "\nScelta non valida. Riprova.\n";
            }
        }

        if (scelta != 6) {
            cout << "\nPremi Invio per continuare...";
            cin.ignore();
            cin.get();
        }

    } while (scelta != 6);

    return 0;
}