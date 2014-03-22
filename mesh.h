
#include <glm/glm.hpp>
#include <memory>

#pragma once

namespace EZGraphics {

  /* ------------------------------------------- */

  class Mesh {

    int vertices, triangles;
    glm::uvec3 *ttable;
    glm::vec3* vtable;
    glm::vec3 *tnormals;
    glm::vec3 *vnormals;
    glm::ivec3 *atable;
    glm::vec3 bbox[2];
    glm::vec3 center;
    float bboxdiam;
    float bboxmaxdim;

  public:
  
    Mesh ( const char *name );
    ~Mesh();

    glm::uvec3 *getTriangleTable();
    glm::vec3 *getVertexTable();
    glm::vec3 *getTriangleNormals();
    glm::vec3 *getVertexNormals();
    glm::ivec3 *getAdjacencyTable();

    glm::vec3 getUpperCorner();
    glm::vec3 getLowerCorner();
    glm::vec3 getCenter();
    float getDiameter();
    float getMaxDim();
    int getTriangleCount();
    int getVertexCount();
    
  };
  
  /* ------------------------------------------- */
  
};
