//
// Created by thabr on 23/12/2024.
//

#include "TaskManager.h"
#include <iostream>
#include <fstream>

using namespace std;

const Task& TaskManager::getTask(int pos) const {
    if (pos < 0 || pos >= tasks.size()) {
        throw out_of_range("Posizione fuori dai limiti: nessun task disponibile in questa posizione.");
    }
    return tasks[pos];
}

void TaskManager::eliminaTask(int pos) {
    if (tasks.empty()) {
        cout << "\nNon ci sono task da eliminare.\n";
        return;
    }

    if (pos < 0 || pos >= tasks.size()) {
        cout << "\nPosizione fuori dai limiti. Impossibile eliminare il task.\n";
        return;
    }

    tasks.erase(tasks.begin() + pos);
    cout << "\nTask \"" << tasks[pos].getTitolo() << "\" eliminato.\n";
}

void TaskManager::modificaTask(int pos, const string& nuovoTitolo, const string& nuovaDescrizione, int nuovaPriorita) {
    if (tasks.empty()) {
        cout << "\nNon ci sono task da modificare.\n";
        return;
    }

    if (pos < 0 || pos >= tasks.size()) {
        cout << "\nPosizione fuori dai limiti. Impossibile modificare il task.\n";
        return;
    }

    Task& taskDaModificare = tasks[pos];
    taskDaModificare = Task(nuovoTitolo, nuovaDescrizione, nuovaPriorita, taskDaModificare.getCompletato());
    cout << "\nTask alla posizione " << pos << " modificato con successo.\n";
}

int TaskManager::getTaskTotali() const {
    return tasks.size();
}

int TaskManager::getTaskDaCompletare() const {
    int count = 0;
    for (const auto& task : tasks) {
        if (!task.getCompletato()) {
            count++;
        }
    }
    return count;
}

void TaskManager::aggiungiTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::listaTask() const {
    if (tasks.empty()) {
        cout << "\nNon ci sono task nella lista.\n";
        return;
    }

    cout << "\nLista dei Task:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << "\n============================================\n";
        cout << "Task " << (i + 1) << ":\n";
        cout << tasks[i].toString();
    }
    cout << "\n============================================\n";
}

void TaskManager::segnaTaskComeCompletato(int pos) {
    if (tasks.empty()) {
        cout << "\nNon ci sono task disponibili da completare.\n";
        return;
    }

    if (pos < 0 || pos >= tasks.size()) {
        cout << "\nPosizione fuori dai limiti. Impossibile completare il task.\n";
        return;
    }

    tasks[pos].segnaComeCompletato();
    cout << "\nIl task \"" << tasks[pos].getTitolo() << "\" alla posizione " << pos << " è stato segnato come completato.\n";
}

void TaskManager::salvaSuFile(const string& nomeFile) const {
    ofstream file(nomeFile);
    if (!file) {
        cout << "\nErrore nell'apertura del file per la scrittura.\n";
        return;
    }
    for (const auto& task : tasks) {
        file << task.serializzaPerFile() << "\n";
    }
    cout << "\nTask salvati su " << nomeFile << ".\n";
}

void TaskManager::caricaDaFile(const string& nomeFile) {
    ifstream file(nomeFile);
    if (!file) {
        cout << "\nErrore nell'apertura del file per la lettura.\n";
        return;
    }

    tasks.clear();
    string testo;
    while (getline(file, testo)) {
        tasks.push_back(Task::deserializzaDaFile(testo));
    }
    cout << "\nTask caricati da " << nomeFile << ".\n";
}



