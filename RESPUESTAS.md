Si fuera una matriz (y no un vector, como es originalmente) cada vez que quisiera acceder a determinada posicion deberia recorrer a la matriz. Recorrer a la matriz es mas costoso, en el peor caso, que recorrer a la estructura original de jugadas. Por ejemplo podria hacerlo con dos "for", uno para las columnas y el otro para las filas. 
Asi, auxiliares como perteneceAJugadas tendrian un mayor costo que el que tenian originalmente. 
Un punto a favor podria ser que esta estructura de jugadas nos da una idea mas concreta del tablero, ya que la propia matriz representa al tablero (y sus posiciones descubiertas).
Entonces, segun como planteamos nosotros los ultimos dos ejercicios, este cambio de estructura haria que estos tuvieran una mayor complejidad temporal del que ya tienen. Aunque tambien afectaria a otros ejercicios donde se usen funciones que requieran recorrer a jugadas. 
 
