#!/bin/bash
bison -yd bison.y
flex flex.l
gcc y.tab.c lex.yy.c
echo "Fin escript de inicializacion"
