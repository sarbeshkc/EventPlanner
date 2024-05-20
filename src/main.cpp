
#include <GLFW/glfw3.h>
#include <boost/asio.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <sqlite3.h>

int main() {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  // Create a window
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Campus Event Planner", nullptr, nullptr);
  if (!window) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);

  // Initialize ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // SQLite test
  sqlite3 *db;
  int rc = sqlite3_open(":memory:", &db);
  if (rc != SQLITE_OK) {
    std::cout << "Failed to open SQLite database: " << sqlite3_errmsg(db)
              << std::endl;
    sqlite3_close(db);
    return -1;
  }
  sqlite3_close(db);

  // Boost.ASIO test
  boost::asio::io_context io_context;
  boost::asio::steady_timer timer(io_context, boost::asio::chrono::seconds(1));
  timer.wait();

  // nlohmann/json test

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Start a new ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Create a simple ImGui window
    ImGui::Begin("Campus Event Planner");
    ImGui::Text("Hello, ImGui!");
    ImGui::End();

    // Render ImGui
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  // Clean up ImGui and GLFW
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
