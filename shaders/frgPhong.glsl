#version 330
#extension GL_ARB_shading_language_420pack: enable

// this is a standard Phong fragment shader...

out vec3 fragcolor;

noperspective in vec3 _wnormal;
noperspective in vec3 _wcoord;

uniform vec3 lloc;
uniform vec3 kd,ka,ks;
uniform float nspec;
uniform vec3 I,Ia;
uniform int reor;

layout (binding=1) uniform sampler2D tex;

void main() { 

    vec3 N = reor*normalize(_wnormal);
    vec3 L = normalize(lloc-_wcoord);
    vec3 V = -normalize(_wcoord);
    vec3 H = normalize(L+V);

    float NdotL = dot(N,L);
    float HdotN = dot(H,N);

    if (NdotL<0) NdotL = 0.0;
    if (HdotN<0) HdotN = 0.0;

    fragcolor = ka*Ia + (kd*NdotL + ks*pow(HdotN,nspec))*I;
} 
