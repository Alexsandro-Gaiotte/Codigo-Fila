#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* items;
    int front;
    int rear;
    int capacity;
};

void createQueue(struct Queue* q, int capacity) {
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
    q->items = (int*)malloc(capacity * sizeof(int));
    if (q->items == NULL) {
        printf("Erro na alocação de memória para a fila.\n");
        exit(1);
    }
}

int isFull(struct Queue* q) {
    return q->rear == q->capacity - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int item) {
    if (isFull(q)) {
        printf("Fila Cheia.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = item;
        printf("%d Enfileirado.\n", item);
    }
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Fila Vazia.\n");
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("%d Desenfileirado.\n", item);
    }
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Fila Vazia.\n");
    } else {
        printf("Fila: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d -> ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    int capacity;
    printf("Diga o tamanho da fila: ");
    scanf("%d", &capacity);

    struct Queue q;
    createQueue(&q, capacity);
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Diga o elemento a ser enfileirado: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                free(q.items);
                printf("Obrigado pelo acesso. Parte da jornada e o fim.\n");
                return 0;
            default:
                printf("Opcao invalida. Tente De novo.\n");
        }
    }

    return 0;
}
