
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

#include <iostream>
#include <cstdlib>

#include <mesh.h>
#include <trackballhandler.h>
#include <program.h>
#include <buffer.h>
#include <glutwrapper.h>
#include <menucreator.h>
#include <framebuffer.h>

using namespace std;
using namespace glm;
using namespace EZGraphics;

/* -------------------------------------- */


class ViewerEventHandlers : public TrackballHandler, public MenuCreator {

  Program *pgmPhong, *pgmSquare;
  float maxdim;
  vec3 center;
  IndexBuffer *ix;
  Buffer *vnormal, *vloc, *qbuf;
  VertexArray *vaPhong, *vaSquare;
  int ts;  // number of triangles

  static int reor;    // reorient the model if !=0
  static vec3 lloc;   // light source location

  static bool showColor;            // show color texture if true; otherwise, depth texture
  static bool nearestInterpolation; // nearest interpolation used if true, bilinear if false
  static bool lightMoving;          // is the light source moving?

  // NEW TYPES ALERT!
  // Texture: a wrapper for a texture object in OpenGL
  // Framebuffer: an object, usually with some textures attached, that can replace the
  //  standard rendering target, i.e. the framebuffer associated with your OpenGL window.
  static Framebuffer *fb;
  static Texture *tcol,*tdepth;

  static int texsize;  // this represents the sizes of textures we'll be rendering to

public:

  ViewerEventHandlers ( int argc, char **argv ) :
    TrackballHandler(argc,argv,GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGB,800,800)
  {
  }

  /* -------------------------------------- */

  // this section contains the event handlers for the menu entries

  // change resolution of the framebuffer to be rendered to to 64x64
  static void res_64()
  {
    delete_fb();    // delete the current framebuffer
                    //   (the method is implemented just below this section)
    texsize = 64;   // change the size
    make_fb();      // re-build the framebuffer, with of the requested size
                    //   (the method is implemented just below this section)
  }

  static void res_128()
  {
    delete_fb();
    texsize = 128;
    make_fb();
  }

  static void res_256()
  {
    delete_fb();
    texsize = 256;
    make_fb();
  }

  static void res_512()
  {
    delete_fb();
    texsize = 512;
    make_fb();
  }

  static void res_1024()
  {
    delete_fb();
    texsize = 1024;
    make_fb();
  }

  static void res_2048()
  {
    delete_fb();
    texsize = 2048;
    make_fb();
  }

  static void reorient()
  {
    reor = -reor;
  }

  static void tog_anim()
  {
    lightMoving = !lightMoving;
  }

  static void tog_texture()
  {
    showColor = !showColor;;
  }

  static void tog_interpolation()
  {
    nearestInterpolation = !nearestInterpolation;
  }

  /* -------------------------------------- */

  static void make_fb()
  {
    // tcol is a 2D RGB texsize x texsize texture
    //  RGB is a constant that represents 8-bit RGB texture
    //  See the definition of TexFormat enum in texture.h for other values allowed.
    //  Stencil may require new hardware/drivers to work properly.
    tcol = new Texture(RGB,texsize,texsize);

    // tdepth is a depth texture, i.e. it stores depth values as the values of texels.
    tdepth = new Texture(Depth,texsize,texsize);

    // allocate new Framebuffer
    fb = new Framebuffer;

    // attach color and depth textures to it; the tcol texture will play the role of color
    //  buffer and tdepth - of the depth buffer.
    fb->attachColor(tcol);
    fb->attachDepth(tdepth);

    // Print out the status of the frame buffer. In particular, if the textures are of
    //  wrong type/format, the framebuffer will not be `complete', i.e. suitable for
    //  rendering into it. If this is the case, you should get a message complaining
    //  about it in the terminal. For example, it is wrong to use a color texture as
    //  the depth texture or the other way around. The restrictions are mostly common
    //  sense. See specification for more details.
    fb->printLog();
  }

  static void delete_fb()
  {
    // delete framebuffer and textures
    delete fb;
    delete tcol;
    delete tdepth;
  }

  /* -------------------------------------- */

  // function used for light movement

  static void timerFunc( int )
  {
    // move light source (if it is supposed to move)
    if (lightMoving)
      lloc = vec3(rotate(mat4(),.75f,vec3(0.0,0.0,1.0))*vec4(lloc,1.0));

    glutTimerFunc(30,timerFunc,0);  // come here again in 30ms
  }

  /* -------------------------------------- */

