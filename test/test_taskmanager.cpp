//
// Created by thabr on 02/01/2025.
//

#include <gtest/gtest.h>
#include "../TaskManager.h"

using namespace std;

// Test aggiunta di un task
TEST(TaskManagerTest, AggiungiTask) {
    TaskManager manager;
    manager.aggiungiTask(Task("Titolo", "Descrizione", 3, false));
    ASSERT_EQ(manager.getUltimoTask().getTitolo(), "Titolo");
}

// Test elimina ultimo task
TEST(TaskManagerTest, EliminaUltimoTask) {
    TaskManager manager;
    manager.aggiungiTask(Task("Task 1", "Descrizione 1", 1, false));
    manager.aggiungiTask(Task("Task 2", "Descrizione 2", 2, false));

    manager.eliminaUltimoTask();

    const Task& ultimoTask = manager.getUltimoTask();
    ASSERT_EQ(ultimoTask.getTitolo(), "Task 1");
}

// Test completamento di ultimo task
TEST(TaskManagerTest, SegnaUltimoTaskComeCompletato) {
    TaskManager manager;
    manager.aggiungiTask(Task("Task 1", "Descrizione 1", 1, false));
    manager.aggiungiTask(Task("Task 2", "Descrizione 2", 2, false));

    manager.segnaUltimoTaskComeCompletato();

    const Task& ultimoTask = manager.getUltimoTask();
    ASSERT_TRUE(ultimoTask.getCompletato());
    ASSERT_EQ(ultimoTask.getTitolo(), "Task 2");
}

// Test salvataggio e caricamento
TEST(TaskManagerTest, SalvaCaricaTask) {
    TaskManager manager;
    manager.aggiungiTask(Task("Titolo", "Descrizione", 3, true));
    manager.salvaSuFile("test_task.txt");

    TaskManager managerCaricato;
    managerCaricato.caricaDaFile("test_task.txt");
    const Task& ultimoTask = managerCaricato.getUltimoTask();
    ASSERT_EQ(ultimoTask.getTitolo(), "Titolo");
    ASSERT_EQ(ultimoTask.getDescrizione(), "Descrizione");
    ASSERT_EQ(ultimoTask.getPriorita(), 3);
    ASSERT_TRUE(ultimoTask.getCompletato());
}
