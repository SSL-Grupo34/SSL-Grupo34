#!/bin/bash
bison -yd bison.y
echo "Bison compilado"
flex flex.l
echo "Flex compilado"
gcc y.tab.c lex.yy.c
echo "Fin de escript de inicializacion"
