
#include <glm/glm.hpp>
#include <trackball.h>
#include <buffer.h>
#include <vertexarray.h>
#include <program.h>
#include <handlerbase.h>

#pragma once

namespace EZGraphics {

  /* -------------------------------------- */

  class TrackballHandler : public EventHandlerBase {

    Trackball t;
    float zoom;
    int lasty;

  public:

    TrackballHandler ( int argc, char **argv, unsigned int mode, int width = 800, int height = 800 );

    virtual void motionWithLeftButtonDown ( int mx, int my );
    virtual void motionWithMiddleButtonDown ( int mx, int my );
    virtual void leftMouseButtonDown ( int mx, int my );
    virtual void leftMouseButtonUp ( int mx, int my );
    virtual void middleMouseButtonDown ( int mx, int my );
    virtual void resize ( int sizex, int sizey );

    glm::mat3 getRotation();
    float getZoom();
  };

  /* -------------------------------------- */

};
