#include <imgui.h>
#define STB_IMAGE_IMPLEMENTATION
#include "/home/etoski/Libaries/stb/stb_image.h"
#include "GL/gl.h"

void RenderImageWindow(const char *imagePath, int width, int height) {

  ImGui::Begin("EventPlanner", nullptr,
               ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                   ImGuiWindowFlags_NoTitleBar);

  // Load the image file
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
                 ImVec2(static_cast<float>(width), static_cast<float>(height)));

    glTextureID = 0;

    // Clean up
    glDeleteTextures(1, &glTextureID);
    stbi_image_free(imageData);
  } else {
    ImGui::Text("Failed to load image.");
  }

  ImGui::End();
}
