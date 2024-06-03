#ifndef GRASP_H
#define GRASP_H

typedef struct solution_{
    int *partition;
    int cost;
} solution;

void GRASP(int *elements, int N, int GRASPmax, solution *s);

#endif // GRASP_H