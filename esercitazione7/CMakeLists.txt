cmake_minimum_required(VERSION 3.10)

# Dai un nome al tuo progetto
project(Esercitazione9)

# Imposta lo standard C++ al 20 (necessario per i "concepts" e lo structured binding che hai usato)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Crea l'eseguibile chiamato "main" a partire dal file sorgente "main.cpp"
add_executable(main main.cpp)