#version 330
#extension GL_ARB_shading_language_420pack: enable

// output fragment color
out vec3 color;

// coordinates of the fragment in range [0,1]
noperspective in vec2 loc;

// This is how you declare texture variables, called samplers
//  since you can sample values from them. binding=1 means that
//  tex can be used to sample texture with TAP #1 
//  (cf t->bind(1) in the C++ code). Generally, you can use more 
//  than 1 sampler in a shader, but here (and in your shadow program) 
//  one will be enough.
layout (binding=1) uniform sampler2D tex;

void main() { 
	
	// Use the texture() function to look up color from texture.
	// First argument: sampler, second argument: texture coordinates.
	// For regular samplers, opposite texture corners correspond
        // to texture coordinates (0,0) and (1,1); this is why we scaled 
	// the coordinates to [0,1] range in the vertex shader.
	color = texture(tex,loc).rgb;
} 
