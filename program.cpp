
#include <GL/glew.h>
#include <GL/gl.h>
#include <assert.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <glm/gtc/matrix_transform.hpp>

#include "program.h"

using namespace std;
using namespace glm;

namespace EZGraphics {

/* ------------------------------------------- */

ShaderFile::ShaderFile ( ShaderType t, string n ) : name(n), type(t) {}

ShaderFile::ShaderFile() : name(""), type(Vert) {}

/* ------------------------------------------- */

const Program * Program::laston = NULL;

/* ------------------------------------------- */

Program::Program ( const Program &a )
{
  cerr << "Attempting to copy Program object" << endl;
  exit(1);
}

/* ------------------------------------------- */

Program::Program ( const Shader *aa, const Shader *bb, const Shader *cc, const Shader *dd, const Shader *ee ) :
  c(NULL), e(NULL), v(NULL), f(NULL), g(NULL), one_warning_printed(false)
{
  const Shader *p[5] = {aa,bb,cc,dd,ee};
  handle = glCreateProgram();
  for ( int i=0; i<5; i++ )
    if (p[i])
      {
	switch(p[i]->getType())
	  {
	  case Vert : 
	    v = p[i];
	    break;
	  case Frag:
	    f = p[i];
	    break;
	  case Geom:
	    g = p[i];
	    break;
	  case TessE:
	    e = p[i];
	    break;
	  case TessC:
	    c = p[i];
	    break;
	  default:
	    exit(1);
	  }
	glAttachShader(handle,p[i]->getHandle());
      }

  glLinkProgram(handle);

  for ( int i=0; i<5; i++ )
    if (p[i])
      glDetachShader(handle,p[i]->getHandle());
  
  GLint n;
  glGetProgramiv(handle,GL_ACTIVE_UNIFORMS,&n);
  
  static GLchar vname[GL_ACTIVE_UNIFORM_MAX_LENGTH];

  for ( int i=0; i<n; i++ )
    {
      GLsizei chars;
      GLint size;
      GLenum t;
      glGetActiveUniform(handle,i,GL_ACTIVE_UNIFORM_MAX_LENGTH,&chars,&size,&t,vname);
      univars[string(vname)] = unidata(glGetUniformLocation(handle,vname),t);
    }
}

/* ------------------------------------------- */

Program::Program ( const vector <string> &l,
		   const Shader *aa, const Shader *bb, const Shader *cc, 
		   const Shader *dd, const Shader *ee ) :
  c(NULL), e(NULL), v(NULL), f(NULL), g(NULL), one_warning_printed(false)
{
  const Shader *p[5] = {aa,bb,cc,dd,ee};
  handle = glCreateProgram();
  for ( int i=0; i<5; i++ )
    if (p[i])
      {
	switch(p[i]->getType())
	  {
	  case Vert : 
	    v = p[i];
	    break;
	  case Frag:
	    f = p[i];
	    break;
	  case Geom:
	    g = p[i];
	    break;
	  case TessE:
	    e = p[i];
	    break;
	  case TessC:
	    c = p[i];
	    break;
	  default:
	    exit(1);
	  }
	glAttachShader(handle,p[i]->getHandle());
      }

  const char **names = new const char*[l.size()];
  int index = 0;
  for ( vector<string>::const_iterator i = l.begin(); i!=l.end(); ++i )
    names[index++] = i->c_str();
  glTransformFeedbackVaryings(handle,index,names,GL_SEPARATE_ATTRIBS);
  
  glLinkProgram(handle);
  delete[] names;

  for ( int i=0; i<5; i++ )
    if (p[i])
      glDetachShader(handle,p[i]->getHandle());
  
  GLint n;
  glGetProgramiv(handle,GL_ACTIVE_UNIFORMS,&n);

  static GLchar vname[GL_ACTIVE_UNIFORM_MAX_LENGTH];

  for ( int i=0; i<n; i++ )
    {
      GLsizei chars;
      GLint size;
      GLenum t;
      glGetActiveUniform(handle,i,GL_ACTIVE_UNIFORM_MAX_LENGTH,&chars,&size,&t,vname);
      univars[string(vname)] = unidata(glGetUniformLocation(handle,vname),t);
    }
}

/* ------------------------------------------- */

Program & Program::operator= ( const Program & rhs )
{
  cerr << "Attempting assignment for a Program object" << endl;
  exit(1);
}

/* ------------------------------------------- */

Program::~Program()
{
  if (!handle)
    return;
  assert(glIsProgram(handle));
  glDeleteProgram(handle);
}

/* ------------------------------------------- */

void Program::on() const
{
  laston = this;
  glUseProgram(handle);
}

/* ------------------------------------------- */

void Program::off() const
{
  laston = NULL;
  glUseProgram(0);
}


/* ------------------------------------------- */

#define SETUNIFORM(ITYPE,GLTYPE,GLSET,VACCESS)		   \
  void Program::setUniform ( const GLchar *name, ITYPE v ) \
  {							   \
    map<string,unidata>::iterator u = univars.find(name);	   \
    if (u==univars.end())				   \
      {							   \
	if (one_warning_printed==false)				       \
	  cout << "No uniform variable " << name << " found" << endl;  \
        one_warning_printed = true;				       \
	return;							       \
      }								       \
    GLint loc = u->second.location;				       \
    GLenum type = u->second.type;				       \
								       \
    if (type!=GLTYPE)						       \
      {									\
	cerr << "Type mismatch in setUniform for uniform variable " << name << endl; \
	exit(1);							\
      }									\
									\
    glUseProgram(handle);						\
    GLSET(loc,1,VACCESS);						\
									\
    if (laston)								\
      laston->on();							\
  }
   
#define SETUNIFORMMAT(ITYPE,GLTYPE,GLSET,VACCESS)	   \
  void Program::setUniform ( const GLchar *name, ITYPE v ) \
  {							   \
    map<string,unidata>::iterator u = univars.find(name);			   \
    if (u==univars.end())				   \
      {							   \
	if (one_warning_printed==false)				       \
	  cout << "No uniform variable " << name << " found" << endl;  \
        one_warning_printed = true;				       \
	return;							       \
      }								       \
    GLint loc = u->second.location;				       \
    GLenum type = u->second.type;				       \
								       \
    if (type!=GLTYPE)						       \
      {									\
	cerr << "Type mismatch in setUniform for uniform variable " << name << endl; \
	exit(1);							\
      }									\
									\
    glUseProgram(handle);						\
    GLSET(loc,1,false,VACCESS);						\
									\
    if (laston)								\
      laston->on();							\
  }


SETUNIFORM(vec2,GL_FLOAT_VEC2,glUniform2fv,&v[0])
SETUNIFORM(vec3,GL_FLOAT_VEC3,glUniform3fv,&v[0])
SETUNIFORM(vec4,GL_FLOAT_VEC4,glUniform4fv,&v[0])

SETUNIFORM(ivec2,GL_INT_VEC2,glUniform2iv,&v[0])
SETUNIFORM(ivec3,GL_INT_VEC3,glUniform3iv,&v[0])
SETUNIFORM(ivec4,GL_INT_VEC4,glUniform4iv,&v[0])

SETUNIFORM(uvec2,GL_UNSIGNED_INT_VEC2,glUniform2uiv,&v[0])
SETUNIFORM(uvec3,GL_UNSIGNED_INT_VEC3,glUniform3uiv,&v[0])
SETUNIFORM(uvec4,GL_UNSIGNED_INT_VEC4,glUniform4uiv,&v[0])

SETUNIFORM(GLfloat,GL_FLOAT,glUniform1fv,&v)
SETUNIFORM(GLint,GL_INT,glUniform1iv,&v)
SETUNIFORM(GLuint,GL_UNSIGNED_INT,glUniform1uiv,&v)
  
SETUNIFORMMAT(mat2,GL_FLOAT_MAT2,glUniformMatrix2fv,&v[0][0])
SETUNIFORMMAT(mat3,GL_FLOAT_MAT3,glUniformMatrix3fv,&v[0][0])
SETUNIFORMMAT(mat4,GL_FLOAT_MAT4,glUniformMatrix4fv,&v[0][0])

SETUNIFORMMAT(mat2x3,GL_FLOAT_MAT2x3,glUniformMatrix2x3fv,&v[0][0])
SETUNIFORMMAT(mat3x2,GL_FLOAT_MAT3x2,glUniformMatrix3x2fv,&v[0][0])

SETUNIFORMMAT(mat2x4,GL_FLOAT_MAT2x4,glUniformMatrix2x4fv,&v[0][0])
SETUNIFORMMAT(mat4x2,GL_FLOAT_MAT4x2,glUniformMatrix4x2fv,&v[0][0])

SETUNIFORMMAT(mat3x4,GL_FLOAT_MAT3x4,glUniformMatrix3x4fv,&v[0][0])
SETUNIFORMMAT(mat4x3,GL_FLOAT_MAT4x3,glUniformMatrix4x3fv,&v[0][0])


/* ------------------------------------------- */

void Program::printLog ( )
{
  int infologLength = 0;
  int maxLength;
  
  glGetProgramiv(handle,GL_INFO_LOG_LENGTH,&maxLength);
  char infoLog[maxLength];
  glGetProgramInfoLog(handle, maxLength, &infologLength, infoLog);
  
  if (infologLength > 0)
    cout << infoLog << endl;
}

/* --------------------------------------------- */

Program::operator bool()
{
  GLint status;
  glGetProgramiv(handle,GL_LINK_STATUS,&status);
  return (status==GL_TRUE);
}

/* --------------------------------------------- */

