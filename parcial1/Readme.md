## Instructions - Consignas

#### English:

**La facultad - The University**

A prestigious university in the Palermo neighborhood manages the enrollment of students through an innovative system of referral based on the student's background. There are two types of students: those who start their studies from scratch and those who have already completed some courses at another university and want to present subjects for validation and recognition. The UniDerivator is a system that refers students according to the information provided. This derivator allows for student enrollment as well as displaying those already enrolled. Therefore, there will be 3 processes: one for the derivator and two for each type of student, where the students' history and associated data will be stored.

To communicate the processes, FILES and SEMAPHORES are implemented:

**UniDerivator Process**
- Create a menu to control the incoming students:
  1. Option 1 - Student Enrollment
     - Prompt for:
       - The type of student (whether they are starting or with subjects to validate).
       - If with subjects to validate, enter the number of subjects.
       - Enter the student's name and surname.
       - Additional data such as student ID can be entered if desired.
  2. Option 2 - Read Enrolled Students
     - Prompt for the type of student to read (starting or with subjects to validate) and display the enrolled students' data according to each case.

**Student Type Process** (execute twice with the same source code)
- Receive as a parameter the type of student number (from 1 to 2). Initial values can be loaded into the file as a title if desired.
- Every 500 ms, check for new enrolled students; only update the screen when there are changes. That is:
  1. Wait for semaphore.
  2. Read if there are new enrolled students. It could clear the screen before displaying them.
  3. Release semaphore.
  4. Wait 500 ms and return to point 1.

Implement the solution using FILES and SEMAPHORES. There are a total of 3 processes running simultaneously. The Derivator initializes the semaphore and initial data.

## Instructions

1) Read the entire prompt.
2) Solve the exercise.
3) Send the solution as a response to this activity in a compressed file (.tar or .tar.gz).

**Correction Conditions** (if not met, the solution will not be corrected)
- The program must compile without errors.
- The program must run without memory errors.
- It must be correctly indented.
- Use constants.

**Points to Consider**
- Variable names should be descriptive of their function (especially in the main function).
- Comment the code as much as possible.
- Any variable or array defined dynamically must be freed at the end of the program.


#### Español:

## Consignas

**La facultad**

Una prestigiosa facultad en el barrio de Palermo gestiona la inscripción de estudiantes a través de un innovador sistema de derivación basado en el historial académico del estudiante. Hay dos tipos de estudiantes: aquellos que comienzan sus estudios desde cero y aquellos que ya han cursado algunas materias en otra universidad y desean presentar materias para su validación y reconocimiento. El UniDerivador es un sistema que deriva a los estudiantes según la información proporcionada. Este derivador permite la inscripción de estudiantes y también mostrar aquellos que ya están inscritos. Por lo tanto, habrá 3 procesos: uno para el derivador y dos para cada tipo de estudiante, donde se almacenará el historial de los estudiantes y los datos asociados.

Para comunicar los procesos, se implementan ARCHIVOS y SEMÁFOROS:

**Proceso UniDerivador**
- Crear un menú para controlar los estudiantes que ingresan:
  1. Opción 1 - Inscripción de Estudiantes
     - Solicitar:
       - El tipo de estudiante (si comienza o tiene materias para validar).
       - Si tiene materias para validar, ingresar la cantidad de materias.
       - Ingresar el nombre y apellido del estudiante.
       - Se pueden ingresar datos adicionales como el legajo del estudiante si se desea.
  2. Opción 2 - Leer Estudiantes Inscriptos
     - Solicitar el tipo de estudiante a leer (comenzando o con materias para validar) y mostrar los datos de los estudiantes inscritos según cada caso.

**Proceso Tipo de Estudiante** (ejecutar dos veces con el mismo código fuente)
- Recibe como parámetro el número de tipo de estudiante (de 1 a 2). Se pueden cargar valores iniciales en el archivo como un título si se desea.
- Cada 500 ms, verificar si hay nuevos estudiantes inscritos; solo actualizar la pantalla cuando haya cambios. Es decir:
  1. Esperar semáforo.
  2. Leer si hay nuevos estudiantes inscritos. Podría limpiar la pantalla antes de mostrarlos.
  3. Liberar semáforo.
  4. Esperar 500 ms y volver al punto 1.

Implementar la solución utilizando ARCHIVOS y SEMÁFOROS. Hay un total de 3 procesos ejecutándose simultáneamente. El Derivador inicializa el semáforo y los datos iniciales.

## Instrucciones

1) Leer todo el enunciado.
2) Resolver el ejercicio.
3) Enviar la solución como respuesta a esta actividad en un archivo comprimido (.tar o .tar.gz).

**Condiciones de Corrección** (si no se cumplen, la solución no será corregida)
- El programa debe compilar sin errores.
- El programa debe ejecutarse sin errores de memoria.
- Debe estar correctamente indentado.
- Utilizar constantes.

**Puntos a Considerar**
- Los nombres de las variables deben describir su función (especialmente en la función principal).
- Comentar el código tanto como sea posible.
- Cualquier variable o array definido dinámicamente debe liberarse al final del programa.


## Considerations on the resolution - Consideraciones sobre la resolución:

The studentSystem process runs even if the uniDerivator is not running yet, 
it will simply wait for the uniDerivator, and will finish when the uniDerivator finishes.

El proceso sistemaAlumno corre aunque el uniDerivador no este corriendo aun,
simplemente esperara al uniderivador, y finalizara cuando finalice el uniDerivador.
