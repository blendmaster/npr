
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include <iostream>
#include <cstdlib>

#include <mesh.h>
#include <trackballhandler.h>
#include <program.h>
#include <buffer.h>
#include <glutwrapper.h>

using namespace std;
using namespace glm;

namespace EZGraphics {

/* -------------------------------------- */

TrackballHandler::TrackballHandler ( int argc, char **argv, unsigned int mode, int width, int height ) :
  EventHandlerBase(argc,argv,mode,width,height), t(width,height), zoom(3.0f)
{
}

/* -------------------------------------- */

void TrackballHandler::motionWithMiddleButtonDown ( int mx, int my )
{
  int dy = my-lasty;
  zoom += dy/100.0;
  if (zoom<=0.01) zoom = 0.01;
  if (zoom>=179) zoom = 179;
  lasty = my;
}

/* -------------------------------------- */

void TrackballHandler::motionWithLeftButtonDown ( int mx, int my )
{
  t.mouseMove(mx,my);
}

/* -------------------------------------- */

void TrackballHandler::leftMouseButtonDown ( int mx, int my )
{
  t.mouseDown(mx,my);
}

/* -------------------------------------- */

void TrackballHandler::leftMouseButtonUp ( int mx, int my )
{
  t.mouseUp(mx,my);
}

/* -------------------------------------- */

void TrackballHandler::middleMouseButtonDown ( int mx, int my )
{
  lasty = my;
}

/* -------------------------------------- */

void TrackballHandler::resize ( int sizex, int sizey )
{
  EventHandlerBase::resize(sizex,sizey);
  t.resize(sizex,sizey);  
}

/* -------------------------------------- */

glm::mat3 TrackballHandler::getRotation()
{
  return t.rotation();
}

/* -------------------------------------- */

float TrackballHandler::getZoom()
{
  return zoom;
}

/* -------------------------------------- */

};
