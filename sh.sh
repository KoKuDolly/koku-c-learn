#!/bin/bash
gcc src/server.c -o -lwsock32 -lws2_32 src/server.exe
gcc  -o  server.exe server.c -lwsock32 -lws2_32