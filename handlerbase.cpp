
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include <iostream>
#include <cstdlib>

#include <mesh.h>
#include <handlerbase.h>
#include <program.h>
#include <buffer.h>
#include <glutwrapper.h>

using namespace std;
using namespace glm;

namespace EZGraphics {

/* -------------------------------------- */

EventHandlerBase::EventHandlerBase ( int argc, char **argv, unsigned int mode, int width, int height )
{
  windowHeight = height;
  windowWidth = width;
  _argc = argc;
  _argv = argv;
  windowMode = mode;
}

/* -------------------------------------- */

void EventHandlerBase::initializeGL()
{
}

/* -------------------------------------- */

void EventHandlerBase::cleanup()
{
}

/* -------------------------------------- */

void EventHandlerBase::mouseCursorLeaves()
{
}

/* -------------------------------------- */

void EventHandlerBase::mouseCursorEnters()
{
}

/* -------------------------------------- */

void EventHandlerBase::specialKeyFunction ( int, int, int )
{
}

/* -------------------------------------- */

void EventHandlerBase::windowInvisible()
{
}

/* -------------------------------------- */

void EventHandlerBase::windowVisible()
{
}

/* -------------------------------------- */

void EventHandlerBase::passiveMotion ( int, int )
{
}

/* -------------------------------------- */

void EventHandlerBase::rightMouseButtonUp ( int, int )
{
}

/* -------------------------------------- */

void EventHandlerBase::rightMouseButtonDown ( int, int )
{
}

/* -------------------------------------- */

void EventHandlerBase::motionWithRightButtonDown ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::motionWithMiddleButtonDown ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::motionWithLeftButtonDown ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::draw()
{
}

/* -------------------------------------- */

void EventHandlerBase::leftMouseButtonDown ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::leftMouseButtonUp ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::middleMouseButtonDown ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::middleMouseButtonUp ( int mx, int my )
{
}

/* -------------------------------------- */

void EventHandlerBase::keyPressed ( unsigned char key, int x, int y )
{
  if (key==27)  // ESC
    {
      cleanup();
      exit(0);
    }
}

/* -------------------------------------- */

void EventHandlerBase::resize ( int sizex, int sizey )
{
  windowWidth = sizex;
  windowHeight = sizey;

  glViewport(0, 0,windowWidth,windowHeight);
  glutReshapeWindow(windowWidth,windowHeight);
}

/* -------------------------------------- */

void EventHandlerBase::idleFunction()
{
    static int lastUpdate = 0;
    static int frames = 0;
    char buf[20];

    glutPostRedisplay(); // calls your display callback function

    int currentTime = glutGet( GLUT_ELAPSED_TIME );
    frames++;

    // is the time difference between lastUpdate and current time > one second ( 1000 ms )?
    if ( ( currentTime - lastUpdate ) >= 1000 )
      {
	sprintf( buf, "FPS: %d", frames );
	glutSetWindowTitle( buf );
	frames = 0;
	lastUpdate = currentTime;
	}
}

/* -------------------------------------- */

void EventHandlerBase::run()
{
  glutMainLoop();
}

/* -------------------------------------- */

int EventHandlerBase::getWindowWidth()
{
  return windowWidth;
}

/* -------------------------------------- */

int EventHandlerBase::getWindowHeight()
{
  return windowHeight;
}

/* -------------------------------------- */

unsigned int EventHandlerBase::getWindowMode()
{
  return windowMode;
}

/* -------------------------------------- */

int EventHandlerBase::getArgc()
{
  return _argc;
}

/* -------------------------------------- */

char ** EventHandlerBase::getArgv()
{
  return _argv;
}

/* -------------------------------------- */

float EventHandlerBase::getAspectRatio()
{
  return float(windowWidth)/windowHeight;
}

/* -------------------------------------- */



/* -------------------------------------- */

};
