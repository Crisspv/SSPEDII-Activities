#!/bin/bash

cd actividad-3-campos-de-dimension
rm -rf bin
mkdir bin
g++ -o bin/act3 main.cpp menu.cpp student.cpp file.cpp
./bin/act3