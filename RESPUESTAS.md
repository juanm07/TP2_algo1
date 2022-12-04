Lo que pasaria si la estructura jugadas fuera una matriz como la propuesta, seria principalmente que las funciones que requieran recorrer "jugadas" van a cambiar.
Van a cambiar porque, por ejemplo, si quiero verificar si una posicion esta en jugadas ya no voy a tener que hacer busqueda lineal sobre la estructura, sino que me basta 
con acceder a la posicion en jugadas.
Un ejemplo, seria la funcion perteneceAJugadas. En esta hago busqueda lineal hasta encontrar (o no) la posicion buscada, por lo que su complejidad es |j| como ya 
explicamos. Sin embargo, con el cambio de estructura, para saber si una posicion p = (i,j) pertenece a jugadas, bastaria con preguntarse si j[i][j] = -1. 
Y como el acceso a esa posicion tiene complejidad constante, toda la funcion tendria esa complejidad. 
Ahora bien, en el caso de jugarPlus
