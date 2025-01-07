//
// Created by thabr on 23/12/2024.
//

#include "TaskManager.h"
#include <iostream>
#include <fstream>

using namespace std;

const Task& TaskManager::getUltimoTask() const {
    if (tasks.empty()) {
        throw runtime_error("Nessun task disponibile."); // Gestione del caso in cui il vettore sia vuoto
    }
    return tasks.back();
}

void TaskManager::eliminaUltimoTask() {
    if (tasks.empty()) {
        cout << "\nNon ci sono task da eliminare.\n";
        return;
    }

    tasks.pop_back();
    cout << "\nTask \"" << tasks.back().getTitolo() << "\" eliminato.\n";
}

void TaskManager::modificaUltimoTask(const string& nuovoTitolo, const string& nuovaDescrizione, int nuovaPriorita) {
    if (tasks.empty()) {
        cout << "\nNon ci sono task da modificare.\n";
        return;
    }

    Task& ultimoTask = tasks.back();
    ultimoTask = Task(nuovoTitolo, nuovaDescrizione, nuovaPriorita, ultimoTask.getCompletato());
    cout << "\nUltimo task modificato con successo.\n";
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

void TaskManager::segnaUltimoTaskComeCompletato() {
    if (tasks.empty()) {
        cout << "\nNon ci sono task disponibili da completare.\n";
        return;
    }

    tasks.back().segnaComeCompletato();
    cout << "\nL'ultimo task \"" << tasks.back().getTitolo() << "\" è stato segnato come completato.\n";
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



