#!/bin/bash

g++ send_1.c -o send_1.out
g++ receive_1.c -o receive_1.out

./send_1.out
ipcs -q
./receive_1.out
