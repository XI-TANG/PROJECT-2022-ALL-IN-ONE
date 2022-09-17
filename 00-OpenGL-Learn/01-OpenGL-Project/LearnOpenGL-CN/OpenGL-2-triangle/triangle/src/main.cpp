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
	//glViewport�еĲ�������GLAD���ͣ���˱�����gladLoadGLLoader��ִ��
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	unsigned int VBOId = 0;
	/*
	* ʹ��glGenBuffers�����ͻ��buffer memory��ID������VBOId��
	* ����ʹ�õ���&VBOId��Ҳ����glGenBuffers���޸�VBOId��ֵ
	* ��ȻҲ��������һ���������ͣ���ô������3��buffer memory��id�����α�����������
	* Ĭ�ϵ�ID��0�����������ɵı�Ȼ��0
	* �ٷ��ĵ�ָ����GL_INVALID_VALUE is generated if buffer is not a name previously returned form a call to glGenBuffers��
	* ���仰˵�����������Ȼ��GLuint���͵ģ�������������ֱ��ָ������������˵0
	* ����ͬһʱ�䣬���ܰ�������ͬ���͵Ļ������
	*/
	glGenBuffers(1,&VBOId);
	//printf("glGenBuffers ID: %d\n", VBOId);


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