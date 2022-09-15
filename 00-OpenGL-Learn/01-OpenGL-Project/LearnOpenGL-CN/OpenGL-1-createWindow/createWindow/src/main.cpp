#include<stdio.h>
#include"glfw_type.h"

/*
* 后缀_callback为回调函数
*/
void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void close_callback(GLFWwindow* window);
void set_frame_buffer_callback(GLFWwindow* window, int width, int height);
int main() {

	//设置错误回调函数
	glfwSetErrorCallback(error_callback);

	//在使用大部分的GLFW的function之前，必需要先初始化glfw库
	if (!glfwInit()) {
		//error
		return -1;
	}

	//创建窗口之前，最好先统一指定使用的OpenGL的版本与核心，此处OpenGL为3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//创建窗口（OpenGL context）
	GLFWwindow* window = glfwCreateWindow(1080,760,"hello",NULL,NULL);
	//键盘按键回调
	glfwSetKeyCallback(window,key_callback);
	//窗口关闭回调，在glfwSetWindowShouldClose后调用
	glfwSetWindowCloseCallback(window,close_callback);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	//使用OpenGL的API必须要先设置当前的context（上下文、语境）（状态机）
	glfwMakeContextCurrent(window);

	/*
	* 在glfwMakeContextCurrent后才能调用glfwSetFramebufferSizeCallback或glfwGetFramebufferSize
	* 以得到帧缓冲区的参数后，调用glViewport进行绘制
	*/
	glfwSetFramebufferSizeCallback(window, set_frame_buffer_callback);

	//glad管理函数指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	//窗口关闭检测，检测flag，可通过glfwSetWindowShouldClose设置flag
	while (!glfwWindowShouldClose(window)) {

		//render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*
		* 帧缓冲区交换，将设置的画面显示到窗口上
		* GLFW使用double buffer
		* 也就说每个窗口使用两个rendering buffer：前buffer与后buffer；前buffer显示，后buffer渲染
		* 当后buffer渲染完成，就会交换两个buffer
		* 由于缓冲区将在屏幕更新时交换，导致屏幕撕裂。
		* 通常将交换间隔设置为 1（glfwSwapInterval (1)）。它可以设置为更高的值，但通常不建议这样做，因为会导致输入延迟
		*/
		glfwSwapBuffers(window);
		glfwSwapInterval(1);

		/*
		* GLFW需要经常window系统进行通信，既是为了接收事件也是表明应用没有卡死
		* 通常是buffer交换后就要processing events
		* 有两种方法：poll（轮询）以及wait，通常我们都是使用轮询glfwPollEvents，也是最好的方法
		*/
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}


/*
* error_callback用在glfwSetErrorCallback(error_callback)中，
* 进入glfwSetErrorCallback可以看到回调函数的定义：GLFWAPI GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun callback);
* 其中GLFWerrorfun callback能够看到回调函数类型及参数
* 进入能够看见：typedef void (* GLFWerrorfun)(int error_code, const char* description);
* GLFWerrorfun：GLFWerrorfun并非函数指针，而是一种类型，代表返回值为void，接受参数int、const char*的指针
* 即error_callback（函数名记录函数入口地址）的类型为GLFWerrorfun，返回值为void，需要两个参数int和const char*
*/
void error_callback(int error,const char* description) {
	fprintf(stderr, "error %d: %s\n", error,description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		//检测到按下ESC后，设置关闭窗口的flag
		glfwSetWindowShouldClose(window,GLFW_TRUE);
	}
}

//窗口关闭的回调函数，函数在glfwSetWindowCloseCallback中调用
void close_callback(GLFWwindow* window) {
	// log
	printf("close_callback");
}

//帧缓冲区的回调，用于处理绘制窗口
void set_frame_buffer_callback(GLFWwindow* window, int width, int height) {
	/*
	* 绘制视口用于渲染窗口，视口即使能够看见并将会渲染的区域
	* 四个参数依次为：坐标x，坐标y，宽，高
	* glViewport给出了渲染的区域
	*/
	glViewport(0,0, width, height);
}