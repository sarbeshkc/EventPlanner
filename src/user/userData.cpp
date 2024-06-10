#include "userlogin.h"
#include <imgui.h>
#include <iostream>

bool RenderUILogin(User *loggedInuser) {
  static char UserBuffer[256] = {};
  static char PasswordBuffer[256] = {};

  ImGui::SetNextWindowSize(ImVec2(1000, 800), ImGuiCond_FirstUseEver);
  ImGui::Begin("Login", nullptr, ImGuiWindowFlags_NoResize);

  ImGui::InputText("Username", UserBuffer, IM_ARRAYSIZE(UserBuffer));
  ImGui::InputText("Passeord", PasswordBuffer, IM_ARRAYSIZE(PasswordBuffer),
                   ImGuiInputTextFlags_Password);

  bool login = ImGui::Button("login");
  bool cancle = ImGui::Button("cancle");

  if (login) {
    std::string username(UserBuffer);
    std::string password(PasswordBuffer);

    if (username == "admin" && password == "password") {
      loggedInuser = new User(username, password);
      std::cout << "Username : " << loggedInuser->GetUsername() << std::endl;
      std::cout << "Passeord : " << loggedInuser->GetPassword() << std::endl;
      ImGui::CloseCurrentPopup();
    } else {
      ImGui::OpenPopup("Logged in error");
    }

    if (cancle) {
      ImGui::OpenPopup("Logged in Cancle");
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
