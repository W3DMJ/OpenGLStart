//
// Created by w3dmj on 8/24/21.
//

#include "mesh.h"

Mesh::Mesh(std::vector<Vertex>& Vertices, uint32_t numVertices, bool bStatic)
{
    Vertex vertices[numVertices];
    for (uint16_t i = 0; i < numVertices; i++)
        vertices[i] = Vertices[i];

    mDrawCount = numVertices;
    glGenVertexArrays(1, &mVertexArrayObject);
    glBindVertexArray(mVertexArrayObject);
    glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
    if (bStatic)
        glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
    else
        glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &mVertexArrayObject);
}

void Mesh::Update(std::vector<Vertex>& Vertices, uint32_t numVertices, bool bStatic)
{
    Vertex vertices[numVertices];
    for (uint16_t i = 0; i < numVertices; i++)
        vertices[i] = Vertices[i];

    mDrawCount = numVertices;
    glGenVertexArrays(1, &mVertexArrayObject);
    glBindVertexArray(mVertexArrayObject);
    glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
    if (bStatic)
        glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
    else
        glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindVertexArray(0);
}

void Mesh::Draw(GLenum DrawType)
{
    glBindVertexArray(mVertexArrayObject);
    glDrawArrays(DrawType, 0, mDrawCount);
    glBindVertexArray(0);
}