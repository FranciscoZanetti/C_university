### Guidelines - Consignas

#### English:

**The Elections:**

In one of the best countries in the world, presidential elections are about to take place, where the future of the country will be determined.

For vote control, a system has been requested to count the votes for the two possible candidates (Mr. MS and Mr. MI). Vice presidents will also be voted for (Mr. A and Mrs. V). For this system, two processes will be used. The first process (panel process) will display the votes that will be entered in the other process (voters process).

In the panel process, a start message for the elections will be sent, and the voter process will be informed, which can have one thread or two threads, as preferred. In the thread(s), the president and the vice president will be chosen.

It will be carried out by 100 people.

For votes, a random number from 1 to 2 will be used, where 1 will be for the presidential candidate MS and 2 for the presidential candidate MI. The same applies to vice presidents, 1 for the vice presidential candidate A and 2 for the vice presidential candidate V.

To communicate the votes, message queues can/should be used (and for events, for example, EV_INIT, EV_PRESIDENT, EV_VICE).

Votes should be reported every 100ms.

Both processes must report everything that happens.

Use events as you see necessary.

If dynamic memory is used, it must be freed! Use shared memory or a loop to always be able to perform the corresponding initializations, and not depend on running a specific process first. Use a Makefile with the file structure seen in the class.

#### Español:

**Las elecciones:**

En uno de los mejores países del mundo se está por llevar a cabo las elecciones a presidente, donde se definirá el futuro del país.

Para el control de votos se decidió solicitar un sistema que cuente los votos de los dos posibles candidatos (Señor MS y señor MI). También se votará por vicepresidente (Señor A, y señora V) Para este sistema se utilizarán dos procesos. El primer proceso (proceso panel) mostrará los votos que se irán ingresando en el otro proceso (proceso votantes).

En el proceso panel, se enviará un mensaje de inicio de las elecciones y se le informará al proceso votante, que puede tener un hilo, o dos hilos, como se prefiera. En el/los hilos se elegirá el presidente, y el vicepresidente.

Se realizará por 100 personas.

Para los votos se utilizará un número aleatorio de 1 a 2, donde 1 será para el candidato a presidente MS y 2 para el candidato a presidente MI. Lo mismo para los vicepresidentes, 1 para el candidato a vicepresidente A y 2 para la candidata a vicepresidente V.

Para comunicar los votos puede/debe utilizar cola de mensajes (y para los eventos por ejemplo puede usar EV_INIT, EV_PRESIDENTE, EV_VICE).

Cada 100ms debe informar los votos.

Los dos procesos deben ir informando todo lo que va sucediendo.

Usar los eventos que crea necesario.

Si utiliza memoria dinámica debe liberar la memoria! Utilizar memoria compartida o un bucle, para siempre poder realizar las inicializaciones correspondientes, y no depender de correr un proceso determinado primero. Utilizar Makefile con la estructura de archivos vista en la cursada.

### Consideratios on the resolution - Consideraciones sobre la resolución:

Just in case, run the panel process first. I didn't have much time, sorry for the lack of comments, I didn't make it.

Por las dudas correr primero el proceso panel, no tuve tanto tiempo, perdon por la falta de comentarios, no llegue
