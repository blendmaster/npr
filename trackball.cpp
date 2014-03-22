
#include "trackball.h"
#include <cmath>

using namespace glm;

namespace EZGraphics {

/* ---------------------------------------------- */

Trackball::Trackball ( int sx, int sy ) : R(), R0(), R0R(), ismousedown(false)
{
  winsize[0] = sx;
  winsize[1] = sy;
  
}

/* ---------------------------------------------- */

void Trackball::resize ( int sx, int sy )
{
  winsize[0] = sx;
  winsize[1] = sy;
}

/* ---------------------------------------------- */

vec3 Trackball::_ij2xyz ( float i, float j )
{
  float x = 2*i/winsize[0]-1;
  float y = 1-2*j/winsize[1];
  float x2y2 = 1-x*x-y*y;

  if (x2y2<0)
    {
      double l = sqrt(x*x+y*y);
      x = x/l;
      y = y/l;
      x2y2 = 0;
      
    }

  float z = sqrt(x2y2);

  return vec3(x,y,z);      
}

/* ---------------------------------------------- */

void Trackball::mouseDown ( int i, int j )
{
  ismousedown = true;
  last = _ij2xyz(i+0.013347689,j+0.0347387583);    // perturb to ensure no degeneracy
}

/* ---------------------------------------------- */

void Trackball::mouseMove ( int i, int j )
{
  vec3 cur = _ij2xyz(i,j);
  vec3 axis = cross(last, cur);
  R0 = mat3(rotate(mat4(),float(acos(dot(last,cur))/M_PI*180.0),axis));
  R0R = R0*R;
}

/* ---------------------------------------------- */

void Trackball::mouseUp ( int i, int j )
{
  if (!ismousedown)
    return;
  ismousedown = false;

  vec3 cur = _ij2xyz(i,j);
  vec3 axis = cross(last, cur);
  R0 = mat3(rotate(mat4(),float(acos(dot(last,cur))/M_PI*180.0),axis));
  R = R0*R;
  R0 = dmat3();
  R0R = R;
}

/* ---------------------------------------------- */

mat3 Trackball::rotation()
{
  return R0R;
}

/* ---------------------------------------------- */

bool Trackball::isActive()
{
  return ismousedown;
}

/* ---------------------------------------------- */

};
