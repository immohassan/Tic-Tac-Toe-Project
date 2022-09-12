#!/bin/bash

gcc -o ./output.exe main.c util/brain/*.c util/interface/*.c util/data/*.c util/AI_brain/*.c util/load_module/*.c util/save_module/*.c
.\output.exe