#version 330

// locations of vertices of the square, in range -1..1 (see C++ code)
layout(location=0) in vec2 coord;

// locations of vertices scaled to the range 0...1; it's OK to use 
//  linear interpolation in screen space since we use a simple 
//  parallel projection to draw the square
noperspective out vec2 loc;
 
void main() {

  // apply [-1,1]->[0,1] scale
  loc = 0.5*(vec2(1,1)+coord);

  // just place the square at z=0; notice no transformations are applied.
  //  this means that parallel projection along the z-axis with clipping
  // planes @ -1 and 1 is used
  gl_Position = vec4(coord,0,1);           
} 
