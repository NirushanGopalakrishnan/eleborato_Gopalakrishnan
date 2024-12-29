//
// Created by thabr on 23/12/2024.
//

#include "TaskManager.h"
#include <iostream>
#include <fstream>

using namespace std;

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



