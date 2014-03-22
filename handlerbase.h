
#include <glm/glm.hpp>
#include <trackball.h>
#include <buffer.h>
#include <vertexarray.h>
#include <program.h>

#pragma once

namespace EZGraphics {

  /* -------------------------------------- */

  class EventHandlerBase {

    int windowWidth, windowHeight;
    int _argc;
    char **_argv;
    unsigned int windowMode;

  public:

    EventHandlerBase ( int argc, char **argv, unsigned int mode, int width = 800, int height = 800 );

    virtual void motionWithRightButtonDown ( int mx, int my );
    virtual void motionWithLeftButtonDown ( int mx, int my );
    virtual void motionWithMiddleButtonDown ( int mx, int my );
    virtual void draw();
    virtual void leftMouseButtonDown ( int mx, int my );
    virtual void leftMouseButtonUp ( int mx, int my );
    virtual void middleMouseButtonDown ( int mx, int my );
    virtual void middleMouseButtonUp ( int mx, int my );
    virtual void rightMouseButtonDown ( int mx, int my );
    virtual void rightMouseButtonUp ( int mx, int my );
    virtual void keyPressed ( unsigned char key, int x, int y );
    virtual void resize ( int sizex, int sizey );
    virtual void idleFunction();
    virtual void passiveMotion ( int mx, int my );
    virtual void windowVisible();
    virtual void windowInvisible();
    virtual void specialKeyFunction ( int key, int x, int y );
    virtual void mouseCursorEnters();
    virtual void mouseCursorLeaves();
    virtual void initializeGL();
    virtual void cleanup();

    void run();
    int getWindowWidth();
    int getWindowHeight();
    float getAspectRatio();
    unsigned int getWindowMode();
    int getArgc();
    char ** getArgv();
    int getWindowID();
  };

  /* -------------------------------------- */

};
