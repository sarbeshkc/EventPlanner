#include "../src/user/userlogin.h"
#include "../src/user_Interface/mainWindow.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

void frame_buffer_size_callback(GLFWwindow *window, int height, int width) {
  glViewport(0, 0, width, height);
}

int main() {
  if (!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Creating Glfw window
  GLFWwindow *window =
      glfwCreateWindow(2000, 1000, "Event planner", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

  // Setting up imgui CreateContext
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO &io = ImGui::GetIO();

  // Setting up platform and render binding

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  // Setting up imgui window
  ImGui::StyleColorsDark();

  // Showing Window Logic

  bool showLoginWindow = false;
  bool button_pressed = false;
  bool isRendered = false;
  /*
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame(); */

  while (!glfwWindowShouldClose(window)) {

    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);

    // Code Sarts From here

    ImGui::SetNextWindowSize(

        ImVec2(static_cast<float>(display_w), static_cast<float>(display_h)));
    /*
    ImGui::Begin("EventPlanner", nullptr,
                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoTitleBar);  */
    User *FirstUser;
    RenderUILogin(FirstUser);
    //  RenderImageWindow("../images/Demo.jpeg", 2000, 800);

    if (ImGui::Button("Load Splash Page")) {
      button_pressed = true;
    }
    if (button_pressed == true) {
      SplashPage(window, "../images/Demo.jpeg");
      SplashPage(window, "../images/cwajkd.jpg");
    }

    ImGui::End();
    ImGui::Render();
    glViewport(0, 0, display_w, display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  }

  glfwDestroyWindow(window);
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