  void initializeGL()
  {
    // build a vertex array containing a 2D square extending from -1 to 1.
    // we'll be rendering textures as a square with color pattern looked up from
    //  the texture applied to it

    vec2 qv[4] = { vec2(-1,-1), vec2(1,-1), vec2(-1,1), vec2(1,1) };
    qbuf = new Buffer(4,qv);
    vaSquare = new VertexArray;
    vaSquare->attachAttribute(0,qbuf);

    // we'll use the familiar Phong program and a program to apply texture to the square

    pgmPhong = createProgram(ShaderFile(Vert,"shaders/vtxPhong.glsl"),
			     ShaderFile(Frag,"shaders/frgPhong.glsl"));
    pgmSquare = createProgram(ShaderFile(Vert,"shaders/vtxSquare.glsl"),
			    ShaderFile(Frag,"shaders/frgSquare.glsl"));

    // this should look familiar: use the Mesh class to read mesh and get
    //  vertex locations, normals and triangle table (to be used as the index buffer)

    Mesh M(getArgv()[1]);
    center = M.getCenter();
    maxdim = M.getMaxDim();
    ts = M.getTriangleCount();
    vloc = new Buffer(M.getVertexCount(),M.getVertexTable());
    vnormal = new Buffer(M.getVertexCount(),M.getVertexNormals());
    ix = new IndexBuffer(M.getTriangleCount(),M.getTriangleTable());

    // build the VAO for the standard Phong program

    vaPhong = new VertexArray();
    vaPhong->attachAttribute(0,vloc);
    vaPhong->attachAttribute(1,vnormal);

    // want to use culling, depth test and white background

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    // build the framebuffer

    make_fb();

    // ... and menu

    beginMenu();
    addMenuEntry("Reorient",reorient);
    addMenuEntry("Toggle texture",tog_texture);
    addMenuEntry("Toggle light movement", tog_anim);
    addMenuEntry("Toggle interpolation", tog_interpolation);
    beginSubMenu("Texture size");
    addMenuEntry("2048",res_2048);
    addMenuEntry("1024",res_1024);
    addMenuEntry("512",res_512);
    addMenuEntry("256",res_256);
    addMenuEntry("128",res_128);
    addMenuEntry("64",res_64);
    endSubMenu();
    endMenu();

    // register the timer callback

    glutTimerFunc(30,timerFunc,0);   // make timerFunc(0) call in 30 ms
  }

  /* -------------------------------------- */

  void draw()
  {
    // clear the WINDOW

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set up culling...

    if (reor>0)
      glCullFace(GL_BACK);
    else
      glCullFace(GL_FRONT);

    // modelview and projection matrices are as always...

    mat4 ModelView =  translate(mat4(),vec3(0.0f,0.0f,-20.0f)) *
      mat4(getRotation()) *
      scale(mat4(),vec3(1/maxdim)) *
      translate(mat4(),-center);
    mat4 Projection = perspective(getZoom(),getAspectRatio(),18.0f,22.0f);

    // so are all uniform variables for the Phong program...

    pgmPhong->setUniform("MV",ModelView);
    pgmPhong->setUniform("P",Projection);
    pgmPhong->setUniform("NM",getRotation());
    pgmPhong->setUniform("lloc",lloc);
    pgmPhong->setUniform("kd",vec3(0.5,0.7,0.9));
    pgmPhong->setUniform("ka",vec3(0.5,0.7,0.9));
    pgmPhong->setUniform("ks",vec3(0.3,0.3,0.3));
    /* pgmPhong->setUniform("I",vec3(0.8,0.8,0.8)); */
    /* pgmPhong->setUniform("Ia",vec3(0.2,0.2,0.2)); */
    pgmPhong->setUniform("nspec",1000.0f);
    pgmPhong->setUniform("reor",reor);

    // Here, we render into our frame buffer.

    fb->on();   // Turn on the framebuffer; Until it is turned off, the framebuffer will be used as
                // the rendering target.

    glViewport(0,0,texsize,texsize);  // The framebuffer has a different resolution than the
                                      // window. This changes the viewport transformation to
    // scaling [-1,1]x[-1,1] (normalized coordinates, after modelview and projection transformations)
    //   --> [0,texsize]x[0,texsize]

    pgmPhong->on();  // turn the Phong program on

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // this applies to currently active framebuffer!

    vaPhong->sendToPipelineIndexed(GL_TRIANGLES,ix,0,3*ts);  // render the mesh as usual

    pgmPhong->off();  // turn the program off

    fb->off();  // turn the framebuffer off; currently active framebuffer = our window

    // Here, we render the texture into the GLUT window

    glCullFace(GL_BACK);  // the square is oriented CCW

    if (nearestInterpolation) {
      tcol->nearest();
      tdepth->nearest();
    } else {
      tcol->linear();
      tdepth->linear();
    }

    tcol->bind(1);  // bind the texture to attachment point #1; use small numbers as TAP IDs!
    tdepth->bind(2);  // bind the texture to attachment point #1; use small numbers as TAP IDs!

    // resolution of the framebuffer has changes, so the viewport transform needs to be
    //  updated; we need scaling [-1,1]^2 ---> [0,width of window] x [0, height of window]
    glViewport(0,0,getWindowWidth(),getWindowHeight());

    // render the square; see how the square shaders use the texture...
    pgmSquare->on();
    pgmSquare->setUniform("xo", (float)1.0 / ((float) getWindowWidth()));
    pgmSquare->setUniform("yo", (float)1.0 / ((float) getWindowHeight()));
    vaSquare->sendToPipeline(GL_TRIANGLE_STRIP,0,4);  // send 4 vertices
    pgmSquare->off();
  }

  virtual void cleanup()
  {
    cout << "cleaning up..." << endl;
    delete pgmSquare;
    delete pgmPhong;
    delete ix;
    delete vnormal;
    delete vloc;
    delete qbuf;
    delete tcol;
    delete tdepth;
    delete fb;
  }

};

// declare all static variables here...

bool ViewerEventHandlers::lightMoving = true;
int ViewerEventHandlers::reor = 1;
vec3 ViewerEventHandlers::lloc = vec3(0,50,10);
bool ViewerEventHandlers::showColor =  true;
int ViewerEventHandlers::texsize = 2048;
Framebuffer *ViewerEventHandlers::fb = NULL;
Texture *ViewerEventHandlers::tcol = NULL;
Texture *ViewerEventHandlers::tdepth = NULL;
bool ViewerEventHandlers::nearestInterpolation = true;

/* -------------------------------------- */

int main ( int argc, char *argv[] )
{
  GLUTwrapper(new ViewerEventHandlers(argc,argv)).run();
  return 0;
}
