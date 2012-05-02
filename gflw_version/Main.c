#include <stdio.h>
#include <stdlib.h>
#include "glfw.h"
#include "pantograph.h"

int data;
void menu()
{
	int user_input;
	printf("Enter 1 to display window, 0 to display a whole load of random text:");
	scanf("%i",&user_input);
	if(user_input == 1)
	{
		p_open_window(1000, 500, 0, "hi there");
		int i = 0;
		for(i=0;i<1000;i++)
		{
			p_begin_render();
			glBegin(GL_POINTS);
				glVertex2i(i,i/2);
			glEnd();
			p_end_render();
		}
		p_close_window();
	}else{
		int i = 0;
		for(i = 0;i<1000;i++)
		{
			printf("%c", (char)rand());
		}
	}
}
int main(int argc, char** argv)
{
	while(1)
	{
		menu();
	}
	system("PAUSE");
	return 0;
}
