# Sintaxis y semántica de los Lenguajes
# Trabajo Practico N°3
### K2055
### Año de cursada: 2023
## Grupo 34.
### Integrantes: 
### Julián Solá, 172.877-5, https://github.com/Julifsola/SSL 
### Fernando Aquino, 176.149-3, https://github.com/Fernando-23/SSL
### Flex y Bison
El problema se resolvio de la siguiente manera:
1. Creamos el archivo flex.l correspondiente con las reglas lexicas necesarias para reconocer los tokens que contiene el lenguaje micro, aqui se incluyo la solucion al problema de los espacios, tabs y saltos de linea que pueden generar errores indeseados. 
2. En el archivo bison.y incluimos los tokens correspondientes a ser reconocidos por Flex y la gramatica descripta en los apuntes con leves modificaciones para implementar derivacion a izquierda. 
3. Se incluyeron mensajes de yyerror correspondientes a las detecciones 
4. Se implementaron 2 rutinas semanticas. La primera es la ya propuesta correspondiente al largo maximo de los identificadors (esto lo podemos ver en el caso de prueba "casoErrorSemantico.exe", ScreenshotCasoSemantico), el segundo es la resolucion de las operaciones correspondientes a la asignacion de constantes, al encontrar una operacion la resuelve y muestra el resultado por pantalla (caso de prueba "casoCorrecto.exe", ScreenshotCasoCorrecto)
Se adjuntan las Screenshots correspondientes de todos los errores y su salida.
   
### Manual de usuario
Para ejecutar la compilacion de los programas bison.y flex.l y sus resultados se creo un pequeño script llamado "deploy.sh" el mismo debe ser ejecutado en una consola bash de la siguiente manera: 
        ./deploy.sh
Este deploy dara como resultado un ejecutable a.exe que contiene el analizador en si. Para ejecutar un caso de prueba se debe correr el siguiente comando:
        ./a.exe CasosDePrueba/Caso.txt