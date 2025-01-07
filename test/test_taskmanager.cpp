//
// Created by thabr on 02/01/2025.
//

#include <gtest/gtest.h>
#include "../TaskManager.h"

using namespace std;

// Test del costruttore con il nome
TEST(TaskManagerTest, CostruttoreConNome) {
    TaskManager manager("Lista Personale");
    ASSERT_EQ(manager.getNome(), "Lista Personale");
}

// Test aggiunta di un task
TEST(TaskManagerTest, AggiungiTask) {
    TaskManager manager("Lista Personale");
    manager.aggiungiTask(Task("Titolo", "Descrizione", 3, false));
    ASSERT_EQ(manager.getTask(0).getTitolo(), "Titolo");
}

// Test elimina task specifico
TEST(TaskManagerTest, EliminaTask) {
    TaskManager manager("Lista Lavoro");
    manager.aggiungiTask(Task("Task 1", "Descrizione 1", 1, false));
    manager.aggiungiTask(Task("Task 2", "Descrizione 2", 2, false));

    manager.eliminaTask(1);

    ASSERT_EQ(manager.getTask(0).getTitolo(), "Task 1");
}

// Test completamento di un task specifico
TEST(TaskManagerTest, SegnaTaskComeCompletato) {
    TaskManager manager("Lista Progetti");
    manager.aggiungiTask(Task("Task 1", "Descrizione 1", 1, false));
    manager.aggiungiTask(Task("Task 2", "Descrizione 2", 2, false));

    manager.segnaTaskComeCompletato(1);

    ASSERT_TRUE(manager.getTask(1).getCompletato());
    ASSERT_EQ(manager.getTask(1).getTitolo(), "Task 2");
}

// Test modifica di un task specifico
TEST(TaskManagerTest, ModificaTask) {
    TaskManager manager("Lista Modifica");
    manager.aggiungiTask(Task("Task 1", "Descrizione 1", 1, false));
    manager.aggiungiTask(Task("Task 2", "Descrizione 2", 2, false));

    manager.modificaTask(1, "Task Modificato", "Nuova Descrizione", 5); // Modifica il task alla posizione 1

    const Task& taskModificato = manager.getTask(1);
    ASSERT_EQ(taskModificato.getTitolo(), "Task Modificato");
    ASSERT_EQ(taskModificato.getDescrizione(), "Nuova Descrizione");
    ASSERT_EQ(taskModificato.getPriorita(), 5);
    ASSERT_FALSE(taskModificato.getCompletato()); // Stato completato rimane invariato
}

// Test salvataggio e caricamento con nome
TEST(TaskManagerTest, SalvaCaricaTask) {
    TaskManager manager("Lista Test");
    manager.aggiungiTask(Task("Titolo", "Descrizione", 3, true));
    manager.salvaSuFile("test_task.txt");

    TaskManager managerCaricato("Lista Vuota");
    managerCaricato.caricaDaFile("test_task.txt");

    const Task& taskCaricato = managerCaricato.getTask(0);
    ASSERT_EQ(taskCaricato.getTitolo(), "Titolo");
    ASSERT_EQ(taskCaricato.getDescrizione(), "Descrizione");
    ASSERT_EQ(taskCaricato.getPriorita(), 3);
    ASSERT_TRUE(taskCaricato.getCompletato());
}