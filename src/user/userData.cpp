#include <imgui.h>
#include <iostream>
#include <sqlite3.h>

class User {
private:
  std::string userName;
  char userPassword[256];
  std::string useEmai;
  double userNumber;
  std::string userId;

public:
  void Password() {
    ImGui::Text("Enter Password");
    ImGui::InputText("Password", userPassword, sizeof(userPassword));
  }
};

void userProfile() {
  User user;
  user.Password();
}
