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
}

