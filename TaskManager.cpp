//
// Created by thabr on 23/12/2024.
//

#include "TaskManager.h"


    void aggiungiTask(const Task &task) {
        tasks.push_back(task);
    }

    void listaTask() const {
        if (tasks.empty()) {
            cout << "\nNon ci sono task nella lista.\n";
            return;
        }

        cout << "\nLista dei Task:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "\n============================================\n";
            cout << "Task " << (i + 1) << ":\n";
            cout << tasks[i].toString();
        }
        cout << "\n============================================\n";
    }

