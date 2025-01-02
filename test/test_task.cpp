//
// Created by thabr on 02/01/2025.
//

//#include "lib/googletest/include/gtest/gtest.h"
#include <gtest/gtest.h>
#include "../Task.h"

using namespace std;

// Test del costruttore
TEST(TaskTest, CostruttoreTask) {
Task task("Titolo", "Descrizione", 3, false);
ASSERT_EQ(task.getTitolo(), "Titolo");
ASSERT_EQ(task.getDescrizione(), "Descrizione");
ASSERT_EQ(task.getPriorita(), 3);
ASSERT_FALSE(task.getCompletato());
}

// Test segna come completato
TEST(TaskTest, SegnaComeCompletato) {
Task task("Titolo", "Descrizione", 3, false);
task.segnaComeCompletato();
ASSERT_TRUE(task.getCompletato());
}

// Test serializzazione e deserializzazione
TEST(TaskTest, SerializzazioneTask) {
Task task("Titolo", "Descrizione", 3, true);
string serializzato = task.serializzaPerFile();
Task deserializzato = Task::deserializzaDaFile(serializzato);
ASSERT_EQ(deserializzato.getTitolo(), "Titolo");
ASSERT_EQ(deserializzato.getDescrizione(), "Descrizione");
ASSERT_EQ(deserializzato.getPriorita(), 3);
ASSERT_TRUE(deserializzato.getCompletato());
}
