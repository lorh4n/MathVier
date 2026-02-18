#!/bin/bash
# Remove pasta build se existir e recria
if [ -d "build" ]; then
    rm -rf build
fi
mkdir -p build
cd build
cmake ..
make
# Executa o mathvier se a compilação for bem-sucedida
if [ $? -eq 0 ]; then
    ./mathvier
else
    echo "Erro na compilação. Não executado."
fi
cd ..