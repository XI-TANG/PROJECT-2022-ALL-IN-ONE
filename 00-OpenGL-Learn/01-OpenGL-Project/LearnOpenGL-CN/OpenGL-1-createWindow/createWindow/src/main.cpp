#include<stdio.h>
#include"glfw_type.h"

void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void close_callback(GLFWwindow* window);
int main() {

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		//error
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1080,760,"hello",NULL,NULL);
	glfwSetKeyCallback(window,key_callback);
	glfwSetWindowCloseCallback(window,close_callback);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {

	}




	glfwTerminate();

	return 0;
}

void error_callback(int error,const char* description) {
	fprintf(stderr, "error %d: %s\n", error,description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		printf("XXXXXXXX");
		glfwSetWindowShouldClose(window,GLFW_TRUE);
	}
}

void close_callback(GLFWwindow* window) {
	// log
	printf("close_callback");
}