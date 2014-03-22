
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma once

namespace EZGraphics {

  /* ---------------------------------------------- */

  class Trackball {

    glm::mat3 R;     // finished rotations
    glm::mat3 R0;    // current rotation
    glm::mat3 R0R;

    int winsize[2];  // window size

    bool ismousedown;  // true if dragging
    glm::vec3 last;  // last mouse down event

    glm::vec3 _ij2xyz ( float i, float j );

  public:
    
    Trackball ( int sx, int sy );
    void resize ( int sx, int sy );
  
    void mouseDown ( int i, int j );
    void mouseMove ( int i, int j );
    void mouseUp ( int i, int j );

    glm::mat3 rotation();  // the rotation matrix 
    
    bool isActive();   // is mouse button down?
  };

  /* ---------------------------------------------- */

};
