#include <cstdio>
#include <filesystem>
#include <imgui.h>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "../glad.h"
#include "../object/Background.h"
#include "/home/etoski/Libaries/stb/stb_image.h"
#include <GLFW/glfw3.h>
/*

void RenderImageWindow(const char *imagePath, int width, int height) {

  ImGui::Begin("EventPlanner", nullptr,
               ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                   ImGuiWindowFlags_NoTitleBar);
    int channels;
    unsigned char *imageData =
        stbi_load(imagePath, &width, &height, &channels, 0);
    if (imageData) {
      // Create an ImGui texture object
      ImTextureID textureID = 0;
      GLuint glTextureID = 0;
      if (!textureID) {
        glGenTextures(1, &glTextureID);
        textureID = reinterpret_cast<ImTextureID>(glTextureID);
        glBindTexture(GL_TEXTURE_2D, glTextureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        GLenum format = (channels == 3) ? GL_RGB : GL_RGBA;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                     GL_UNSIGNED_BYTE, imageData);
      }

      // Render the image using ImGui::Image
      ImGui::Image(textureID,
                   ImVec2(static_cast<float>(width),
    static_cast<float>(height)));

      glTextureID = 0;

      // Clean up
      glDeleteTextures(1, &glTextureID);
      stbi_image_free(imageData);
    } else {
      ImGui::Text("Failed to load image.");
    }

}
*/

ImVec2 Texture::getSize() const { return ImVec2(width, height); }

Texture::LoadResult Texture::loadFromFile(const std::string &path) {
  if (this->id != 0) {
    glDeleteTextures(1, &this->id);
    std::cerr << "This is already loaded";
  }

  std::filesystem::path pathObj = path;
  int forceChannels = 0;

  if (pathObj.extension() == ".'png'") {
    forceChannels = STBI_rgb_alpha;
  }

  stbi_uc *textRawData = stbi_load(path.data(), &this->width, &this->height,
                                   &this->channelCount, forceChannels);

  if (textRawData == nullptr) {
    return FileLoadFailure;
  }

  glGenTextures(1, &this->id);

  if (this->id == 0) {
    stbi_image_free(textRawData);
    return LoadResult::TextureIdGenFailure;
  }

  glBindTexture(GL_TEXTURE_2D, this->id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);

  int glChannels = GL_RGB;

  if (forceChannels == STBI_rgb_alpha) {
    glChannels = GL_RGBA;
  }

  // this bellow uploades the texture from RAM to VRAM (gpu memory)
  glTexImage2D(GL_TEXTURE_2D, 0, glChannels, this->width, this->height, 0,
               glChannels, GL_UNSIGNED_BYTE, textRawData);

  // This doesm't work idk why , this should work id everything is correct
  //

  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(textRawData);

  std::cout << "Texture Sucessfullly loaded " << path << "   done1"
            << std::endl;

  return LoadResult::Sucess;
}

void RenderSplashImage(const std::string &textureAlias,
                       const std::map<std::string, Texture> &textureIDs,
                       const ImVec2 &windowMaxSize) {
  if (textureIDs.count(textureAlias) == 0) {
    return;
  }

  const Texture &tex = textureIDs.at(textureAlias);
  ImVec2 size = tex.getSize();

  ImGui::SetNextWindowSizeConstraints(ImVec2(0, 0), windowMaxSize);

  ImGui::Begin(std::string("ImageWindow - " + textureAlias).data(), nullptr,
               ImGuiWindowFlags_::ImGuiWindowFlags_HorizontalScrollbar);

  ImGui::Image(reinterpret_cast<ImTextureID>(textureIDs.at(textureAlias).id),
               size);
}
