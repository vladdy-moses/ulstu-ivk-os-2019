#!/bin/bash

g++ server_5.c -o server_5.out
g++ client_send_5.c -o client_send_5.out
g++ client_receive_5.c -o client_receive_5.out
g++ kill_5.c -o kill_5.out

./server_5.out
