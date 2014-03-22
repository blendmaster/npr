
#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/gl.h>

#include "shader.h"

using namespace std;

namespace EZGraphics {

/* ------------------------------------------- */

Shader::Shader ( const Shader &a )
{
  cerr << "Attempting to copy Shader objects" << endl;
  exit(1);
}

/* ------------------------------------------- */

Shader::Shader ( const ShaderType t, const string source )
{
  tp = t;
  
  switch(t)
    {
    case Vert:
      handle = glCreateShader(GL_VERTEX_SHADER);
      break;
    case Frag:
      handle = glCreateShader(GL_FRAGMENT_SHADER);
      break;
    case Geom:
      handle = glCreateShader(GL_GEOMETRY_SHADER);
      break;
    case TessE:
      handle = glCreateShader(GL_TESS_EVALUATION_SHADER);
      break;
    case TessC:
      handle = glCreateShader(GL_TESS_CONTROL_SHADER);
      break;
    default:
      assert(0);
    }

  const GLchar *ssrc = source.c_str();

  glShaderSource(handle,1,&ssrc,NULL);
  glCompileShader(handle);
}

/* ------------------------------------------- */

Shader::~Shader()
{
  if (!handle)
    return;
  // delete the buffer
  assert(glIsShader(handle));
  glDeleteShader(handle);
  handle = 0;
}

/* ------------------------------------------- */

Shader & Shader::operator= ( const Shader & rhs )
{
  cerr << "Attempting assignment of Shader objects" << endl;
  exit(1);
}

  /* ------------------------------------------- */

ShaderType Shader::getType() const 
{
  return tp;
}

/* ------------------------------------------- */

GLuint Shader::getHandle() const
{
  return handle;
}

void Shader::printLog ()
{
  int infologLength = 0;
  int maxLength;
  glGetShaderiv(handle,GL_INFO_LOG_LENGTH,&maxLength);
  char infoLog[maxLength];  
  glGetShaderInfoLog(handle, maxLength, &infologLength, infoLog);
  if (infologLength > 0)
    cout << infoLog << endl;
}


/* ------------------------------------------- */

string ReadFromFile ( const char *name )
{
  ifstream ifs(name);
  if (!ifs)
    {
      cout << "Can't open " << name << endl;
      return string("");
    }
  stringstream sstr;
  sstr << ifs.rdbuf();
  return sstr.str();
}

/* ------------------------------------------- */

Shader::operator bool()
{
  GLint status;
  glGetShaderiv(handle,GL_COMPILE_STATUS,&status);
  return status==GL_TRUE;
}


/* ------------------------------------------- */

};
