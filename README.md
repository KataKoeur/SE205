# SE205

Programmation concurrente

# Compte rendu TD1

## TD1.1

•  Draw a diagram representing the data dependencies of the function vector_reduction_sum (see below). You can focus on accesses to the variable sum and the array a. Hint: Pay special attention to the += operator.
•  Are there any loop-carried dependencies?
•  How does the iteration space graph look like?
•  What can you say about the potential for parallelization using SIMD-like vector operations?

Il y a les 3 types de dépendance présent dans la fonction vector_reduction_sum():
- True Dependence: On écrit dans la variable sum que l'on lit par la suite.
- Anti Dependence: On lit la variable sum pour ensuite écrire dans cette même variable.
- Output Dependence: On écrit dans la variable sum à plusieurs reprises.

Il est possible de calculer les sommes partielles en parallèle dans des variables temporaires afin des gagner du temps

## TD1.2

Les poiteurs A, B et C sont des tableaux de même taille.
Il n'y a aucune dépendance dans la fonction vector_add() dans le meilleur des cas. Cependant, si A, B et C sont les même pointeurs, cela crée des dépendances !
On ne peut donc pas dire sans regarder le main s'il y a des dépendances ou non.

## TD1.3


# Compte rendu TD2

##TD2.1

What is pthread_join() actually doing here?
pthread_join() permet d'attendre que le Thread soit terminer avant de continuer le programme.

##TD2.2

Le programme est race-free car on ne lit/écris jamais dans la même case mémoire depuis différents threads.
Effectivement, la variable counter est atomic, cela signifi qu'elle peut etre lu depuis qu'un seul endroit à la fois.

##TD2.3

Le programme se termine lorsque counter vaut 2. Cela signifi que lors de la compilation, certaines instructions on été permuté pour des raisons d'optimisation. Malheureusement cela créée un comportement inatendu lorsque le thread n'est pas éxécuter d'un seul coup. Cela est rare mais possible.
