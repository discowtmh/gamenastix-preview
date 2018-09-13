// This file is a part of opengl-stickyman project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <GL/glu.h>
#include <opengl/ContextPreserver.h>
#include <opengl/Quad.h>


namespace component {
struct Floor
{
    void render()
    {
        ContextPreserver contextPreserver;

        glTranslatef(0.0F, -0.1F, 0.0F);
        glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
        glColor4ub(0x45, 0x84, 0xD4, 0xFF);
        gluCylinder(quad.get(), 1.5, 1.5, 0.03, 10, 10);
    }

    opengl::Quad quad;
};
}