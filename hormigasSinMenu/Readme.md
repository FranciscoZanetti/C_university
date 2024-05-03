# Consignas - Instructions

### Español:

## Las hormigas del mar rojo:

En el mar rojo, hay una colonia de hormigas, que antes de esperar el invierno se preparan para el duro frío.
Para esto, construyen su nueva civilización, la cual es manejada por la hormiga reina, que controla telepáticamente a todos sus súbditos.

La hormiga reina le indica a cada hormiga la acción que debe realizar, la cual elije aleatoriamente. Hay 4 (cuatro) tipos de acciones:
-Juntar Hojas
-Juntar comida
-Juntar palitos
-Juntar piedritas

A la par, cada hormiga a la hora de realizar la acción, aleatoriamente, obtiene la cantidad de los insumos juntados, que pueden ir de 1 a 6.

Cada hormiga finaliza (puede terminar su trabajo) cuando por lo menos uno de los insumos supera las 100 unidades juntadas.

La cantidad de hormigas que trabajan, se debe poder elegir por teclado, antes de que comiencen a trabajar, mediante un menú en pantalla, y el compartimiento debe ser mediante memoria compartida ó cola de mensaje, donde se debe informar a la hormiga reina.

Se puede contar con un array (arreglo) de estructuras, en la que cada estructura cuenta con cada insumo y la descripción del insumo, o puede manejarse con/sin array/estructuras (mismo archivos si lo desea). 

La hormiga Reina, también es la que informa cuando la hormiga obrera termino sus tareas. Y cuando todas terminaron su trabajo.
 
Para comunicar la hormiga reina con las hormigas súbditas puede/debe utilizar  cola de mensajes (por ejemplo MSJ_HORMIGA+i).

Cada 300ms debe informar la hormiga reina, una nueva acción.

Tanto la hormiga reina como las hormigas deben informar todo lo que va sucediendo, y el stock de lo juntado..

Usar los eventos que crea necesario. 
 

Si utiliza memoria dinámica debe liberar la memoria!
Utilizar memoria compartida o un bucle, para siempre poder realizar las inicializaciones correspondientes, y no depender de correr un proceso determinado primero.
Utilizar Makefile con la estructura de archivos vista en la cursada.


### English:

## The Red Sea Ants:

In the Red Sea, there is a colony of ants that, before the winter arrives, prepare for the harsh cold.
For this, they build their new civilization, which is managed by the queen ant, who telepathically controls all her subjects.

The queen ant instructs each ant on the action it must perform, which is randomly chosen. There are 4 types of actions:
- Gather Leaves
- Gather Food
- Gather Sticks
- Gather Pebbles

At the same time, each ant, when performing the action, randomly obtains the quantity of gathered resources, which can range from 1 to 6.

Each ant finishes (can finish its work) when at least one of the resources exceeds 100 units gathered.

The number of ants working must be selectable via keyboard before they start working, through a menu on the screen, and the sharing must be through shared memory or message queue, where it must inform the queen ant.

You can use an array of structures, where each structure contains each resource and its description, or manage it with/without array/structures (same files if desired).

The queen ant also informs when the worker ant has finished its tasks. And when all ants have finished their work.

To communicate the queen ant with the worker ants, you can/should use message queues (for example, MSG_ANT+i).

Every 300ms, the queen ant must inform a new action.

Both the queen ant and the worker ants must report everything that is happening, and the stock of what is gathered.

Use the events you deem necessary.

If you use dynamic memory, remember to free it!
Use shared memory or a loop to always be able to perform the corresponding initializations, and not depend on running a specific process first.
Use a Makefile with the file structure seen in the class.
