//
// Created by thabr on 23/12/2024.
//

#include "TaskManager.h"
#include <iostream>
#include <fstream>

using namespace std;

const vector<Task> &TaskManager::getTasks() const {
    return tasks;
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
//cancella, segna l'ultimo, quanti task contiene e quanti
void TaskManager::segnaTaskComeCompletato() {
    if (tasks.empty()) {
        cout << "\nNon ci sono task disponibili da completare.\n";
        return;
    }

    cout << "\nSeleziona un task da completare:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << " -> " << tasks[i].getTitolo() << "\n";
    }

    cout << "\nInserisci il numero del task da segnare come completato: ";
    int indiceSelezionato;
    cin >> indiceSelezionato;

    if (indiceSelezionato <= 0 || indiceSelezionato > tasks.size()) {
        cout << "\nIndice non valido. Riprova.\n";
        return;
    }

    tasks[indiceSelezionato - 1].segnaComeCompletato();
    cout << "\nTask \"" << tasks[indiceSelezionato - 1].getTitolo() << "\" segnato come completato.\n";
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


