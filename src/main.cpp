#include "../src/object/Background.h"
#include "../src/user/userlogin.h"
#include "glad.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <map>
#include <string>

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

  int32_t wndWidth{896};
  int32_t wndHeight{504};

  // Showing Window Logic

  bool showLoginWindow = false;
  bool button_pressed = false;
  bool isRendered = false;
  bool loginButton = false;

  std::map<std::string, Texture> textures;
  /*
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame(); */

  // Crerating a window everytime

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

    User *GettingUser;
    RenderUILogin(GettingUser, window);

    /*
    ImGui::Begin("EventPlanner", nullptr,
                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoTitleBar);  */
    /*
        if (ImGui::Button("Click for login")) {
          loginButton = true;
        }

        if (loginButton == true) {
          User *ExistingUser;
          RenderUILogin(ExistingUser, window);
        }
    */
    /*
    if (ImGui::Button("SignUP")) {
    }
    User *FirstUser;
    RenderUILogin(FirstUser, window);  */
    //  RenderImageWindow("../images/Demo.jpeg", 2000, 800);

    /*
    if (ImGui::Button("Load Splash Page")) {
      button_pressed = true;
    }
    if (button_pressed == true) {
      SplashPage(window, "../images/Demo.jpeg");
      SplashPage(window, "../images/cwajkd.jpg");
    }
    */

    if (ImGui::Button("LoadTexture")) {
      // alias can be anything
      Texture &testTexture = textures["image_alias"];

      if (testTexture.loadFromFile(
              "/home/etoski/Documents/4af65be5c257b1d403eeb036cadab979.png") !=
          Texture::Sucess) {
        std::cout << "Failed to load the texture!\n";
      }

      if (textures["second_image"].loadFromFile("../images/cwajkd.jpg") !=
          Texture::Sucess) {
        std::cout << "Failed to load the texture!\n";
      }
    }

    RenderSplashImage("image_alias", textures);
    RenderSplashImage("second_image", textures);

    ImGui::Render();
    glViewport(0, 0, display_w, display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.69f, 0.85f, 0.9f, 1.0f);
  }

  glfwDestroyWindow(window);
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
