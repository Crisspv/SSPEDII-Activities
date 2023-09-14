#!/bin/bash

cd actividad-2-delimitadores
rm -rf bin
mkdir bin
g++ -o bin/act2 main.cpp menu.cpp calculator.cpp file.cpp
./bin/act2