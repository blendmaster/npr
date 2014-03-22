
#include <vector>
#include "buffer.h"

#pragma once

namespace EZGraphics {

  /* ------------------------------------------- */

  class VertexArray {

  private:
    GLuint handle;

  public:

    VertexArray();
    ~VertexArray();

    VertexArray ( const VertexArray & );
    VertexArray & operator= ( const VertexArray & );

    void attachInstancedAttribute ( const GLuint aix, const Buffer * b, GLuint divisor = 1 );
    void attachAttribute ( const GLuint aix, const Buffer *b );

    void on();
    void off();

    void sendToPipeline ( GLenum ptype, GLint first, GLsizei num );
    void sendToPipelineIndexed ( GLenum ptype, IndexBuffer *b, GLint first, GLsizei num );

    void sendToPipelineInstanced ( GLenum ptype, GLint first, GLsizei num, GLsizei N );
    void sendToPipelineInstancedIndexed ( GLenum ptype, IndexBuffer *b, GLint first, GLsizei num, GLsizei N );

    void setDivisor ( GLuint aix, GLuint divisor );
    void resetDivisor ( GLuint aix );
  };
  

/* ------------------------------------------- */

};
