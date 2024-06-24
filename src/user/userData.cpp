#include "userlogin.h"
#include <imgui.h>
#include <iostream>

bool RenderUILogin(User *loggedInuser, GLFWwindow *loginwindow) {
  static char UserBuffer[256] = {};
  static char PasswordBuffer[256] = {};

  // This is a comment

  int height, width;
  glfwGetWindowSize(loginwindow, &width, &height);
  ImGui::SetNextWindowSize(ImVec2(width, height));
  ImGui::SetNextWindowPos(ImVec2(0, 0));

  //  ImGui::SetNextWindowSize(ImVec2(1000, 800), ImGuiCond_FirstUseEver);
  ImGui::Begin("Login", nullptr, ImGuiWindowFlags_NoResize);
  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.69f, 0.85f, 0.9f, 1.0f));

  ImGui::InputText("Username", UserBuffer, IM_ARRAYSIZE(UserBuffer));
  ImGui::InputText("Passeord", PasswordBuffer, IM_ARRAYSIZE(PasswordBuffer),
                   ImGuiInputTextFlags_Password);

  ImGui::PopStyleColor();

  bool login = ImGui::Button("login");
  bool cancle = ImGui::Button("cancle");

  if (login) {
    std::string username(UserBuffer);
    std::string password(PasswordBuffer);

    if (username == "admin" && password == "password") {
      loggedInuser = new User(username, password);
      std::cout << "Username : " << loggedInuser->GetUsername() << std::endl;
      std::cout << "Passeord : " << loggedInuser->GetPassword() << std::endl;

    } else {
      ImGui::OpenPopup("Logged in error");
    }

    if (cancle) {

      ImGui::OpenPopup("Logged in Cancle");
      std::cout << "cancle button was accessed";
      ImGui::CloseCurrentPopup();
    }

    if (ImGui::BeginPopupModal("Logged in fail", nullptr,
                               ImGuiWindowFlags_AlwaysAutoResize)) {
      ImGui::Text("Invalid user name and password");
      if (ImGui::Button("ok", ImVec2(120, 0))) {
        ImGui::CloseCurrentPopup();
      }

      ImGui::End();
    }
  }
  return loggedInuser != nullptr;
}
