#include <iostream>
#include <vector>
#include <string>
#include "TaskManager.h"

using namespace std;

void mostraMenu() {
    cout << "GESTORE TODO LIST\n\n";
    cout << "********************************************\n";
    cout << "1. Seleziona o Crea un TaskManager\n";
    cout << "2. Aggiungi Task\n";
    cout << "3. Lista Task\n";
    cout << "4. Segna Task Come Completato\n";
    cout << "5. Salva Task su File\n";
    cout << "6. Carica Task da File\n";
    cout << "7. Elimina Task\n";
    cout << "8. Modifica Task\n";
    cout << "9. Esci\n";
    cout << "********************************************\n";
    cout << "Inserisci la tua scelta: ";
}

int main() {
    // Vettore per i TaskManager
    vector<TaskManager> taskManagers;
    // Indice del TaskManager attualmente selezionato
    int indiceCorrente = -1;

    int scelta;

    do {
        system("cls");
        mostraMenu();
        cin >> scelta;
        cin.ignore();

        system("cls");
        switch (scelta) {
            case 1: {
                cout << "Inserisci il nome del TaskManager: ";
                string nome;
                cin >> nome;

                bool trovato = false;
                for (int i = 0; i < taskManagers.size(); i++) {
                    if (taskManagers[i].getNome() == nome) {
                        indiceCorrente = i;
                        cout << "TaskManager \"" << nome << "\" selezionato.\n";
                        trovato = true;
                        break;
                    }
                }

                // Se non trovato ne crea uno
                if (!trovato) {
                    taskManagers.push_back(TaskManager(nome));
                    indiceCorrente = taskManagers.size() - 1;
                    cout << "Creato un nuovo TaskManager con nome \"" << nome << "\".\n";
                }
                break;
            }
            case 2: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                string titolo, descrizione;
                int priorita;

                cout << "Inserisci il titolo del task: ";
                cin >> titolo;
                cout << "Inserisci la descrizione del task: ";
                cin >> descrizione;
                cout << "Inserisci la priorità del task (1-5): ";
                cin >> priorita;

                taskManagers[indiceCorrente].aggiungiTask(Task(titolo, descrizione, priorita));
                break;
            }
            case 3: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                taskManagers[indiceCorrente].listaTask();
                break;
            }
            case 4: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                int pos;
                cout << "Inserisci la posizione del task da completare: ";
                cin >> pos;

                taskManagers[indiceCorrente].segnaTaskComeCompletato(pos);
                break;
            }
            case 5: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                string nomeFile;
                cout << "Inserisci il nome del file per salvare i task: ";
                cin >> nomeFile;
                taskManagers[indiceCorrente].salvaSuFile(nomeFile);
                break;
            }
            case 6: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                string nomeFile;
                cout << "Inserisci il nome del file per caricare i task: ";
                cin >> nomeFile;
                taskManagers[indiceCorrente].caricaDaFile(nomeFile);
                break;
            }
            case 7: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                int pos;
                cout << "Inserisci la posizione del task da eliminare: ";
                cin >> pos;

                taskManagers[indiceCorrente].eliminaTask(pos);
                break;
            }
            case 8: {
                if (indiceCorrente == -1) {
                    cout << "\nNessun TaskManager selezionato. Scegli o crea un TaskManager prima di continuare.\n";
                    break;
                }

                int pos;
                string nuovoTitolo, nuovaDescrizione;
                int nuovaPriorita;

                cout << "Inserisci la posizione del task da modificare: ";
                cin >> pos;
                cout << "Inserisci il nuovo titolo del task: ";
                cin >> nuovoTitolo;
                cout << "Inserisci la nuova descrizione del task: ";
                cin >> nuovaDescrizione;
                cout << "Inserisci la nuova priorità del task (1-5): ";
                cin >> nuovaPriorita;

                taskManagers[indiceCorrente].modificaTask(pos, nuovoTitolo, nuovaDescrizione, nuovaPriorita);
                break;
            }
            case 9:
                cout << "\nUscita dal programma. Arrivederci!\n";
                break;
            default:
                cout << "\nScelta non valida. Riprova.\n";
        }

        if (scelta != 9) {
            cout << "\nPremi Invio per continuare...";
            cin.ignore();
            cin.get();
        }

    } while (scelta != 9);

    return 0;
}