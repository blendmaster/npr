
#include <GL/gl.h>
#include <glm/glm.hpp>

#pragma once

namespace EZGraphics {

  /* ------------------------------------------- */

  typedef enum { Array, ElemArray }  BufType;

  /* ------------------------------------------- */

  class Buffer {
  
  private:
    GLuint handle; 
    BufType tp;
    GLenum type;
    int components;

  public:
    Buffer ( const Buffer &a );
    Buffer ( const int cs, const int size, const GLubyte * const data = NULL, const BufType t = Array );
    Buffer ( const int cs, const int size, const GLbyte * const data = NULL, const BufType t = Array );
    Buffer ( const int cs, const int size, const GLuint * const data = NULL, const BufType t = Array );
    Buffer ( const int cs, const int size, const GLint * const data = NULL, const BufType t = Array );
    Buffer ( const int cs, const int size, const GLshort * const data = NULL, const BufType t = Array );
    Buffer ( const int cs, const int size, const GLushort * const data = NULL, const BufType t = Array );
    Buffer ( const int cs, const int size, const GLfloat * const data = NULL, const BufType t = Array );

    Buffer ( const int size, const GLubyte * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const GLbyte * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const GLshort * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const GLushort * const data = NULL, const BufType t = Array );

    Buffer ( const int size, const GLint * const data, const BufType t = Array );
    Buffer ( const int size, const glm::ivec2 * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const glm::ivec3 * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const glm::ivec4 * const data = NULL, const BufType t = Array );

    Buffer ( const int size, const GLuint * const data, const BufType t = Array );
    Buffer ( const int size, const glm::uvec2 * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const glm::uvec3 * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const glm::uvec4 * const data = NULL, const BufType t = Array );

    Buffer ( const int size, const GLfloat * const data, const BufType t = Array );
    Buffer ( const int size, const glm::vec2 * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const glm::vec3 * const data = NULL, const BufType t = Array );
    Buffer ( const int size, const glm::vec4 * const data = NULL, const BufType t = Array );

    ~Buffer();
    Buffer & operator= ( const Buffer & rhs );

    void setIndex ( int aix ) const;
    void on();
    void off();

    GLenum getType() const { return type; }
    GLuint getHandle() const { return handle; }

//    void useAsShaderStorage ( GLuint index );
  };

  /* ------------------------------------------- */

  class IndexBuffer : public Buffer {
  public:
    IndexBuffer ( const int size, const GLubyte * const data = NULL );
    IndexBuffer ( const int size, const GLuint * const data = NULL );
    IndexBuffer ( const int size, const GLushort * const data = NULL );

    IndexBuffer ( const int size, const glm::uvec2 * const data = NULL );
    IndexBuffer ( const int size, const glm::uvec3 * const data = NULL );

    IndexBuffer ( const IndexBuffer & );
    IndexBuffer & operator= ( const IndexBuffer & );
  };

  /* ------------------------------------------- */

};
