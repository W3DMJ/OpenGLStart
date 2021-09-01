//
// Created by w3dmj on 8/24/21.
//

#ifndef INC_02_OPENGLSTART_MESH_H
#define INC_02_OPENGLSTART_MESH_H

#include <stdint.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>

class Vertex{
public:
    Vertex()
    {

    }

    Vertex(const glm::vec3& pos)
    {
        this->pos = pos;
    }

    void SetPos(const glm::vec3& pos)
    {
        this->pos = pos;
    }
protected:
private:
    glm::vec3 pos;
};

class Mesh {
public:
    Mesh(std::vector<Vertex>& Vertices, uint32_t numVertices, bool bStatic);
    virtual ~Mesh();
    void Update(std::vector<Vertex>& Vertices, uint32_t numVertices, bool bStatic);
    void Draw(GLenum DrawType);
protected:
private:
    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint mVertexArrayObject;
    GLuint mVertexArrayBuffers[NUM_BUFFERS];
    uint32_t mDrawCount;
};


#endif //INC_02_OPENGLSTART_MESH_H
