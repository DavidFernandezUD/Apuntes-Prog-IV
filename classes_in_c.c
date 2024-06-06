#include <stdio.h>
#include <stdlib.h>


struct Point {
    int x;
    int y;
    void (*add)(struct Point* this, struct Point* p);
    void (*print)();
};


void add(struct Point* this, struct Point* p) {
    this->x += p->x;
    this->y += p->y;
}

void print(struct Point* this) {
    printf("(%d, %d)\n", this->x, this->y);
}


struct Point create_point(int x, int y) {
    return (struct Point) {
        .x = x,
        .y = y,
        .add = add,
        .print = print
    };
}


int main() {

    struct Point p1 = create_point(2, 4);
    struct Point p2 = create_point(3, 6);

    p1.print(&p1);
    p2.print(&p2);

    p1.add(&p1, &p2);
    p1.print(&p1);

    return 0;
}

