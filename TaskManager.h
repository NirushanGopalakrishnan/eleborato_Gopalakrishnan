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
    void aggiungiTask(const Task& task);

    void listaTask() const;

    void segnaTaskComeCompletato();

    void salvaSuFile(const string& filename) const;

    void caricaDaFile(const string& filename);
};


#endif //ELEBORATO_GOPALAKRISHNAN_TASKMANAGER_H
