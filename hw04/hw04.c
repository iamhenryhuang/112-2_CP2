#include <stdio.h>
#include <stdlib.h>

// define a struct to save tv show start time and end time
struct Show {
    int start;
    int end;
};

typedef struct Show Show;


// compare function, using in qsort
int compareShows(const void* a, const void* b) {
    Show* showA = (Show*)a;
    Show* showB = (Show*)b;
    return (showA->end - showB->end);
}

int main() {
    int total;
    scanf("%d", &total);

    Show* shows = (Show*)malloc(total * sizeof(Show));

    for (int i = 0; i < total; ++i) {
        scanf("%d %d", &shows[i].start, &shows[i].end);
    }

    qsort(shows, total, sizeof(Show), compareShows);

    int count = 0;
    int lastEndTime = 0;

    for (int i = 0; i < total; i++) {
        if (shows[i].start > lastEndTime) {
            lastEndTime = shows[i].end;
            count++;
        }
    }

    printf("%d\n", count);

    free(shows);
    return 0;
}
