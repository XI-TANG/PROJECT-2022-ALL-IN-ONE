#include <stdio.h>
#include <glad/glad.h> 
#include <GLFW\glfw3.h>

void error_callback(int error_code, const char* description);
void window_callback(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1080, 760, "triangle", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window,key_callback);
	glfwSetWindowCloseCallback(window, window_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwTerminate();
		return -1;
	}
	//glViewport中的参数均是GLAD类型，因此必须再gladLoadGLLoader后执行
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	while (!glfwWindowShouldClose(window)) {
		
		if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window,GLFW_TRUE);
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwSwapInterval(1);

		glfwPollEvents();
	}


	glfwTerminate();

	return 0;
}

void error_callback(int error_code, const char* description) {
	printf("ERROR CODE[%d]: %s", error_code, description);
}

void window_callback(GLFWwindow* window) {
	//printf("XXX");
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
}