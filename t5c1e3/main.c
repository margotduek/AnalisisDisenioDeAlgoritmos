/* Algoritmo Punto Medio para el trazado de líneas */
#include <stdio.h>
#include <graphics.h>

void MidPointLine(int x0, int y0, int x1, int y1);

int main(int argc, char **argv)
{
	int x1, y1, x2, y2;
	int x11, y11, x21, y21;
	
	int gd = DETECT, gm = VGAMAX;
	
	printf("Entre el punto de origen [x1,y1]: ");
	scanf("%d,%d", &x1, &y1);

	printf("Entre el punto destino [x2,y2]: ");
	scanf("%d,%d", &x2, &y2);
	
	printf("Entre el punto de origen 2 [x1,y1]: ");
	scanf("%d,%d", &x11, &y11);

	printf("Entre el punto destino 2 [x2,y2]: ");
	scanf("%d,%d", &x21, &y21);
	
	initgraph(&gd, &gm, NULL);

	MidPointLine(x1, y1, x2, y2);
	
	line(x11, y11, x21, y21);

	getch();

	closegraph();
	return 0;
}

void MidPointLine(int x0, int y0, int x1, int y1)
{
	int x, y, dx, dy, xend, p, incE, incNE;
	int maxY;
    
	dx = x1 - x0; 
    dy = y1 - y0; 
	
	maxY=getmaxy();
    
	p = 2 * dy - dx; 
    incE = 2 * dy;
    incNE = 2 * (dy - dx);
    
    /* determinar que punto usar para empezar, cual para terminar */
    if (x0 > x1) { 
		x = x1; 
		y = y1;
        xend = x0;
    }
    else {
        x = x0;
        y = y0;
        xend = x1;
    }
    
    /* se repite hasta llegar al extremo de la línea */
    while (x <= xend)
    {
        putpixel(x, y, WHITE); 
		x = x + 1;
        if (p <= 0) {
            p = p + incE;
		}
        else {
            y = y + 1;
            p = p + incNE;
        }
    }
}