  static string _type2string ( ShaderType t )
  {
    switch(t)
      {
      case Vert:
	return "Vertex";
	break;
      case Frag:
	return "Fragment";
	break;
      case Geom:
	return "Geometry";
	break;
      case TessC:
	return "Tesselation control";
	break;
      case TessE:
	return "Tesselation Evaluation";
	break;
      default:
	cout << "Unknown shader type" << endl;
	exit(1);
	break;
      }
  }

/* --------------------------------------------- */

Program * createProgram ( ShaderFile s1, ShaderFile s2, ShaderFile s3, ShaderFile s4, ShaderFile s5 )
{
  ShaderFile in[5];
  Shader *sh[5] = {NULL,NULL,NULL,NULL,NULL};
  int ins = 0;
  
  if (s1.name!="") in[ins++] = s1;
  if (s2.name!="") in[ins++] = s2;
  if (s3.name!="") in[ins++] = s3;
  if (s4.name!="") in[ins++] = s4;
  if (s5.name!="") in[ins++] = s5;

  for ( int i=0; i<ins; i++ )
    for ( int j=i+1; j<ins; j++ )
      if (in[i].type==in[j].type)
	{
	  cout << "Program cannot contain two shaders for the same pipeline stage" << endl;
	  exit(1);
	}

  bool failed = false;

  for ( int i=0; i<ins; i++ )
    {
      string src = ReadFromFile(in[i].name.c_str());
      sh[i] = new Shader(in[i].type,src);
      cout << _type2string(in[i].type) << " shader log:" << endl;
      sh[i]->printLog();
      failed = failed || !sh[i];
    }

  if (failed)
    {
      cout << "Compilation of one of the shaders failed!" << endl;
      exit(1);
    }

  Program *res = new Program(sh[0],sh[1],sh[2],sh[3],sh[4]);

  cout << "Program info log: " << endl;
  res->printLog();
  if (!*res)
    {
      cout << "Linking failed!" << endl;
      exit(1);
    }

  // mark shaders for deletion
  for ( int i=0; i<ins; i++ )
    delete sh[i];

  return res;
}

};
