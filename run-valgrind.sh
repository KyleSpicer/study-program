#!/bin/bash

cd build
valgrind --leak-check=full ./study ../source/study-docs/
