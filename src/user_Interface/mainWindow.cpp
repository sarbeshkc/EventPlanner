#include "../object/Background.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
void SplashPage(GLFWwindow *windowload, const char *ImageLoaction) {

  // Initialize GLFW and create a window
  /*
    GLFWwindow *window = glfwCreateWindow(800, 600, "My Window", NULL, NULL);
    if (!window) {
      glfwTerminate();
    }
  */
  // Make the window's context current
  glfwMakeContextCurrent(windowload);

  int height;
  int width;

  glfwGetWindowSize(windowload, &height, &width);
}
