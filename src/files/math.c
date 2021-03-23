#include "pathfinder.h"

void mx_make_and_calculate_matriks(t_struct *my_struct) {
    int is_count = my_struct->islands_count;

    for(int i = 0; i < is_count - 1; ++i) {
        mx_math_test(i, my_struct->islands_count, my_struct);
    }
}

void mx_math_test(int src, int V, t_struct *my_struct) {
    int dist[V];
    bool sptSet[V];

    for(int i = 0; i < V; ++i) {
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;

    for(int count = 0; count < V - 1; ++count) {
        int u = mx_min_distance(dist, sptSet, V);

        sptSet[u] = true;
        for(int v = 0; v < V; ++v) {
            if(!sptSet[v] && my_struct->arr[u][v] && dist[u] != INT_MAX 
                && dist[u] + my_struct->arr[u][v] < dist[v]) {      
                dist[v] = dist[u] + my_struct->arr[u][v];
            }
        }
    }
    mx_print(dist, src, my_struct, V);
}

int mx_min_distance(int *dist, bool *sptSet, int V) {
    int min = INT_MAX, min_index;

    for(int v = 0; v < V; ++v) {
        if(sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}


