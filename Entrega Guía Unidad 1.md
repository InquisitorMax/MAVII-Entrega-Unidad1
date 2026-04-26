Objetivo
Modificar el proyecto base entregado para construir una escena interactiva en la que el usuario pueda crear nuevas cajas físicas durante la ejecución y definir su rotación inicial antes de generarlas.

La práctica busca reforzar los conceptos de:

b2World

cuerpos dinámicos y estáticos

shapes y fixtures

actualización con Step()

integración entre Box2D y Raylib

creación dinámica de cuerpos

ángulo inicial de un body

Situación inicial
Se entrega un proyecto base que ya incluye:

una ventana funcionando con Raylib

un mundo físico

un suelo estático

al menos una caja dinámica de ejemplo

el ciclo principal con actualización de simulación

A partir de ese punto, el estudiante deberá completar la lógica pedida.

Consigna
Modificar el proyecto base entregado para permitir que Mavix pueda crear nuevas cajas físicas dentro del mundo de simulación.

El programa deberá permitir:

Crear nuevas cajas
Cuando el usuario presione la tecla ESPACIO, se deberá crear una nueva caja dinámica en la parte superior de la escena.

Cada caja deberá:

pertenecer al mundo físico de Box2D,

tener forma rectangular,

poseer propiedades físicas definidas mediante una fixture,

caer por efecto de la gravedad,

colisionar con el suelo y con las demás cajas existentes.

Rotar la caja antes de crearla
Antes de generar una nueva caja, Mavix puede ajustar su orientación.

Las teclas deberán funcionar de la siguiente manera:

Flecha izquierda → rotar la caja hacia la izquierda

Flecha derecha → rotar la caja hacia la derecha

El ángulo configurado deberá aplicarse a la caja en el momento en que esta se cree.

Comportamiento esperado
Al ejecutar el programa:

inicialmente existe un mundo físico con un suelo,

al presionar ESPACIO aparecen nuevas cajas,

las cajas caen por efecto de la gravedad,

interactúan entre sí mediante colisiones,

el ángulo inicial influye en cómo se acomodan al impactar.

Objetivo conceptual del ejercicio
Este práctico busca reforzar los siguientes conceptos vistos en la Unidad 1:

el mundo físico (b2World) donde ocurre la simulación,

los cuerpos dinámicos (b2Body),

las formas físicas (shapes) y fixtures,

la actualización de la simulación mediante Step(),

y la integración entre Box2D (simulación) y Raylib (visualización).