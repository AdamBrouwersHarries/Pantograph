#include <stdio.h>
#include <stdlib.h>
#include "glfw.h"
#include "pantograph.h"
int main(int argc, char** argv)
{
	printf("program start\n");
	printf("how many iterations do you want to run for? ");
	int j = 1000;
	scanf("%i", &j);
	j = j % 1000;
	printf("\nRunning for %i iterations\n",j);
	p_open_window(1000, 500, 0, "hi there");
	int i = 0;
	for(i=0;i<j;i++)
	{
		p_begin_render();
		glBegin(GL_POINTS);
			glVertex2i(i,i/2);
		glEnd();
		p_end_render();
	}
	p_close_window();
	scanf("%i",&j); //this does not work
	printf("%i", j);
	system("PAUSE");
	return 0;
}