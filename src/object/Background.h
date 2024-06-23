#pragma once
#include "../glad.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <iostream>
#include <map>

class Texture {
public:
  Texture() {}
  Texture(GLuint id, int width, int height) {
    this->id = id;
    this->width = width;
    this->height = height;
  }

  ~Texture() {
    glDeleteTextures(1, &this->id);
    this->id = 0U;
  }

  enum LoadResult : int32_t {
    FileLoadFailure = 0,
    Sucess,
    TextureIdGenFailure,

  };

  LoadResult loadFromFile(const std::string &path);
  ImVec2 getSize() const;

  GLuint id{0U};
  GLsizei height{0};
  GLsizei width{0};
  int channelCount{0};
};

void RenderSplashImage(const std::string &textureAlias,
                       const std::map<std::string, Texture> &textureIDs,
                       const ImVec2 &windowMaxSize = ImVec2(400, 400));
