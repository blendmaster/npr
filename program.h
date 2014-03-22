
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <map>
#include <string>
#include <glm/glm.hpp>

#include <buffer.h>

#include "shader.h"

#pragma once

namespace EZGraphics {

  /* ------------------------------------------- */

  struct ShaderFile {

    std::string name;
    ShaderType type;

    ShaderFile ( ShaderType t, std::string n );
    ShaderFile();
  };

  /* ------------------------------------------- */

  class Program {

  private:

    struct unidata {
      GLint location;
      GLenum type;
      unidata ( GLint l, GLint t ) : location(l), type(t) {}
      unidata() {}
    };

    static const Program * laston;

    GLuint handle;
    const Shader *c, *e, *v, *f, *g;
    const Shader *cmp;
    bool one_warning_printed;

    std::map<std::string,unidata> univars;

  protected:

    Program ( const std::vector<std::string> &l,
	      const Shader *aa = NULL, const Shader *bb = NULL, const Shader *cc = NULL, const Shader *dd = NULL, const Shader *ee = NULL );

  public:
    Program ( const Program &a );   // will generate an error
    Program & operator= ( const Program & rhs );  // will generate an error

    Program ( const Shader *aa = NULL, const Shader *bb = NULL, const Shader *cc = NULL, const Shader *dd = NULL, const Shader *ee = NULL );

    ~Program();

    void on() const;
    void off() const;

    void setUniform ( const GLchar *name, glm::vec2 v );
    void setUniform ( const GLchar *name, glm::vec3 v );
    void setUniform ( const GLchar *name, glm::vec4 v );
    void setUniform ( const GLchar *name, GLfloat v );
    void setUniform ( const GLchar *name, glm::ivec2 v );
    void setUniform ( const GLchar *name, glm::ivec3 v );
    void setUniform ( const GLchar *name, glm::ivec4 v );
    void setUniform ( const GLchar *name, GLint v );
    void setUniform ( const GLchar *name, glm::uvec2 v );
    void setUniform ( const GLchar *name, glm::uvec3 v );
    void setUniform ( const GLchar *name, glm::uvec4 v );
    void setUniform ( const GLchar *name, GLuint v );

    void setUniform ( const GLchar *name, glm::mat2 v );
    void setUniform ( const GLchar *name, glm::mat3 v );
    void setUniform ( const GLchar *name, glm::mat4 v );
    void setUniform ( const GLchar *name, glm::mat2x3 v );
    void setUniform ( const GLchar *name, glm::mat2x4 v );
    void setUniform ( const GLchar *name, glm::mat3x2 v );
    void setUniform ( const GLchar *name, glm::mat3x4 v );
    void setUniform ( const GLchar *name, glm::mat4x2 v );
    void setUniform ( const GLchar *name, glm::mat4x3 v );
    
    void printLog();

    operator bool();
  };

  /* ------------------------------------------- */

  extern Program * createProgram ( ShaderFile s1, 
				   ShaderFile s2 = ShaderFile(), ShaderFile s3 = ShaderFile(), 
				   ShaderFile s4 = ShaderFile(), ShaderFile s5 = ShaderFile() );

  /* ------------------------------------------- */

};
