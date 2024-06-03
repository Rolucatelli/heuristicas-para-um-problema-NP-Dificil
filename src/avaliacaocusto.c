#include <stdio.h>
#include <stdlib.h>
#include "../hdr/grasp.h"


int f(solution *s, int N, int *elements) {

    int *sum = (int *)calloc(((int)N/3), sizeof(int));
    for (int i = 0; i < N; i++) {
        sum[s->partition[i]] += elements[i];
        
    }
     
    s->cost = 0;
    for (int i = 1; i < ((int)N/3); i++)
    {
        s->cost += abs(sum[i - 1] - sum[i]);
    }
    s->cost += abs(sum[0] - sum[((int)N/3) - 1]); // Soma a diferença entre o primeiro e o último elemento

    free(sum);
    return s->cost;
}