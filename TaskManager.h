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
    const vector<Task> &getTasks() const;

    void aggiungiTask(const Task& task);

    void listaTask() const;

    void segnaTaskComeCompletato();

    void salvaSuFile(const string& nomeFile) const;

    void caricaDaFile(const string& nomeFile);

};

#endif //ELEBORATO_GOPALAKRISHNAN_TASKMANAGER_H
