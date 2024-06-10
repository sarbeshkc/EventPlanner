#ifndef DEBUG

#include "imgui.h"
#include <iostream>
#include <ostream>
#include <sqlite3.h>
#include <string>

class User {
private:
  std::string m_username;
  std::string m_password;

public:
  User(const std::string &username, const std::string &password)
      : m_username(username), m_password(password) {}

  const std::string &GetUsername() const { return m_username; }
  const std::string &GetPassword() const { return m_password; }
};

bool RenderUILogin(User *loggedInuser);

#endif // !DEBUG
