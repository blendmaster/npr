
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <handlerbase.h>

#pragma once

namespace EZGraphics {

  /* -------------------------------------- */

  class GLUTwrapper {
    
    static  EventHandlerBase *handler;
    static int windowID;
    static int buttonDown;
    
    static void activeMotion ( int mx, int my );
    static void draw();
    static void mouseButton ( int btn, int state, int mx, int my );
    static void keyPressed ( unsigned char key, int x, int y );
    static void resize ( int sizex, int sizey );
    static void idleFunction();
    static void passiveMotion ( int mx, int my );
    static void visibilityFunction ( int state );
    static void specialFunction ( int key, int x, int y );
    static void entryFunction ( int state );

  public:

    GLUTwrapper ( EventHandlerBase *h );
    void run();
  };

  /* -------------------------------------- */

};
