#!/bin/bash/
printf 'Program is being compiled\n'
make clean
make
printf '%s\n' '-------------------------------------------'
printf 'Runnig All Tests for Robot Localization Problem\n'
printf '%s\n' '---------------------------------------------------'
printf "Test 1:\n"
printf "Running: ./robot Tests/input.txt 0.1 NW NS\n"
./robot Tests/input.txt 0.1 NW NS
printf "\nProfessors given output: (0,1) ~0.998408\n"
printf '%s\n' '---------------------------------------------------'
printf "Test 2:\n"
printf "Running: ./robot Tests/input1.txt 0.1 SW NS NE W\n"
./robot Tests/input1.txt 0.1 SW NS NE W
printf "\nProfessors given output: (3,4) ~0.991362\n"
printf '%s\n' '---------------------------------------------------'
printf "Test 3:\n"
printf "Running: ./robot Tests/input1.txt 0.1 NS NS N SW\n"
./robot Tests/input1.txt 0.1 NS NS N SW
printf "\nProfessors given output: (5,3) ~0.731416\n"
printf '%s\n' '---------------------------------------------------'
printf "Test 4:\n"
printf "Running: ./robot Tests/input0.txt 0.1 NS NSE\n"
./robot Tests/input0.txt 0.1 NS NSE
printf "\nProfessors given output: (0,2) ~0.55555\n"
printf '%s\n' '---------------------------------------------------'
