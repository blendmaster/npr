
#pragma once

namespace EZGraphics {

/* ------------------------------------------- */

  typedef enum { R, RG, RGB, RGBA, // 8-bit
		 RF, RGF, RGBF, RGBAF, // 32-bit float
		 RSF, RGSF, RGBSF, RGBASF, // 16-bit float
		 R32UI, RG32UI, RGB32UI, RGBA32UI,  // 32-bit unsigned int
		 Depth, DepthStencil, Stencil }  TexFormat;

/* ------------------------------------------- */

  class Texture {

  protected:

    GLuint handle;
    int dim;
    int size[3];
    GLint internalfmt;
    GLenum fmt;
    GLenum type;
    GLenum tgt;
    GLenum attachedto;

/* ------------------------------------------- */

  public:

    Texture ( TexFormat t, int x, int y, int z, GLvoid *data = NULL );  // 3D
    Texture ( TexFormat t, int x, int y, GLvoid *data = NULL );         // 2D
    Texture ( TexFormat t, int x, GLvoid *data = NULL );                // 1D
    ~Texture();

    // don't use - will generate an error
    Texture ( const Texture & );
    Texture & operator= ( const Texture & );
    
    void linear();
    void nearest();
    void clampToEdge();
    void clampToBorder();
    void setBorderColor ( GLfloat r, GLfloat g, GLfloat b );
    void repeat();

    void makeMipmap();

    void bind ( int TAP );  // attaches to a texture attachment point #i

/*
    void bindAsImage ( int index, int level = 0 );  // attaches as an image...
    void bindAsROImage ( int index, int level = 0 );  // attaches as an image...
    void bindAsWOImage ( int index, int level = 0 );  // attaches as an image...
*/

    GLuint getHandle();
  };

/* ------------------------------------------- */

  class RGBTexture1D : public Texture
  {
  public:
    RGBTexture1D ( int x, unsigned char *ptr = NULL );
  };

  class RGBTexture2D : public Texture
  {
  public:
    RGBTexture2D ( int x, int y, unsigned char *ptr = NULL );
  };

  class RGBTexture3D : public Texture 
  {
  public:
    RGBTexture3D ( int x, int y, int z, unsigned char *ptr = NULL );
  };

  class RGBATexture1D : public Texture
  {
  public:
    RGBATexture1D ( int x, unsigned char *ptr = NULL );
  };

  class RGBATexture2D : public Texture
  {
  public:
    RGBATexture2D ( int x, int y, unsigned char *ptr = NULL );
  };

  class RGBATexture3D : public Texture 
  {
  public:
    RGBATexture3D ( int x, int y, int z, unsigned char *ptr = NULL );
  };

  class RTexture1D : public Texture
  {
  public:
    RTexture1D ( int x, unsigned char *ptr = NULL );
  };

  class RTexture2D : public Texture
  {
  public:
    RTexture2D ( int x, int y, unsigned char *ptr = NULL );
  };

  class RTexture3D : public Texture 
  {
  public:
    RTexture3D ( int x, int y, int z, unsigned char *ptr = NULL );
  };

  class DepthTexture1D : public Texture
  {
  public:
    DepthTexture1D ( int x, unsigned char *ptr = NULL );
  };

  class DepthTexture2D : public Texture
  {
  public:
    DepthTexture2D ( int x, int y, unsigned char *ptr = NULL );
  };

  class DepthTexture3D : public Texture 
  {
  public:
    DepthTexture3D ( int x, int y, int z, unsigned char *ptr = NULL );
  };

  class StencilTexture1D : public Texture
  {
  public:
    StencilTexture1D ( int x, unsigned char *ptr = NULL );
  };

  class StencilTexture2D : public Texture
  {
  public:
    StencilTexture2D ( int x, int y, unsigned char *ptr = NULL );
  };

  class StencilTexture3D : public Texture 
  {
  public:
    StencilTexture3D ( int x, int y, int z, unsigned char *ptr = NULL );
  };


  class DepthStencilTexture1D : public Texture
  {
  public:
    DepthStencilTexture1D ( int x, unsigned char *ptr = NULL );
  };

  class DepthStencilTexture2D : public Texture
  {
  public:
    DepthStencilTexture2D ( int x, int y, unsigned char *ptr = NULL );
  //  void setMode ( int i );
  };

  class DepthStencilTexture3D : public Texture 
  {
  public:
    DepthStencilTexture3D ( int x, int y, int z, unsigned char *ptr = NULL );
  };


  /* ----------------------------------------------------- */

  // reads 3D texture from a raw 8-bit RGB binary file,
  // creates and returns a pointer to the resulting texture object
  // arguments: resolution and file name
  //  optional arguments: border color

  RGBTexture3D *createRGBTexture3D ( int x, int y, int z, const char *name, GLfloat r = 0.0, GLfloat g = 0.0, GLfloat b = 0.0 );

  /* ----------------------------------------------------- */
  
  // reads a 2D texture from a binary 8-bit RGB PPM file
  // creates and returns a pointer to the resulting texture object
  // The argument: file name (has to be PPM with no comment lines)
  //  optional arguments: border color

  extern RGBTexture2D *createRGBTexture2D ( const char *name, GLfloat r = 0.0, GLfloat g = 0.0, GLfloat b = 0.0 );
  
  /* ----------------------------------------------------- */

};
