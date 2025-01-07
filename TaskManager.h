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
    string nome;

public:
    TaskManager(const string& nome) : nome(nome) {}

    const string& getNome() const { return nome; }

    const Task& getTask(int pos) const;

    void eliminaTask(int pos);

    void modificaTask(int pos, const string& nuovoTitolo, const string& nuovaDescrizione, int nuovaPriorita);

    int getTaskTotali() const;

    int getTaskDaCompletare() const;

    void aggiungiTask(const Task& task);

    void listaTask() const;

    void segnaTaskComeCompletato(int pos);

    void salvaSuFile(const string& nomeFile) const;

    void caricaDaFile(const string& nomeFile);

};

#endif //ELEBORATO_GOPALAKRISHNAN_TASKMANAGER_H
