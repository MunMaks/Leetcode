/*
950. Reveal Cards In Increasing Order
https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
You are given an integer array deck.
There is a deck of cards where every card has a unique integer.
The integer on the ith card is deck[i].

You can order the deck in any order you want.
Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:
  1) Take the top card of the deck, reveal it, and take it out of the deck.
  2) If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
  3) If there are still unrevealed cards, go back to step 1. Otherwise, stop.

Return an ordering of the deck that would reveal the cards in increasing order.
Note that the first entry in the answer is considered to be the top of the deck.

Example 1:
Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
*/

#define MAX_SIZE 4
#define COEFF_MUL 2

typedef struct queue {
    int debut, fin;
    int capacite;
    int *arr;
} Queue;


Queue *creation_queue(void);
int est_vide(Queue *queue);
int est_rempli(Queue *queue);
Queue *doubler_la_queue(Queue *queue);

void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
void liberer_queue(Queue *queue);
int cmpfunc(const void *a, const void *b);


int *deckRevealedIncreasing(int *deck, int deckSize, int *returnSize) {
    Queue *queue = creation_queue();
    if (!queue){
        fprintf(stderr, "Pas de memoire pour queue\n");
        return NULL;
    }

    *returnSize = deckSize;
    int* returnArr = malloc(*returnSize * sizeof(*returnArr));
    if (!returnArr){
        fprintf(stderr, "Pas de memoire pour arr\n");
        free(queue);
        return NULL;
    }

    int deck_indice = 0;
    qsort(deck, deckSize, sizeof(*deck), cmpfunc);

    for (int i = 0; i < deckSize; ++i) { enqueue(queue, i); }

    bool inserer = 1;
    while (!est_vide(queue)) {
        if (inserer) {
            returnArr[dequeue(queue)] = deck[deck_indice];
            ++deck_indice;
        } else {
            int nombre = dequeue(queue);
            enqueue(queue, nombre);
        }
        inserer = 1 - inserer;
    }

    liberer_queue(queue);
    return returnArr;
}


Queue *creation_queue(void) {
    Queue *queue = malloc(sizeof *queue);
    if (!queue){
        fprintf(stderr, "Probleme de memoire\n");
        return NULL;
    }
    queue->capacite = MAX_SIZE;
    queue->arr = malloc(queue->capacite * sizeof (*queue->arr));
    if (!queue->arr){
        free(queue);
        return NULL;
    }
    queue->debut = -1;
    queue->fin = -1;
    return queue;
}

int est_vide(Queue *queue) {
    if (!queue) return -1;
    return queue->debut == -1;
}

int est_rempli(Queue *queue) {
    if (!queue) return -1;
    return (queue->fin + 1) % queue->capacite == queue->debut;
}

Queue *doubler_la_queue(Queue *queue)
{
    if (!queue) return NULL;
    int *arr_ptr = realloc(queue->arr, (queue->capacite * COEFF_MUL) * sizeof(*arr_ptr));
    if (!arr_ptr) {
        fprintf(stderr, "Pas de memoire pour la reallocation\n");
        return queue;
    }
    queue->arr = arr_ptr;
    queue->capacite *= COEFF_MUL;
    return queue;
}


/* mettre en file d'attente */
void enqueue(Queue *queue, int item) {

    if (est_rempli(queue)) { queue = doubler_la_queue(queue); }

    if (est_vide(queue) == 1) { queue->debut = 0; }

    queue->fin = (queue->fin + 1) % queue->capacite;
    queue->arr[queue->fin] = item;
}

/* retirer de la file d'attente */ 
int dequeue(Queue *queue) {
    if (!queue) { return -1; }

    if (est_vide(queue) == 1) { return -1; } /* erreur */

    int nombre = queue->arr[queue->debut];
    if (queue->debut == queue->fin) {
        /* vider la queue */
        queue->debut = -1;
        queue->fin = -1;
    } else {
        queue->debut = (queue->debut + 1) % queue->capacite;
    }

    return nombre;
}


void liberer_queue(Queue *queue) {
    if (!queue) { return; }
    free(queue->arr);
    free(queue);
}


int cmpfunc(const void *a, const void *b) { return ( *(int *)a - *(int *)b ); }
