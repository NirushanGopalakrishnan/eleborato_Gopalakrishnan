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
    ASSERT_EQ(manager.getTasks().size(), 1);
    ASSERT_EQ(manager.getTasks()[0].getTitolo(), "Titolo");
}

// Test completamento di un task
TEST(TaskManagerTest, CompletaTask) {
    TaskManager manager;
    manager.aggiungiTask(Task("Titolo", "Descrizione", 3, false));
    manager.segnaTaskComeCompletato();
    ASSERT_TRUE(manager.getTasks()[0].getCompletato());
}

// Test salvataggio e caricamento
TEST(TaskManagerTest, SalvaCaricaTask) {
    TaskManager manager;
    manager.aggiungiTask(Task("Titolo", "Descrizione", 3, true));
    manager.salvaSuFile("test_task.txt");

    TaskManager managerCaricato;
    managerCaricato.caricaDaFile("test_task.txt");
    ASSERT_EQ(managerCaricato.getTasks().size(), 1);
    ASSERT_EQ(managerCaricato.getTasks()[0].getTitolo(), "Titolo");
    ASSERT_EQ(managerCaricato.getTasks()[0].getDescrizione(), "Descrizione");
    ASSERT_EQ(managerCaricato.getTasks()[0].getPriorita(), 3);
    ASSERT_TRUE(managerCaricato.getTasks()[0].getCompletato());
}
