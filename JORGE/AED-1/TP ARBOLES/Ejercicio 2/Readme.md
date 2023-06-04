# Caso 2
Se carga una base de datos con un conjunto de datos que tiene por clave un valor índice
entero. Los valores claves son almacenados en una estructura de datos de tipo árbol, que
permite acelerar la búsqueda de los datos relacionados.

Periódicamente se realizan actualizaciones en la base de datos, y como consecuencia de
ello se deben actualizar los datos del árbol de claves asociado.

Los datos de actualización se cargan en una lista enlazada, los cuales se procesan en lote
para poder actualizar el árbol de índices.

Cada elemento de la lista contiene la siguiente información:
* Clave a actualizar.
* Tipo de operación a realizar (1: Agregar clave - 2: Eliminar clave)

El programa debe:
* Crear una estructura de árbol con un conjunto de claves.
* Crear una lista con un lote de datos para actualizar el árbol de claves.
* Realizar el proceso de actualización del árbol de claves.
* Mostrar un resumen con la cantidad de datos actualizados
