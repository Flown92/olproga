#!/bin/bash

g++ -std=c++17 -o main main.cpp
if [ $? -ne 0 ]; then
    echo "Ошибка компиляции main.cpp"
    exit 1
fi

g++ -std=c++17 -o for_stress/stupid for_stress/stupid.cpp
if [ $? -ne 0 ]; then
    echo "Ошибка компиляции for_stress/stupid.cpp"
    exit 1
fi

if [ -z "$1" ]; then
    echo "Тесты укажи"
    exit 1
fi

python3 for_stress/checker.py for_stress/stupid main for_stress/gen.py "$1"
if [ $? -ne 0 ]; then
    echo "Ошибка выполнения checker.py"
    exit 1
fi

echo "Скрипт успешно выполнен!"
