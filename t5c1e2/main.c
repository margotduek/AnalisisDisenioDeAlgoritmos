/* Algoritmo Bresenham para el trazado de líneas */
#include <stdio.h>
#include <graphics.h>

void BresenhamLine(float x0, float y0, float x1, float y1);

int main(int argc, char **argv)
{
	float x1, y1, x2, y2;
	
	int gd = DETECT, gm = VGAMAX;
	
	printf("Entre el punto de origen [x1,y1]: ");
	scanf("%f,%f", &x1, &y1);

	printf("Entre el punto destino [x2,y2]: ");
	scanf("%f,%f", &x2, &y2);
	
	initgraph(&gd, &gm, NULL);

	BresenhamLine(x1, y1, x2, y2);

	getch();

	closegraph();
	return 0;
}

void BresenhamLine(float x0, float y0, float x1, float y1)
{
	int x, y, dx, dy, xend, p, incE, incNE;
	int maxY;
    
	dx = abs(x1 - x0); 
    dy = abs(y1 - y0); 
	
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
        if (p < 0) {
            p = p + incE;
		}
        else {
            y = y + 1;
            p = p + incNE;
        }
    }
}