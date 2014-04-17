#version 330
#extension GL_ARB_shading_language_420pack: enable

// output fragment color
out vec3 color;

// coordinates of the fragment in range [0,1]
noperspective in vec2 loc;

layout (binding=1) uniform sampler2D tex;
layout (binding=2) uniform sampler2D depth;

// one pixel in texture space, i.e., width^-1
uniform float xo;
uniform float yo;

void main() {
  // get texture around window
  vec3 window[9];
  int k = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      window[k++] = texture(depth, loc + vec2(i * xo, j * yo)).rgb;
    }
  }

  // http://www.blitzbasic.com/Community/posts.php?topic=85263

  vec3 horiz = window[2] + (2.0*window[5]) + window[8] -
                   (window[0] + (2.0*window[3]) + window[6]);
  vec3 vert = window[0] + (2.0*window[1]) + window[2] -
                  (window[6] + (2.0*window[7]) + window[8]);

  vec3 mag = sqrt((horiz * horiz) + (vert * vert));

  color = length(mag) > 0.01 ? vec3(0) : texture(tex,loc).rgb - mag;
}
