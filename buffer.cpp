
#include <GL/glew.h>
#include <GL/gl.h>
#include <assert.h>
#include <cstdlib>
#include <iostream>

#include "buffer.h"

/* ------------------------------------------- */

using namespace std;

namespace EZGraphics {

/* ------------------------------------------- */

Buffer::Buffer ( const Buffer &a )
{
  cerr << "Attempting to use copy constructor for a Buffer object" << endl;
  exit(1);
}

/* ------------------------------------------- */

Buffer::Buffer ( const int cs, const int size, const GLubyte * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_UNSIGNED_BYTE;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLubyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLubyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  /* ------------------------------------------- */

Buffer::Buffer ( const int size, const GLubyte * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_UNSIGNED_BYTE;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLubyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLubyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer (  const int cs, const int size, const GLbyte * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_BYTE;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLbyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLbyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer (  const int size, const GLbyte * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_BYTE;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLbyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLbyte),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer (  const int cs, const int size, const GLshort * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_SHORT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLshort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLshort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int size, const GLshort * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_SHORT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLshort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLshort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int cs, const int size, const GLushort * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_UNSIGNED_SHORT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLushort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLushort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int size, const GLushort * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_UNSIGNED_SHORT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLushort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLushort),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int cs, const int size, const GLuint * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_UNSIGNED_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int size, const GLuint * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_UNSIGNED_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int cs, const int size, const GLint * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int size, const GLint * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (  const int cs, const int size, const GLfloat * const data, const BufType t )
{
  tp = t;
  components = cs;
  type = GL_FLOAT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer (   const int size, const GLfloat * const data, const BufType t )
{
  tp = t;
  components = 1;
  type = GL_FLOAT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}
  
/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::vec2 * const data, const BufType t ) 
{
  int cs = 2;
  tp = t;
  components = cs;
  type = GL_FLOAT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }  
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::vec3 * const data, const BufType t ) 
{
  int cs = 3;
  tp = t;
  components = cs;
  type = GL_FLOAT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }    
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::vec4 * const data, const BufType t ) 
{
  int cs = 4;
  tp = t;
  components = cs;
  type = GL_FLOAT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLfloat),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }    
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::ivec2 * const data, const BufType t ) 
{
  int cs = 2;
  tp = t;
  components = cs;
  type = GL_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::ivec3 * const data, const BufType t )
{
  int cs = 3;
  tp = t;
  components = cs;
  type = GL_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::ivec4 * const data, const BufType t )
{
  int cs = 4;
  tp = t;
  components = cs;
  type = GL_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::uvec2 * const data, const BufType t )
{
  int cs = 2;
  tp = t;
  components = cs;
  type = GL_UNSIGNED_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::uvec3 * const data, const BufType t )
{
  int cs = 3;
  tp = t;
  components = cs;
  type = GL_UNSIGNED_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::Buffer ( const int size, const glm::uvec4 * const data, const BufType t )
{
  int cs = 4;
  tp = t;
  components = cs;
  type = GL_UNSIGNED_INT;
  glGenBuffers(1,&handle);
  switch(t)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      glBufferData(GL_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,cs*size*sizeof(GLuint),data,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    default:
      assert(0);
    }
}

/* ------------------------------------------- */

Buffer::~Buffer()
{
  if (!handle)
    return;
  assert(glIsBuffer(handle));
  glDeleteBuffers(1,&handle);
}
  
/* ------------------------------------------- */

Buffer & Buffer::operator= ( const Buffer & rhs )
{
  cerr << "Attempting to use assignment operator for a Buffer object" << endl;
  exit(1);
}

/* ------------------------------------------- */

void Buffer::setIndex ( int aix ) const
{
  glBindBuffer(GL_ARRAY_BUFFER,handle);
  if (type==GL_BYTE || type==GL_UNSIGNED_BYTE || type==GL_SHORT || type==GL_UNSIGNED_SHORT || type==GL_INT || type==GL_UNSIGNED_INT)
    glVertexAttribIPointer(aix,components,type,0,0);    
  else
    glVertexAttribPointer(aix,components,type,GL_FALSE,0,0);    
  glBindBuffer(GL_ARRAY_BUFFER,0);
}

/* ------------------------------------------- */

void Buffer::on()
{
  switch(tp)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,handle);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,handle);
      break;
    }
}

/* ------------------------------------------- */

void Buffer::off()
{
  switch(tp)
    {
    case Array :
      glBindBuffer(GL_ARRAY_BUFFER,0);
      break;
    case ElemArray :
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      break;
    }
}

/* ------------------------------------------- */
/*
void Buffer::useAsShaderStorage ( GLuint index )
{
  glBindBufferBase(GL_SHADER_STORAGE_BUFFER,index,handle);
}
*/
/* ------------------------------------------- */

IndexBuffer::IndexBuffer ( const int size, const GLubyte * const data ) :
  Buffer(1,size,data,ElemArray) {}

IndexBuffer::IndexBuffer ( const int size, const GLuint * const data ) :
  Buffer(1,size,data,ElemArray) {}
      
IndexBuffer::IndexBuffer ( const int size, const GLushort * const data ) :
  Buffer(1,size,data,ElemArray) {}

IndexBuffer::IndexBuffer ( const int size, const glm::uvec2 * const data ) :
  Buffer(size,data,ElemArray) {}

IndexBuffer::IndexBuffer ( const int size, const glm::uvec3 * const data ) :
  Buffer(size,data,ElemArray) {}

IndexBuffer::IndexBuffer ( const IndexBuffer & e ) : Buffer(e)
{
  cerr << "Attempting to make a copy of an IndexBuffer object" << endl;
  exit(1);
}
    
IndexBuffer & IndexBuffer::operator= ( const IndexBuffer & )
{
  cerr << "Attempting assignment of IndexBuffer objects " << endl;
  exit(1);
}
  

/* ------------------------------------------- */

};
