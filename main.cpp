#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include <vector>


int main()
{
    Display display;
    std::vector<Vertex> spokes;
    std::vector<Vertex> circle[4];
    std::vector<Vertex> sweep;

    float theta = 0.0;
    float x = 0.0f;
    float y = 0.0f;
    float r = 0.0f;
    float angle = 0.0f;

    //# Draw spokes for radar display at 30 degree intervals
    for (uint16_t i = 0; i < 360; i += 30)
    {
        Vertex originVertex(glm::vec3(0.0f,0.0f,0.0f));
        Vertex radiusVertex;
        spokes.push_back(originVertex);
        theta = 2.0f * 3.1415926f * float(i) / float(360.0);//get the current angle
        x = 512.0 * cosf(theta);//calculate the x component
        y = 512.0 * sinf(theta);//calculate the y component

        radiusVertex.SetPos(glm::vec3(x,y,0.0f));
        spokes.push_back(radiusVertex);

    }

    Mesh mesh(spokes, (uint32_t)spokes.size(), true);

    theta = 0.0;
    x = 0.0f;
    y = 0.0f;

    Mesh *circles[4];

    for (uint16_t ii = 0; ii < 4; ii++)
    {
        for (uint16_t i = 0; i < 360; i++)
        {
            //Vertex originVertex(glm::vec3(0.0f,0.0f,0.0f));
            Vertex radiusVertex;
            //spokes.push_back(originVertex);
            theta = 2.0f * 3.1415926f * float(i) / float(360.0);//get the current angle
            switch (ii)
            {
                case 0:
                    r = 128.0f;
                    break;
                case 1:
                    r = 256.0f;
                    break;
                case 2:
                    r = 384.0;
                    break;
                case 3:
                    r = 512.0;
                    break;
            }


            x = r * cosf(theta); //# calculate the x component
            y = r * sinf(theta); //# calculate the y component

            radiusVertex.SetPos(glm::vec3(x,y,0.0f));
            circle[ii].push_back(radiusVertex);
        }
        circles[ii] = new Mesh(circle[ii], (uint32_t)circle[ii].size(), true);
    }

    Vertex sweepOriginVertex(glm::vec3(0.0f,0.0f,0.0f));
    Vertex sweepVertex;
    sweep.push_back(sweepOriginVertex);
    theta = 2.0f * 3.1415926f * float(angle) / float(360.0);//get the current angle
    x = 512.0 * cosf(theta);//calculate the x component
    y = 512.0 * sinf(theta);//calculate the y component
    sweepVertex.SetPos(glm::vec3(x,y,0.0f));
    sweep.push_back(sweepVertex);

    Mesh Sweeper(sweep, (uint32_t)sweep.size(), false);
    Shader shader("./res/basicShader");

    while (!display.IsClosed())
    {
        display.clear();
        //# Draws spokes
        mesh.Draw(GL_LINES);

        //# Draws Range Rings
        for (uint16_t ii = 0; ii < 4; ii++)
            circles[ii]->Draw(GL_LINE_LOOP);

        //# Draw Sweeper
        Sweeper.Draw(GL_LINES);
        shader.Bind();
        display.Update();

        //# Update Sweeper Data before draw everything again
//        if (angle - (0.0878*2) < 60.0)
//            angle  = 120.0;

        if (angle - 1 < 0.0)
            angle  = 360.0;

//        angle-= (0.0878 * 2);
        angle--;
        theta = 2.0f * 3.1415926f * float(angle) / float(360.0);//get the current angle
        x = 512.0 * cosf(theta);//calculate the x component
        y = 512.0 * sinf(theta);//calculate the y component

//        sweep.push_back(sweepOriginVertex);
        sweep[1].SetPos(glm::vec3(x,y,0.0f));
//        sweep.push_back(sweepVertex);
        Sweeper.Update(sweep, (uint32_t)sweep.size(), false);

    }

    return 0;
}
