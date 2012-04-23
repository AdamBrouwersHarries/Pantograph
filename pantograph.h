//===================================================
//PANTOGRAPH TOOLKIT, Copyright Adam Harries 2012
//Main include file
//===================================================

int p_open_window(int width, int height, int fullscreen, const char* title)
{
	glfwInit();
	glfwDisable(GLFW_AUTO_POLL_EVENTS);
	if(fullscreen)
	{
		glfwOpenWindow(width,height,8,8,8,8,0,0,GLFW_FULLSCREEN);
	}else{
		glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
		glfwOpenWindow(width,height,8,8,8,8,0,0,GLFW_WINDOW);		
	}
	glfwSetWindowTitle(title);
	//set the location of the opengl viewport?
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	return 1;
}
void p_begin_render()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();
}
void p_end_render()
{
	glfwSwapBuffers();
}
void p_close_window()
{
	glfwCloseWindow();
	glfwTerminate();
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF); //flush the input buffer so we can continue to use scanf
}
