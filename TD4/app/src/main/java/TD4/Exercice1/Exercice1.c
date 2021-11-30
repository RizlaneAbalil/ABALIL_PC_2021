#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

entier NbRessDisponibles := Max ;
 Procédure request (entier m) {
Tant que (NbRessDisponibles<m) faire attente le processus appelant ;
NbRessDisponibles = NbRessDisponibles – m ;
 }

 Procédure release(entier m) {
 NbRessDisponibles = NbRessDisponibles + m ;
 }

 Tant que (true) {
  request(m) ;
  utiliser les m ressources
  release(m) ;
  }

  typedef int Semaphore
  //init semaphore
  //post sema