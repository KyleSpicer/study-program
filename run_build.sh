#!/bin/bash

mkdir build
cd build
cmake ../source
make
cd ..
echo # add spacing for output readability 
./build/study "$@"