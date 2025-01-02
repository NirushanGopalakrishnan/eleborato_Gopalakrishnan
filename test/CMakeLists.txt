# Aggiungi la directory di Google Test
add_subdirectory(lib/googletest)

# Specifica il percorso dell'inclusione per Google Test
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/include)

# Lista dei file sorgente per i test
set(TEST_SOURCES
        test_task.cpp
        test_taskmanager.cpp
        runAllTests.cpp
        )

# Crea l'eseguibile per i test
add_executable(runAllTests ${TEST_SOURCES})

# Collega Google Test e il progetto principale
target_link_libraries(runAllTests PRIVATE gtest gtest_main Task TaskManager)

# Aggiungi un comando per eseguire i test con CTest
add_test(NAME AllTests COMMAND runAllTests)




