#include "../src/user/userlogin.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>

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
  GLFWwindow *window = glfwCreateWindow(1280, 700, "Event planner", NULL, NULL);
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

  while (!glfwWindowShouldClose(window)) {

    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);

    if (!showLoginWindow) {
      ImGui::SetNextWindowSize(
          ImVec2(static_cast<float>(display_w), static_cast<float>(display_h)));
      ImGui::Begin("EventPlanner", nullptr,
                   ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                       ImGuiWindowFlags_NoTitleBar);
      ImGui::Button("click");
      if (ImGui::Button("Loginnn", ImVec2(100, 50))) {
        showLoginWindow = true;
      }
      ImGui::End();
    }

    if (showLoginWindow) {
      User *loggedInUser = nullptr;
      bool isLoggedIn = false;
      isLoggedIn = RenderUILogin(loggedInUser);
      ImGui::End();
      if (isLoggedIn) {
        std::cout << "Username: " << loggedInUser->GetUsername() << std::endl;
        std::cout << "Password: " << loggedInUser->GetPassword() << std::endl;
        showLoginWindow = false; // Go back to the "EventPlanner" window
      }
    }
    ImGui::Render();
    glViewport(0, 0, display_w, display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
