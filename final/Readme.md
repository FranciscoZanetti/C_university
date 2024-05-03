### Instructions - Consignas

#### English:

**The "Dando Vueltas" Laundry:**

In a laundry shop called "Dando Vueltas," the washing time and price are determined through a control system (called "ropa controller") based on the type of clothing the customer brings (randomly, it can be white clothes, colored clothes, or dark clothes). The washing time depends on whether it is nylon (45 minutes, in our case represented as 450 ms) with a price of 5 dollars, or cotton (60 minutes, in our case represented as 600 ms) with a price of 7 dollars (the material is also random). If the clothes are colored, there is an additional cost of 1 dollar for supplies. There are a total of 4 washing machines, and the control system informs each empty washing machine that they have a new order (load for each washing machine).

There are 2 processes: one for the control system "RopaController" and another process for the N washing machines (in this case, 4 washing machines).

You can use (if desired) an array of structures, where each structure contains the type of material, the color, and may contain the price and washing time (or if deemed appropriate, use dynamic memory or another method with/without arrays/structures where the price, time, material, and color can be stored). Files can also be used if desired.

The empty washing machine can receive a washing order, start the washing, and must complete the washing in the informed time, according to the material. Upon completion, it must report that it has finished and be available again to receive another washing order.

To communicate the controller with the washing machines, message queues should be used (for example, MSJ_LAVARROPA+i).

The corresponding washing machine must display the total price that the customer must pay and keep a counter for each washing machine with the total number of washes and the total price. The control system must display the total number of washes and the total price, i.e., for all washes. The structure can have variables with these values, or calculate them in each process.

The activity of each process must be shown.

Use the necessary events and the variables and structures that are required.

Remember to delete the messages at the beginning and perform other necessary initializations.

Consider using shared memory if needed for development. It is recommended to use shared memory to inform and control if the initialization process was executed first or not.

Use a Makefile with the file structure seen in class.


#### Español: 

**El lavadero de ropa “Dando Vueltas”:**

En un lavadero de ropa llamado “Dando Vueltas”, se destina mediante un sistema de control (llamado "ropa controller”) el tiempo de lavado y el precio, según el tipo de ropa que el cliente lleva (aleatorio, puede ser ropa blanca, ropa de color o ropa oscura). El tiempo de lavado depende de si es nylon (45 min, en nuestro caso lo representamos con 450 ms) con un precio de 5 dólares, o algodón (60 min, en nuestro caso lo representamos con 600 ms) con un precio de 7 dólares (el material es aleatorio también). Si la ropa es de color, tiene un costo de 1 dólar más, por los insumos. Hay en total 4 lavarropas, y el sistema de control va informando a cada lavarropas vacío que tienen una nueva orden (carga cada lavarropa).

Se cuenta con 2 procesos, uno para el sistema de control “RopaController” y otro proceso para los N lavarropas (en este caso 4 lavarropas).

Se puede contar (si se desea) con un array (arreglo) de estructuras, en la que cada estructura cuenta con el tipo de material, el color, puede contener el precio y el tiempo de lavado (o si se cree conveniente utilizar memoria dinámica u otro método con/sin array/estructuras donde se pueda colocar el precio, el tiempo, el material y el color). También se pueden usar archivos si se desea.

El lavarropa que esté desocupado puede recibir una orden de lavado, comenzar el lavado y debe realizar el lavado en el tiempo informado, según el material. Al finalizar, debe informar que finalizó y quedar libre para volver a poder recibir otra orden de lavado.

Para comunicar el controlador con los lavarropas, se debe utilizar cola de mensajes (por ejemplo, MSJ_LAVARROPA+i).

El lavarropa que le corresponda debe mostrar el precio total que debe pagar el cliente y llevar un contador por lavarropa con el total de lavados y del precio total. El sistema de control debe ir mostrando el total de lavados y el precio total, es decir, de todos los lavados. La estructura puede tener variables con estos valores, o ir calculándolos en cada proceso.

Se debe mostrar la actividad de cada proceso.

Usar los eventos que crea necesarios y las variables y estructuras que precise.

Recordar borrar los mensajes al inicio y realizar otras inicializaciones necesarias.

Puede considerar utilizar memoria compartida si es necesario para el desarrollo. Se recomienda utilizar memoria compartida para informar y controlar si se ejecutó primero el proceso de inicialización o no.

Utilizar Makefile con la estructura de archivos vista en la cursada.
