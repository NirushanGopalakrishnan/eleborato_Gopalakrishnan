cmake_minimum_required(VERSION 3.16)

# Nome del progetto
project(TodoListManager)

# Specifica la versione del C++ da utilizzare
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggiungi i file sorgente al progetto principale
set(SOURCES
        main.cpp
        Task.cpp
        TaskManager.cpp
        )

# Aggiungi i file header al progetto principale
set(HEADERS
        Task.h
        TaskManager.h
        )

# Crea librerie statiche per Task e TaskManager
add_library(Task STATIC Task.cpp Task.h)
add_library(TaskManager STATIC TaskManager.cpp TaskManager.h)

# Collega le librerie statiche al progetto principale
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Task TaskManager)

# Aggiungi flag per una migliore gestione degli errori e warning
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# Aggiungi sottodirectory per i test
add_subdirectory(test)






