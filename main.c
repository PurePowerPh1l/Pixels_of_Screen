#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel;

typedef struct{
    int width;
    int height;
    pixel *data;
}screen;

screen* screen_create(int width, int height){
    int i,j;
    screen *s=malloc(sizeof(screen));
    s->width=width;
    s->height=height;
    s->data=malloc(height*width*sizeof(pixel));
    for(i=0;i<s->height;i++){
        for (j=0;j<s->width;j++){
            int index = i*s->width+j;
            s->data[index].r=0;
            s->data[index].b=0;
            s->data[index].g=0;
        }
    }
    return s;
}

void screen_free(screen *s){
    free(s->data);
    free(s);
}

void screen_print(screen *s) {
    int i, j;

    for (i = 0; i < s->width; i++) {
        for (j = 0; j < s->height; j++) {
            int index = i * s->width + j;
            printf("(%u,%u,%u)", s->data[index].r, s->data[index].b, s->data[index].g = 0);
        }
        printf("\n");
    }

}

screen* screen_redder(screen* s){
    int i,j,grade;
    grade =1;
    for(i=0;i<s->height;i++){
        for (j=0;j<s->width;j++){
            int index = i*s->width+j;
            s->data[index].r=grade++;
        }
    }
    return s;
}


int main() {
    screen *s=screen_create(5,5);
    printf("\nbefore:\n");
    screen_print(s);
    screen_redder(s);
    printf("\nafter:\n");
    screen_print(s);
    screen_free(s);

    return 0;
}
