//
// Created by thabr on 23/12/2024.
//

#ifndef ELEBORATO_GOPALAKRISHNAN_TASKMANAGER_H
#define ELEBORATO_GOPALAKRISHNAN_TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <string>

using namespace std;

class TaskManager {
private:
    vector<Task> tasks;

public:
    const Task& getUltimoTask() const;

    void eliminaUltimoTask();

    void modificaUltimoTask(const string& nuovoTitolo, const string& nuovaDescrizione, int nuovaPriorita);

    void aggiungiTask(const Task& task);

    void listaTask() const;

    void segnaUltimoTaskComeCompletato();

    void salvaSuFile(const string& nomeFile) const;

    void caricaDaFile(const string& nomeFile);

};

#endif //ELEBORATO_GOPALAKRISHNAN_TASKMANAGER_H
