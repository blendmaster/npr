
#include <vector>
#include <texture.h>

#pragma once

namespace EZGraphics {

  class Framebuffer {

    GLuint handle;
    std::vector<GLenum> color_attachments;

  public:
    Framebuffer();
    ~Framebuffer();
    void attachDepth ( Texture *t );
    void attachStencil ( Texture *t );
    void attachDepthStencil ( Texture *t );
    void attachColor ( Texture *t, int i = 0 );
    void on();
    void off();

    // returns error
    GLenum printLog();
  };

};
