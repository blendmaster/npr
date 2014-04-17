#version 330
#extension GL_ARB_shading_language_420pack: enable

// basic NPR from http://www.cs.northwestern.edu/~ago820/SIG98/gooch98.pdf

out vec3 fragcolor;

noperspective in vec3 _wnormal;
noperspective in vec3 _wcoord;

uniform vec3 lloc;
uniform vec3 kd,ka,ks;
uniform float nspec;
/* uniform vec3 I,Ia; */
uniform int reor;

const float alpha = 0.2;
const float beta = 0.6;
const vec3 k_blue = vec3(0, 0, 0.4);
const vec3 k_yellow = vec3(0.4, 0.4, 0);

layout (binding=1) uniform sampler2D tex;

void main() {

    vec3 N = reor*normalize(_wnormal);
    vec3 I = normalize(lloc-_wcoord);

    fragcolor = mix(k_blue + alpha * kd,
                    k_yellow + beta * kd,
                    (1 + dot(I, N)) / 2.0);
}
